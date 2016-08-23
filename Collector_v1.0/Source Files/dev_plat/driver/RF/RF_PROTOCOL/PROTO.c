/******************************************************************************
*  	名称：	PROTO.c
*  	功能：	规约函数，用于与汇集单元的通信
*  	日期:	2016-8-5
*  	初始建立： 赵传强
* 	修改:
******************************************************************************/
#include	"RF_include.h"


struct  FrameInfo	FrameRF;
struct  Capture_Address  Collector_List;

uint32_t	LocalAddr;			//本机地址，生产序列号，由出厂时写入，初始化过程中要从flash读出并赋值
uint8_t	RxFlag = 0;				//接收数据标志，射频接收中断中置位
uint8_t	TxFlag = 0;				//发送数据标志，有发送需求时置位

/****************************************************************************
 * 名称：void	InitProt(void)
 * 功能： 初始化规约
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	InitProt(void)
{
	memset (&FrameRF, 0, sizeof (struct  FrameInfo));
}

/****************************************************************************
 * 名称：void	ProtRetrasmit(void)
 * 功能：重传机制
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	ProtRetrasmit(void)
{

}

/****************************************************************************
 * 名称：void	APP_RecMIDData(void)
 * 功能： 读取mid层缓存数据，提取mid层缓冲数据到应用层进行处理
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	APP_RecMIDData(void)
{
    uint16_t     count;

    count = RFRead( (uint8_t *)&FrameRF.RxdBuf[FrameRF.RxdTail], LPDUSIZE);
    if (count == 0)
    {
        return ;
    }
    RFLseek( count);

    FrameRF.RxdTail += count;
    FrameRF.RxdLength += count;
    Prot_SearchFrame( ); //查找正确帧
}

/****************************************************************************
 * 名称：void		Prot_SearchFrame(void)
 * 功能： 查找正确帧,请密切关注规约帧格式的变化
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	Prot_SearchFrame( void)
{
	BOOL    stop = false;
	uint16_t	num,temp;
	while ((FrameRF.RxdHead < FrameRF.RxdTail) && (!stop))
	{
		//1 发现数据 发现0x68
		if (FrameRF.RxdStatus == RXDSTART)//找帧起始点
		{
			if( FrameRF.RxdBuf[FrameRF.RxdHead] != STARTCODE)
			{
				FrameRF.RxdHead++;
				continue;
			}

			//找到后，清除无用的缓冲区报文
			if (FrameRF.RxdTail > FrameRF.RxdHead)
			{
				FrameRF.RxdLength = FrameRF.RxdTail - FrameRF.RxdHead;
				memcpy (FrameRF.RxdBuf, &FrameRF.RxdBuf[FrameRF.RxdHead], FrameRF.RxdLength);
				FrameRF.RxdHead = 0;
				FrameRF.RxdTail = FrameRF.RxdLength;
			}
			FrameRF.RxdStatus = RXDHEAD;
		}
		//2 查找数据 找到帧头
		if (FrameRF.RxdStatus == RXDHEAD)
		{
			if(FrameRF.RxdLength > 10)//数据前有10字节
			{
				if(!Prot_CheckFrameHead())//检查帧头
				{
					FrameRF.RxdHead++;
					FrameRF.RxdStatus = RXDSTART;
				}
				else
				{
					FrameRF.RxdStatus = RXDCONTINUE;
				}
			}
			else
			{
				stop = true;
			}
		}
		//3 后续数据
		if (FrameRF.RxdStatus == RXDCONTINUE)
		{
			num = FrameRF.RxdBuf[FrameRF.RxdHead + 10];		//数据域长度字节
			if(FrameRF.RxdLength >= (num + 13)  )			//报文收全，除了数据，其余部分有13字节
			{
				temp = CS((void*)&FrameRF.RxdBuf[FrameRF.RxdHead ],num + 11);
				if ((FrameRF.RxdBuf[FrameRF.RxdHead + num + 11] == temp)&& (FrameRF.RxdBuf[FrameRF.RxdHead + num + 12] == ENDCODE))
				{
					if(FrameRF.RxdHead > 0)
					{
						FrameRF.RxdLength = FrameRF.RxdTail - FrameRF.RxdHead;
						memcpy (FrameRF.RxdBuf, &FrameRF.RxdBuf[FrameRF.RxdHead], FrameRF.RxdLength);
						FrameRF.RxdHead = 0;
						FrameRF.RxdTail = FrameRF.RxdLength;
					}
					APP_SettleFrame();//进行帧数据处理
					FrameRF.RxdHead += FrameRF.RxdBuf[FrameRF.RxdHead + 10] + 13;//num+13
					FrameRF.RxdStatus = RXDSTART;
				}
				else
				{
					FrameRF.RxdHead += 4;//说明找的不是正确数据，指针后移跨过头
					FrameRF.RxdStatus = RXDSTART;
				}
			}
			else
			{
				stop = true;
			}
		}
	}
	/*未找到帧的处理*/
	if (FrameRF.RxdHead)
	{
		FrameRF.RxdLength = FrameRF.RxdTail - FrameRF.RxdHead;
		if (FrameRF.RxdLength)
		{
			memcpy (FrameRF.RxdBuf, &FrameRF.RxdBuf[FrameRF.RxdHead], FrameRF.RxdLength);
		}
		FrameRF.RxdHead = 0;
		FrameRF.RxdTail = FrameRF.RxdLength;
		memset(&FrameRF.RxdBuf[FrameRF.RxdTail],0,FRAMEBUFSIZE - FrameRF.RxdLength);
	}
}

