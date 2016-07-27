#include "flash_def.h"
#include "flash_fun.h"
#include "em_gpio.h"

#define    TIME_OUT_LOOP	100000

//
//    ׼��ʹ��SPI FLASH
//
void  spi_open_flash(void)
{
        SPI_D2_INPUT;//PD6-INPUT-WP��������Ϊ����
        SPI_D3_INPUT;//PD7-INPUT-SO3��������Ϊ����

        SPISI_INPUT; //MCU-SI��������Ϊ����
        SPISO_OUTPUT;//MCU-SO��������Ϊ���
        SPISCK_OUTPUT;//PG0-OUTPUT-SCK��������Ϊ���
        SPICS_FLASH_OUTPUT;  //CS��������Ϊ���
        SPICS_FLASH_LAT_HIGH;//CS���ߣ��ر�Flash

        SPISCK_LAT_HIGH;      //SCK����

        SPICS_FLASH_LAT_LOW;//CS��������ѡ��
}

// ����ʹ��SPI FLASH
void  spi_close_flash(void)
{
        SPICS_FLASH_OUTPUT;//CS�������
        SPICS_FLASH_LAT_HIGH;//CS�������߹ر�

        SPI_D0_INPUT; //�˳�ʱĬ�����߷���������ģʽ
        SPI_D1_INPUT;
        SPI_D2_INPUT;
        SPI_D3_INPUT;
        //SPI_D3_OUTPUT;
        //SPI_D3_HIGH;
}
/********************************************
 * ����������������spi�������ַ����������л�
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
	 SPICS_FLASH_OUTPUT;//CS�������
	 SPICS_FLASH_LAT_HIGH;//CS�������߹ر�
}
/***********************************************/
//ģ��SPIд�ֽں���
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

//����������½���
//���ú󣬱���SCKΪ�ߵ�ƽ
//�������У���߷����ٶ�
//ģ��SPI���ֽں���
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
   ���ܣ� Dummy Cycle
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
 * 4IO���ֽ�
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
 * 4IOд�ֽ�
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









//SPI flash��ʼ��
void MX25L256_FLASH_INIT(void)
{
	unsigned char idcode[3]={0};

	//SPI��������ʼ��
	spi_close_flash();

	//оƬ��λ
	MX25_MEM_RST();

	//����״̬�Ĵ���
	MX25_WRSR(0);

	//����4��ַ����ģʽ
	SET_4B_MODE(1);

	//��ȡID��
	MX25_RDID(idcode);

}

//�ж�FLASH�Ƿ���� 1-��������д���� 0-дæ
unsigned char IS_FLASH_READY(void)
{
	return (((MX25_RDSR()&WIP)==0)?1:0);
}

//дʹ���ж� 1-дʹ�� 0-д��ֹ
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

//����д��ֹ����
void MX25_WR_DISABLE(void)
{
	//����дʹ������
	spi_open_flash();
	spi_writebyte(MX25_CMD_WRDI);
	spi_close_flash();
}

//�ȴ�д��ɲ��� 1-�ɹ� 0-����
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
//оƬ�����λ
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

//��ȡID��
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

//��ȡ״̬�Ĵ���
unsigned char MX25_RDSR(void)
{
	unsigned char status = 0;

	spi_open_flash();
	spi_writebyte(MX25_CMD_RDSR);
    status=spi_readbyte();
  	spi_close_flash();
	return status;
}

//д״̬�Ĵ���
void MX25_WRSR(unsigned char statval)
{
	if(IS_FLASH_READY())
	{
		MX25_WR_ENABLE();
		spi_open_flash();
		spi_writebyte(MX25_CMD_WRSR);
		spi_writebyte(statval);
	  	spi_close_flash();
		MX25_WR_COMPLETE();//�ȴ�д���
	}
}

//ʹ��/����4�ֽڵ�ַģʽ
void SET_4B_MODE(unsigned char enable)
{
	spi_open_flash();
	spi_writebyte((enable?MX25_CMD_EN4B: MX25_CMD_EX4B));
	spi_close_flash();
}

//������������(4�ֽڵ�ַģʽ)sector_addr:0-8191,ÿsector4k�ֽ�
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
//32KB���������(4�ֽڵ�ַģʽ)b32k_addr:0-1023
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
//64KB���������(4�ֽڵ�ַģʽ)b64k_addr:0-511
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

//��Ƭ��������
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

//���ֽ�����(4�ֽڵ�ַģʽ)
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


//д�ֽ�����(4�ֽڵ�ַģʽ)
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
  ���ܣ��ȴ��豸����
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



//4IO�¶��ֽ�����(4�ֽڵ�ַģʽ)
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

//4IO��д�ֽ�����(4�ֽڵ�ַģʽ)
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
