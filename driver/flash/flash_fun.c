#include "flash_def.h"
#include "flash_fun.h"
#include "em_gpio.h"

#define    TIME_OUT_LOOP	100000

//
//    准备使用SPI FLASH
//
void  spi_open_flash(void)
{
        SPI_D2_INPUT;//PD6-INPUT-WP引脚设置为输入
        SPI_D3_INPUT;//PD7-INPUT-SO3引脚设置为输入

        SPISI_INPUT; //MCU-SI引脚设置为输入
        SPISO_OUTPUT;//MCU-SO引脚设置为输出
        SPISCK_OUTPUT;//PG0-OUTPUT-SCK引脚设置为输出
        SPICS_FLASH_OUTPUT;  //CS引脚设置为输出
        SPICS_FLASH_LAT_HIGH;//CS拉高，关闭Flash

        SPISCK_LAT_HIGH;      //SCK拉高

        SPICS_FLASH_LAT_LOW;//CS引脚拉低选中
}

// 结束使用SPI FLASH
void  spi_close_flash(void)
{
        SPICS_FLASH_OUTPUT;//CS引脚输出
        SPICS_FLASH_LAT_HIGH;//CS引脚拉高关闭

        SPI_D0_INPUT; //退出时默认四线放置在输入模式
        SPI_D1_INPUT;
        SPI_D2_INPUT;
        SPI_D3_INPUT;
        //SPI_D3_OUTPUT;
        //SPI_D3_HIGH;
}
/********************************************
 * 这两个函数用来在spi传输完地址后进行四线切换
 * ******************************************/
void enter_quad(void)
{
	   SPI_D0_INPUT;
	   SPI_D1_INPUT;
	   SPI_D2_INPUT;
	   SPI_D3_INPUT;
}

void exit_quad(void)
{
	 SPICS_FLASH_OUTPUT;//CS引脚输出
	 SPICS_FLASH_LAT_HIGH;//CS引脚拉高关闭
}
/***********************************************/
//模拟SPI写字节函数
void spi_writebyte(unsigned char data)
{
        //BIT7
        SPISCK_LAT_LOW;
        if (data&0x80)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();

        //BIT6
        SPISCK_LAT_LOW;
        if (data&0x40)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();

        //BIT5
        SPISCK_LAT_LOW;
        if (data&0x20)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();

        //BIT4
        SPISCK_LAT_LOW;
        if (data&0x10)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();


        //BIT3
        SPISCK_LAT_LOW;
        if (data&0x08)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();


        //BIT2
        SPISCK_LAT_LOW;
        if (data&0x04)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();

        //BIT1
        SPISCK_LAT_LOW;
        if (data&0x02)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();

        //BIT0
        SPISCK_LAT_LOW;
        if (data&0x01)
        {
              SPISO_LAT_HIGH;
        }
        else
        {
              SPISO_LAT_LOW;
              SPISO_LAT_LOW;
        }
        Nop();
        SPISCK_LAT_HIGH;
        Nop();
}

//输出数据在下降沿
//调用后，保持SCK为高电平
//代码罗列，提高访问速度
//模拟SPI读字节函数
unsigned char spi_readbyte(void)
{

    unsigned char ch;

     ch=0;

     //-----BIT7
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x80;
     }
     //-----BIT6
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x40;
     }
     //-----BIT5
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x20;
     }
     //-----BIT4
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x10;
     }
     //-----BIT3
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x08;
     }
     //-----BIT2
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x04;
     }
     //-----BIT1
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x02;
     }
     //-----BIT0
     SPISCK_LAT_LOW;
     Nop();
     Nop();
     SPISCK_LAT_HIGH;
     if (SPISI)
     {
        ch |= 0x01;
     }
     return ch;
}

/*+++
   功能： Dummy Cycle
---*/
void spi_read_dummy(unsigned char count)
{
   while(count > 0)
   {
       SPISCK_LAT_LOW;
       count--;
       SPISCK_LAT_HIGH;
   }
}

/************
 * 4IO读字节
 ***********/
unsigned char  quad_readbyte(void)
{
	unsigned char ch;

    ch=0;

    //-----D4,D5,D6,D7
    SPISCK_LAT_LOW;
    Nop();
    Nop();
    SPISCK_LAT_HIGH;

    if (SPI_D0)    ch |= 0x10;
    if (SPI_D1)    ch |= 0x20;
    if (SPI_D2)    ch |= 0x40;
    if (SPI_D3)    ch |= 0x80;


    //-----D0,D1,D2,D3
    SPISCK_LAT_LOW;
    Nop();
    Nop();
    SPISCK_LAT_HIGH;


    if (SPI_D0)    ch |= 0x01;
    if (SPI_D1)    ch |= 0x02;
    if (SPI_D2)    ch |= 0x04;
    if (SPI_D3)    ch |= 0x08;



    return ch;
}

