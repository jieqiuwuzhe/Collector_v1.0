/******************************************************************************
 * Copyright (C), 2016-2017, www.topscomm.com
 *
 * 文件名：     data_type.h
 * 内容简述：数据类型定义
 *
 * 文件历史:
 * 版本号             日期                作者             说明
 * v0.1          2016.7.28         Root           创建文件
 ******************************************************************************/
#ifndef DATA_TYPE_H_
#define DATA_TYPE_H_

#ifdef	__cplusplus
extern "C" {
#endif

typedef unsigned char           BOOLEAN;
typedef unsigned char           INT8U;                    /* Unsigned  8 bit quantity                           */
typedef signed   char             INT8S;                    /* Signed    8 bit quantity                           */
typedef unsigned short         INT16U;                   /* Unsigned 16 bit quantity                           */
typedef signed   short           INT16S;                   /* Signed   16 bit quantity                           */
typedef unsigned int              INT32U;                   /* Unsigned 32 bit quantity                           */
typedef signed   int                INT32S;                   /* Signed   32 bit quantity                           */
typedef unsigned long long   INT64U;
typedef float                          FP32;                     /* Single precision floating point                    */
typedef double                       FP64;                     /* Double precision floating point                    */

#ifndef TRUE
#define TRUE  0x01
#endif

#ifndef FALSE
#define FALSE 0x00
#endif

#ifndef PIN_HIGH
#define PIN_HIGH                1      //高电平
#endif
#ifndef PIN_LOW
#define PIN_LOW                 0      //低电平
#endif

#ifndef NULL
 #define NULL   0x00
#endif

#endif
