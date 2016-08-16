
#include "../../../../Header Files/app_plat/bsp.h"

#define  R8025T_SLAVE_ADDRESS  0b01100100


/***************************************************************
 * 8025T从寄存器读数据驱动函数
 **************************************************************/
//0.95s内完成
uint8_t drv_R8025T_read(uint8_t addr, uint8_t* data, uint8_t len)
{
	uint8_t  result = 0;
	uint8_t  idx;
	uint8_t  try_count = 0;
	uint32_t star_tick;

	/* Transfer structure */
	  I2C_TransferSeq_TypeDef i2cTransfer;//

	  /* Initializing I2C transfer */
	  i2cTransfer.addr          = R8025T_SLAVE_ADDRESS;
	  i2cTransfer.flags         = I2C_FLAG_WRITE_READ;//I2C_FLAG_WRITE_READ - data written from buf[0].data and read into buf[1].data
	  i2cTransfer.buf[0].data   = (&addr);
	  i2cTransfer.buf[0].len    = 1;
	  i2cTransfer.buf[1].data   = data;
	  i2cTransfer.buf[1].len    = len;
	  I2C_TransferInit(I2C0, &i2cTransfer);

	  /* Sending data */
	  while (I2C_Transfer(I2C0) == i2cTransferInProgress){;}

	  result = (sizeof(data)/sizeof(uint8_t));

	  return result;
}


/**********************************************************************
 * 8025T向寄存器写数据驱动函数
 **********************************************************************/
uint8_t drv_R8025T_write(uint8_t addr, uint8_t* data, uint8_t len)
{
	bool     result = false;
	uint8_t  idx;
	uint8_t  try_count;
	uint32_t star_tick;

	/* Transfer structure */
	  I2C_TransferSeq_TypeDef i2cTransfer;//

	  /* Initializing I2C transfer */
	  i2cTransfer.addr          = R8025T_SLAVE_ADDRESS;
	  i2cTransfer.flags         = I2C_FLAG_WRITE_WRITE;
	  i2cTransfer.buf[0].data   = (&addr);
	  i2cTransfer.buf[0].len    = 1;
	  i2cTransfer.buf[1].data   = data;
	  i2cTransfer.buf[1].len    = len;
	  I2C_TransferInit(I2C0, &i2cTransfer);

	  /* Sending data */
	  while (I2C_Transfer(I2C0) == i2cTransferInProgress){;}

	  return 0;
}

/**********************************************************
 * 8025T芯片初始化
 **********************************************************/
void drv_R8025T_init(void)
{
    uint8_t data[32];
    uint8_t try_count=0;
    uint8_t update_flag;

    drv_R8025T_read(0,data,32);

    if(data[0x0E]&0x02)
    {
    	//上电默认处理
        data[0] = 0x00;//秒
        data[1] = 0x00;//分
        data[2] = 0x00;//时
        data[3] = 0x10;//星期
        data[4] = 0x01;//日
        data[5] = 0x01;//月
        data[6] = 0x15;//年
        data[7] = 0x00;
        drv_R8025T_write(0x00,data,8);

        data[0x0D] = 0x00;
        data[0x0E] = 0x00;
        data[0x0F] = 0x60;
        drv_R8025T_write(0x0D,&data[0x0D],3);
    }
    else
    {
        update_flag = false;
        if(data[0]>=0x60) update_flag = true;
        if(data[1]>=0x60) update_flag = true;
        if(data[2]>=0x24) update_flag = true;
        if(data[4]>=0x32) update_flag = true;
        if(data[5]>=0x13) update_flag = true;
        if(data[4]==0x00) update_flag = true;
        if(data[5]==0x00) update_flag = true;
        if(update_flag == true)
        {
            data[0] = 0x00; //秒
            data[1] = 0x00; //分
            data[2] = 0x00; //时
            data[3] = 0x10; //星期
            data[4] = 0x01; //日
            data[5] = 0x01; //月
            data[6] = 0x15; //年
            data[7] = 0x00;
            drv_R8025T_write(0x00, data, 8);
        }
        update_flag = false;
        //检查寄存器的值是否正确
        if(data[0x0F] != 0x60)
        {
            data[0x0F] = 0x60;//补偿间隔2s  UIE TIE AIE RESET为0
            update_flag = true;
        }

        if(data[0x0E] != 0x00)
        {
            data[0x0E] = 0x00;  //启动温度补偿  UF TF AF为0
            update_flag = true;
        }

        if(data[0x0D] != 0x00)
        {
            data[0x0D] = 0x00;
            update_flag = true;
        }
        if(update_flag == true)
        {
            drv_R8025T_write(0x0D,&data[0x0D],3);
        }
    }
}

