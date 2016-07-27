/****************************************
 *  File:                  radio_hal.c
 *  Created on:    2016-7-16
 *  Author:            WANGJIANHUI
 ****************************************/
#include "rf_config.h"


uint8_t ctsWentHigh = 0;

uint8_t Radio_Configuration_Data_Array[] = RADIO_CONFIGURATION_DATA_ARRAY;

tRadioConfiguration RadioConfiguration = RADIO_CONFIGURATION_DATA;

tRadioConfiguration *pRadioConfiguration = &RadioConfiguration;

uint8_t fixRadioPacket[RADIO_MAX_PACKET_LENGTH];

/*****************************************************************************!
 *  Power up the Radio.
 *  @note
 *****************************************************************************/
void Radio_PowerUp(void)
{
	uint16_t wDelay = 0u;

	/* Hardware reset the chip */
	si446x_reset();

	/* Wait until reset timeout or Reset IT signal */
	for (; wDelay < pRadioConfiguration->Radio_Delay_Cnt_After_Reset; wDelay++);
}

/*****************************************************************************!
 *  Radio Initialization.
 *  @author Sz. Papp
 *  @note
 *****************************************************************************/
void Radio_Init(void)
{
	Radio_PowerUp();

	while (SI446X_SUCCESS != si446x_configuration_init(pRadioConfiguration->Radio_ConfigurationArray))
	{
		for(uint16_t i=0;i<10000;i++);
		Radio_PowerUp();
	}
	si446x_get_int_status(0u, 0u, 0u);
}

/*****************************************************************************!
 *  Check if Packet sent IT flag is pending.
 *  @return   TRUE / FALSE
 *  @note
 *****************************************************************************/
uint8_t Radio_CheckTransmitted(void)
{
	if (radio_hal_NirqLevel() == false)
	{
		si446x_get_int_status(0u, 0u, 0u);

		if (Si446xCmd.GET_INT_STATUS.PH_PEND & SI446X_CMD_GET_INT_STATUS_REP_PACKET_SENT_PEND_BIT)
		{
			return true;
		}
	}
	return false;
}

/*****************************************************************************!
 *  Set Radio to TX mode, fixed packet length.
 *  @param channel Freq. Channel, Packet to be sent
 *  @note
 *****************************************************************************/
void  Radio_StartTx(uint8_t *pioFixRadioPacket,uint8_t cnt)
{
	uint8_t channel=pRadioConfiguration->Radio_ChannelNumber;
	/* Reset TX FIFO */
	si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_TX_BIT);

	// Read ITs, clear pending ones
	si446x_get_int_status(0u, 0u, 0u);

	/* Fill the TX fifo with datas */
	//si446x_write_tx_fifo(RadioConfiguration.Radio_PacketLength, pioFixRadioPacket);
	si446x_write_tx_fifo(cnt, pioFixRadioPacket);

	/* Start sending packet, channel 0, START immediately, Packet length according to PH, go READY when done */
	//si446x_start_tx(channel, 0x30,  0x00);
	si446x_start_tx(channel, 0x30,  cnt);
}

uint8_t Radio_CheckReceived(void)
{
	if (radio_hal_NirqLevel() == false)
	{
		/* Read ITs, clear pending ones */
		si446x_get_int_status(0u, 0u, 0u);

		/* check the reason for the IT */
		if (Si446xCmd.GET_INT_STATUS.MODEM_PEND & SI446X_CMD_GET_INT_STATUS_REP_SYNC_DETECT_BIT)
		{

		}
		if (Si446xCmd.GET_INT_STATUS.PH_PEND & SI446X_CMD_GET_INT_STATUS_REP_PACKET_RX_PEND_BIT)
		{
			/* Packet RX */
			si446x_read_rx_fifo(pRadioConfiguration->Radio_PacketLength, fixRadioPacket);

			return true;
		}
		if (Si446xCmd.GET_INT_STATUS.PH_PEND & SI446X_CMD_GET_INT_STATUS_REP_CRC_ERROR_BIT)
		{
			/* Reset FIFO */
			si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_RX_BIT);
		}
	}
	return false;
}

/*****************************************************************************!
 *  Check if Packet received IT flag is pending.
 *  @return   TRUE - Packet successfully received / FALSE - No packet pending.
 *  @note
 *****************************************************************************/
