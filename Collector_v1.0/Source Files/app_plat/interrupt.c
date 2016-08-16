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
	    //15引脚中断
		case 0x8000:
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
			break;
		default:
			break;

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
void TIMER1_IRQHandler(void)
{
  uint32_t compareValue;

  TIMER_IntClear(TIMER1, TIMER_IF_OF);

 compareValue = (7000000/PWM_FREQ)*10/100; //占空比百分之五十

  TIMER_CompareBufSet(TIMER1, 0, compareValue);
}