/**********************************************************
 * 8025T数据读取检查
 **********************************************************/

uint8_t drv_R8025T_check_read(uint8_t* buffer)
{
    uint8_t drv_R8025T_read(uint8_t addr,uint8_t* data,uint8_t len);
    extern INT16S  compare_string(INT8U *str1,INT8U *str2,INT16U len);
    extern bool is_valid_bcd(INT8U *bcd,INT8U bytes);

    uint8_t data[32];


     while(1)
    {
    	 drv_R8025T_read(0,data,32);

            if(compare_string(data,data+16,16)!=0)//读到不同，需要重新读取
            {
                continue;
            }
            //检查数据是否合法，不合法，重新读取
            if((is_valid_bcd(data,3)==false) || (is_valid_bcd(data+4,3)==false))
            {
                continue;
            }
            if(data[0]>=0x60) continue;
            if(data[1]>=0x60) continue;
            if(data[2]>=0x24) continue;
            if(data[4]>=0x32) continue;
            if(data[5]>=0x13) continue;
            if(data[4]==0x00) continue;
            if(data[5]==0x00) continue;
            mem_cpy(buffer,data,16);
            return 16;


    }
    return 0;
}


/******************************************************************
 * 获取RTC当前时间
 *****************************************************************/
void get_rtc_time(INT8U * datetime)
{
	uint8_t rtc[16];
		INT8U write_rtc[16];
		INT8U idx;
		INT8U data_len;

		data_len = (drv_R8025T_check_read(rtc));

		if(data_len == 16)
	  {
		if(rtc[0x0E]&0x02)
		{
			rtc[0x0D] = 0x00;
			rtc[0x0E] = 0x00;
		    rtc[0x0F] = 0x60;
		    drv_R8025T_write(0x0D,&rtc[0x0D],3);//正常运行读取时发现VLF位置1，则需要立即清除掉

		    DateTime2RTCBCD(datetime,rtc);
		    //写入8025T的星期是按位标识
		    mem_cpy(write_rtc,rtc,16);
		    write_rtc[3] = BCD2byte(write_rtc[3]);
		    if(write_rtc[3]==7)
		    {
		    	write_rtc[3] = 0;
		    }

		    write_rtc[3] = 1<<write_rtc[3];
		    drv_R8025T_write(0,write_rtc,7);//当VLF置1后，将当期时间写入时钟芯片
		}

		//rtc[3]是星期，8025T是按位标识的
		for(idx=0;idx<7;idx++)
		{
			if(rtc[3]&(0x01<<idx))
		    {
				break;
		    }
		}

		if(idx==0)
		{
			idx = 7;
		}
		rtc[3] = byte2BCD(idx);
		RTCBCD2DateTime(datetime,rtc);
	  }
}

/***********************************************************************
 * 设置8025T当前时间
 **********************************************************************/
void set_rtc_time(INT8U *new_time)
{
	 INT8U rtc[8];
	 INT8U write_rtc[8];

	 DateTime2RTCBCD(new_time,rtc);//time转换成bcd


	 //写入8025T的星期是按位标识
	    mem_cpy(write_rtc,rtc,8);
	    write_rtc[3] = BCD2byte(write_rtc[3]);
	    if(write_rtc[3]==7)
	    {
	        write_rtc[3] = 0;
	    }
	    write_rtc[3] = 1<<write_rtc[3];
	    drv_R8025T_write(0,write_rtc,7);
}
/*********************************************************************/
