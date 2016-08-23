/******************************************************
 * Flash��غ궨��
 ******************************************************/

#define __EN_QUAD_MODE__


#define Nop()				__asm("nop")

/*** MX25 ����Ԥ����***/
//ID comands
#define    MX25_CMD_RDID      0x9F    //RDID (Read Identification)
#define    MX25_CMD_RES       0xAB    //RES (Read Electronic ID)
#define    MX25_CMD_REMS      0x90    //REMS (Read Electronic & Device ID)
#define    MX25_CMD_QPIID     0xAF    //QPIID (QPI ID Read)

//Register comands
#define    MX25_CMD_WRSR      0x01    //WRSR (Write Status Register)
#define    MX25_CMD_RDSR      0x05    //RDSR (Read Status Register)
#define    MX25_CMD_WRSCUR    0x2F    //WRSCUR (Write Security Register)
#define    MX25_CMD_RDSCUR    0x2B    //RDSCUR (Read Security Register)
#define    MX25_CMD_RDCR      0x15    //RDCR (Read Configuration Register)
#define    MX25_CMD_RDEAR     0xC8    //RDEAR (Read Extended Address Register)
#define    MX25_CMD_WREAR     0xC5    //WREAR (Write Extended Address Register)
#define    MX25_CMD_RDFBR     0x16    //RDFBR (read fast boot Register)
#define    MX25_CMD_WRFBR     0x17    //WRFBR (write fast boot Register)
#define    MX25_CMD_ESFBR     0x18    //ESFBR (erase fast boot Register)
#define    MX25_CMD_WRLR      0x2C    //WRLR (write lock Register)
#define    MX25_CMD_RDLR      0x2D    //RDLR (read lock Register)
#define    MX25_CMD_RDSPB     0xE2    //RDSPB (read SPB status)
#define    MX25_CMD_WRSPB     0xE3    //WRSPB (write SPB bit)
#define    MX25_CMD_ESSPB     0xE4    //ESSPB (erase all SPB status)
#define    MX25_CMD_SPBLK     0xA6    //SPBLK (SPB lock set)
#define    MX25_CMD_RDSPBLK   0xA7    //SPBLK (read SPB lock register)
#define    MX25_CMD_WRPASS    0x28    //WRPASS (write password Register)
#define    MX25_CMD_RDPASS    0x27    //RDPASS (read password Register)
#define    MX25_CMD_PASSULK   0x29    //RDPASS (password unlock)
#define    MX25_CMD_RDDPB     0xE0    //RDDPB (read DPB register)
#define    MX25_CMD_WRDPB     0xE1    //WRDPB (write DPB register)

//READ comands
#define    MX25_CMD_READ        0x03    //READ (1 x I/O)
#define    MX25_CMD_2READ       0xBB    //2READ (2 x I/O)
#define    MX25_CMD_4READ       0xEB    //4READ (4 x I/O)
#define    MX25_CMD_4READ_TOP   0xEA    //4READ (4 x I/O read from top 128Mb)
#define    MX25_CMD_FASTREAD    0x0B    //FAST READ (Fast read data)
#define    MX25_CMD_DREAD       0x3B    //DREAD (1In/2 Out fast read)
#define    MX25_CMD_QREAD       0x6B    //QREAD (1In/4 Out fast read)
#define    MX25_CMD_RDSFDP      0x5A    //RDSFDP (Read SFDP)


//Program comands
#define    MX25_CMD_WREN     0x06    //WREN (Write Enable)
#define    MX25_CMD_WRDI     0x04    //WRDI (Write Disable)
#define    MX25_CMD_PP       0x02    //PP (page program)
#define    MX25_CMD_4PP      0x38    //4PP (Quad page program)
#define    MX25_CMD_PP4B     0x12    //PP4B (page program with 4 byte address)
#define    MX25_CMD_4PP4B    0x3E    //4PP4B (Quad page program with 4 byte address)

//Erase comands
#define    MX25_CMD_SE       0x20    //SE (Sector Erase)
#define    MX25_CMD_BE32K    0x52    //BE32K (Block Erase 32kb)
#define    MX25_CMD_BE       0xD8    //BE (Block Erase)
#define    MX25_CMD_BE4B     0xDC    //BE4B (Block Erase with 4 byte address)
#define    MX25_CMD_CE       0x60    //CE (Chip Erase) hex code: 60 or C7
#define    MX25_CMD_SE4B     0x21    //SE (Sector Erase with 4 byte addr)
#define    MX25_CMD_BE32K4B  0x5C    //BE32K4B (Block Erase 32kb with 4 byte addr)

