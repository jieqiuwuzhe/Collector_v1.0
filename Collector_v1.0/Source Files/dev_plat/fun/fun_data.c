/*
 * fun_data.c
 *
 *  Created on: 2016-8-3
 *      Author: Root-Wang
 *      数据处理函数
 */

#include "../../../Header Files/app_plat/bsp.h"

#define YEAR		5       //年，不带世纪
#define MONTH		4       //月
#define DAY  		3       //日
#define HOUR		2       //时
#define MINUTE		1       //分
#define SECOND		0       //秒
#define WEEKDAY     9       //星期


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
   功能：把字符串转换为整数
   参数：char *str 字符数据
   描述：字符数据前面可以有空格，数字必须连续，之后可以有空格或结束
---*/
INT16U   str2uint(INT8S *str)
{
    unsigned int val;

    val= 0;

    //首先，剔出字符数字前面的空格
    while(*str!=0)
    {
       if(*str==' ')
            str++;
       else
            break;
    }

    //然后，对字符数据从高位到低位依次进行转换，十进制，碰到第一个非数字结束
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
   功能：把字符串转换为整数,加上个数控制（GPS提取时间用）
   参数：char *str 字符数据
           n 转换个数
   描述：字符数据前面可以有空格，数字必须连续，之后可以有空格或结束
---*/
INT16U   str2uint_gps(INT8S *str, INT8U n)
{
    unsigned int val,i;

    val= 0;
    i = 1;//转换个数控制，初值设成1，保证和n对应起来

    //首先，剔出字符数字前面的空格
    while(*str!=0)
    {
       if(*str==' ')
            str++;
       else
            break;
    }

    //然后，对字符数据从高位到低位依次进行转换，十进制，碰到第一个非数字结束
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


//float转char型
unsigned char Float2Char(float value, unsigned char *array)
{
	uint8_t IntegerPart;
	float DecimalPart;
	uint8_t i = 0;
	uint8_t j = 0;
	char temp;
	//分离整数和小数
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
	    //处理整数部分
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
