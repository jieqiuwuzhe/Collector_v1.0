/****************************************
 *  File:                  rf_spi.h
 *  Created on:    2016-7-16
 *  Author:            WANGJIANHUI
 ****************************************/
#ifndef   _RF_SPI_H
#define  _RF_SPI_H


#include "em_usart.h"
#include "em_gpio.h"
#include "em_cmu.h"



typedef enum
{
  eSpi_Nsel_RF,
} eSpi_Nsel;

void Spi_Init(void);
uint8_t Spi_ReadWrite(uint8_t data);
void Spi_WriteDataBurst(uint8_t cnt, uint8_t* data);
void Spi_ReadDataBurst(uint8_t cnt, uint8_t* data);
void Spi_ClearNsel(eSpi_Nsel qiSelect);
void Spi_SetNsel(eSpi_Nsel qiSelect);


#endif

