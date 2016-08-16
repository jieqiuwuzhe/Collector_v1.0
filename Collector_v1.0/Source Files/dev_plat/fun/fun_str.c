/******************************************************************************
 * Copyright (C), 2016-2017, www.topscomm.com
 *
 * 文件名：     fun_str.c
 * 内容简述：字符串操作
 *
 * 文件历史:
 * 版本号             日期                作者             说明
 * v0.1    2016.7.28   Root    创建文件
 ******************************************************************************/

#include "../../Header Files/app_plat/bsp.h"

/******************************************************************************
 * 函数名： compare_string
 * 输     入： str1 : 字符串1
 *         str2 : 字符串2
 *         len  : 比较长度
 * 返回：      -1: str1 < str2
           0: str1 = str2
           1: str1 > str2
 * 功     能： 字符串大小比较
 ****************************************************************************/
INT16S  compare_string(INT8U *str1,INT8U *str2,INT16U len)
{
    while(len > 0)
    {
        if(*str1 < *str2) return -1;
        if(*str1 > *str2) return 1;
        str1++;
        str2++;
        len--;
    }
    return 0;
}



/******************************************************************************
 * 函数名： compare_string_reverse
 * 输     入： str1 : 字符串1
 *         str2 : 字符串2
 *         len  : 比较长度
 * 返回：      -1: str1 < str2
            0: str1 = str2
            1: str1 > str2
 * 功     能： 比较两个字节串的大小,逆序比较
 ****************************************************************************/
INT16S  compare_string_reverse(INT8U *str1,INT8U *str2,INT16U len)
{
    INT16U idx;
    while(len > 0)
    {
        len--;
        if(str1[len] < str2[len]) return -1;
        if(str1[len] > str2[len]) return 1;
    }
    return 0;
}

/******************************************************************************
 * 函数名： mem_cpy
 * 输     入： dst  : 拷贝地址
 *         src  : 被拷贝字符串
 *         len  : 拷贝长度
 * 返     回：  无
 * 功     能： 拷贝字符串
 ****************************************************************************/
void mem_cpy(INT8U *dst,INT8U *src,INT16U len)
{
    INT16U idx;
    for(idx=0;idx<len;idx++)
    {
        dst[idx] = src[idx];
    }
}

//反向拷贝字符串（参数同上）
void mem_cpy_reverse(INT8U *dst,INT8U *src,INT16U len)
{
    INT16U idx;
    for(idx=0;idx<len;idx++)
    {
        dst[idx] = src[len-idx-1];
    }
}

//反向拷贝字符串
void buffer_reverse(INT8U *dst,INT16U len)
{
    INT16U idx,time;
	INT8U tmp;
	time = (INT16U)(len/2);
    for(idx=0;idx<time;idx++)
    {
       	tmp = dst[idx];
		dst[idx] = dst[len-idx-1];
		dst[len-idx-1] = tmp;
    }
}
//去空格函数
void trimspace(INT8U *str,INT16U size)
{
    INT16U idx;
    //去前空格，思路为发现空格则将后续字符向先移动一下，,直到遇到非空格为止
    while(str[0]==' ')
    {
        for(idx=1;idx<size;idx++)
        {
            str[idx-1]=str[idx];
        	if(str[idx]=='\0')break;
        }
        str[idx-1]='\0';
    }
   //去后空格，思路为从后查找，发现空格则将其置为'\0',直到遇到非空格为止
   idx=size;
   while(--idx)
   {
   	   if((str[idx]!='\0') && (str[idx]!=' ')) break;
       str[idx]='\0';
   }
}
/*+++
  功能： 查找指定字符窜,支持第几次出现
----*/
INT16S  str_find_again(INT8U *buffer,INT16U buflen,INT8U *target,INT16U targetlen,INT8U againcount)
{
    INT16U pos;
    INT16U idx;

    for(pos=0;pos<buflen;pos++)
    {
        for(idx=0;idx<targetlen;idx++)
        {
           if(target[idx]!=buffer[idx]) break;
        }
        if(idx>=targetlen)
        {
         	againcount--;
            if(againcount==0) return pos;
        }
        buffer++;
    }
    return -1;
}

