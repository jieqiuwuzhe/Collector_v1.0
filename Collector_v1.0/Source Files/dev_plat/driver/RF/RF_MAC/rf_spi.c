/****************************************
 *  File:                  rf_spi.c
 *  Created on:    2016-7-16
 *  Author:            WANGJIANHUI
 ****************************************/
#include "rf_spi.h"
#include "InitDevice.h"


void Spi_Init(void)
{
//在外设初始化函数中已完成
}

//uint8_t Spi_ReadWrite(uint8_t data)
//{
//	while (!(USART1->STATUS & USART_STATUS_TXBL));
//	USART1->TXDATA = (uint32_t)data;
//
//	while (!(USART1->STATUS & USART_STATUS_TXC));
//	return (uint8_t)(USART1->RXDATA);
//}

uint8_t Spi_ReadWrite(uint8_t data)
{
  USART2->TXDATA = data;
  while (!(USART2->STATUS & USART_STATUS_TXC));
  return (uint8_t)(USART2->RXDATA);
}


void Spi_WriteDataBurst(uint8_t cnt, uint8_t *data)
{
	while (cnt--)
	{
		Spi_ReadWrite(*data++);
	}
}

void Spi_ReadDataBurst(uint8_t cnt, uint8_t* data)
{
	while (cnt--)
	{
		*data++ = Spi_ReadWrite(0xFF);
	}
}

void Spi_ClearNsel(eSpi_Nsel qiSelect)
{
	switch (qiSelect)
	{
		case eSpi_Nsel_RF:
			GPIO_PinOutClear(SPI_CS_PORT, SPI_CS_PIN);
			break;
		default:
			break;
	}
}

void Spi_SetNsel(eSpi_Nsel qiSelect)
{
	switch (qiSelect)
	{
		case eSpi_Nsel_RF:
			GPIO_PinOutSet(SPI_CS_PORT, SPI_CS_PIN);
			break;
		default:
			break;
	}
}

