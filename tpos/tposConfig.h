/*

 */

#ifndef TPOSCONFIG_H
#define TPOSCONFIG_H

#include "em_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************** Configuration of TPOS ****************************/

/* Implement TPOS configASSERT as emlib assert */
#define configASSERT( x )       EFM_ASSERT( x )

/* ����Ϊ0ȡ�����ȼ�������ʱ��Ƭ��ѯ*/
#define configUSE_PREEMPTION       ( 0 )

/* Energy saving modes */
#define configUSE_TICKLESS_IDLE    ( 1 )
/* Available options when configUSE_TICKLESS_IDLE set to 1
 * or configUSE_SLEEP_MODE_IN_IDLE set to 1 :
 * 1 - EM1, 2 - EM2, 3 - EM3 is not available on this CPU, because
 * timer doesn't work in EM3 mode */
#define configSLEEP_MODE           ( 2 )
/* Definition used only if configUSE_TICKLESS_IDLE == 0 */
#define configUSE_SLEEP_MODE_IN_IDLE       ( 1 )


/* EM1 use systick as system clock*/
/* EM2 use crystal 32768Hz and RTC Component as system clock
 * We use 2 times divider of this clock to reduce energy consumtion
 * You can also in this mode choose crystal oscillator to get more preccision in
 * time measurement or RC oscillator for more energy reduction.*/
/* EM3 use 2kHz RC and BURTC Component as system clock*/
#if ( ( configSLEEP_MODE == 2 ) && ( configUSE_TICKLESS_IDLE == 1 || configUSE_SLEEP_MODE_IN_IDLE == 1 ) )
/* Choose source of clock for RTC (system tick)
 * if configCRYSTAL_IN_EM2 set to 1 then Crystal oscillator is used,
 * when 0 RC oscillator */
#define configCRYSTAL_IN_EM2    ( 1 )
#endif
#if (  (configSLEEP_MODE == 2 ) && ( configUSE_TICKLESS_IDLE == 1 || configUSE_SLEEP_MODE_IN_IDLE == 1 ) )
/* ʹ��EM2��EM3ģʽʱ,ϵͳʱ��Ƶ�ʽϵ�
 * ���Խ��δ����ʽ�����128HZ��40HZ���ڵδ�֮�����ø����ʱ������*/
#define configTICK_RATE_HZ    ( 128 )
#elif (  ( configSLEEP_MODE == 3 ) && ( configUSE_TICKLESS_IDLE == 1 || configUSE_SLEEP_MODE_IN_IDLE == 1 ) )
#define configTICK_RATE_HZ    ( 40 )
#else
#define configTICK_RATE_HZ    ( 1000 )
#endif

/* Definition used by Keil to replace default system clock source when we use EM2 or EM3 mode. */
#if ( ( configSLEEP_MODE == 2 || configSLEEP_MODE == 3 ) && ( configUSE_TICKLESS_IDLE == 1 || configUSE_SLEEP_MODE_IN_IDLE == 1 ) )
#define configOVERRIDE_DEFAULT_TICK_CONFIGURATION ( 1 )
#endif

/* Main functions*/

#define configMAX_PRIORITIES                      ( 2 )//���ȼ���Ŀ������Խ��RAM����Խ��
#define configMINIMAL_STACK_SIZE                  (( unsigned short ) 140)//ϵͳ��С��ջ��140����ջ��32λEFMΪ560�ֽ�
#define configTOTAL_HEAP_SIZE                     (( size_t )(9000))//ϵͳ�����ڴ棬һ����ɳ�����ϵͳ���û���������RAM֮������RAM
#define configMAX_TASK_NAME_LEN                   ( 10 )//����������󳤶�
#define configUSE_TRACE_FACILITY                  ( 0 )
#define configUSE_16_BIT_TICKS                    ( 0 )
#define configIDLE_SHOULD_YIELD                   ( 0 )
#define configUSE_MUTEXES                         ( 1 )
#define configUSE_RECURSIVE_MUTEXES               ( 0 )
#define configUSE_COUNTING_SEMAPHORES             ( 0 )
#define configUSE_ALTERNATIVE_API                 ( 0 )/* Deprecated! */
#define configQUEUE_REGISTRY_SIZE                 ( 10 )
#define configUSE_QUEUE_SETS                      ( 0 )