//Mode setting comands
#define    MX25_CMD_DP       0xB9    //DP (Deep Power Down)
#define    MX25_CMD_RDP      0xAB    //RDP (Release form Deep Power Down)
#define    MX25_CMD_ENSO     0xB1    //ENSO (Enter Secured OTP)
#define    MX25_CMD_EXSO     0xC1    //EXSO  (Exit Secured OTP)
#define    MX25_CMD_EQIO     0x35    //EQIO (Enable Quad I/O)
#define    MX25_CMD_WPSEL    0x68    //WPSEL (Enable block protect mode)
#ifdef SBL_CMD_0x77
#define    MX25_CMD_SBL      0x77    //SBL (Set Burst Length), new: 0x77
#else
#define    MX25_CMD_SBL      0xC0    //SBL (Set Burst Length), old: 0xC0
#endif
#define    MX25_CMD_EN4B     0xB7    //EN4B( Enter 4-byte Mode )
#define    MX25_CMD_EX4B     0xE9    //EX4B( Exit 4-byte Mode )

//Reset comands
#define    MX25_CMD_RSTEN     0x66    //RSTEN (Reset Enable)
#define    MX25_CMD_RST       0x99    //RST (Reset Memory)
#define    MX25_CMD_RSTQIO    0xF5    //RSTQIO (Reset Quad I/O)

//Security comands
#define    MX25_CMD_GBLK       0x7E    //GBLK (Gang Block Lock)
#define    MX25_CMD_GBULK      0x98    //GBULK (Gang Block Unlock)

//Suspend/Resume comands
#ifdef PGM_ERS_0xB0
#define    MX25_CMD_PGM_ERS_S    0xB0    //PGM/ERS Suspend (Suspends Program/Erase) old: 0xB0
#define    MX25_CMD_PGM_ERS_R    0x30    //PGM/ERS Erase (Resumes Program/Erase) old: 0x30
#else
#define    MX25_CMD_PGM_ERS_S    0x75    //PGM/ERS Suspend (Suspends Program/Erase) old: 0xB0
#define    MX25_CMD_PGM_ERS_R    0x7A    //PGM/ERS Erase (Resumes Program/Erase) old: 0x30
#endif

#define    MX25_CMD_NOP          0x00    //NOP (No Operation)

//״̬�Ĵ���
#define WIP		(1<<0)//д������ 1-д������ 0-��д����
#define WEL		(1<<1)//дʹ�ܱ�� 1-дʹ��   0-д��ֹ
#define BP0		(1<<2)//�鱣������
#define BP1		(1<<3)//�鱣������
#define BP2		(1<<4)//�鱣������
#define BP3		(1<<5)//�鱣������
#define QE		(1<<6)//4�߲���ʹ��
#define SRWD	(1<<7)//״̬�Ĵ���д���� 1-д��ֹ 0-дʹ��

//���üĴ���
#define ODS0	(1<<0)//������������
#define ODS1	(1<<1)//������������
#define ODS2	(1<<2)//������������
#define TB		(1<<3)//0-�������򱣻� 1-�ײ����򱣻�
#define RESERVE	(1<<4)//��
#define MOD_4B	(1<<5)//��ַģʽ 0->3��ַģʽ, 1->4��ַģʽ
#define DC0		(1<<6)//dummy clock cycles����
#define DC1		(1<<7)//dummy clock cycles����

//Reset comands
#define    MX25_CMD_RSTEN     0x66    //RSTEN (Reset Enable)
#define    MX25_CMD_RST       0x99    //RST (Reset Memory)
#define    MX25_CMD_RSTQIO    0xF5    //RSTQIO (Reset Quad I/O)

//FLASH_RST
#define FLASH_RST_LOW     GPIO_PinOutClear(gpioPortD, 3)
#define FLASH_RST_HIGH    GPIO_PinOutSet(gpioPortD, 3)
#define FLASH_RST_INPUT   GPIO_PinModeSet(gpioPortD, 3, gpioModeInput, 0)
#define FLASH_RST_OUTPUT  GPIO_PinModeSet(gpioPortD, 3, gpioModePushPull, 0)

//Flash-CS
#define SPICS_FLASH_LOW         GPIO_PinOutClear(gpioPortD, 2)
#define SPICS_FLASH_HIGH        GPIO_PinOutSet(gpioPortD, 2)
#define SPICS_FLASH_LAT_LOW     GPIO_PinOutClear(gpioPortD, 2)
#define SPICS_FLASH_LAT_HIGH    GPIO_PinOutSet(gpioPortD, 2)
#define SPICS_FLASH_INPUT       GPIO_PinModeSet(gpioPortD, 2, gpioModeInput, 0)
#define SPICS_FLASH_OUTPUT      GPIO_PinModeSet(gpioPortD, 2, gpioModePushPull, 0)

