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

	//8025T�������жϴ���

	    //15�����ж�
		if ((GPIO->IF) & 0x8000)
		{
			//timer����
			gSystemInfo.ms_tick = 0;
			gSystemInfo.ss_tick ++;

//			if(gSystemInfo.ss_tick >= 30)
//			{
//			//�����ã�ɾ����
//
//			tpos_give_sem_fromISR(Sem_duanlu,xHigherPriorityTaskWoken);
//			//***************
//			}

			//���־λ
			GPIO_IntClear(0x8000);

			/**/portYIELD_FROM_ISR( xHigherPriorityTaskWoken );  //��������һ���������
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


//Timer1 PWM���жϺ���
//void TIMER1_IRQHandler(void)
//{
//  uint32_t compareValue;
//
//  TIMER_IntClear(TIMER1, TIMER_IF_OF);
//
// compareValue = (7000000/PWM_FREQ)*10/100; //ռ�ձȰٷ�֮��ʮ
//
//  TIMER_CompareBufSet(TIMER1, 0, compareValue);
//}

/******************************
 * LEUART0�жϷ��񣨽���/���ͣ�-GPS
 ******************************/
void LEUART0_IRQHandler(void)
{

	unsigned char rx_data;

	if(LEUART0->IF & LEUART_IF_TXC)//��������ж�
    {
		LEUART0->IFC = LEUART_IFC_TXC;//�巢������жϱ�־λ
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

	if((LEUART0->IF & LEUART_IF_RXDATAV))//���������ж�
	{
		//���жϱ�־�����ֶ������
		while (!(LEUART0->STATUS & LEUART_STATUS_RXDATAV))
		    ;
		rx_data = ((uint8_t)LEUART0->RXDATA);
		DrvGPS232Channel.recv_buffer[DrvGPS232Channel.recv_ptr ++] = rx_data;
		if(DrvGPS232Channel.recv_ptr >= sizeof(DrvGPS232Channel.recv_buffer)) DrvGPS232Channel.recv_ptr = 0;
	}
}


/******************************
 * UART0�жϷ��񣨷��ͣ�- GPRS
 ******************************/
void UART0_TX_IRQHandler(void)
{
	UART0->IFC = UART_IFC_TXC;//�巢������жϱ�־λ
	if(DrvGPRSRS232Channel.drv_send_len > 0)
	{
		--DrvGPRSRS232Channel.drv_send_len;
		USART_Tx(UART0, *(DrvGPRSRS232Channel.drv_send_data ++));
	}
}

/******************************
 * UART0�жϷ��񣨽��գ�- GPRS
 ******************************/
void UART0_RX_IRQHandler(void)
{
	unsigned char rx_data;
	//���жϱ�־�����ֶ������
	while (!(UART0->STATUS & LEUART_STATUS_RXDATAV))
	    ;
	rx_data = ((uint8_t)UART0->RXDATA);
	DrvGPRSRS232Channel.recv_buffer[DrvGPRSRS232Channel.recv_ptr ++] = rx_data;
	if(DrvGPRSRS232Channel.recv_ptr >= sizeof(DrvGPRSRS232Channel.recv_buffer)) DrvGPRSRS232Channel.recv_ptr = 0;
}
/********************************************************************************************************/

//GPIOż�ж�
void GPIO_EVEN_IRQHandler(void)
{
	static BaseType_t xHigherPriorityTaskWoken;

	    //2�����ж�
		if ((GPIO->IF) & 0x04)
		{
				//���־λ
				GPIO_IntClear(0x04);
			if (Radio_CheckReceived()==true)
			{
				//���յ�����Ч���������ź���
				//�ڻ㼯��Ԫ����LDCģʽ�ǣ��ܲ������жϵ�Ψһԭ������·�����˶�·/�ӵ�/�͵�������
				//��˸��������ź���
				tpos_give_sem_fromISR(Sem_Fault, xHigherPriorityTaskWoken);
			}

			/**/portYIELD_FROM_ISR( xHigherPriorityTaskWoken );  //��������һ���������
		}


}

