/*
 * bsp.h
 *
 *  Created on: 2016-7-11
 *      Author: Root-Wang
 */

#ifndef BSP_H_
#define BSP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "tposConfig.h"
#include "tpos.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "croutine.h"
#include "sleep.h"

#include "em_chip.h"
#include "em_timer.h"
#include "em_cmu.h"
#include "em_system.h"
#include "em_emu.h"
#include "em_device.h"
#include "em_adc.h"
#include "em_dma.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "em_letimer.h"
#include "em_leuart.h"
#include "em_rtc.h"
#include "em_usart.h"
#include "em_wdog.h"
#include "em_int.h"
#include "dmactrl.h"

#include "InitDevice.h"
#include "app_task.h"
#include "flash_fun.h"


//======================================================
// PreDefine
//======================================================
#define STACK_SIZE_FOR_TASK    			(configMINIMAL_STACK_SIZE + 10)
#define TPOS_TASKPROPERTY_USER          (TPOS_TASKPROPERTY_SYS + 1)

#define DMA_CHANNEL    0	//DMA通道0
#define NUM_SAMPLES    3	//采样数3

#define PWM_FREQ 	   4000





#endif /* BSP_H_ */
