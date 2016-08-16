/*
 * GPS.c
 *
 *  Created on: 2016-8-3
 *      Author: Root-Wang
 */

#include "../../../../Header Files/app_plat/bsp.h"
#include "var.h"

#include <string.h>


#define MAX_GPS_BUFF_LEN 128
INT8S gps_tmp_buff[MAX_GPS_BUFF_LEN];

extern tagSystemInfo gSystemInfo;

INT8S check_sum_gps_frame(INT8S * buff, INT8U len)
{
    INT8U i;
    INT8S result;

    for(result=buff[0], i=1; i<len; i++)
    {
        result ^= buff[i];
    }
    return result;
}

INT8U gps_get_loc_from(INT8S * buff, INT8U max_len)
{
    INT8U pos;

    pos = 17;

    if(buff[pos] != ',')   //纬度信息
    {
        gSystemInfo.GPS_Info.latitude = str2uint(buff+pos);
        pos += 5;
        gSystemInfo.GPS_Info.latitude_sec = str2uint(buff+pos);
        pos += 5;
        gSystemInfo.GPS_Info.loc_NS = *(buff+pos);
        pos += 2;
    }
    else
    {
        return FALSE;
    }

    if(buff[pos] != ',')   //经度信息
    {
        gSystemInfo.GPS_Info.longitude = str2uint(buff+pos);
        pos += 6;
        gSystemInfo.GPS_Info.longitude_sec = str2uint(buff+pos);
        pos += 5;
        gSystemInfo.GPS_Info.loc_EW = *(buff+pos);
        pos += 2;
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

INT8U gps_get_abstime_from(INT8S * buff, INT8U max_len)
{
    INT8U pos;

    pos = 6;

    if(buff[pos] != ',')   //时分秒信息
    {
        gSystemInfo.GPS_Info.abstime_hh = str2uint_gps(buff+pos,2);
        pos += 2;
        gSystemInfo.GPS_Info.abstime_mm = str2uint_gps(buff+pos,2);
        pos += 2;
        gSystemInfo.GPS_Info.abstime_ss = str2uint_gps(buff+pos,2);;
        pos += 3;
    }
    else
    {
        return FALSE;
    }

    if(buff[pos] != ',')   //毫秒信息
    {
        gSystemInfo.GPS_Info.abstime_ms = str2uint_gps(buff+pos,3);
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

INT8U process_gps_location_recv(void)
{
    static INT8U GPS_recv_state = 0;
    static INT8U GPS_buff_pos = 0;
    static INT8U GPS_check_sum;

    INT16S rx_data;
    INT8S recv_byte;

    rx_data = gps_232_read_byte();

    if(rx_data < 0)
    {
        return 0;
    }

    recv_byte = (INT8S)rx_data;
    switch(GPS_recv_state)
    {
        case 0: //等待帧头'$'
            if(recv_byte == '$')
            {
                GPS_recv_state ++;
                GPS_buff_pos = 0;
            }
            break;
        case 1:     //收取Talker ID"GPGGA"
            gps_tmp_buff[GPS_buff_pos++] = recv_byte;
            if(GPS_buff_pos >= 5)
            {
                if(0 != memcmp(gps_tmp_buff, "GPGGA", 5))
                {
                    GPS_buff_pos = 0;
                    GPS_recv_state = 0;
                }
                else
                {
                    GPS_recv_state ++;
                }
            }
            break;
        case 2:     //收取帧内容
            if(recv_byte != '*')
            {
                gps_tmp_buff[GPS_buff_pos++] = recv_byte;
                if(GPS_buff_pos >= MAX_GPS_BUFF_LEN)
                {
                    GPS_buff_pos = 0;
                    GPS_recv_state = 0;
                }
            }
            else
            {
                GPS_recv_state ++;
            }
            break;
        case 3:     //校验的第一个字符
            GPS_check_sum = (recv_byte - '0')<<4;
            GPS_recv_state ++;
            break;
        case 4:
            GPS_check_sum += recv_byte - '0';
            if(GPS_check_sum == check_sum_gps_frame(gps_tmp_buff, GPS_buff_pos))//check_sum_gps_frame(gps_tmp_buff, GPS_buff_pos))
            {
                return gps_get_loc_from(gps_tmp_buff, GPS_buff_pos);     //提取经纬度信息
            }
            GPS_buff_pos = 0;
            GPS_recv_state = 0;
            break;
        default:
            GPS_recv_state = 0;
            break;
    }

    return 0;
}

INT8U process_gps_abstime_recv(void)
{
    static INT8U GPS_recv_state = 0;
    static INT8U GPS_buff_pos = 0;
    static INT8U GPS_check_sum;

    INT16S rx_data;
    INT8S recv_byte;

    rx_data = gps_232_read_byte();

    if(rx_data < 0)
    {
        return 0;
    }

    recv_byte = (INT8S)rx_data;
    switch(GPS_recv_state)
    {
        case 0: //等待帧头'$'
            if(recv_byte == '$')
            {
                GPS_recv_state ++;
                GPS_buff_pos = 0;
            }
            break;
        case 1:     //收取Talker ID"GPGGA"
            gps_tmp_buff[GPS_buff_pos++] = recv_byte;
            if(GPS_buff_pos >= 5)
            {
                if(0 != memcmp(gps_tmp_buff, "GPGGA", 5))
                {
                    GPS_buff_pos = 0;
                    GPS_recv_state = 0;
                }
                else
                {
                    GPS_recv_state ++;
                }
            }
            break;
        case 2:     //收取帧内容
            if(recv_byte != '*')
            {
                gps_tmp_buff[GPS_buff_pos++] = recv_byte;
                if(GPS_buff_pos >= MAX_GPS_BUFF_LEN)
                {
                    GPS_buff_pos = 0;
                    GPS_recv_state = 0;
                }
            }
            else
            {
                GPS_recv_state ++;
            }
            break;
        case 3:     //校验的第一个字符
            GPS_check_sum = (recv_byte - '0')<<4;
            GPS_recv_state ++;
            break;
        case 4:
            GPS_check_sum += recv_byte - '0';
            if(GPS_check_sum == check_sum_gps_frame(gps_tmp_buff, GPS_buff_pos))//check_sum_gps_frame(gps_tmp_buff, GPS_buff_pos))
            {
                return gps_get_abstime_from(gps_tmp_buff, GPS_buff_pos);     //提取经纬度信息
            }
            GPS_buff_pos = 0;
            GPS_recv_state = 0;
            break;
        default:
            GPS_recv_state = 0;
            break;
    }

    return 0;
}

INT8U Get_Location_Now(void)
{
    uint32_t start_timer;

    //GPS初始化
//    pin_ctrl_gps_ctrl(PIN_HIGH);  //GPS上电
//    drv_gps_232_init(9600, USART_8N1);

    start_timer = system_get_tick10ms();
    while(1)
    {
        if((system_get_tick10ms()-start_timer) > 1000)
        {
            //禁止GPS串口中断
 //           pin_ctrl_gps_ctrl(PIN_LOW);
//            PLIB_INT_SourceDisable(INT_ID_0, UART_GPS_INT_SOURCE_RECEIVE);
            return FALSE;
        }

        if(process_gps_location_recv())
        {
            //禁止GPS串口中断
    //        pin_ctrl_gps_ctrl(PIN_LOW);
 //           PLIB_INT_SourceDisable(INT_ID_0, UART_GPS_INT_SOURCE_RECEIVE);
            return TRUE;
        }
    }

    //should bever be here
    return FALSE;

}

INT8U Get_Abstime_Now(void)
{
    uint32_t start_timer;

    //GPS初始化
//    pin_ctrl_gps_ctrl(PIN_HIGH);  //GPS上电
//    drv_gps_232_init(9600, USART_8N1);

    start_timer = system_get_tick10ms();
    while(1)
    {
        if((system_get_tick10ms()-start_timer) > 1000)
        {
            //禁止GPS串口中断
 //           pin_ctrl_gps_ctrl(PIN_LOW);
//            PLIB_INT_SourceDisable(INT_ID_0, UART_GPS_INT_SOURCE_RECEIVE);
            return FALSE;
        }

        if(process_gps_abstime_recv())
        {
            //禁止GPS串口中断
  //          pin_ctrl_gps_ctrl(PIN_LOW);
 //           PLIB_INT_SourceDisable(INT_ID_0, UART_GPS_INT_SOURCE_RECEIVE);
            return TRUE;
        }
    }

    //should bever be here
    return FALSE;

}


