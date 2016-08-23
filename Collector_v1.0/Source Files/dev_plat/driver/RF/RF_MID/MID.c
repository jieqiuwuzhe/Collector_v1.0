/******************************************************************************
*  	���ƣ�	MISI.c
*  	���ܣ�	�м�㴦��,��Ƶ���档
*  	����:	2016-8-5
*  	��ʼ������ zcq
* 	�޸�:
******************************************************************************/
/*
 * Ӧ�ò�
 * ��Լ��
 * misi���м�㣬�ṩ��Ƶ���洦������
 * mac����Ƶ����Ƶ����ģʽ���ơ����ʹ���ȣ�Ϊ�ϲ��ṩ͸��֧��
 * �������Ƶ
 * */
#include	"RF_include.h"

struct	pRF	RFbuf;
/*-----------------------------------------------------------------------------
*	���ƣ�InitMID
*	���ܣ���ʼ��miD����
*	��ڲ�����
*	����ֵ��
------------------------------------------------------------------------------*/
void	InitMID(void)
{
	memset(&RFbuf,0,sizeof(struct	pRF));
	RFbuf.pRxBufRead = RFbuf.RFRxBuf;
	RFbuf.pRxBufWrite = RFbuf.RFRxBuf;
	RFbuf.pTxBufRead = RFbuf.RFTxBuf;
	RFbuf.pTxBufWrite = RFbuf.RFTxBuf;
	RFbuf.pRxEnd = RFbuf.RFRxBuf + RX_RFBUF_SIZE - 1;
	RFbuf.pTxEnd = RFbuf.RFRxBuf + TX_RFBUF_SIZE - 1;
//uart���ݺ����ټ�
}

/*-----------------------------------------------------------------------------
*	���ƣ�RFReceive
*	���ܣ� ����Ƶ�������ݣ�д��RFbuf.RFRxBuf
*	��ڲ�����uint8_t   *pbuf ��Ƶ����ָ��  ,uint16_t len ���յ���Ƶ���ݳ���
*	����ֵ��
------------------------------------------------------------------------------*/
void	RFReceive(uint8_t   *pbuf  ,uint16_t len)
{
	uint16_t	i;
	for(i = 0; i < len; i++ )
	{
		*(RFbuf.pRxBufWrite) = *pbuf ;                 /*���������дָ��*/
		pbuf ++;
		if(RFbuf.pRxBufWrite < RFbuf.pRxEnd)
		{
			RFbuf.pRxBufWrite++;
		}
		else
		{
			RFbuf.pRxBufWrite = RFbuf.RFRxBuf;
		}
	}
}




/*-----------------------------------------------------------------------------
*	���ƣ�RFLseek
*	���ܣ���RF���ջ����ָ����д����ڶ�����ջ�����ƶ���ָ��ʹ��׷��дָ��
*	��ڲ����� INT16U	offset  ��ָ���ƶ���
*	����ֵ��
------------------------------------------------------------------------------*/
void	RFLseek(uint16_t	offset)
{
	if(offset == 0)
	{
		return;
	}

    uint8_t *pRxEnd = RFbuf.RFRxBuf + RX_RFBUF_SIZE - 1;   //pRxEndָ����ջ�������ĩ�ˡ�

    if((RFbuf.pRxBufRead + offset) <= pRxEnd)
    {
    	RFbuf.pRxBufRead = RFbuf.pRxBufRead + offset;
    }
    else
    {
    	RFbuf.pRxBufRead = RFbuf.RFRxBuf + ((RFbuf.pRxBufRead + offset) - pRxEnd - 1);
    }
}


/*-----------------------------------------------------------------------------
*	���ƣ�ResetRFRXBuf
*	���ܣ� ʹrfbuf�Ķ�ָ��׷��дָ��
*	��ڲ�����
*	����ֵ��
------------------------------------------------------------------------------*/
void	ResetRFRXBuf(void)
{
	RFbuf.pRxBufRead = RFbuf.pRxBufWrite;
}
/*-----------------------------------------------------------------------------
*	���ƣ�RFWrite
*	���ܣ���rf���ͻ���д���ݣ�������Ƶ����
*	��ڲ�����  INT8U   *pbuf ָ��Ҫд������ݵĵ�ַ
*	����ֵ��д������ݸ���
------------------------------------------------------------------------------*/
uint16_t  	RFWrite(uint8_t   *pbuf  )  //��ע�⣬���*pbuf������ʵ����ֻ��֮ǰ��һ��Ҫ����һ�£�ʹ��ʵ��ָ��ָ��ĳ�����ݡ�
{
	uint16_t 	i = 0;
    while(*(pbuf+i)!= 0x00)
    {
        *(RFbuf.pTxBufWrite) = *(pbuf+i);                          /*��д�����дָ��*/
        if(RFbuf.pTxBufWrite < RFbuf.pTxEnd)
        {
        	RFbuf.pTxBufWrite++;
        }
        else
        {
        	RFbuf.pTxBufWrite = RFbuf.RFTxBuf;
        }
        i++;
    }

    return i;
}

/*-----------------------------------------------------------------------------
*	���ƣ�RFWriteLen
*	���ܣ���rf���ͻ���д����
*	��ڲ�����  INT8U   *pbuf ָ��Ҫд������ݵĵ�ַ,INT16U lenд�볤��
*	����ֵ��д������ݸ���
------------------------------------------------------------------------------*/
uint16_t	RFWriteLen( uint8_t   *pbuf  ,uint16_t len)  //��ע�⣬���*pbuf������ʵ����ʹ��֮ǰ��һ��Ҫ����һ�£�ʹ��ʵ��ָ��ָ��ĳ�����ݡ�
{
	uint16_t 	i = 0;

    for (i = 0; i < len; i++)
    {
        *(RFbuf.pTxBufWrite) = *(pbuf+i);                          /*��д�����дָ��*/
        if(RFbuf.pTxBufWrite < RFbuf.pTxEnd)
        {
        	RFbuf.pTxBufWrite++;
        }
        else
        {
        	RFbuf.pTxBufWrite = RFbuf.RFTxBuf;
        }
    }

    return i;
}
/*-----------------------------------------------------------------------------
*	���ƣ�RFRead
*	���ܣ���ȡrf���ջ���
*	��ڲ�����
*				INT8U *pbuf,  	   ���������ݴ�ŵĻ����ַ
*				INT16U   count		��ȡ������  �ֽ���
*	����ֵ��
------------------------------------------------------------------------------*/
uint16_t	RFRead( uint8_t *pbuf,  uint16_t   count)
{
	uint16_t i;

	uint8_t *pTem = RFbuf.pRxBufRead;                 //*pTem����ʱָ�룬ʹ��rfRead�������ı��ָ��pRxBufRead��
    if (  RFbuf.pRxBufWrite ==  pTem  )
    {
        return 0;
    }

    for (i = 0; (i < count)&&(RFbuf.pRxBufWrite !=  pTem); i++) //��buf��ʱ����Ҫ�жϸ�buf�Ķ�дָ���Ƿ���ͬһλ�á�
    {
        *(pbuf+i) = *pTem;                           /*��������Ķ�ָ��*/
        if(pTem < RFbuf.pRxEnd)
            pTem++;
        else
            pTem = RFbuf.RFRxBuf;
    }
    return i;
}






















