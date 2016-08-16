/*
 * gpio.c
 *
 *  Created on: 2016-8-3
 *      Author: Root-Wang
 */

#include "../../../../Header Files/app_plat/bsp.h"

//GPRS开关
void pin_ctrl_gprs_onoff(uint8_t pin_level)
{
     //相应引脚设为输出

	 if(pin_level == PIN_HIGH)
     {
         //打开GPRS电源
     }
     else
     {
         //关闭GPRS电源
     }
}

//GPS开关
void pin_ctrl_gprs_ctrl(uint8_t pin_level)
{
     //相应引脚设为输出

	 if(pin_level == PIN_HIGH)
     {
         //打开GPRS电源
     }
     else
     {
         //关闭GPRS电源
     }
}
