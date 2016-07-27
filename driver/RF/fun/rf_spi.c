/****************************************
 *  File:                  rf_spi.c
 *  Created on:    2016-7-16
 *  Author:            WANGJIANHUI
 ****************************************/
#include "rf_spi.h"


void Spi_Init(void)
{
	USART_Reset(USART1);

	CMU_ClockEnable(cmuClock_USART1, true);

	USART_InitSync_TypeDef spiinit = USART_INITSYNC_DEFAULT;
	spiinit.baudrate     = 1000000;
	spiinit.msbf=1;

	USART_InitSync(USART1, &spiinit);

	GPIO_PinModeSet(SPI_MOSI_PORT, SPI_MOSI_PIN, gpioModePushPull, 1);
	GPIO_PinModeSet(SPI_MISO_PORT, SPI_MISO_PIN, gpioModeInput, 0);
	GPIO_PinModeSet(SPI_CLK_PORT, SPI_CLK_PIN, gpioModePushPull, 1);
	GPIO_PinModeSet(SPI_CS_PORT, SPI_CS_PIN, gpioModePushPull, 1);
	GPIO_PinModeSet(RF_SDN_PORT, RF_SDN_PIN, gpioModePushPull, 0);
	GPIO_PinModeSet(RF_nIRQ_PORT, RF_nIRQ_PIN, gpioModeInput, 0);

	 USART1->ROUTE |= USART_ROUTE_CLKPEN | USART_ROUTE_TXPEN | USART_ROUTE_RXPEN | USART_ROUTE_LOCATION_LOC1;
}

uint8_t Spi_ReadWrite(uint8_t data)
{
	while (!(USART1->STATUS & USART_STATUS_TXBL));
	USART1->TXDATA = (uint32_t)data;

	while (!(USART1->STATUS & USART_STATUS_TXC));
	return (uint8_t)(USART1->RXDATA);
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

