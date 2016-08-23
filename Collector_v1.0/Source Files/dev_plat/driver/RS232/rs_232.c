/******************************************************************************
 * Copyright (C), 2016-2017, www.topscomm.com
 *
 * �ļ�����     rs_232.c
 * ���ݼ���������������
 *
 * �ļ���ʷ:
 * �汾��             ����                ����             ˵��
 * v0.1    2016.7.27   Root    �����ļ�
 ******************************************************************************/

#include "../../Header Files/app_plat/bsp.h"
#include "em_leuart.h"


objDrvChannel   DrvGPS232Channel;


uint8_t rtmp[200];//���ջ�����
uint8_t wtmp[200];//���ͻ�����
static uint8_t rwflag; //����/���ձ�־λ
static uint8_t wcount = 0;//���ͼ���ָ��
static uint8_t rcount = 0;//���ռ���ָ��
uint16_t size;


/******************************************************************************
 * �������� Uart_Write
 * ��     �룺 USARTx : Ҫ���͵Ĵ���(gps_uart/gprs_uart/weihu_uart)
 *         sdata  : Ҫ���͵�����ָ��
 *         len    : Ҫ���͵����ݳ���
 * ��     ���� ��
 * ��     �ܣ� �������ݷ���
 ****************************************************************************/
void Uart_Write(Uart_Type uart, uint8_t *sdata, uint16_t len)
{
	switch(uart)
    {
	  case gps_uart:
		  mem_cpy(wtmp,sdata,len);
		  LEUART0->IEN = LEUART_IEN_TXC;//�򿪷����ж�
		  rwflag = 1;//��־λ��1����ʾ����(��leuartֻ��һ���ж�����)
		  size = len;//�����ݳ��ȸ���
		  wcount = 0;
		  LEUART_Tx(LEUART0, *wtmp);//��������һ�η���
		  break;
      case gprs_uart:
    	  mem_cpy(wtmp,sdata,len);
    	  size = len;
    	  rcount = 0;
    	  USART_Tx(UART0, *wtmp);
          break;
      case weihu_uart:
    	  ;
    	  break;
	  default:;
    }
}

/******************************************************************************
 * �������� Uart_Read
 * ��     �룺 USARTx : Ҫ���յĴ���(gps_uart/gprs_uart/weihu_uart)
 *         sdata  : Ҫ���յ�����ָ��
 *         len    : Ҫ���յ����ݳ���
 * ��     ���� ��
 * ��     �ܣ� �������ݷ���
 ****************************************************************************/
void Uart_Read(Uart_Type uart, uint8_t *rdata, uint16_t len)//��ʼ��ʱ��Ӧ�򿪽����ж�
{
	switch(uart)
    {
	  case gps_uart:
		  mem_cpy(rdata,rtmp,len);//�ӻ�����ȡ��
		  rcount = 0;//ָ��ص�����ͷ
		  break;
      case gprs_uart:
    	  mem_cpy(rdata,rtmp,len);//�ӻ�����ȡ��;
    	  rcount = 0;//ָ��ص�����ͷ
          break;
      case weihu_uart:
    	  ;
    	  break;
	  default:;
    }
}


/******************************
 * LEUART0�жϷ��񣨽���/���ͣ�-GPS
 ******************************/
void LEUART0_IRQHandler(void)
{

	unsigned char rx_data;

	if(LEUART0->IF & 0x01)//��������ж�
    {
		LEUART0->IFC = _LEUART_IFC_MASK;//���жϱ�־λ
		if(DrvGPS232Channel.drv_send_len > 0)
		{
		     --DrvGPS232Channel.drv_send_len;
		     LEUART_Tx(LEUART0, *(DrvGPS232Channel.drv_send_data ++));
		 }
    	 else
	    {
	      //disable  uart tx interrupt
	      //PLIB_INT_SourceDisable(INT_ID_0, UART_GPS_INT_SOURCE_TRANSMIT);
	      // IEC5CLR = 0x01 << 12;
	      //* DrvGPS232Channel.drv_send_state = APP_FRAME_SEND_COMPLETED;
	      // break;
	    }
    }

	if((LEUART0->IF & 0x04))//���������ж�
	{
		LEUART0->IFC = _LEUART_IFC_MASK;//���жϱ�־λ
		while (!(LEUART0->STATUS & LEUART_STATUS_RXDATAV))
		    ;
		rx_data = ((uint8_t)LEUART0->RXDATA);
		DrvGPS232Channel.recv_buffer[DrvGPS232Channel.recv_ptr ++] = rx_data;
		if(DrvGPS232Channel.recv_ptr >= sizeof(DrvGPS232Channel.recv_buffer)) DrvGPS232Channel.recv_ptr = 0;
	}
}

/******************************
 * UART0�жϷ��񣨷��ͣ�
 ******************************/
void UART0_TX_IRQHandler(void)
{
	UART0->IFC = _UART_IFC_MASK;//���жϱ�־λ
	if(wcount < size)
    {
	  wcount++;
	  USART_Tx(UART0,*(wtmp + wcount));
	}
}

/******************************
 * UART0�жϷ��񣨽��գ�
 ******************************/
void UART0_RX_IRQHandler(void)
{
	UART0->IFC = _UART_IFC_MASK;//���жϱ�־λ
	while (!(UART0->STATUS & UART_STATUS_RXDATAV))
	 ;
	*(rtmp + rcount) = ((uint8_t)UART0->RXDATA);
	rcount++;
	if(rcount == 200)//���ջ������
	{
		rcount = 0; //�ӵ�һ����ʼ����
	}
}










//GPSģ��
void gps_232_init(void)
{
    DrvGPS232Channel.read_ptr = DrvGPS232Channel.recv_ptr = 0;
}



INT16S gps_232_read_byte(void)
{
    INT16S data;

    data = -1;

    #ifdef __UART_RX_USE_DMA__
    #else
    if(DrvGPS232Channel.read_ptr == DrvGPS232Channel.recv_ptr)
        return data;
    data = DrvGPS232Channel.recv_buffer[DrvGPS232Channel.read_ptr ++];
    if(DrvGPS232Channel.read_ptr >=sizeof(DrvGPS232Channel.recv_buffer) ) DrvGPS232Channel.read_ptr = 0;
    #endif

    return data;
}





