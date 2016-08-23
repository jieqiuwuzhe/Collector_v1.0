/*
 * var.h
 *
 *  Created on: 2016-8-4
 *      Author: Root-Wang
 */

#ifndef VAR_H_
#define VAR_H_

#include "data_type.h"
#include "stdint.h"


//GPS信息
typedef struct{
    INT8S loc_NS;            //南/北纬
    INT8S loc_EW;           //东/西经
    INT16U latitude;         //纬度（整）
    INT16U latitude_sec;   //纬度（秒）
    INT16U longitude;       //经度（整）
    INT16U longitude_sec; //经度（秒）
    INT8U   abstime_hh;
    INT8U   abstime_mm;
    INT8U   abstime_ss;
    INT16U abstime_ms;

}tag_GPS_Info;

//系统信息
typedef struct
{
       INT16U ms_tick;//用来维持ms级单位的计数变量
       INT16U ss_tick;  //用来维持s级单位的计数变量
       FP32 sun_bat;
       FP32 cap_bat;
       FP32 xu_bat;
       INT8U call_15min ;//15min召测信号
       uint32_t Ticks;//计数系统心跳，每个tick++
//    INT8U gprs_ver_info[26];
//    INT8U gprs_ccid[20];
//    INT8U gprs_type[3];
//    INT8U gprs_imsi[15];
//    INT8U DJB_Central_address[6];
//    INT8U djb_ver_info[16];
//    INT8U DJB_Perip_Cnt;
//    tagDJB_Peripheral_Info DJB_Peripheral_Info[8];//扫描到的蓝牙外设信息，一共可储存8个外部设备
//    INT8U DJB_Link_State;//蓝牙连接状态，如果连接成功，置1。
//    INT8U DJB_Notify_State;//蓝牙Notify使能，如果不使能，则主机无法接收到从机发来的数据，成功置1。
//    INT8U Central_Status;//主设备未成功返回的值，该值来自协议栈内部。
//    INT8U Selected_Port;//载波、红外、蓝牙端口选择，用于报文解析
//    INT8U Recv_xybuffer_1_flag;//通过蓝牙接收到表计返回的报文后，这个置1。
//    volatile INT8U Recv_xybuffer_2_flag;//通过蓝牙接收到表计返回的报文后，这个置1。
//    INT8U standby_battery[2];   //备用电池电压
//    INT8U clock_battrey[2];     //时钟电池电压
//    INT8U temperature[2];       //温度
//    INT8U lvd[2];
//    INT8U vdd[2];
//    INT8U vref[2];
//    INT8U plc_ver_info[15];
//    INT8U ertu_devid[6];
//    INT8U heart_cycle;
//    INT8U gprs_csq;
//    INT8U gprs_ber;
//    INT8U gprs_error_state;
//    INT8U gprs_client_state;
//    INT8U gprs_end_state;//gprs最终状态
//    INT8U secondary_gprs_client_state;
//    INT8U eth_client_state;
//    INT8U secondary_eth_client_state;
//    INT8U eth_ip_update_flag;
//    INT8U gprs_pin_state;       //GPRS管脚状态，从蓝牙获取
//    INT8S devp_temperature;
//    INT8U rated_voltage[2];//额定电压，单位0.1V
//    INT8U rated_current[2];//额定电流，单位0.1A
//    INT8U day_bytes[4];    //日通信流量
//    INT8U month_bytes[4];  //月通信流量
//    INT8U ESAM_DEVID[8];
//    INT8U ESAM_RAND[8];
//    INT8U ESAM_CERT_STATE;
//    INT8U battery_charge;
//    INT8U primary_osc_status;
//    INT8U secondary_osc_status;
//    INT8U pin_32768;              //32768管脚，0xAA,32768在SOSCO管脚，其他在SOSCI管脚
//    INT8U sys_frequency[4];
//    INT8U log_level;            //日志级别
//    INT8U log_out_type;             //日志输出方式
//    INT8U frame_monitor_type[2];   //报文监控类别
//    INT8U beidou_flag;
//    INT8U beidou_user_no[3];
//    INT8U beidou_msa_no[3];
//    INT8U rs232_report_type;
	tag_GPS_Info GPS_Info;
}tagSystemInfo;


//内部通信数据结构
typedef struct{

}tag_data_In;

//内部通信帧


//SOE事件记录
typedef struct{

}tag_soe_event;

//日志数据记录

#endif /* VAR_H_ */