uint8_t Radio_CheckReceived_VariablePacket(void)
{
	if (radio_hal_NirqLevel() == false)
	{
		/* Read ITs, clear pending ones */
		si446x_get_int_status(0u, 0u, 0u);

		if (Si446xCmd.GET_INT_STATUS.CHIP_PEND & SI446X_CMD_GET_CHIP_STATUS_REP_CMD_ERROR_PEND_BIT)
		{
			/* State change to */
			si446x_change_state(SI446X_CMD_CHANGE_STATE_ARG_NEW_STATE_ENUM_SLEEP);

			/* Reset FIFO */
			si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_RX_BIT);

			/* State change to */
			si446x_change_state(SI446X_CMD_CHANGE_STATE_ARG_NEW_STATE_ENUM_RX);
		}
		/* check the reason for the IT */
		if (Si446xCmd.GET_INT_STATUS.MODEM_PEND & SI446X_CMD_GET_INT_STATUS_REP_SYNC_DETECT_BIT)
		{

		}
		if (Si446xCmd.GET_INT_STATUS.PH_PEND & SI446X_CMD_GET_INT_STATUS_REP_PACKET_RX_PEND_BIT)
		{
			/* Read the length of RX_FIFO */
			si446x_fifo_info(0u);

			/* Packet RX */
			si446x_read_rx_fifo(Si446xCmd.FIFO_INFO.RX_FIFO_COUNT, &fixRadioPacket[0]);
			return true;
		}
		if (Si446xCmd.GET_INT_STATUS.PH_PEND & SI446X_CMD_GET_INT_STATUS_REP_CRC_ERROR_BIT)
		{
			/* Reset FIFO */
			si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_RX_BIT);
		}
	}
	return false;
}

/*****************************************************************************!
 *  Set Radio to RX mode, fixed packet length.
 *  @param channel Freq. Channel
 *  @note
 *****************************************************************************/
void Radio_StartRx(uint8_t cnt)
{
	uint8_t channel=pRadioConfiguration->Radio_ChannelNumber;
	// Read ITs, clear pending ones
	si446x_get_int_status(0u, 0u, 0u);

	/* Start Receiving packet, channel 0, START immediately, Packet length according to PH */
	si446x_start_rx(channel, 0u, cnt,
                  SI446X_CMD_START_RX_ARG_RXTIMEOUT_STATE_ENUM_NOCHANGE,
                  SI446X_CMD_START_RX_ARG_RXVALID_STATE_ENUM_RX,
                  SI446X_CMD_START_RX_ARG_RXINVALID_STATE_ENUM_RX );
}

/*****************************************************************************!
 * Gets a command response from the radio chip
 * @param byteCount     Number of bytes to get from the radio chip
 * @param pData         Pointer to where to put the data
 * @return CTS value
 *****************************************************************************/
uint8_t radio_comm_GetResp(uint8_t byteCount, uint8_t* pData)
{
	uint8_t ctsVal = 0;
	uint16_t errCnt = RADIO_CTS_TIMEOUT;

	while (errCnt != 0)      //wait until radio IC is ready with the data
	{
		radio_hal_ClearNsel();
		radio_hal_SpiWriteByte(0x44);    //read CMD buffer
		ctsVal = radio_hal_SpiReadByte();
		if (ctsVal == 0xFF)
		{
			if (byteCount)
			{
				radio_hal_SpiReadData(byteCount, pData);
			}
			radio_hal_SetNsel();
			break;
		}
		radio_hal_SetNsel();
		errCnt--;
	}
	if (errCnt == 0)
	{
		while(1)
		{

		}
	}
	if (ctsVal == 0xFF)
	{
		ctsWentHigh = 1;
	}
	return ctsVal;
}

/*****************************************************************************!
 * Sends a command to the radio chip
 * @param byteCount     Number of bytes in the command to send to the radio device
 * @param pData         Pointer to the command to send.
 *****************************************************************************/
void radio_comm_SendCmd(uint8_t byteCount, uint8_t* pData)
{
	/* There was a bug in A1 hardware that will not handle 1 byte commands.
	It was supposedly fixed in B0 but the fix didn't make it at the last minute, so here we go again */
    if (byteCount == 1)
    	byteCount++;

	while (!ctsWentHigh)
    {
		radio_comm_PollCTS();
    }
    radio_hal_ClearNsel();
    radio_hal_SpiWriteData(byteCount, pData);
    radio_hal_SetNsel();
    ctsWentHigh = 0;
}

/*****************************************************************************!
 * Gets a command response from the radio chip
 * @param cmd           Command ID
 * @param pollCts       Set to poll CTS
 * @param byteCount     Number of bytes to get from the radio chip.
 * @param pData         Pointer to where to put the data.
 *****************************************************************************/
