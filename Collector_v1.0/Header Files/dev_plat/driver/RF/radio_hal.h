/****************************************
 *  File:                  radio_hal.h
 *  Created on:    2016-7-16
 *  Author:            WANGJIANHUI
 ****************************************/
#ifndef   _RADIO_HAL_H
#define  _RADIO_HAL_H


#define RADIO_MAX_PACKET_LENGTH     64u

#define RADIO_CTS_TIMEOUT 10000

extern uint8_t fixRadioPacket[RADIO_MAX_PACKET_LENGTH];
extern uint8_t Radio_Configuration_Data_Array[];
extern uint8_t radioCmd[16u];

typedef struct
{
    uint8_t   *Radio_ConfigurationArray;
    uint8_t   Radio_ChannelNumber;
    uint8_t   Radio_PacketLength;
    uint8_t   Radio_State_After_Power_Up;
    uint16_t  Radio_Delay_Cnt_After_Reset;
    uint8_t   Radio_CustomPayload[RADIO_MAX_PACKET_LENGTH];
} tRadioConfiguration;

void Radio_PowerUp(void);
void  Radio_Init(void);

void Radio_StartRx(uint8_t lens, uint8_t channel);
void Radio_LDC_StartRx(uint8_t lens, uint8_t channel);

void  Radio_StartTx(uint8_t *data,uint8_t lens, uint8_t channel,uint8_t ldctx_en);
void  Radio_LongTx(uint8_t *data,uint32_t lens, uint8_t channel,uint8_t ldctx_en);
void Radio_Tx_Repeat(uint8_t *data,uint8_t lens,uint32_t cnt, uint8_t channel,uint8_t ldctx_en);

uint8_t   Radio_CheckReceived(void);
uint8_t   Radio_CheckTransmitted(void);

uint8_t Radio_Cmd(uint8_t *data,uint8_t lens);
void Enter_LDCRX_mode(uint8_t osc_cal);
void Exit_LDCRX_mode(uint8_t osc_cal);
void Enter_LDCTX_Mode(uint8_t osc_cal);
void Exit_LDCTX_Mode(uint8_t osc_cal);

void Wait_Radio_Transmitted(void);
void Set_LDC_RX_SLEEP_Time(uint8_t wut_m_15_8,uint8_t wut_m_7_0,uint8_t wut_r,uint8_t wut_ldc);
void Wait_Channeldet_Idle(void);
void Set_RSSI_Thresh(uint8_t thresh);
void Set_TX_FIFO_ALMOST_EMPTY_Thresh(uint8_t thresh);
void Preamble_Config(uint8_t lens,uint8_t format);

void Radio_StartSleep(void);
void Radio_ReadyTx(void);

void radio_hal_AssertShutdown(void);
void radio_hal_DeassertShutdown(void);
void radio_hal_ClearNsel(void);
void radio_hal_SetNsel(void);
uint8_t radio_hal_NirqLevel(void);

void radio_hal_SpiWriteByte(uint8_t byteToWrite);
uint8_t radio_hal_SpiReadByte(void);
void radio_hal_SpiWriteData(uint8_t byteCount, uint8_t* pData);
void radio_hal_SpiReadData(uint8_t byteCount, uint8_t* pData);

void radio_comm_SendCmd(uint8_t byteCount, uint8_t* pData);
void radio_comm_ReadData(uint8_t cmd, uint8_t pollCts, uint8_t byteCount, uint8_t* pData);
void radio_comm_WriteData(uint8_t cmd, uint8_t pollCts, uint8_t byteCount, uint8_t* pData);
uint8_t radio_comm_GetResp(uint8_t byteCount, uint8_t* pData);
uint8_t radio_comm_SendCmdGetResp(uint8_t cmdByteCount, uint8_t* pCmdData, uint8_t respByteCount, uint8_t* pRespData);
void radio_comm_ClearCTS(void);
uint8_t radio_comm_PollCTS(void);

uint8_t radio_hal_Gpio0Level(void);
uint8_t radio_hal_Gpio1Level(void);
uint8_t radio_hal_Gpio2Level(void);
uint8_t radio_hal_Gpio3Level(void);


#endif

