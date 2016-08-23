/****************************************
 *  File:                  radio_hal.c
 *  Created on:    2016-7-16
 *  Author:            WANGJIANHUI
 ****************************************/
#include "rf_config.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "InitDevice.h"
//#include "hal_delay.h"

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
	si446x_reset();

	for (uint16_t i = 0; i < pRadioConfiguration->Radio_Delay_Cnt_After_Reset; i++);
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
/************************************************************!
Function:  Radio_StartRx
Description:  start rx data in normal mode.
Input:  @lens:
            @channel: the send channel
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Radio_StartRx(uint8_t lens, uint8_t channel)
{
	si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_TX_BIT);   //复位FIFO

	si446x_get_int_status(0u, 0u, 0u);

	si446x_start_rx(channel, 0u, lens,
                  SI446X_CMD_START_RX_ARG_RXTIMEOUT_STATE_ENUM_NOCHANGE,
                  SI446X_CMD_START_RX_ARG_RXVALID_STATE_ENUM_RX,
                  SI446X_CMD_START_RX_ARG_RXINVALID_STATE_ENUM_RX );
}
/************************************************************!
Function:  Radio_LDC_StartRx
Description:  start rx data in ldc mode.
Input:  @lens:
            @channel: the send channel
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Radio_LDC_StartRx(uint8_t lens, uint8_t channel)
{
	si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_TX_BIT);   //复位FIFO

	si446x_get_int_status(0u, 0u, 0u);

	si446x_start_rx(channel, 0, lens,
			      SI446X_CMD_START_RX_ARG_RXTIMEOUT_STATE_ENUM_SLEEP,
				  SI446X_CMD_START_RX_ARG_RXVALID_STATE_ENUM_SLEEP,
				  SI446X_CMD_START_RX_ARG_RXINVALID_STATE_ENUM_RX );
}
/************************************************************!
Function:  Radio_StartTx
Description:  send the packet.
Input:  @data:
            @lens:
            @channel: the send channel
            @ldctx_en: normal tx or ldctx
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void  Radio_StartTx(uint8_t *data,uint8_t lens, uint8_t channel,uint8_t ldctx_en)
{
	uint8_t condition=0x30;

	if(ldctx_en==1)
		condition=0x31;

	si446x_change_state(SI446X_CMD_CHANGE_STATE_ARG_NEW_STATE_ENUM_READY);

	si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_TX_BIT);   //复位FIFO

	si446x_get_int_status(0u, 0u, 0u);

	si446x_write_tx_fifo(lens, data);

	si446x_start_tx(channel, condition, lens);
}
/************************************************************!
Function:  Radio_LongTx
Description:  send the uint32_t bytes of the packet.
Input:  @data:
            @lens:
            @channel: the send channel
            @ldctx_en: normal tx or ldctx
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void  Radio_LongTx(uint8_t *data,uint32_t lens, uint8_t channel,uint8_t ldctx_en)
{
	uint8_t cnt=0;

	//Exit_LDCRX_mode(0);

	while(lens>=64)
	{
		Radio_StartTx((data+(cnt++)*64),0x40,channel, ldctx_en);
		Wait_Radio_Transmitted();
		lens-=64;
	}
	while(lens<64&&lens>0)
	{
		Radio_StartTx((data+cnt*64),lens,channel, ldctx_en);
		Wait_Radio_Transmitted();
		lens=0;
	}
	//Enter_LDCRX_mode(0);
}
/************************************************************!
Function:  Radio_Tx_Repeat
Description:  repeat the desired num of the same packet.
Input:  @data:
            @lens:
            @cnt: the num to repeat.
            @channel: the send channel
            @ldctx_en: normal tx or ldctx
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Radio_Tx_Repeat(uint8_t *data,uint8_t lens, uint32_t cnt, uint8_t channel,uint8_t ldctx_en)
{
	uint32_t flags=0;

	Exit_LDCRX_mode(0);
	while(flags++<cnt)
	{
		Radio_StartTx(data,lens, channel, ldctx_en);
		Wait_Radio_Transmitted();
	}
	Enter_LDCRX_mode(0);
}
/************************************************************!
Function:  Wait_Radio_Transmitted
Description:  wait until the packet is transmitted.
Input:
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Wait_Radio_Transmitted(void)
{
	while(true)
	{
		if(Radio_CheckTransmitted()==true)
		{
			break;
		}
	}
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
 *  Check if Packet received IT flag is pending.
 *  @return   TRUE - Packet successfully received / FALSE - No packet pending.
 *  @note
 *****************************************************************************/
