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


#define SPI_CS_PORT       gpioPortB
#define SPI_CLK_PORT      gpioPortB
#define SPI_MOSI_PORT     gpioPortB
#define SPI_MISO_PORT     gpioPortB

#define RF_SDN_PORT       gpioPortC
#define RF_nIRQ_PORT      gpioPortC

#define RF_GPIO0_PORT     gpioPortC
#define RF_GPIO1_PORT     gpioPortC
#define RF_GPIO2_PORT     gpioPortC
#define RF_GPIO3_PORT     gpioPortC

#define SPI_CS_PIN        6
#define SPI_CLK_PIN       5
#define SPI_MOSI_PIN      3
#define SPI_MISO_PIN      4

#define RF_SDN_PIN        0
#define RF_nIRQ_PIN       1

#define RF_GPIO0_PIN      2
#define RF_GPIO1_PIN      3
#define RF_GPIO2_PIN      4
#define RF_GPIO3_PIN      5

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

