/*
 * fun_data.c
 *
 *  Created on: 2016-8-3
 *      Author: Root-Wang
 *      ���ݴ�����
 */

#include "../../../Header Files/app_plat/bsp.h"

#define YEAR		5       //�꣬��������
#define MONTH		4       //��
#define DAY  		3       //��
#define HOUR		2       //ʱ
#define MINUTE		1       //��
#define SECOND		0       //��
#define WEEKDAY     9       //����


INT8U BCD2byte(INT8U bcd)
{
   return ((bcd>>4) & 0x000F) * 10 + ( bcd & 0x000F );
}
INT8U byte2BCD(INT8U bVal)
{
    INT8U ch;

    ch = ((bVal/10)<<4) + (bVal%10);

    return ch;
}
void RTCBCD2DateTime(INT8U *dt,INT8U *nValue)
{
     dt[SECOND] = BCD2byte(nValue[0]);
     dt[MINUTE] = BCD2byte(nValue[1]);
     dt[HOUR] =   BCD2byte(nValue[2]);
     dt[WEEKDAY] =BCD2byte(nValue[3]);
     dt[DAY] =    BCD2byte(nValue[4]);
     dt[MONTH] =  BCD2byte(nValue[5]);
     dt[YEAR] =   BCD2byte(nValue[6]);
}
void  DateTime2RTCBCD(INT8U *dt,INT8U *nValue)
{
     nValue[0]=byte2BCD(dt[SECOND]);
     nValue[1]=byte2BCD(dt[MINUTE]);
     nValue[2]=byte2BCD(dt[HOUR]);
     nValue[3]=byte2BCD(dt[WEEKDAY]);
     nValue[4]=byte2BCD(dt[DAY]);
     nValue[5]=byte2BCD(dt[MONTH]);
     nValue[6]=byte2BCD(dt[YEAR]);
}

bool is_valid_bcd(INT8U *bcd,INT8U bytes)
{
   INT8U i;
   for(i=0;i<bytes;i++)
   {
      if((bcd[i] & 0x0F) > 0x09) return false;
      if((bcd[i] & 0xF0) > 0x90) return false;
   }
   return true;
}

/*+++
   ���ܣ����ַ���ת��Ϊ����
   ������char *str �ַ�����
   �������ַ�����ǰ������пո����ֱ���������֮������пո�����
---*/
INT16U   str2uint(INT8S *str)
{
    unsigned int val;

    val= 0;

    //���ȣ��޳��ַ�����ǰ��Ŀո�
    while(*str!=0)
    {
       if(*str==' ')
            str++;
       else
            break;
    }

    //Ȼ�󣬶��ַ����ݴӸ�λ����λ���ν���ת����ʮ���ƣ�������һ�������ֽ���
    while(*str!=0)
    {
        if( (*str>='0') && (*str<='9') )
        {
            val = val *10 + ((*str)-'0');
        }
        else
        {
           break;
        }
        str++;
    }
    return val;
}


/*+++
   ���ܣ����ַ���ת��Ϊ����,���ϸ������ƣ�GPS��ȡʱ���ã�
   ������char *str �ַ�����
           n ת������
   �������ַ�����ǰ������пո����ֱ���������֮������пո�����
---*/
INT16U   str2uint_gps(INT8S *str, INT8U n)
{
    unsigned int val,i;

    val= 0;
    i = 1;//ת���������ƣ���ֵ���1����֤��n��Ӧ����

    //���ȣ��޳��ַ�����ǰ��Ŀո�
    while(*str!=0)
    {
       if(*str==' ')
            str++;
       else
            break;
    }

    //Ȼ�󣬶��ַ����ݴӸ�λ����λ���ν���ת����ʮ���ƣ�������һ�������ֽ���
    while(*str!=0)
    {
        if( i <= n )
        {
            val = val *10 + ((*str)-'0');
        }
        else
        {
           break;
        }
        str++;
        i ++;
    }
    return val;
}


//floatתchar��
unsigned char Float2Char(float value, unsigned char *array)
{
	uint8_t IntegerPart;
	float DecimalPart;
	uint8_t i = 0;
	uint8_t j = 0;
	char temp;
	//����������С��
	if(value >= 1)
	{
	    IntegerPart = (uint8_t)value;
	    DecimalPart = value - IntegerPart;
	}
	else
	{
	    IntegerPart = 0;
	    DecimalPart = value - IntegerPart;
	}
	    //������������
	if(IntegerPart == 0)
	{
		array[0] = '0';
		array[1] = '.';
		i =1;
	}
	else
	{
		while(IntegerPart > 0)
		{
			array[i] = IntegerPart % 10 + '0';
			IntegerPart /= 10;
			i++;
		}
		i--;

	//fix the result
	for(j=0; j<i; j++)
	{
		temp = array[j];
		array[j] = array[i - j];
		array[i - j] = temp;
	}
	i++;
	array[i] = '.';
	}
	//convert the Decimalpart
	i++;
	array[i++] = (uint32_t)(DecimalPart * 10)%10 + '0';
	array[i++] = (uint32_t)(DecimalPart * 100)%10 + '0';
	array[i++] = (uint32_t)(DecimalPart * 1000)%10 + '0';
	array[i++] = (uint32_t)(DecimalPart * 10000)%10 + '0';
	array[i]  = '\0';
	 return i;
}
