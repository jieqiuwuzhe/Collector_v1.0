/*
 * app_task.c
 *
 *  Created on: 2016-7-12
 *      Author: Root-Wang
 */

#include "../../Header Files/app_plat/bsp.h"

extern void printadc(FP32 f);//������


//================================================================================
// ADC��ѹ�������
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
	                      NUM_SAMPLES - 1);//��ADC scan������������ݵ�samples������

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

	    //������������������samples[0]��[1]��[2]��
	    //����SUN��CAP��BAT��ѹֵ
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


//	    tpos_yield();//5000������,����ʱ�����ر�׼
	    //tpos_delay()��tpos_delayUntil():tpos_delay����ڵ�ǰ����tpos_delay��ʱ��Ϊ��㣬��ʱָ��ʱ�ӽ���
	    //tpos_delayUntil�൱�ھ�����ʱ����Ϊ��׼
	}
}



//================================================================================
// ���ϴ�������
//================================================================================
//�ȴ���·/�ӵ�/�����͹����ź���
  void Task_Fault_Handler (void *pvParameters)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
		//�ȴ������ź���

		 if( tpos_wait_sem( Sem_Fault, ( TickType_t ) 10 ) == pdTRUE )
		 {
			 APP_RecMIDData(); //��ȡMID�㻺�����ݣ��������Ļ������RFbuf.pRxBufRead��
		 }
    }
}


//================================================================================
// ������������GPRS���ƣ�
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
// �����Է�������(��������)
//================================================================================
//�ɼ���Ԫ���������ɼ���Ԫ��Դ��Ϣ���������ɵ���/��ѹ��
 void Task_Cycle_Service(void *pvParameters)
{

	/* Stay in this loop forever */
	while(1)
	{
     	ClrTaskWdt();

		if((gSystemInfo.ss_tick) >= 43200)//
		{
			gSystemInfo.ss_tick = 0;
			//����GPS��ʱ(�Ƿ���Ҫ�ر�������ȣ�)

		}

		//15�����ٲ�һ��
		if(gSystemInfo.call_15min == 1 )//
		{
			//����ϢҪ����

			//������ɺ��־λ����
			gSystemInfo.call_15min = 0;
		}


	}
}

 //LED��ת������������
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