/****************************************************************************
 * 名称：BOOL	Prot_CheckFrameHead( )
 * 功能： 检查帧头正确性
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
BOOL	Prot_CheckFrameHead(void)
{
	struct PDUFRAME *pFrame;

	pFrame = (struct PDUFRAME*)(&FrameRF.RxdBuf[FrameRF.RxdHead]);

	if (pFrame->StartField1 != pFrame->StartField2)
	{
		return (false);
	}

	return (true);
}

/****************************************************************************
 * 名称：uint8_t 	CS(void *pbuf, uint16_t count)
 * 功能： 求校验和
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
uint8_t 	CS(void *pbuf, uint16_t count)
{
    register uint8_t i, sum;
    register uint8_t *p = (uint8_t *)pbuf;

    for(sum=0,i=0; i < count; i++)     /*求和*/
    {
        sum = sum + *(p+i);
    }
    return sum;
}


/****************************************************************************
 * 名称：BOOL	APP_SettleData(uint8_t	*buf)
 * 功能： 找到帧后，处理帧
 * 规约说明：	1 此处处理的是采集单元发起的故障数据帧；
 * 					2 汇集单元接受本组内的采集单元并需要判断地址和相号是否对应；
 * 					3 汇集单元作为从机的情况：短路/接地/电池故障、遥信数据
 * 输入参数:无
 * 返回值:
 *
 * 20160822   修改适合汇集单元使用   Root
 *****************************************************************************/
BOOL	APP_SettleFrame(void)
{
	struct PDUFRAME *pframe;
	pframe =(struct PDUFRAME *) (&FrameRF.RxdBuf[FrameRF.RxdHead ]);

//汇集单元内部维护一张地址对应表 Collector_List;

	/*A*/
		if((pframe->Addr == Collector_List.Capture_A_Addres) && (pframe->Team ==  SysPara.TeamNum) && (pframe->LinePhase == 0x01))
		{

					if((pframe->Control) & PRM)//此处汇集单元为从动者，接收到的采集单元包PRM为1，汇集单元作为从机进行数据处理
					{
						APP_SecAppProc(pframe->Data,(pframe->Control)&FUNCODE);//接收到的control应为2或5
					}

					else//此处汇集单元为发起者，召唤回的数据包PRM为0，汇集单元作为主机进行数据处理
					{
						APP_PriAppProc(pframe->Data,(pframe->Control)&FUNCODE);
					}

		}

	/*B*/
		else if((pframe->Addr == Collector_List.Capture_B_Addres) && (pframe->Team ==  SysPara.TeamNum) && (pframe->LinePhase == 0x02))
		{
				if((pframe->Control) & PRM)
				{
					APP_SecAppProc(pframe->Data,(pframe->Control)&FUNCODE);
				}

				else
				{
					APP_PriAppProc(pframe->Data,(pframe->Control)&FUNCODE);
				}
		}

	/*C*/
		else if((pframe->Addr == Collector_List.Capture_C_Addres)&& (pframe->Team ==  SysPara.TeamNum) && (pframe->LinePhase == 0x03))
		{
				if((pframe->Control) & PRM)
				{
					APP_SecAppProc(pframe->Data,(pframe->Control)&FUNCODE);
				}

				else
				{
					APP_PriAppProc(pframe->Data,(pframe->Control)&FUNCODE);
				}
		}

		else
		{
			return false;//should never be here
		}

}

