/******************************************************************************
 * Copyright (C), 2016-2017, www.topscomm.com
 *
 * 文件名：     rs_232.c
 * 内容简述：串口驱动层
 *
 * 文件历史:
 * 版本号             日期                作者             说明
 * v0.1    2016.7.27   Root    创建文件
 ******************************************************************************/

#include "../../Header Files/app_plat/bsp.h"
#include "em_leuart.h"


objDrvChannel   DrvGPS232Channel;


uint8_t rtmp[200];//接收缓冲区
uint8_t wtmp[200];//发送缓冲区
static uint8_t rwflag; //发送/接收标志位
static uint8_t wcount = 0;//发送计数指针
static uint8_t rcount = 0;//接收计数指针
uint16_t size;


/******************************************************************************
 * 函数名： Uart_Write
 * 输     入： USARTx : 要发送的串口(gps_uart/gprs_uart/weihu_uart)
 *         sdata  : 要发送的数据指针
 *         len    : 要发送的数据长度
 * 输     出： 无
 * 功     能： 串口数据发送
 ****************************************************************************/
void Uart_Write(Uart_Type uart, uint8_t *sdata, uint16_t len)
{
	switch(uart)
    {
	  case gps_uart:
		  mem_cpy(wtmp,sdata,len);
		  LEUART0->IEN = LEUART_IEN_TXC;//打开发送中断
		  rwflag = 1;//标志位置1，表示发送(因leuart只有一个中断向量)
		  size = len;//将数据长度给出
		  wcount = 0;
		  LEUART_Tx(LEUART0, *wtmp);//立即启动一次发送
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
 * 函数名： Uart_Read
 * 输     入： USARTx : 要接收的串口(gps_uart/gprs_uart/weihu_uart)
 *         sdata  : 要接收的数据指针
 *         len    : 要接收的数据长度
 * 输     出： 无
 * 功     能： 串口数据发送
 ****************************************************************************/
void Uart_Read(Uart_Type uart, uint8_t *rdata, uint16_t len)//初始化时就应打开接收中断
{
	switch(uart)
    {
	  case gps_uart:
		  mem_cpy(rdata,rtmp,len);//从缓冲区取出
		  rcount = 0;//指针回到数组头
		  break;
      case gprs_uart:
    	  mem_cpy(rdata,rtmp,len);//从缓冲区取出;
    	  rcount = 0;//指针回到数组头
          break;
      case weihu_uart:
    	  ;
    	  break;
	  default:;
    }
}


/******************************
 * LEUART0中断服务（接收/发送）-GPS
 ******************************/
void LEUART0_IRQHandler(void)
{

	unsigned char rx_data;

	if(LEUART0->IF & 0x01)//发送完成中断
    {
		LEUART0->IFC = _LEUART_IFC_MASK;//清中断标志位
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

	if((LEUART0->IF & 0x04))//接收数据中断
	{
		LEUART0->IFC = _LEUART_IFC_MASK;//清中断标志位
		while (!(LEUART0->STATUS & LEUART_STATUS_RXDATAV))
		    ;
		rx_data = ((uint8_t)LEUART0->RXDATA);
		DrvGPS232Channel.recv_buffer[DrvGPS232Channel.recv_ptr ++] = rx_data;
		if(DrvGPS232Channel.recv_ptr >= sizeof(DrvGPS232Channel.recv_buffer)) DrvGPS232Channel.recv_ptr = 0;
	}
}

/******************************
 * UART0中断服务（发送）
 ******************************/
void UART0_TX_IRQHandler(void)
{
	UART0->IFC = _UART_IFC_MASK;//清中断标志位
	if(wcount < size)
    {
	  wcount++;
	  USART_Tx(UART0,*(wtmp + wcount));
	}
}

/******************************
 * UART0中断服务（接收）
 ******************************/
void UART0_RX_IRQHandler(void)
{
	UART0->IFC = _UART_IFC_MASK;//清中断标志位
	while (!(UART0->STATUS & UART_STATUS_RXDATAV))
	 ;
	*(rtmp + rcount) = ((uint8_t)UART0->RXDATA);
	rcount++;
	if(rcount == 200)//接收缓存溢出
	{
		rcount = 0; //从第一个开始覆盖
	}
}










//GPS模块
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





