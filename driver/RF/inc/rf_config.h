/****************************************
 *  File:                  rf_config.h
 *  Created on:    2016-7-16
 *  Author:            WANGJIANHUI
 ****************************************/
#ifndef  _RF_CONFIG_H
#define  _RF_CONFIG_H


#define SILABS_RADIO_SI446X
#undef  SILABS_RADIO_SI4455

#define RADIO_DRIVER_EXTENDED_SUPPORT
#define RADIO_DRIVER_FULL_SUPPORT

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "rf_spi.h"
#include "radio_config.h"
#include "radio_hal.h"
#include "si446x_defs.h"
#include "si446x_api_lib.h"
#include "si446x_nirq.h"
#include "si446x_patch.h"


#endif

