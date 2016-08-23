/*
 * app_task.c
 *
 *  Created on: 2016-7-12
 *      Author: Root-Wang
 */


#include "../../Header Files/app_plat/bsp.h"
extern void printadc(FP32 f);


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

		//		TIMER1->CMD = 0b01;//start timer1
		//		TIMER1->CMD = 0b10;//stop timer1

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

	    gSystemInfo.xu_bat =  (3.31/4096)*samples[0] *6;
	    gSystemInfo.cap_bat = (3.31/4096)*samples[1] *6 ;
	    gSystemInfo.sun_bat = (3.31/4096)*samples[2] *6 ;

	    printadc( gSystemInfo.xu_bat);
	    tpos_delay(50);
	    printadc( gSystemInfo.cap_bat);
	    tpos_delay(50);
	    printadc( gSystemInfo.sun_bat);
	    tpos_delay(50);

	    if((gSystemInfo.xu_bat < 13.4) && ( gSystemInfo.sun_bat >= 14.9) )
	    {
	    	TIMER1->CMD = 0b01;
	    }
	    else
	    {
	    	TIMER1->CMD = 0b10;
	    }


//	    TIMER0->CMD = TIMER_CMD_START;
//	    TIMER0->CMD = TIMER_CMD_STOP;

	    tpos_delay(50);//5000������,����ʱ�����ر�׼
	    //tpos_delay()��tpos_delayUntil():tpos_delay����ڵ�ǰ����tpos_delay��ʱ��Ϊ��㣬��ʱָ��ʱ�ӽ���
	    //tpos_delayUntil�൱�ھ�����ʱ����Ϊ��׼
	}
}



//================================================================================
// ���ϴ�������
//================================================================================
//�ȴ���·/�ӵع����ź���
  void Task_Fault_Handler (void *pvParameters)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
		//�ȴ������ź���

		 if( tpos_wait_sem( Sem_duanlu, ( TickType_t ) 10 ) == pdTRUE )
		 {
		            GPIO_PinOutSet(gpioPortE, 6);//�ɵ�ɶ�أ�
		 }

	    if( Sem_jiedi != NULL )
	  	{
	  		    if( tpos_wait_sem( Sem_jiedi, ( TickType_t ) 10 ) == pdTRUE )
	  		    {
	  		            //�ɵ�ɶ�أ�
	  		    }
	  		    else
	  		    {
	  		    }
	     }
	    if( Sem_lowbat != NULL )
	  	{
	    		if( tpos_wait_sem( Sem_lowbat, ( TickType_t ) 10 ) == pdTRUE )
	  		    {
	  		            //�ɵ�ɶ�أ�
	  		    }
	  		    else
	  		    {
	  		    }
	     }

	    tpos_delay(5000);
    }
}

 /*  �ж��﷢���ź�������
  void USART1_IRQHandler(void)
  {
      static BaseType_t xHigherPriorityTaskWoken;

              xSemaphoreGiveFromISR( xSemaphore, &xHigherPriorityTaskWoken );

      portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
  }
 */

//================================================================================
// ������������GPRS���ƣ�
//================================================================================
  void Task_Report(void *pvParameters)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();

	    tpos_delay(5000);
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

		tpos_delay(5000) ;

	}
}
