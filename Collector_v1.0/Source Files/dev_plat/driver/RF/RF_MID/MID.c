/******************************************************************************
*  	名称：	MISI.c
*  	功能：	中间层处理,射频缓存。
*  	日期:	2016-8-5
*  	初始建立： zcq
* 	修改:
******************************************************************************/
/*
 * 应用层
 * 规约层
 * misi：中间层，提供射频缓存处理！！！
 * mac层射频：射频工作模式控制、速率管理等，为上层提供透传支持
 * 物理层射频
 * */
#include	"RF_include.h"

struct	pRF	RFbuf;
/*-----------------------------------------------------------------------------
*	名称：InitMID
*	功能：初始化miD缓存
*	入口参数：
*	返回值：
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
//uart内容后期再加
}

/*-----------------------------------------------------------------------------
*	名称：RFReceive
*	功能： 从射频接收数据，写入RFbuf.RFRxBuf
*	入口参数：uint8_t   *pbuf 射频数据指针  ,uint16_t len 接收的射频数据长度
*	返回值：
------------------------------------------------------------------------------*/
void	RFReceive(uint8_t   *pbuf  ,uint16_t len)
{
	uint16_t	i;
	for(i = 0; i < len; i++ )
	{
		*(RFbuf.pRxBufWrite) = *pbuf ;                 /*！读缓存的写指针*/
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
*	名称：RFLseek
*	功能：对RF接收缓存读指针进行处理，在读完接收缓存后，移动读指针使其追上写指针
*	入口参数： INT16U	offset  读指针移动量
*	返回值：
------------------------------------------------------------------------------*/
void	RFLseek(uint16_t	offset)
{
	if(offset == 0)
	{
		return;
	}

    uint8_t *pRxEnd = RFbuf.RFRxBuf + RX_RFBUF_SIZE - 1;   //pRxEnd指向接收缓存区的末端。

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
*	名称：ResetRFRXBuf
*	功能： 使rfbuf的读指针追上写指针
*	入口参数：
*	返回值：
------------------------------------------------------------------------------*/
void	ResetRFRXBuf(void)
{
	RFbuf.pRxBufRead = RFbuf.pRxBufWrite;
}
/*-----------------------------------------------------------------------------
*	名称：RFWrite
*	功能：向rf发送缓存写数据，用于射频发送
*	入口参数：  INT8U   *pbuf 指向要写入的数据的地址
*	返回值：写入的数据个数
------------------------------------------------------------------------------*/
uint16_t  	RFWrite(uint8_t   *pbuf  )  //！注意，这个*pbuf参数，实参在只用之前，一定要定义一下，使得实参指针指向某个数据。
{
	uint16_t 	i = 0;
    while(*(pbuf+i)!= 0x00)
    {
        *(RFbuf.pTxBufWrite) = *(pbuf+i);                          /*！写缓存的写指针*/
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
*	名称：RFWriteLen
*	功能：向rf发送缓存写数据
*	入口参数：  INT8U   *pbuf 指向要写入的数据的地址,INT16U len写入长度
*	返回值：写入的数据个数
------------------------------------------------------------------------------*/
uint16_t	RFWriteLen( uint8_t   *pbuf  ,uint16_t len)  //！注意，这个*pbuf参数，实参在使用之前，一定要定义一下，使得实参指针指向某个数据。
{
	uint16_t 	i = 0;

    for (i = 0; i < len; i++)
    {
        *(RFbuf.pTxBufWrite) = *(pbuf+i);                          /*！写缓存的写指针*/
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
*	名称：RFRead
*	功能：读取rf接收缓存
*	入口参数：
*				INT8U *pbuf,  	   读出的数据存放的缓存地址
*				INT16U   count		读取数据量  字节数
*	返回值：
------------------------------------------------------------------------------*/
uint16_t	RFRead( uint8_t *pbuf,  uint16_t   count)
{
	uint16_t i;

	uint8_t *pTem = RFbuf.pRxBufRead;                 //*pTem：临时指针，使得rfRead函数不改变读指针pRxBufRead。
    if (  RFbuf.pRxBufWrite ==  pTem  )
    {
        return 0;
    }

    for (i = 0; (i < count)&&(RFbuf.pRxBufWrite !=  pTem); i++) //读buf的时候，需要判断该buf的读写指针是否处于同一位置。
    {
        *(pbuf+i) = *pTem;                           /*！读缓存的读指针*/
        if(pTem < RFbuf.pRxEnd)
            pTem++;
        else
            pTem = RFbuf.RFRxBuf;
    }
    return i;
}






















