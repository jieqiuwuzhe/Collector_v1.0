/******************************************************************************
*  	名称：	MISI.H
*  	日期:	2016-8-5
******************************************************************************/

#ifndef MISI_H_
#define MISI_H_

//#define	RX_UARTBUF_SIZE		64				//uart发送缓冲
//#define	TX_UARTBUF_SIZE		64				//uart接收缓冲
#define	RX_RFBUF_SIZE		512				//rf发送缓冲
#define	TX_RFBUF_SIZE		512				//rf接收缓冲

/*声明变量-------------------------------------------------------------------*/
//struct 	pUart
//{
//	uint8_t 	UartRxBuf[RX_UARTBUF_SIZE];
//	uint8_t 	UartTxBuf[TX_UARTBUF_SIZE];
//	uint8_t 	*pRxBufRead;                   /*接收缓冲区读指针*/
//	uint8_t 	*pRxBufWrite;                  /*接收缓冲区写指针*/
//	uint8_t 	*pTxBufRead;                   /*发送缓冲区读指针*/
//	uint8_t 	*pTxBufWrite;                  /*发送缓冲区写指针*/
//    uint8_t 	*pRxEnd;                       /*发送缓冲区读指针*/
//	uint8_t 	*pTxEnd;                       /*发送缓冲区写指针*/
//};
struct 	pRF
{
	uint8_t 	RFRxBuf[RX_RFBUF_SIZE];
	uint8_t 	RFTxBuf[TX_RFBUF_SIZE];
	uint8_t 	*pRxBufRead;                   /*接收缓冲区读指针*/
	uint8_t 	*pRxBufWrite;                  /*接收缓冲区写指针*/
	uint8_t 	*pTxBufRead;                   /*发送缓冲区读指针*/
	uint8_t 	*pTxBufWrite;                  /*发送缓冲区写指针*/
	uint8_t 	*pRxEnd;                       /*发送缓冲区读指针*/
	uint8_t 	*pTxEnd;                       /*发送缓冲区写指针*/
};

extern	struct	pRF	RFbuf;



void		InitMID(void);
void		RFLseek(uint16_t	offset);
void		ResetRFRXBuf(void);
void		RFReceive(uint8_t   *pbuf  ,uint16_t len);
uint16_t	RFWrite(uint8_t   *pbuf  ) ;
uint16_t  	RFWriteLen( uint8_t   *pbuf  ,uint16_t len) ;
uint16_t  	RFRead( uint8_t *pbuf,  uint16_t   count);













#endif /* MISI_H_ */
