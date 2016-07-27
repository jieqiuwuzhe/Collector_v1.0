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

#include "../../inc/bsp.h"
#include "em_leuart.h"

typedef enum
{
  gps_uart,
  gprs_uart,
  weihu_uart
}Uart_Type;

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
		  while(len>0)
		  {
			  while (!(LEUART0->STATUS & LEUART_STATUS_TXBL))
			      ;
			    /* LF register about to be modified require sync. busy check */
			    LEUART_Sync(LEUART0, LEUART_SYNCBUSY_TXDATA);
			    LEUART0->TXDATA = (uint32_t)(*sdata++);
			    len--;
		  };
	  case gprs_uart:
		  ;
	  case weihu_uart:;
	  default:;
	}
}

