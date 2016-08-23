/*
 * rs_232.h
 *
 *  Created on: 2016-7-28
 *      Author: Root-Wang
 */

#ifndef RS_232_H_
#define RS_232_H_


#define SIZE_OF_RS232_RECV_BUFFER  1200



typedef enum
{
  gps_uart,
  gprs_uart,
  weihu_uart
}Uart_Type;

void Uart_Write(Uart_Type uart, uint8_t *sdata, uint16_t len);
void Uart_Read (Uart_Type uart, uint8_t *rdata, uint16_t len);

INT16S gps_232_read_byte(void);


typedef struct  tagObjDrvChannel {

    //Driver ��
    //����
    volatile INT16U  recv_ptr;
    INT16U  read_ptr;      //����˫Э���֧�֣� �������ʹ�����顣
    INT16U  state;
    INT16U  recv_len;

    //���ͣ�����Ӧ����Ҫһ���ź���????
    volatile INT16U  drv_send_len;
    INT8U   *drv_send_data;
    INT8U   *drv_send_state;

    INT8U    recv_buffer[SIZE_OF_RS232_RECV_BUFFER];
}objDrvChannel;









#endif /* RS_232_H_ */
