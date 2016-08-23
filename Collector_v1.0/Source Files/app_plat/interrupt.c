/*
 * interrupt.c
 *
 *  Created on: 2016-8-8
 *      Author: Root-Wang
 */

#include "em_gpio.h"
#include "../../../Header Files/app_plat/bsp.h"

void GPIO_ODD_IRQHandler(void)
{
	/**/static BaseType_t xHigherPriorityTaskWoken;

	switch (GPIO->IF)
	{
	    //15�����ж�
		case 0x8000:
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
			break;
		default:
			break;

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
void TIMER1_IRQHandler(void)
{
  uint32_t compareValue;

  TIMER_IntClear(TIMER1, TIMER_IF_OF);

 compareValue = (7000000/PWM_FREQ)*10/100; //ռ�ձȰٷ�֮��ʮ

  TIMER_CompareBufSet(TIMER1, 0, compareValue);
}
