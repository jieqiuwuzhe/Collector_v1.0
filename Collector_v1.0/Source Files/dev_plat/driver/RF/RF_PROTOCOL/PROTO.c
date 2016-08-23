/******************************************************************************
*  	���ƣ�	PROTO.c
*  	���ܣ�	��Լ������������㼯��Ԫ��ͨ��
*  	����:	2016-8-5
*  	��ʼ������ �Դ�ǿ
* 	�޸�:
******************************************************************************/
#include	"RF_include.h"


struct  FrameInfo	FrameRF;
struct  Capture_Address  Collector_List;

uint32_t	LocalAddr;			//������ַ���������кţ��ɳ���ʱд�룬��ʼ��������Ҫ��flash��������ֵ
uint8_t	RxFlag = 0;				//�������ݱ�־����Ƶ�����ж�����λ
uint8_t	TxFlag = 0;				//�������ݱ�־���з�������ʱ��λ

/****************************************************************************
 * ���ƣ�void	InitProt(void)
 * ���ܣ� ��ʼ����Լ
 * �������:��
 * ����ֵ:
 *****************************************************************************/
void	InitProt(void)
{
	memset (&FrameRF, 0, sizeof (struct  FrameInfo));
}

/****************************************************************************
 * ���ƣ�void	ProtRetrasmit(void)
 * ���ܣ��ش�����
 * �������:��
 * ����ֵ:
 *****************************************************************************/
void	ProtRetrasmit(void)
{

}

/****************************************************************************
 * ���ƣ�void	APP_RecMIDData(void)
 * ���ܣ� ��ȡmid�㻺�����ݣ���ȡmid�㻺�����ݵ�Ӧ�ò���д���
 * �������:��
 * ����ֵ:
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
    Prot_SearchFrame( ); //������ȷ֡
}

/****************************************************************************
 * ���ƣ�void		Prot_SearchFrame(void)
 * ���ܣ� ������ȷ֡,�����й�ע��Լ֡��ʽ�ı仯
 * �������:��
 * ����ֵ:
 *****************************************************************************/
