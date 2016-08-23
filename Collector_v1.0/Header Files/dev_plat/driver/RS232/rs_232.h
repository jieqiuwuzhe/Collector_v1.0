/*
 * rs_232.h
 *
 *  Created on: 2016-7-28
 *      Author: Root-Wang
 */

#ifndef RS_232_H_
#define RS_232_H_


#define SIZE_OF_RS232_RECV_BUFFER  1200


typedef struct  tagObjDrvChannel {

    //Driver ��
    //����
    volatile INT16U  recv_ptr; //�������ָ��
    INT16U  read_ptr;    //������ȡָ��
    INT16U  state;
    INT16U  recv_len;

    //����
    volatile INT16U  drv_send_len;
    INT8U   *drv_send_data;
    INT8U   *drv_send_state;

    INT8U    recv_buffer[SIZE_OF_RS232_RECV_BUFFER]; //������ȡ����
}objDrvChannel;




void drv_gprs_rs232_init(void);
void drv_gps_rs232_init(void);
INT16S drv_gprs_rs232_read_byte(void);
INT16S drv_gps_232_read_byte(void);
void drv_gprs_send_byte(const INT8U data);








#endif /* RS_232_H_ */
