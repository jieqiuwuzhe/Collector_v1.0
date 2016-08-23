/******************************************************************************
 * Copyright (C), 2016-2017, www.topscomm.com
 *
 * 文件名：     rs_232.c
 * 内容简述：串口驱动层
 *
 * 文件历史:
 * 版本号             日期                作者             说明
 * v0.1    2016.7.27   Root    创建文件
 ******************************************************************************/

#include "../../Header Files/app_plat/bsp.h"
#include "em_leuart.h"



objDrvChannel   DrvGPS232Channel;
objDrvChannel   DrvGPRSRS232Channel;

/****************************************/
//GPS初始化
void drv_gps_232_init(void)
{
    DrvGPS232Channel.read_ptr = DrvGPS232Channel.recv_ptr = 0;
}

//GPS读字节
INT16S drv_gps_232_read_byte(void)
{
    INT16S data;

    data = -1;

    #ifdef __UART_RX_USE_DMA__
    #else
    if(DrvGPS232Channel.read_ptr == DrvGPS232Channel.recv_ptr)
        return data;
    data = DrvGPS232Channel.recv_buffer[DrvGPS232Channel.read_ptr ++];
    if(DrvGPS232Channel.read_ptr >=sizeof(DrvGPS232Channel.recv_buffer) ) DrvGPS232Channel.read_ptr = 0;
    #endif

    return data;
}
/******************************************/
// GPRS初始化
void drv_gprs_rs232_init(void)
{
    DrvGPRSRS232Channel.read_ptr = DrvGPRSRS232Channel.recv_ptr = 0;
 }

//GPRS读字节
INT16S drv_gprs_rs232_read_byte(void)
{
    INT16S data;

    data = -1;

    #ifdef __UART_RX_USE_DMA__
    #else
    if(DrvGPRSRS232Channel.read_ptr == DrvGPRSRS232Channel.recv_ptr)
        return data;
    data = DrvGPRSRS232Channel.recv_buffer[DrvGPRSRS232Channel.read_ptr ++];
    if(DrvGPRSRS232Channel.read_ptr >=sizeof(DrvGPRSRS232Channel.recv_buffer) ) DrvGPRSRS232Channel.read_ptr = 0;
    #endif

    return data;
}
//GPRS发字节
void drv_gprs_send_byte(const INT8U data)
{
	USART_Tx(UART0, data);
}

// GPRS发buffer
INT8U drv_gprs_rs232_send_buffer(INT8U *buffer,INT16U buffer_len,INT8U *send_state)
{
     //增加是否可以调用的判断
    if(DrvGPRSRS232Channel.drv_send_len) return FALSE;

    DrvGPRSRS232Channel.drv_send_len = buffer_len;
    DrvGPRSRS232Channel.drv_send_data = buffer;
    DrvGPRSRS232Channel.drv_send_state = send_state;

    drv_gprs_send_byte( DrvGPRSRS232Channel.drv_send_data );

    return TRUE;
}