void	Prot_SearchFrame( void)
{
	BOOL    stop = false;
	uint16_t	num,temp;
	while ((FrameRF.RxdHead < FrameRF.RxdTail) && (!stop))
	{
		//1 �������� ����0x68
		if (FrameRF.RxdStatus == RXDSTART)//��֡��ʼ��
		{
			if( FrameRF.RxdBuf[FrameRF.RxdHead] != STARTCODE)
			{
				FrameRF.RxdHead++;
				continue;
			}

			//�ҵ���������õĻ���������
			if (FrameRF.RxdTail > FrameRF.RxdHead)
			{
				FrameRF.RxdLength = FrameRF.RxdTail - FrameRF.RxdHead;
				memcpy (FrameRF.RxdBuf, &FrameRF.RxdBuf[FrameRF.RxdHead], FrameRF.RxdLength);
				FrameRF.RxdHead = 0;
				FrameRF.RxdTail = FrameRF.RxdLength;
			}
			FrameRF.RxdStatus = RXDHEAD;
		}
		//2 �������� �ҵ�֡ͷ
		if (FrameRF.RxdStatus == RXDHEAD)
		{
			if(FrameRF.RxdLength > 10)//����ǰ��10�ֽ�
			{
				if(!Prot_CheckFrameHead())//���֡ͷ
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
		//3 ��������
		if (FrameRF.RxdStatus == RXDCONTINUE)
		{
			num = FrameRF.RxdBuf[FrameRF.RxdHead + 10];		//�����򳤶��ֽ�
			if(FrameRF.RxdLength >= (num + 13)  )			//������ȫ���������ݣ����ಿ����13�ֽ�
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
					APP_SettleFrame();//����֡���ݴ���
					FrameRF.RxdHead += FrameRF.RxdBuf[FrameRF.RxdHead + 10] + 13;//num+13
					FrameRF.RxdStatus = RXDSTART;
				}
				else
				{
					FrameRF.RxdHead += 4;//˵���ҵĲ�����ȷ���ݣ�ָ����ƿ��ͷ
					FrameRF.RxdStatus = RXDSTART;
				}
			}
			else
			{
				stop = true;
			}
		}
	}
	/*δ�ҵ�֡�Ĵ���*/
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
 * ���ƣ�BOOL	Prot_CheckFrameHead( )
 * ���ܣ� ���֡ͷ��ȷ��
 * �������:��
 * ����ֵ:
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
 * ���ƣ�uint8_t 	CS(void *pbuf, uint16_t count)
 * ���ܣ� ��У���
 * �������:��
 * ����ֵ:
 *****************************************************************************/
uint8_t 	CS(void *pbuf, uint16_t count)
{
    register uint8_t i, sum;
    register uint8_t *p = (uint8_t *)pbuf;

    for(sum=0,i=0; i < count; i++)     /*���*/
    {
        sum = sum + *(p+i);
    }
    return sum;
}


/****************************************************************************
 * ���ƣ�BOOL	APP_SettleData(uint8_t	*buf)
 * ���ܣ� �ҵ�֡�󣬴���֡
 * ��Լ˵����	1 �˴�������ǲɼ���Ԫ����Ĺ�������֡��
 * 					2 �㼯��Ԫ���ܱ����ڵĲɼ���Ԫ����Ҫ�жϵ�ַ������Ƿ��Ӧ��
 * 					3 �㼯��Ԫ��Ϊ�ӻ����������·/�ӵ�/��ع��ϡ�ң������
 * �������:��
 * ����ֵ:
 *
 * 20160822   �޸��ʺϻ㼯��Ԫʹ��   Root
 *****************************************************************************/
BOOL	APP_SettleFrame(void)
{
	struct PDUFRAME *pframe;
	pframe =(struct PDUFRAME *) (&FrameRF.RxdBuf[FrameRF.RxdHead ]);

//�㼯��Ԫ�ڲ�ά��һ�ŵ�ַ��Ӧ�� Collector_List;

	/*A*/
		if((pframe->Addr == Collector_List.Capture_A_Addres) && (pframe->Team ==  SysPara.TeamNum) && (pframe->LinePhase == 0x01))
		{

					if((pframe->Control) & PRM)//�˴��㼯��ԪΪ�Ӷ��ߣ����յ��Ĳɼ���Ԫ��PRMΪ1���㼯��Ԫ��Ϊ�ӻ��������ݴ���
					{
						APP_SecAppProc(pframe->Data,(pframe->Control)&FUNCODE);//���յ���controlӦΪ2��5
					}

					else//�˴��㼯��ԪΪ�����ߣ��ٻ��ص����ݰ�PRMΪ0���㼯��Ԫ��Ϊ�����������ݴ���
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
 * ���ƣ�BOOL	APP_PriAppProc(uint8_t	*pdata)
 * ���ܣ� �㼯��Ԫ��Ϊ���ˣ��յ���������Ӧ��
 * 		  �㼯��Ԫ��Ҫ�յ�Ӧ��������Уʱ�·��������·��������·���LED�����ơ���Ƶ����
 * �������:��
 * ����ֵ:
 *****************************************************************************/
void	APP_PriAppProc(uint8_t *pdata, uint8_t	fun)
{
	struct DU	*pdat;
	pdat = (struct	DU	*)pdata;

	if()

}

/****************************************************************************
 * ���ƣ�BOOL	APP_SecAppProc(uint8_t	*pdata)
 * ���ܣ� �Ӷ˴�������������  prm=1
 * �������:  �յ�������ָ�롢������Ĺ�����
 * ����ֵ:NULL
 *****************************************************************************/
void	APP_SecAppProc(uint8_t *pdata, uint8_t	fun)
{
	struct	DU	*pdat;
	pdat = (struct	DU	*)pdata;
	if(fun == FCREPORTFAULT)//�ɼ���Ԫ���������㼯��Ԫ�Ķ�·/�ӵ�/��ع��ϣ���Ϊ��Ӧ��
	{
		switch(pdat->Head.TypeID )
		{
			case DUANLU:
				//��·���ϴ���
				break;
			case JIEDI:
				//�ӵع��ϴ���
				break;
			case BATLOW:
				//��ص����ʹ���
				break;
			default:
				break;
		}
	}
	else if(fun == FCSENDDATANA) //ң������
	{
		switch(pdat->Head.TypeID )
		{
			case DBYXTIM:
			//ң�Ŵ���
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
 * ���ƣ�void	Prot_EditAckFrame(void)
 * ���ܣ��� Ӧ��֡����
 * �������:��
 * ����ֵ:
 *****************************************************************************/
void	Prot_SendAckFrame(void)
{
	//��֡
	struct PDUFRAME *pframe;
	FrameRF.TxdHead = 0;
	FrameRF.TxdTail = 0;
	pframe = (struct PDUFRAME*)&FrameRF.TxdBuf[FrameRF.TxdHead];
	pframe->StartField1 = STARTCODE;
	pframe->Addr = LocalAddr;
	pframe->Team = SysPara.TeamNum;
	pframe->LinePhase = SysPara.LinePhase;
	pframe->StartField2 = STARTCODE;
	pframe->Control = 0;//�϶�ȷ��
	pframe->Len = 0;
	pframe->Data[0] = CS((void *)&pframe, 12);
	pframe->Data[1] = ENDCODE;

	FrameRF.TxdTail += 13;
	//���͵�MID����
	APP_SendDataToMID();
}

/****************************************************************************
 * ���ƣ�void	Prot_SendFrame(void)
 * ���ܣ��� ����֡����
 * �������:��
 * ����ֵ:
 *****************************************************************************/
void	Prot_SendFrame(uint8_t dvalid,uint8_t *dat,uint8_t len)
{
	//��֡
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
	//���͵�MID����
	APP_SendDataToMID();
}
/****************************************************************************
 * ���ƣ�void	Prot_EditFrame(void)
 * ���ܣ�Ӧ��֡
 * �������:��
 * ����ֵ:
 *****************************************************************************/
void	Prot_ReplayFrame(uint8_t	type)
{
	switch(type)
	{
	case DBALL:	//����
		//�������ݿ�

		//Ӧ��
		//Prot_SendFrame(uint8_t dvalid,uint8_t *at,uint8_t len);
		break;
	case DBYXTIM:// �ٻ�soe

		break;
	case DBWAVE:// �ٻ�¼������

		break;

	default:break;
	}
}


/****************************************************************************
 * ���ƣ�void	APP_SendDataToMID(void)
 * ���ܣ��������ݵ�mid��
 * �������:��
 * ����ֵ:
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




