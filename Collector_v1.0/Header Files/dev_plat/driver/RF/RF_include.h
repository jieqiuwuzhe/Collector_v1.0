/*
 * RF_include.h
 *
 *  Created on: 2016-8-17
 *      Author: Root-Wang
 */

#ifndef RF_INCLUDE_H_
#define RF_INCLUDE_H_

/* 默认变量定义---------------------------------------------------------------*/
#ifndef NULL
#define NULL    				((void *)0)
#endif

#ifndef TRUE
#define TRUE  					1
#endif

#ifndef FALSE
#define FALSE 					0
#endif

#define BOOL  					uint8_t

/*变量类型声明-------------------------------------------------------------*/
/*CPU 无关，在已知数据存储格式的条件下（如通信归约中的遥测读写）可以生成CPU无关代码*/
#define BYTE    				uint8_t
#define WORD    				uint16_t
#define DWORD   				uint32_t

#define LOBYTE(w)               ((BYTE)(w))
#define HIBYTE(w)               ((BYTE)((WORD)(w) >> 8))
#define LOWORD(l)               ((WORD)(l))
#define HIWORD(l)               ((WORD)((DWORD)(l) >> 16))
#define MAKEDWORD(low,high)     ((DWORD)(((WORD)(low)) | (((DWORD)((WORD)(high))) << 16)))
#define MAKEWORD(low, high)     ((WORD)(((BYTE)(low)) | (((WORD)((BYTE)(high))) << 8)))
#define LLBYTE(w)               ((BYTE)(w))
#define LHBYTE(w)               ((BYTE)((WORD)(w) >> 8))
#define HLBYTE(w)               ((BYTE)((DWORD)(w) >> 16))
#define HHBYTE(w)               ((BYTE)((DWORD)(w) >>24))

#define ADJUSTWORD(x)           (MAKEWORD(HIBYTE(x),LOBYTE(x)))
#define ADJUSTDWORD(x)          (MAKEDWORD(ADJUSTWORD(HIWORD(x)),ADJUSTWORD(LOWORD(x))))

#ifdef  BIG_ENDIAN
#define GETWORD(x)          	(ADJUSTWORD(*(unsigned short*)(x)))
#else
#define GETWORD(x)          	(*(unsigned short*)(x))
#endif

#ifdef  BIG_ENDIAN
#define GETDWORD(x)         	(ADJUSTDWORD(*(unsigned long*)(x)))
#else
#define GETDWORD(x)         	(*(unsigned long*)(x))
#endif


/*包含头文件*/
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_adc.h"
#include "em_cmu.h"
#include "em_cryotimer.h"
#include "em_dma.h"
#include "em_ldma.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_i2c.h"
#include "em_letimer.h"
#include "em_leuart.h"
#include "em_msc.h"
#include "em_timer.h"
#include "em_usart.h"
#include "em_wdog.h"
#include "em_int.h"
//RF
#include "rf_config.h"
#include "radio_config.h"
#include "si446x_defs.h"
#include "si446x_api_lib.h"
#include "si446x_nirq.h"
#include "si446x_patch.h"
#include "rf_spi.h"
#include "radio_hal.h"
//normal
#include "DATABASE.h"
#include "MID.h"
#include "APP.h"
#include "PARA.h"
#include "PROTO.h"






#endif /* RF_INCLUDE_H_ */
