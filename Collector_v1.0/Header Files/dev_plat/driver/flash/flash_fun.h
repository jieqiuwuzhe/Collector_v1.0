#ifndef __HANSHU_H
#define __HANSHU_H

void  		  spi_open_flash(void);
void  		  spi_close_flash(void);
void 		  spi_writebyte(unsigned char data);
unsigned char spi_readbyte(void);
void 		  spi_read_dummy(unsigned char count);
void 		  MX25L256_FLASH_INIT(void);
unsigned char IS_FLASH_READY(void);
unsigned char MX25_WR_ENABLE(void);
void 		  MX25_WR_DISABLE(void);
unsigned char MX25_WR_COMPLETE(void);
void 		  MX25_MEM_RST(void);
void 		  MX25_RDID(unsigned char *pdata);
unsigned char MX25_RDSR(void);
void 		  MX25_WRSR(unsigned char statval);
void 		  SET_4B_MODE(unsigned char enable);
//注意：flash只能将1写为0，故每次重新写入数据前需要进行擦除操作！
void 		  MX25_SECTOR_ERASE_4B(unsigned short sector_addr);
void 		  MX25_B32K_ERASE_4B(unsigned short b32k_addr);
void 		  MX25_B64K_ERASE_4B(unsigned short b64k_addr);
void 		  MX25_CHIP_ERASE(void);
void 		  MX25_BYTE_READ4B(unsigned int addr,unsigned char *pbuf, unsigned int length);
void 		  MX25_BYTE_PP4B(unsigned int addr,unsigned char *pbuf, unsigned int length);
void 		  MX25_QUAD_BYTE_READ4B(unsigned int addr,unsigned char *pbuf, unsigned int length);
void 		  MX25_QUAD_BYTE_PP4B(unsigned int addr,unsigned char *pbuf, unsigned int length);

#endif
