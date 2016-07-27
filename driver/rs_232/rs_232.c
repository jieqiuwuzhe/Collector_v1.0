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

#include "../../inc/bsp.h"
#include "em_leuart.h"

typedef enum
{
  gps_uart,
  gprs_uart,
  weihu_uart
}Uart_Type;

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

