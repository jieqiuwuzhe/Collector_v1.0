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


//GPS��Ϣ
typedef struct{
    INT8S loc_NS;            //��/��γ
    INT8S loc_EW;           //��/����
    INT16U latitude;         //γ�ȣ�����
    INT16U latitude_sec;   //γ�ȣ��룩
    INT16U longitude;       //���ȣ�����
    INT16U longitude_sec; //���ȣ��룩
    INT8U   abstime_hh;
    INT8U   abstime_mm;
    INT8U   abstime_ss;
    INT16U abstime_ms;

}tag_GPS_Info;

//ϵͳ��Ϣ
typedef struct
{
       INT16U ms_tick;//����ά��ms����λ�ļ�������
       INT16U ss_tick;  //����ά��s����λ�ļ�������
       FP32 sun_bat;
       FP32 cap_bat;
       FP32 xu_bat;
       INT8U call_15min ;//15min�ٲ��ź�
       uint32_t Ticks;//����ϵͳ������ÿ��tick++
//    INT8U gprs_ver_info[26];
//    INT8U gprs_ccid[20];
//    INT8U gprs_type[3];
//    INT8U gprs_imsi[15];
//    INT8U DJB_Central_address[6];
//    INT8U djb_ver_info[16];
//    INT8U DJB_Perip_Cnt;
//    tagDJB_Peripheral_Info DJB_Peripheral_Info[8];//ɨ�赽������������Ϣ��һ���ɴ���8���ⲿ�豸
//    INT8U DJB_Link_State;//��������״̬��������ӳɹ�����1��
//    INT8U DJB_Notify_State;//����Notifyʹ�ܣ������ʹ�ܣ��������޷����յ��ӻ����������ݣ��ɹ���1��
//    INT8U Central_Status;//���豸δ�ɹ����ص�ֵ����ֵ����Э��ջ�ڲ���
//    INT8U Selected_Port;//�ز������⡢�����˿�ѡ�����ڱ��Ľ���
//    INT8U Recv_xybuffer_1_flag;//ͨ���������յ���Ʒ��صı��ĺ������1��
//    volatile INT8U Recv_xybuffer_2_flag;//ͨ���������յ���Ʒ��صı��ĺ������1��
//    INT8U standby_battery[2];   //���õ�ص�ѹ
//    INT8U clock_battrey[2];     //ʱ�ӵ�ص�ѹ
//    INT8U temperature[2];       //�¶�
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
//    INT8U gprs_end_state;//gprs����״̬
//    INT8U secondary_gprs_client_state;
//    INT8U eth_client_state;
//    INT8U secondary_eth_client_state;
//    INT8U eth_ip_update_flag;
//    INT8U gprs_pin_state;       //GPRS�ܽ�״̬����������ȡ
//    INT8S devp_temperature;
//    INT8U rated_voltage[2];//���ѹ����λ0.1V
//    INT8U rated_current[2];//���������λ0.1A
//    INT8U day_bytes[4];    //��ͨ������
//    INT8U month_bytes[4];  //��ͨ������
//    INT8U ESAM_DEVID[8];
//    INT8U ESAM_RAND[8];
//    INT8U ESAM_CERT_STATE;
//    INT8U battery_charge;
//    INT8U primary_osc_status;
//    INT8U secondary_osc_status;
//    INT8U pin_32768;              //32768�ܽţ�0xAA,32768��SOSCO�ܽţ�������SOSCI�ܽ�
//    INT8U sys_frequency[4];
//    INT8U log_level;            //��־����
//    INT8U log_out_type;             //��־�����ʽ
//    INT8U frame_monitor_type[2];   //���ļ�����
//    INT8U beidou_flag;
//    INT8U beidou_user_no[3];
//    INT8U beidou_msa_no[3];
//    INT8U rs232_report_type;
	tag_GPS_Info GPS_Info;
}tagSystemInfo;


//�ڲ�ͨ�����ݽṹ
typedef struct{

}tag_data_In;

//�ڲ�ͨ��֡


//SOE�¼���¼
typedef struct{

}tag_soe_event;

//��־���ݼ�¼

#endif /* VAR_H_ */
