/******************************************************************************
*  	���ƣ�	MISI.H
*  	����:	2016-8-5
******************************************************************************/

#ifndef MISI_H_
#define MISI_H_

//#define	RX_UARTBUF_SIZE		64				//uart���ͻ���
//#define	TX_UARTBUF_SIZE		64				//uart���ջ���
#define	RX_RFBUF_SIZE		512				//rf���ͻ���
#define	TX_RFBUF_SIZE		512				//rf���ջ���

/*��������-------------------------------------------------------------------*/
//struct 	pUart
//{
//	uint8_t 	UartRxBuf[RX_UARTBUF_SIZE];
//	uint8_t 	UartTxBuf[TX_UARTBUF_SIZE];
//	uint8_t 	*pRxBufRead;                   /*���ջ�������ָ��*/
//	uint8_t 	*pRxBufWrite;                  /*���ջ�����дָ��*/
//	uint8_t 	*pTxBufRead;                   /*���ͻ�������ָ��*/
//	uint8_t 	*pTxBufWrite;                  /*���ͻ�����дָ��*/
//    uint8_t 	*pRxEnd;                       /*���ͻ�������ָ��*/
//	uint8_t 	*pTxEnd;                       /*���ͻ�����дָ��*/
//};
struct 	pRF
{
	uint8_t 	RFRxBuf[RX_RFBUF_SIZE];
	uint8_t 	RFTxBuf[TX_RFBUF_SIZE];
	uint8_t 	*pRxBufRead;                   /*���ջ�������ָ��*/
	uint8_t 	*pRxBufWrite;                  /*���ջ�����дָ��*/
	uint8_t 	*pTxBufRead;                   /*���ͻ�������ָ��*/
	uint8_t 	*pTxBufWrite;                  /*���ͻ�����дָ��*/
	uint8_t 	*pRxEnd;                       /*���ͻ�������ָ��*/
	uint8_t 	*pTxEnd;                       /*���ͻ�����дָ��*/
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