void radio_comm_ReadData(uint8_t cmd, uint8_t pollCts, uint8_t byteCount, uint8_t* pData)
{
	if(pollCts)
	{
		while(!ctsWentHigh)
        {
			radio_comm_PollCTS();
        }
    }
    radio_hal_ClearNsel();
    radio_hal_SpiWriteByte(cmd);
    radio_hal_SpiReadData(byteCount, pData);
    radio_hal_SetNsel();
    ctsWentHigh = 0;
}

/*****************************************************************************!
 * Gets a command response from the radio chip
 * @param cmd           Command ID
 * @param pollCts       Set to poll CTS
 * @param byteCount     Number of bytes to get from the radio chip
 * @param pData         Pointer to where to put the data
 *****************************************************************************/
void radio_comm_WriteData(uint8_t cmd, uint8_t pollCts, uint8_t byteCount, uint8_t* pData)
{
	if(pollCts)
	{
		while(!ctsWentHigh)
        {
			radio_comm_PollCTS();
        }
    }
	radio_hal_ClearNsel();
    radio_hal_SpiWriteByte(cmd);
    radio_hal_SpiWriteData(byteCount, pData);
    radio_hal_SetNsel();
    ctsWentHigh = 0;
}

/*****************************************************************************!
 * Waits for CTS to be high
 * @return CTS value
 *****************************************************************************/
uint8_t radio_comm_PollCTS(void)
{
	#ifdef RADIO_USER_CFG_USE_GPIO1_FOR_CTS
		while(!radio_hal_Gpio1Level())
		{
			/* Wait...*/
		}
		ctsWentHigh = 1;
		return 0xFF;
	#else
		return radio_comm_GetResp(0, 0);
	#endif
}

/*****************************************************************************!
 * Clears the CTS state variable.
 *****************************************************************************/
void radio_comm_ClearCTS()
{
	ctsWentHigh = 0;
}

/*****************************************************************************!
 * Sends a command to the radio chip and gets a response
 * @param cmdByteCount  Number of bytes in the command to send to the radio device
 * @param pCmdData      Pointer to the command data
 * @param respByteCount Number of bytes in the response to fetch
 * @param pRespData     Pointer to where to put the response data
 * @return CTS value
 *****************************************************************************/
uint8_t radio_comm_SendCmdGetResp(uint8_t cmdByteCount, uint8_t* pCmdData, uint8_t respByteCount, uint8_t* pRespData)
{
	radio_comm_SendCmd(cmdByteCount, pCmdData);
	return radio_comm_GetResp(respByteCount, pRespData);
}


void radio_hal_AssertShutdown(void)
{
	GPIO_PinOutSet(RF_SDN_PORT, RF_SDN_PIN);
}

void radio_hal_DeassertShutdown(void)
{
	GPIO_PinOutClear(RF_SDN_PORT, RF_SDN_PIN);
}

void radio_hal_ClearNsel(void)
{
    GPIO_PinOutClear(SPI_CS_PORT, SPI_CS_PIN);
}

void radio_hal_SetNsel(void)
{
	GPIO_PinOutSet(SPI_CS_PORT, SPI_CS_PIN);
}

uint8_t radio_hal_NirqLevel(void)
{
	return GPIO_PinInGet(RF_nIRQ_PORT, RF_nIRQ_PIN);
}

void radio_hal_SpiWriteByte(uint8_t byteToWrite)
{
	Spi_ReadWrite(byteToWrite);
}

uint8_t radio_hal_SpiReadByte(void)
{
	return Spi_ReadWrite(0x00);
}

void radio_hal_SpiWriteData(uint8_t byteCount, uint8_t* pData)
{
	Spi_WriteDataBurst(byteCount, pData);
}

void radio_hal_SpiReadData(uint8_t byteCount, uint8_t* pData)
{
	Spi_ReadDataBurst(byteCount, pData);
}

#ifdef RADIO_DRIVER_EXTENDED_SUPPORT
uint8_t radio_hal_Gpio0Level(void)
{
	return GPIO_PinInGet(RF_GPIO0_PORT, RF_GPIO0_PIN);
}

uint8_t radio_hal_Gpio1Level(void)
{
    return GPIO_PinInGet(RF_GPIO1_PORT, RF_GPIO1_PIN);
}

uint8_t radio_hal_Gpio2Level(void)
{
    return GPIO_PinInGet(RF_GPIO2_PORT, RF_GPIO2_PIN);
}

uint8_t radio_hal_Gpio3Level(void)
{
	return GPIO_PinInGet(RF_GPIO3_PORT, RF_GPIO3_PIN);
}
#endif