/************
 * 4IO写字节
 ***********/
void  quad_writebyte(unsigned char data)
{
	//D4,D5,D6,D7
	SPISCK_LAT_LOW;
	(data&0x10) ? SPI_D0_HIGH : SPI_D0_LOW;
	(data&0x20) ? SPI_D1_HIGH : SPI_D1_LOW;
	(data&0x40) ? SPI_D2_HIGH : SPI_D2_LOW;
	(data&0x80) ? SPI_D3_HIGH : SPI_D3_LOW;
	SPISCK_LAT_HIGH;
	Nop();

	//D0,D1,D2,D3
	SPISCK_LAT_LOW;
	(data&0x01) ? SPI_D0_HIGH : SPI_D0_LOW;
	(data&0x02) ? SPI_D1_HIGH : SPI_D1_LOW;
	(data&0x04) ? SPI_D2_HIGH : SPI_D2_LOW;
	(data&0x08) ? SPI_D3_HIGH : SPI_D3_LOW;
	SPISCK_LAT_HIGH;
}









//SPI flash初始化
void MX25L256_FLASH_INIT(void)
{
	unsigned char idcode[3]={0};

	//SPI控制器初始化
	spi_close_flash();

	//芯片软复位
	MX25_MEM_RST();

	//设置状态寄存器
	MX25_WRSR(0);

	//设置4地址访问模式
	SET_4B_MODE(1);

	//读取ID号
	MX25_RDID(idcode);

}

//判断FLASH是否就绪 1-就绪可以写操作 0-写忙
unsigned char IS_FLASH_READY(void)
{
	return (((MX25_RDSR()&WIP)==0)?1:0);
}

//写使能判断 1-写使能 0-写禁止
unsigned char MX25_WR_ENABLE(void)
{
	unsigned int timeout = 0;

	do{
		spi_open_flash();
		spi_writebyte(MX25_CMD_WREN);
		spi_close_flash();

		if(++timeout>TIME_OUT_LOOP)
			return 0;

	}while((MX25_RDSR()&WEL)==0);

	return 1;
}

//设置写禁止命令
void MX25_WR_DISABLE(void)
{
	//发送写使能命令
	spi_open_flash();
	spi_writebyte(MX25_CMD_WRDI);
	spi_close_flash();
}

//等待写完成操作 1-成功 0-错误
unsigned char MX25_WR_COMPLETE(void)
{
	unsigned int timeout = 0;

	while((MX25_RDSR()&WIP))
	{
		if(++timeout>TIME_OUT_LOOP)
			return 0;
	}
	return 1;
}
//芯片软件复位
void MX25_MEM_RST(void)
{
	spi_open_flash();
	spi_writebyte(MX25_CMD_RSTEN);
	spi_close_flash();

	spi_open_flash();
	spi_writebyte(MX25_CMD_RST);
	spi_close_flash();

	if(IS_FLASH_READY())
		MX25_WR_COMPLETE();
}

//读取ID号
void MX25_RDID(unsigned char *pdata)
{
	unsigned char i;
	spi_open_flash();
	spi_writebyte(MX25_CMD_RDID);
	for(i=0;i<3;i++)
	{
        pdata[i]=spi_readbyte();
	}
  	spi_close_flash();
}

//读取状态寄存器
unsigned char MX25_RDSR(void)
{
	unsigned char status = 0;

	spi_open_flash();
	spi_writebyte(MX25_CMD_RDSR);
    status=spi_readbyte();
  	spi_close_flash();
	return status;
}

//写状态寄存器
void MX25_WRSR(unsigned char statval)
{
	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_WRSR);
		spi_writebyte(statval);
	  	spi_close_flash();
		MX25_WR_COMPLETE();//等待写完成
	}
}

//使能/除能4字节地址模式
void SET_4B_MODE(unsigned char enable)
{
	spi_open_flash();
	spi_writebyte((enable?MX25_CMD_EN4B: MX25_CMD_EX4B));
	spi_close_flash();
}

