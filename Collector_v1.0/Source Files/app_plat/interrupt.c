/*
 * interrupt.c
 *
 *  Created on: 2016-8-8
 *      Author: Root-Wang
 */

#include "em_gpio.h"
#include "../../../Header Files/app_plat/bsp.h"

extern objDrvChannel   DrvGPS232Channel;
extern objDrvChannel   DrvGPRSRS232Channel;


void GPIO_ODD_IRQHandler(void)
{
	/**/static BaseType_t xHigherPriorityTaskWoken;

	//8025T秒脉冲中断处理

	    //15引脚中断
		if ((GPIO->IF) & 0x8000)
		{
			//timer清零
			gSystemInfo.ms_tick = 0;
			gSystemInfo.ss_tick ++;

//			if(gSystemInfo.ss_tick >= 30)
//			{
//			//调试用，删掉！
//
//			tpos_give_sem_fromISR(Sem_duanlu,xHigherPriorityTaskWoken);
//			//***************
//			}

			//清标志位
			GPIO_IntClear(0x8000);

			/**/portYIELD_FROM_ISR( xHigherPriorityTaskWoken );  //立即引发一次任务调度
		}


	if(((gSystemInfo.ss_tick % 900) == 0) )
	{
		gSystemInfo.call_15min = 1;
	}
}


void TIMER0_IRQHandler(void)
{
	TIMER_IntClear(TIMER0, TIMER_IF_OF);

	gSystemInfo.ms_tick ++;
}


//Timer1 PWM波中断函数
//void TIMER1_IRQHandler(void)
//{
//  uint32_t compareValue;
//
//  TIMER_IntClear(TIMER1, TIMER_IF_OF);
//
// compareValue = (7000000/PWM_FREQ)*10/100; //占空比百分之五十
//
//  TIMER_CompareBufSet(TIMER1, 0, compareValue);
//}

/******************************
 * LEUART0中断服务（接收/发送）-GPS
 ******************************/
void LEUART0_IRQHandler(void)
{

	unsigned char rx_data;

	if(LEUART0->IF & LEUART_IF_TXC)//发送完成中断
    {
		LEUART0->IFC = LEUART_IFC_TXC;//清发送完成中断标志位
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

	if((LEUART0->IF & LEUART_IF_RXDATAV))//接收数据中断
	{
		//该中断标志无需手动清除？
		while (!(LEUART0->STATUS & LEUART_STATUS_RXDATAV))
		    ;
		rx_data = ((uint8_t)LEUART0->RXDATA);
		DrvGPS232Channel.recv_buffer[DrvGPS232Channel.recv_ptr ++] = rx_data;
		if(DrvGPS232Channel.recv_ptr >= sizeof(DrvGPS232Channel.recv_buffer)) DrvGPS232Channel.recv_ptr = 0;
	}
}


/******************************
 * UART0中断服务（发送）- GPRS
 ******************************/
void UART0_TX_IRQHandler(void)
{
	UART0->IFC = UART_IFC_TXC;//清发送完成中断标志位
	if(DrvGPRSRS232Channel.drv_send_len > 0)
	{
		--DrvGPRSRS232Channel.drv_send_len;
		USART_Tx(UART0, *(DrvGPRSRS232Channel.drv_send_data ++));
	}
}

/******************************
 * UART0中断服务（接收）- GPRS
 ******************************/
void UART0_RX_IRQHandler(void)
{
	unsigned char rx_data;
	//该中断标志无需手动清除？
	while (!(UART0->STATUS & LEUART_STATUS_RXDATAV))
	    ;
	rx_data = ((uint8_t)UART0->RXDATA);
	DrvGPRSRS232Channel.recv_buffer[DrvGPRSRS232Channel.recv_ptr ++] = rx_data;
	if(DrvGPRSRS232Channel.recv_ptr >= sizeof(DrvGPRSRS232Channel.recv_buffer)) DrvGPRSRS232Channel.recv_ptr = 0;
}
/********************************************************************************************************/

//GPIO偶中断
void GPIO_EVEN_IRQHandler(void)
{
	static BaseType_t xHigherPriorityTaskWoken;

	    //2引脚中断
		if ((GPIO->IF) & 0x04)
		{
				//清标志位
				GPIO_IntClear(0x04);
			if (Radio_CheckReceived()==true)
			{
				//接收到了有效包，发送信号量
				//在汇集单元处于LDC模式是，能产生此中断的唯一原因是线路发生了短路/接地/低电量故障
				//因此给出故障信号量
				tpos_give_sem_fromISR(Sem_Fault, xHigherPriorityTaskWoken);
			}

			/**/portYIELD_FROM_ISR( xHigherPriorityTaskWoken );  //立即引发一次任务调度
		}


}

