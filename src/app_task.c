/*
 * app_task.c
 *
 *  Created on: 2016-7-12
 *      Author: Root-Wang
 */


#include "../inc/bsp.h"


//================================================================================
// ADC电压监测任务
//================================================================================
extern void Task_Power_Ctrl(void)
{
    SYSTEM_ChipRevision_TypeDef chipRev;
	int errataShift = 0;

	/* ADC errata for rev B when using VDD as reference, need to multiply */
	/* result by 2 */
	SYSTEM_ChipRevisionGet(&chipRev);
	if ((chipRev.major == 1) && (chipRev.minor == 1))
	{
	  errataShift = 1;
	}
	uint32_t samples[NUM_SAMPLES];
	int      i;

	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
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
	    for (i = 0; i < NUM_SAMPLES; i++)
	    {
	    	samples[i] = (3.31/4096)*(samples[i]);
	    }
	    //sample[0]-CH4 sample[1]-CH5 sample[2]-CH6


	    tpos_delay(5000);//5000个节拍,该延时无需特别精准
	    //tpos_delay()和tpos_delayUntil():tpos_delay相对于当前调用tpos_delay的时刻为零点，延时指定时钟节拍
	    //tpos_delayUntil相当于绝对延时，较为精准
	}
}


//================================================================================
// 故障处理任务
//================================================================================
//等待短路/接地故障信号量
extern void Task_Fault_Handler(void)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
		//等待故障信号量
	    tpos_delay(5000);
	}
}


//================================================================================
// 数据上送任务（GPRS控制）
//================================================================================
extern void Task_Report(void)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
	    tpos_delay(5000);
	}
}

//================================================================================
// 周期性服务任务(待机任务)
//================================================================================
//采集单元心跳包、采集单元电源信息、正常负荷电流/电压、
extern void Task_Cycle_Service(void)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
	    tpos_delay(5000);
	}
}