//Flash-SCK
#define SPISCK_LAT_LOW     GPIO_PinOutClear(gpioPortD, 5)
#define SPISCK_LAT_HIGH    GPIO_PinOutSet(gpioPortD, 5)
#define SPISCK_OUTPUT      GPIO_PinModeSet(gpioPortD, 5, gpioModePushPull, 0)
#define SPISCK_INPUT       GPIO_PinModeSet(gpioPortD, 5, gpioModeInput, 0)

//MCU-SO(FLASH��SI�ܽ�)
#define SPISO             GPIO_PinOutGet(gpioPortD, 6)
#define SPISO_LAT_LOW     GPIO_PinOutClear(gpioPortD, 6)
#define SPISO_LAT_HIGH    GPIO_PinOutSet(gpioPortD, 6)
#define SPISO_INPUT       GPIO_PinModeSet(gpioPortD, 6, gpioModeInput, 0)
#define SPISO_OUTPUT      GPIO_PinModeSet(gpioPortD, 6, gpioModePushPull, 0)

//MCU-SI(FLASH��SO�ܽ�)
#define SPISI             GPIO_PinInGet(gpioPortD, 1)//����Ϊ��ȡ�����ƽ״̬
#define SPISI_LAT_LOW     GPIO_PinOutClear(gpioPortD, 1)
#define SPISI_LAT_HIGH    GPIO_PinOutSet(gpioPortD, 1)
#define SPISI_INPUT       GPIO_PinModeSet(gpioPortD, 1, gpioModeInput, 0)
#define SPISI_OUTPUT      GPIO_PinModeSet(gpioPortD, 1, gpioModePushPull, 0)

/************************************************************************
 * D0��D	1��D2��D3Ϊ����ģʽ��ʹ������ SIO0��SIO1��SIO2��SIO3
 ***********************************************************************/

//FLASH_D0(FLASH��SI�ܽ�)
#define SPI_D0             GPIO_PinInGet(gpioPortD, 6)
#define SPI_D0_LOW         GPIO_PinOutClear(gpioPortD, 6)
#define SPI_D0_HIGH        GPIO_PinOutSet(gpioPortD, 6)
#define SPI_D0_INPUT       GPIO_PinModeSet(gpioPortD, 6, gpioModeInput, 0)
#define SPI_D0_OUTPUT      GPIO_PinModeSet(gpioPortD, 6, gpioModePushPull, 0)

//FLASH_D1(FLASH��SO�ܽ�)
#define SPI_D1             GPIO_PinInGet(gpioPortD, 1)
#define SPI_D1_LOW         GPIO_PinOutClear(gpioPortD, 1)
#define SPI_D1_HIGH        GPIO_PinOutSet(gpioPortD, 1)
#define SPI_D1_INPUT       GPIO_PinModeSet(gpioPortD, 1, gpioModeInput, 0)
#define SPI_D1_OUTPUT      GPIO_PinModeSet(gpioPortD, 1, gpioModePushPull, 0)

//FLASH D2(WP)
#define SPI_D2             GPIO_PinInGet(gpioPortD, 0)
#define SPI_D2_LOW         GPIO_PinOutClear(gpioPortD, 0)
#define SPI_D2_HIGH        GPIO_PinOutSet(gpioPortD, 0)
#define SPI_D2_INPUT       GPIO_PinModeSet(gpioPortD, 0, gpioModeInput, 0)
#define SPI_D2_OUTPUT      GPIO_PinModeSet(gpioPortD, 0, gpioModePushPull, 0)

//FLASH D3(SO3)
#define SPI_D3             GPIO_PinInGet(gpioPortD, 4)
#define SPI_D3_LOW         GPIO_PinOutClear(gpioPortD, 4)
#define SPI_D3_HIGH        GPIO_PinOutSet(gpioPortD, 4)
#define SPI_D3_INPUT       GPIO_PinModeSet(gpioPortD, 4, gpioModeInput, 0)
#define SPI_D3_OUTPUT      GPIO_PinModeSet(gpioPortD, 4, gpioModePushPull, 0)

/**********************************************************************************/

/**********************************************************************************
 * Flash �ռ仮��Ԥ����
 **********************************************************************************/