uint8_t Radio_CheckReceived(void)
{
	if (radio_hal_NirqLevel() == false)
	{
		si446x_get_int_status(0u, 0u, 0u);
		if (Si446xCmd.GET_INT_STATUS.PH_PEND & SI446X_CMD_GET_INT_STATUS_REP_PACKET_RX_PEND_BIT)
		{
			si446x_fifo_info(0u);    //Read the length of RX_FIFO

			si446x_read_rx_fifo(Si446xCmd.FIFO_INFO.RX_FIFO_COUNT, &fixRadioPacket[0]);

			return true;
		}
		if (Si446xCmd.GET_INT_STATUS.CHIP_PEND & SI446X_CMD_GET_CHIP_STATUS_REP_CMD_ERROR_PEND_BIT)
		{
			si446x_change_state(SI446X_CMD_CHANGE_STATE_ARG_NEW_STATE_ENUM_SLEEP);

			si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_RX_BIT);    //复位FIFO

			si446x_change_state(SI446X_CMD_CHANGE_STATE_ARG_NEW_STATE_ENUM_RX);
		}
		if (Si446xCmd.GET_INT_STATUS.PH_PEND & SI446X_CMD_GET_INT_STATUS_REP_CRC_ERROR_BIT)
		{
			si446x_fifo_info(SI446X_CMD_FIFO_INFO_ARG_RX_BIT);    //复位FIFO
		}
	}
	return false;
}
/************************************************************!
Function:  Enter_LDCRX_mode
Description:  open the wut_ldc function,then enter LDCRX mode.
                      note: the period of the time cal is 128s.
Input:  @osc_cal: enable or disable the timer cal.
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Enter_LDCRX_mode(uint8_t osc_cal)
{
	uint8_t cmd[10]={RF_GLOBAL_CONFIG_6};  //开启WUT_LDC
    if(osc_cal==1)
		cmd[5]=0x7b;

	Radio_Cmd(cmd,0x0a);
}
/************************************************************!
Function:  Exit_LDCRX_mode
Description:  close the wut_ldc function,then exit LDCRX mode.
                      note: the period of the time cal is 128s.
Input:  @osc_cal: enable or disable the timer cal.
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Exit_LDCRX_mode(uint8_t osc_cal)
{
	uint8_t cmd[10]={RF_GLOBAL_CONFIG_6};
	cmd[5]=0x02;
	if(osc_cal==1)
		cmd[5]=0x3b;

	Radio_Cmd(cmd,0x0a);
}
/************************************************************!
Function:  Enter_LDCTX_Mode
Description:  open the LDC_TX_EN,then enter LDCTX mode.
                      note: a.the period of the time cal is 128s.
                               b.first,the program must enter the ldc mode.
Input:  @osc_cal: enable or disable the timer cal.
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Enter_LDCTX_Mode(uint8_t osc_cal)
{
	//uint8_t cmd1[5]={0x11, 0x00, 0x01, 0x04, 0x82};
	//Radio_Cmd(cmd1,0x05);

	uint8_t cmd[10]={0x11, 0x00, 0x06, 0x03, 0x20,0x82,0x03, 0x33, 0x20, 0x5};
	if(osc_cal==1);
		cmd[4]=0xbb;

	Radio_Cmd(cmd,0x0a);
}
/************************************************************!
Function:  Exit_LDCTX_Mode
Description:  close the LDC_TX_EN function,then exit LDCTX mode.
                      note: a.the period of the time cal is 128s.
                               b.first,the program must enter the ldc mode.
Input:  @osc_cal: enable or disable the timer cal.
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Exit_LDCTX_Mode(uint8_t osc_cal)
{
	uint8_t cmd[10]={RF_GLOBAL_CONFIG_6};
	cmd[5]=0x02;
	if(osc_cal==1);
		cmd[5]=0x3b;

	Radio_Cmd(cmd,0x0a);
}
/************************************************************!
Function:  Set_LDC_RX_SLEEP_Time
Description:  set the RX time and SLEEP time of the LDC mode.
                      note: to set the related parameter, please according
                               to the WDS software or the 4460 API.
Input:  @wut_m_15_8:
		    @wut_m_7_0:
            @wut_r:
            @wut_ldc:
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Set_LDC_RX_SLEEP_Time(uint8_t wut_m_15_8,uint8_t wut_m_7_0,
		                                        uint8_t wut_r,uint8_t wut_ldc)
{
	uint8_t cmd[5]={0x11, 0x00, 0x01, 0x04, 0x00};

	Radio_Cmd(cmd,0x05);

	uint8_t cmd1[8]={0x11, 0x00, 0x04, 0x05, 0x00,0x00,0x00,0x00};
	cmd1[4]=wut_m_15_8;
	cmd1[5]=wut_m_7_0;
	cmd1[6]=wut_r;
	cmd1[7]=wut_ldc;

	Radio_Cmd(cmd1,0x08);
}
/************************************************************!
Function:  Wait_Channeldet_Idle
Description:  to avoid the channel collision, detecting the channal
                     whether is idle or not before sending data.
                     note: the corresponding pin should be configured to
                              CCA,please according to the GPIO_PIN_CFG of
                              the WDS software or the 4460 API.
Input:  null
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Wait_Channeldet_Idle(void)
{
	while(radio_hal_Gpio1Level()==true);
}
/************************************************************!
Function:  Set_RSSI_Thresh
Description:  set the rssi thresh for detecting the channal whether
                      is idle or not.
Input:  @thresh:
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Set_RSSI_Thresh(uint8_t thresh)
{
	uint8_t cmd[5]={0x11, 0x20, 0x01, 0x4a, 0x03};  //设置RSSI阈值命令
	cmd[4]=thresh;

	Radio_Cmd(cmd,0x05);
}
/************************************************************!
Function:  Set_TX_FIFO_ALMOST_EMPTY_Thresh
Description:  set the TX_FIFO_ALMOST_EMPTY thresh to trigger
                     the int.
Input:  @thresh:
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Set_TX_FIFO_ALMOST_EMPTY_Thresh(uint8_t thresh)
{
	uint8_t cmd[5]={0x11, 0x20, 0x01, 0x4a, 0x30};  //设置RSSI阈值命令
	cmd[4]=thresh;

	Radio_Cmd(cmd,0x05);
}
/************************************************************!
Function:  Preamble_Config
Description:  set the lens and the standard format of the
                     preamble of the packet.
Input:  @lens:  unit:byte
            @format:  0: 010101...  1:101010...
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
void Preamble_Config(uint8_t lens,uint8_t format)
{
	uint8_t cmd[9]={0x11,0x10,0x05,0x00,0x08,0x14,0x00,0x0f,0x31};

	cmd[4]=lens;
	if(format==0)
		cmd[8]=0x12;
	if(format==1)
		cmd[8]=0x31;

	Radio_Cmd(cmd,0x09);
}
/************************************************************!
Function:  Radio_Cmd
Description:  send the cmd to radio.
Input:  @data:
            @lens:
Output:   null
Return:  null
Author: WANGJIANHUI
*************************************************************/
uint8_t Radio_Cmd(uint8_t *data,uint8_t lens)
{
	if (radio_comm_SendCmdGetResp(lens, data, 0, 0) != 0xFF)
	{
		return false;
    }
	return true;
}

void Radio_StartSleep(void)
{
  si446x_change_state(SI446X_CMD_CHANGE_STATE_ARG_NEW_STATE_ENUM_SLEEP);
}

void Radio_ReadyTx(void)
{
  si446x_change_state(SI446X_CMD_CHANGE_STATE_ARG_NEW_STATE_ENUM_READY);
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
		while(1);
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
