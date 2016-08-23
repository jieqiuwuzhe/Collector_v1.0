/******************************************************************************
 * Topscomm����ָʾ���㼯��Ԫ������
 ******************************************************************************
 * Author: Root
 ******************************************************************************/

#include "../../Header Files/app_plat/bsp.h"

//�˴�����ͬ�����ʺ�ʹ�ö�ֵ�ź���
SemaphoreHandle_t  Sem_duanlu; //��·�����ź���
SemaphoreHandle_t  Sem_jiedi;      //�ӵع����ź���
SemaphoreHandle_t  Sem_lowbat; //�ɼ���Ԫ��ѹ���ź���
SemaphoreHandle_t  Sem_Fault; //�ɼ���Ԫ��ѹ���ź���

int i;
/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/

/*************�����ú���******************/

//ADC���ڴ�ӡ����
void printadc(FP32 f)
{
	unsigned char s[20];

	Float2Char(f,s);


	 for(uint8_t i=0;i<20;i++)
	 {
	    	USART_Tx(UART0,s[i]);
	 }
}

void UART0_send_32(uint32_t txBuffer)
{
	uint8_t temp[2];
	temp[0]=(uint8_t)(((uint32_t)txBuffer>>24)&0xff);
    temp[1]=(uint8_t)(((uint32_t)txBuffer>>16)&0xff);
    temp[2]=(uint8_t)(((uint32_t)txBuffer>>8)&0xff);
    temp[3]=(uint8_t)(((uint32_t)txBuffer>>0)&0xff);
    for(uint8_t i=0;i<4;i++)
    {
    	USART_Tx(UART0,temp[i]);
    }
}

static void Task_LED(void *pvParameters)
{
//	uint32_t j = *(uint32_t *)(0x4001041C);
	for(;;)
	{
     	ClrTaskWdt();
     	//    	 __disable_irq();
     	delay(50);
     	led_toggle();

     	 i = 100000;
     	delay(50);
     	led_toggle();
	}
}


/******************************************/

int main(void)
{
  /* Chip init */
  CHIP_Init();
  enter_DefaultMode_from_RESET();//ȫ������ĳ�ʼ��

  GPIO_PinModeSet(gpioPortD, 8, gpioModePushPull, 1); //����LED
  GPIO_PinModeSet(gpioPortE, 6, gpioModePushPull, 0); //���ص��Կ�PE6
  GPIO_PinModeSet(gpioPortE, 7, gpioModePushPull, 0); //���ص��Կ�PE7
  GPIO_PinModeSet(gpioPortC, 14, gpioModePushPull, 1); //GPRS��������

  SystemCoreClockUpdate();
  NVIC_EnableIRQ( SysTick_IRQn );

//==========================================================================//
  /* Initialize SLEEP driver, no calbacks are used */
  SLEEP_Init ( NULL, NULL );
#if (configSLEEP_MODE < 3)
  /* do not let to sleep deeper than define */
  SLEEP_SleepBlockBegin((SLEEP_EnergyMode_t)(configSLEEP_MODE+1));
#endif
//==========================================================================//

  //Create Semaphores
  Sem_duanlu = tpos_Create_Sem_Binary();
  Sem_jiedi      = tpos_Create_Sem_Binary();
  Sem_lowbat = tpos_Create_Sem_Binary();
  Sem_Fault    = tpos_Create_Sem_Binary();


//  drv_R8025T_init();//�ⲿRTC��ʼ��
//  MX25L256_FLASH_INIT();//Flash��ʼ��
  Init_RF_APP();//RF��ʼ��

  /*Create four tasks for collector*/
  tpos_createTask( Task_Power_Ctrl, 		      (const char *) "PowerCtrl",    		    STACK_SIZE_FOR_TASK, NULL,     TPOS_TASKPROPERTY_USER, NULL);
  tpos_createTask( Task_Fault_Handler,      (const char *) "Fault_Handler",      STACK_SIZE_FOR_TASK, NULL,     TPOS_TASKPROPERTY_USER, NULL);
  tpos_createTask( Task_Report, 				  (const char *) "Report", 	  		        STACK_SIZE_FOR_TASK, NULL,     TPOS_TASKPROPERTY_USER, NULL);
  tpos_createTask( Task_Cycle_Service,       (const char *) "CycleService", 	    STACK_SIZE_FOR_TASK, NULL,     TPOS_TASKPROPERTY_USER, NULL);
  tpos_createTask( Task_LED,                       (const char *) "CycleService", 	    STACK_SIZE_FOR_TASK, NULL,     TPOS_TASKPROPERTY_USER, NULL);


  /*Start TPOS Scheduler*/
  tpos_start();

  while(1);

  return 0 ;
}