/****************************************************************************
 * 名称：BOOL	APP_PriAppProc(uint8_t	*pdata)
 * 功能： 汇集单元作为主端，收到的数据是应答
 * 		  汇集单元需要收到应答的情况：校时下发、参数下发、程序下发、LED、翻牌、射频唤醒
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	APP_PriAppProc(uint8_t *pdata, uint8_t	fun)
{
	struct DU	*pdat;
	pdat = (struct	DU	*)pdata;

	if()

}

/****************************************************************************
 * 名称：BOOL	APP_SecAppProc(uint8_t	*pdata)
 * 功能： 从端处理数据域数据  prm=1
 * 输入参数:  收到的数据指针、控制域的功能码
 * 返回值:NULL
 *****************************************************************************/
void	APP_SecAppProc(uint8_t *pdata, uint8_t	fun)
{
	struct	DU	*pdat;
	pdat = (struct	DU	*)pdata;
	if(fun == FCREPORTFAULT)//采集单元主动发给汇集单元的短路/接地/电池故障，均为无应答
	{
		switch(pdat->Head.TypeID )
		{
			case DUANLU:
				//短路故障代码
				break;
			case JIEDI:
				//接地故障代码
				break;
			case BATLOW:
				//电池电量低代码
				break;
			default:
				break;
		}
	}
	else if(fun == FCSENDDATANA) //遥测数据
	{
		switch(pdat->Head.TypeID )
		{
			case DBYXTIM:
			//遥信代码
				break;
			default:
				break;
		}
	}
	else
	{
		//should not be here
	}
}

/****************************************************************************
 * 名称：void	Prot_EditAckFrame(void)
 * 功能：组 应答帧发送
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	Prot_SendAckFrame(void)
{
	//组帧
	struct PDUFRAME *pframe;
	FrameRF.TxdHead = 0;
	FrameRF.TxdTail = 0;
	pframe = (struct PDUFRAME*)&FrameRF.TxdBuf[FrameRF.TxdHead];
	pframe->StartField1 = STARTCODE;
	pframe->Addr = LocalAddr;
	pframe->Team = SysPara.TeamNum;
	pframe->LinePhase = SysPara.LinePhase;
	pframe->StartField2 = STARTCODE;
	pframe->Control = 0;//肯定确认
	pframe->Len = 0;
	pframe->Data[0] = CS((void *)&pframe, 12);
	pframe->Data[1] = ENDCODE;

	FrameRF.TxdTail += 13;
	//发送到MID缓存
	APP_SendDataToMID();
}

/****************************************************************************
 * 名称：void	Prot_SendFrame(void)
 * 功能：组 数据帧发送
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	Prot_SendFrame(uint8_t dvalid,uint8_t *dat,uint8_t len)
{
	//组帧
	struct PDUFRAME *pframe;

	FrameRF.TxdHead = 0;
	FrameRF.TxdTail = 0;
	pframe = (struct PDUFRAME*)&FrameRF.TxdBuf[FrameRF.TxdHead];
	pframe->StartField1 = STARTCODE;
	pframe->Addr = LocalAddr;
	pframe->Team = SysPara.TeamNum;
	pframe->LinePhase = SysPara.LinePhase;
	pframe->StartField2 = STARTCODE;
	if(dvalid == true)
	{
		pframe->Control = PRMSEC + FCRESDATA;//
	}
	else
	{
		pframe->Control = PRMSEC + FCNODATA;//
	}
	pframe->Len = len;
	memcpy(pframe->Data,dat,len);
	pframe->Data[len] = CS((void *)&pframe, 11 + len);
	pframe->Data[len+1] = ENDCODE;

	FrameRF.TxdTail += (13 + len);
	//发送到MID缓存
	APP_SendDataToMID();
}
/****************************************************************************
 * 名称：void	Prot_EditFrame(void)
 * 功能：应答帧
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	Prot_ReplayFrame(uint8_t	type)
{
	switch(type)
	{
	case DBALL:	//总召
		//访问数据库

		//应答
		//Prot_SendFrame(uint8_t dvalid,uint8_t *at,uint8_t len);
		break;
	case DBYXTIM:// 召唤soe

		break;
	case DBWAVE:// 召唤录波数据

		break;

	default:break;
	}
}


/****************************************************************************
 * 名称：void	APP_SendDataToMID(void)
 * 功能：发送数据到mid层
 * 输入参数:无
 * 返回值:
 *****************************************************************************/
void	APP_SendDataToMID(void)
{
    uint16_t    count, num;

    if (FrameRF.TxdHead >= FrameRF.TxdTail)
        return ;

    num = FrameRF.TxdTail - FrameRF.TxdHead;
    count = RFWriteLen((uint8_t *)&FrameRF.TxdBuf[FrameRF.TxdHead], num );

    FrameRF.TxdHead += count;
    if (FrameRF.TxdHead >= FrameRF.TxdTail)
    {
    	FrameRF.TxdTail = 0;
    	FrameRF.TxdHead = 0;
    }
}




