/******************************************************************************
 * Copyright (C), 2016-2017, www.topscomm.com
 *
 * �ļ�����     fun_str.c
 * ���ݼ������ַ�������
 *
 * �ļ���ʷ:
 * �汾��             ����                ����             ˵��
 * v0.1    2016.7.28   Root    �����ļ�
 ******************************************************************************/

#include "../../Header Files/app_plat/bsp.h"

/******************************************************************************
 * �������� compare_string
 * ��     �룺 str1 : �ַ���1
 *         str2 : �ַ���2
 *         len  : �Ƚϳ���
 * ���أ�      -1: str1 < str2
           0: str1 = str2
           1: str1 > str2
 * ��     �ܣ� �ַ�����С�Ƚ�
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
 * �������� compare_string_reverse
 * ��     �룺 str1 : �ַ���1
 *         str2 : �ַ���2
 *         len  : �Ƚϳ���
 * ���أ�      -1: str1 < str2
            0: str1 = str2
            1: str1 > str2
 * ��     �ܣ� �Ƚ������ֽڴ��Ĵ�С,����Ƚ�
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
 * �������� mem_cpy
 * ��     �룺 dst  : ������ַ
 *         src  : �������ַ���
 *         len  : ��������
 * ��     �أ�  ��
 * ��     �ܣ� �����ַ���
 ****************************************************************************/
void mem_cpy(INT8U *dst,INT8U *src,INT16U len)
{
    INT16U idx;
    for(idx=0;idx<len;idx++)
    {
        dst[idx] = src[idx];
    }
}

//���򿽱��ַ���������ͬ�ϣ�
void mem_cpy_reverse(INT8U *dst,INT8U *src,INT16U len)
{
    INT16U idx;
    for(idx=0;idx<len;idx++)
    {
        dst[idx] = src[len-idx-1];
    }
}

//���򿽱��ַ���
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
//ȥ�ո���
void trimspace(INT8U *str,INT16U size)
{
    INT16U idx;
    //ȥǰ�ո�˼·Ϊ���ֿո��򽫺����ַ������ƶ�һ�£�,ֱ�������ǿո�Ϊֹ
    while(str[0]==' ')
    {
        for(idx=1;idx<size;idx++)
        {
            str[idx-1]=str[idx];
        	if(str[idx]=='\0')break;
        }
        str[idx-1]='\0';
    }
   //ȥ��ո�˼·Ϊ�Ӻ���ң����ֿո�������Ϊ'\0',ֱ�������ǿո�Ϊֹ
   idx=size;
   while(--idx)
   {
   	   if((str[idx]!='\0') && (str[idx]!=' ')) break;
       str[idx]='\0';
   }
}
/*+++
  ���ܣ� ����ָ���ַ���,֧�ֵڼ��γ���
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

