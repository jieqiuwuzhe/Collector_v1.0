/*
 * app_task.c
 *
 *  Created on: 2016-7-12
 *      Author: Root-Wang
 */

#include "../../Header Files/app_plat/bsp.h"

extern void printadc(FP32 f);//调试用


//================================================================================
// ADC电压监测任务
//================================================================================
 void Task_Power_Ctrl (void *pvParameters)
{
	uint32_t samples[NUM_SAMPLES];
	int      i;

    SYSTEM_ChipRevision_TypeDef chipRev;
	int errataShift = 0;

	/* ADC errata for rev B when using VDD as reference, need to multiply */
	/* result by 2 */
	SYSTEM_ChipRevisionGet(&chipRev);
	if ((chipRev.major == 1) && (chipRev.minor == 1))
	{
	  errataShift = 1;
	}


	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();

		TIMER1->CMD = 0b10;
		delay(150);

		DMA_ActivateBasic(DMA_CHANNEL,
	                      true,
	                      false,
	                      samples,
	                      (void *)((uint32_t) &(ADC0->SCANDATA)),
	                      NUM_SAMPLES - 1);//把ADC scan的三个结果传递到samples变量中

	    /* Start Scan */
	    ADC_Start(ADC0, adcStartScan);

	    /* Poll for scan conversion complete */
	    while (ADC0->STATUS & ADC_STATUS_SCANACT);

	    if (errataShift)
	    {
	      for (i = 0; i < NUM_SAMPLES; i++)
	      {
	        samples[i] <<= errataShift;
	      }
	    }

	    //采样后的三个结果存在samples[0]、[1]、[2]中
	    //计算SUN、CAP、BAT电压值
	    //sample[0]-CH4 sample[1]-CH5 sample[2]-CH6

	    gSystemInfo.cap_bat =  (3.31/4096)*samples[0] *6;
	    gSystemInfo.xu_bat = (3.31/4096)*samples[1] *6 ;
	    gSystemInfo.sun_bat = (3.31/4096)*samples[2] *6 ;


	    printadc( gSystemInfo.cap_bat);
	    	    delay(50);
	    printadc( gSystemInfo.xu_bat);
	    	    delay(50);
	    printadc( gSystemInfo.sun_bat);
	    	    delay(50);

//	    if((gSystemInfo.xu_bat < 13.4) && ( gSystemInfo.sun_bat >= 14.9) )
//	    {
//	    tpos_enterCriticalSection();
	    	TIMER1->CMD = 0b01;
	    	delay(1500);//3s
//	    TIMER1_enter_DefaultMode_from_RESET();
//	    tpos_leaveCriticalSection();

//	    	tpos_delay(500);
//	    }
//	    else
//	    {
//	    	TIMER1->CMD = 0b10;
//	    }


//	    tpos_yield();//5000个节拍,该延时无需特别精准
	    //tpos_delay()和tpos_delayUntil():tpos_delay相对于当前调用tpos_delay的时刻为零点，延时指定时钟节拍
	    //tpos_delayUntil相当于绝对延时，较为精准
	}
}



//================================================================================
// 故障处理任务
//================================================================================
//等待短路/接地/电量低故障信号量
  void Task_Fault_Handler (void *pvParameters)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
		//等待故障信号量

		 if( tpos_wait_sem( Sem_Fault, ( TickType_t ) 10 ) == pdTRUE )
		 {
			 APP_RecMIDData(); //读取MID层缓存数据，读出来的缓存放在RFbuf.pRxBufRead中
		 }
    }
}


//================================================================================
// 数据上送任务（GPRS控制）
//================================================================================
  void Task_Report(void *pvParameters)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();

	}
}

//================================================================================
// 周期性服务任务(待机任务)
//================================================================================
//采集单元心跳包、采集单元电源信息、正常负荷电流/电压、
 void Task_Cycle_Service(void *pvParameters)
{

	/* Stay in this loop forever */
	while(1)
	{
     	ClrTaskWdt();

		if((gSystemInfo.ss_tick) >= 43200)//
		{
			gSystemInfo.ss_tick = 0;
			//进行GPS对时(是否需要关闭任务调度？)

		}

		//15分钟召测一次
		if(gSystemInfo.call_15min == 1 )//
		{
			//发信息要数据

			//发送完成后标志位清零
			gSystemInfo.call_15min = 0;
		}


	}
}

 //LED翻转函数，调试用
 void led_toggle()
 {
	 if(GPIO_PinOutGet(gpioPortD,8 ) == 1)
	 {
	 	 GPIO_PinOutClear(gpioPortD,8);
	 }
	 	 else
	 	 {
	 		 GPIO_PinOutSet(gpioPortD,8);
	 	 }
}