/* Hook function related definitions. */

#define configUSE_TICK_HOOK                       ( 0 )
#define configCHECK_FOR_STACK_OVERFLOW            ( 0 )
#define configUSE_MALLOC_FAILED_HOOK              ( 0 )

/* Run time stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS             ( 0 )

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES                     ( 0 )
#define configMAX_CO_ROUTINE_PRIORITIES           ( 1 )

/* Software timer related definitions. */
#define configUSE_TIMERS                          ( 1 )
#define configTIMER_TASK_PRIORITY                 ( configMAX_PRIORITIES - 1 ) /* Highest priority */
#define configTIMER_QUEUE_LENGTH                  ( 10 )
#define configTIMER_TASK_STACK_DEPTH              ( configMINIMAL_STACK_SIZE )

/* Interrupt nesting behaviour configuration. */
#define configKERNEL_INTERRUPT_PRIORITY           ( 255 )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY      ( 191 ) /* equivalent to 0xa0, or priority 5. */

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                  ( 1 )//���Ըı��������ȶ�
#define INCLUDE_uxTaskPriorityGet                 ( 1 )//���Բ�ѯ�������ȶ�
#define INCLUDE_vTaskDelete                       ( 1 )//����ɾ������
#define INCLUDE_vTaskSuspend                      ( 1 )
#define INCLUDE_xResumeFromISR                    ( 1 )
#define INCLUDE_tpos_delayUntil                   ( 1 )
#define INCLUDE_vTaskDelay                        ( 1 )
#define INCLUDE_xTaskGetSchedulerState            ( 1 )
#define INCLUDE_xTaskGetCurrentTaskHandle         ( 1 )
#define INCLUDE_uxTaskGetStackHighWaterMark       ( 0 )
#define INCLUDE_xTaskGetIdleTaskHandle            ( 0 )
#define INCLUDE_xTimerGetTimerDaemonTaskHandle    ( 0 )
#define INCLUDE_pcTaskGetTaskName                 ( 0 )
#define INCLUDE_eTaskGetState                     ( 0 )

/* ϵͳCPUƵ��14MHz*/
#define configCPU_CLOCK_HZ                        (( unsigned long ) 14000000)

/* Defines used in energy modes */
#if ( ( configSLEEP_MODE == 2 )  && ( ( configUSE_SLEEP_MODE_IN_IDLE == 1 ) || ( configUSE_TICKLESS_IDLE == 1 ) ) )
        #define configSYSTICK_CLOCK_HZ    ( 16384 )
#endif

#if ( ( configSLEEP_MODE == 3 )  && ( ( configUSE_SLEEP_MODE_IN_IDLE == 1 ) || ( configUSE_TICKLESS_IDLE == 1 ) ) )
       #define configSYSTICK_CLOCK_HZ    ( 2000 )
#endif

#if ( ( configUSE_TICKLESS_IDLE == 0 ) && ( configUSE_SLEEP_MODE_IN_IDLE == 1 ) )
//IDLE�����HOOK����������OS������չ����Ҫ�Լ�����Ӧ����������Ϊvoid vApplicationIdleHook(void)
#define configUSE_IDLE_HOOK  ( 1 )
#else
#define configUSE_IDLE_HOOK  ( 0 )
#endif

/*-----------------------------------------------------------*/


/* Definitions that map the TPOS port interrupt handlers to their CMSIS
 * standard names. */
#define vPortSVCHandler        SVC_Handler
#define xPortPendSVHandler     PendSV_Handler
#define xPortSysTickHandler    SysTick_Handler


#ifdef __cplusplus
}
#endif
#endif /* TPOSCONFIG_H */