//扇区擦除命令(4字节地址模式)sector_addr:0-8191,每sector4k字节
void MX25_SECTOR_ERASE_4B(unsigned short sector_addr)
{
	unsigned int addr = (sector_addr << 12);

	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_SE);
		spi_writebyte((addr>>24)&0xff);
		spi_writebyte((addr>>16)&0xff);
		spi_writebyte((addr>> 8)&0xff);
		spi_writebyte((addr>> 0)&0xff);
		spi_close_flash();
		MX25_WR_COMPLETE();
	}
}
//32KB块擦除命令(4字节地址模式)b32k_addr:0-1023
void MX25_B32K_ERASE_4B(unsigned short b32k_addr)
{
	unsigned int addr = (b32k_addr<<15);

	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_BE32K);//
		spi_writebyte((addr>>24)&0xff);
		spi_writebyte((addr>>16)&0xff);
		spi_writebyte((addr>> 8)&0xff);
		spi_writebyte((addr>> 0)&0xff);
		spi_close_flash();
		MX25_WR_COMPLETE();
	}
}
//64KB块擦除命令(4字节地址模式)b64k_addr:0-511
void MX25_B64K_ERASE_4B(unsigned short b64k_addr)
{
	unsigned int addr = (b64k_addr<<16);

	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_BE);
		spi_writebyte((addr>>24)&0xff);
		spi_writebyte((addr>>16)&0xff);
		spi_writebyte((addr>> 8)&0xff);
		spi_writebyte((addr>> 0)&0xff);
		spi_close_flash();
		MX25_WR_COMPLETE();
	}
}

//整片擦除命令
void MX25_CHIP_ERASE(void)
{
	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_CE);
		spi_close_flash();
		MX25_WR_COMPLETE();
	}
}

//读字节数据(4字节地址模式)
void MX25_BYTE_READ4B(unsigned int addr,unsigned char *pbuf, unsigned int length)
{
	unsigned int i=0;

	spi_open_flash();
	spi_writebyte(MX25_CMD_READ);//MX25_CMD_PP4B
	spi_writebyte(addr>>24);
	spi_writebyte(addr>>16);
	spi_writebyte(addr>> 8);
	spi_writebyte(addr>> 0);
	for(i=0; i<length; i++)
	{
		pbuf[i] = spi_readbyte();
	}
	spi_close_flash();
}


//写字节数据(4字节地址模式)
void MX25_BYTE_PP4B(unsigned int addr,unsigned char *pbuf, unsigned int length)
{
	unsigned int i=0;

	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_PP);//MX25_CMD_PP4B
		spi_writebyte(addr>>24);
		spi_writebyte(addr>>16);
		spi_writebyte(addr>> 8);
		spi_writebyte(addr>> 0);

		for(i=0; i<length; i++)
		{
			spi_writebyte(pbuf[i]);
		}
		spi_close_flash();
		MX25_WR_COMPLETE();
	}
}



/*+++
  功能：等待设备空闲
---*/
void   flash_waitidle(void)
{
    INT8U status;

    do
    {
       status = MX25_RDSR();
    }while(status & 0x01);

    while(!(status & 0x40) ) //QE Check
    {
        spi_open_flash();
        spi_writebyte(0x06);   //WREN
        spi_close_flash();

        spi_open_flash();
        spi_writebyte(0x01);   //WRSR
        spi_writebyte(0x40);   //QE 0x40
        spi_close_flash();

        status = MX25_RDSR();
    }
}



//4IO下读字节数据(4字节地址模式)
void MX25_QUAD_BYTE_READ4B(unsigned int addr,unsigned char *pbuf, unsigned int length)
{
	unsigned int i=0;

	flash_waitidle();

	spi_open_flash();
	spi_writebyte(MX25_CMD_QREAD);//QREAD (1In/4 Out fast read)
	spi_writebyte(addr>>24);
	spi_writebyte(addr>>16);
	spi_writebyte(addr>> 8);
	spi_writebyte(addr>> 0);

	SPI_D0_INPUT;
	SPI_D1_INPUT;

	spi_read_dummy(8);
	for(i=0; i<length; i++)
	{
		pbuf[i] = quad_readbyte();
	}
	spi_close_flash();
}

//4IO下写字节数据(4字节地址模式)
void MX25_QUAD_BYTE_PP4B(unsigned int addr,unsigned char *pbuf, unsigned int length)
{
	unsigned int i=0;

	flash_waitidle();

	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_4PP);//MX25_CMD_PP4B
		SPI_D1_OUTPUT;
		SPI_D2_OUTPUT;
		SPI_D3_OUTPUT;
		SPI_D0_OUTPUT;
		quad_writebyte(addr>>24);
		quad_writebyte(addr>>16);
		quad_writebyte(addr>> 8);
		quad_writebyte(addr>> 0);

		for(i=0; i<length; i++)
		{
			quad_writebyte(pbuf[i]);
		}
		spi_close_flash();
		flash_waitidle();
		MX25_WR_COMPLETE();
	}
}
