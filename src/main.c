/******************************************************************************
 * Topscomm故障指示器汇集单元主程序
 ******************************************************************************
 * Author: Root
 ******************************************************************************/

#include "../inc/bsp.h"

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
  /* Chip init */
  CHIP_Init();
  enter_DefaultMode_from_RESET();//全部外设的初始化

//==========================================================================//
  /* Initialize SLEEP driver, no calbacks are used */
  SLEEP_Init(NULL, NULL);
#if (configSLEEP_MODE < 3)
  /* do not let to sleep deeper than define */
  SLEEP_SleepBlockBegin((SLEEP_EnergyMode_t)(configSLEEP_MODE+1));
#endif
//==========================================================================//

  /*Create four tasks for collector*/
  tpos_createTask( Task_Power_Ctrl, 	(const char *) "PowerCtrl",    STACK_SIZE_FOR_TASK, NULL, TPOS_TASKPROPERTY_USER, NULL);
  tpos_createTask( Task_Fault_Handler, 	(const char *) "Fault_Handler",STACK_SIZE_FOR_TASK, NULL, TPOS_TASKPROPERTY_USER, NULL);
  tpos_createTask( Task_Report, 		(const char *) "Report", 	   STACK_SIZE_FOR_TASK, NULL, TPOS_TASKPROPERTY_USER, NULL);
  tpos_createTask( Task_Cycle_Service,  (const char *) "CycleService", STACK_SIZE_FOR_TASK, NULL, TPOS_TASKPROPERTY_USER, NULL);

  /*Start TPOS Scheduler*/
  tpos_start();

  return 0;
}
