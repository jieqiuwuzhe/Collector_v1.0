/*
 * fun_str.h
 *
 *  Created on: 2016-7-28
 *      Author: Root-Wang
 */

#ifndef FUN_STR_H_
#define FUN_STR_H_

#include "../../Header Files/app_plat/bsp.h"

INT16S  compare_string(INT8U *str1,INT8U *str2,INT16U len);
INT16S  compare_string_reverse(INT8U *str1,INT8U *str2,INT16U len);
void    mem_cpy_reverse(INT8U *dst,INT8U *src,INT16U len);
void    mem_cpy(INT8U *dst,INT8U *src,INT16U len);
void    buffer_reverse(INT8U *dst,INT16U len);
void    trimspace(INT8U *str,INT16U size);
INT16S  str_find_again(INT8U *buffer,INT16U buflen,INT8U *target,INT16U targetlen,INT8U againcount);

#endif /* FUN_STR_H_ */
