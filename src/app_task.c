/*
 * app_task.c
 *
 *  Created on: 2016-7-12
 *      Author: Root-Wang
 */


#include "../inc/bsp.h"


//================================================================================
// ADC��ѹ�������
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
	    for (i = 0; i < NUM_SAMPLES; i++)
	    {
	    	samples[i] = (3.31/4096)*(samples[i]);
	    }
	    //sample[0]-CH4 sample[1]-CH5 sample[2]-CH6


	    tpos_delay(5000);//5000������,����ʱ�����ر�׼
	    //tpos_delay()��tpos_delayUntil():tpos_delay����ڵ�ǰ����tpos_delay��ʱ��Ϊ��㣬��ʱָ��ʱ�ӽ���
	    //tpos_delayUntil�൱�ھ�����ʱ����Ϊ��׼
	}
}


//================================================================================
// ���ϴ�������
//================================================================================
//�ȴ���·/�ӵع����ź���
extern void Task_Fault_Handler(void)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
		//�ȴ������ź���
	    tpos_delay(5000);
	}
}


//================================================================================
// ������������GPRS���ƣ�
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
// �����Է�������(��������)
//================================================================================
//�ɼ���Ԫ���������ɼ���Ԫ��Դ��Ϣ���������ɵ���/��ѹ��
extern void Task_Cycle_Service(void)
{
	/* Stay in this loop forever */
	while (1)
	{
		ClrTaskWdt();
	    tpos_delay(5000);
	}
}
