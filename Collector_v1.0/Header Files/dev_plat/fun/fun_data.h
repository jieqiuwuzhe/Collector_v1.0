/*
 * fun_data.h
 *
 *  Created on: 2016-8-3
 *      Author: Root-Wang
 */

#ifndef FUN_DATA_H_
#define FUN_DATA_H_

INT8U BCD2byte(INT8U bcd);
INT8U byte2BCD(INT8U bVal);
void RTCBCD2DateTime(INT8U *dt,INT8U *nValue);
void  DateTime2RTCBCD(INT8U *dt,INT8U *nValue);
bool is_valid_bcd(INT8U *bcd,INT8U bytes);
INT16U   str2uint(INT8S *str);
INT16U   str2uint_gps(INT8S *str, INT8U n);
unsigned char Float2Char(float value, unsigned char *array);

#endif /* FUN_DATA_H_ */
