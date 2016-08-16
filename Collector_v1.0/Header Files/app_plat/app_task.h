/*
 * app_task.h
 *
 *  Created on: 2016-7-12
 *      Author: Root-Wang
 */

#ifndef APP_TASK_H_
#define APP_TASK_H_

extern void Task_Power_Ctrl(void *pvParameters);
extern void Task_Fault_Handler(void *pvParameters);
extern void Task_Report(void *pvParameters);
extern void Task_Cycle_Service(void *pvParameters);

#endif /* APP_TASK_H_ */
