/******************************************************************************
*  	���ƣ�	PROTO.H
*  	����:	2016-8-5
*  	//20160823  �޸���ӻ㼯��Ԫ�˲��ִ���    Root
******************************************************************************/

#ifndef PROTO_H_
#define PROTO_H_

//�궨��
#define LPDUSIZE        268     	// ��·�㱨�ĵ���󳤶�255+13
#define FRAMEBUFSIZE    1024    	// ���ջ���������󳤶�
#define	STARTCODE		0x68		// ��������ͷ  ���б���ά�������ݶ�Ҫ����Ū
#define	ENDCODE			0x16		// ��������β
#define	RFDULEN			255			// ֡�����򳤶�

//��ƫ����ƫ��
#define	LINEOFFSET		0xFC		//��
#define	PHASEOFFSET		0x03		//��

//������ṹ
#define FUNCODE 		0x0F		//������
#define SFV     		0x10		//����֡��Ч                                				  X
#define PRM     		0x40		//����վ��־
#define DIR     		/*0x80*/	0x00	//���䷽�� ���㼯��Ԫ����Ϊ1���ɼ���Ԫ����Ϊ0    X

//prm����
#define	PRMPRI			0x40
#define	PRMSEC			0x00
//ʼ��վ������FUNCODE  PRM=1
#define FCRESETUSE      0       	    //��λ����
#define FCRESETFAULT    1       	//��λ����
#define FCSENDDATANA    2       	//�������ݣ�����ҪӦ��
#define FCSENDDATA      3       	//�������ݣ���ҪӦ��
#define FCREQUESTD      4       	//��������
#define FCREPORTFAULT  5    		//������ϣ��ɼ���Ԫ������

//�Ӷ�վ�����붨��PRM=0
#define FCCON           0       	    //�϶�ȷ��
#define FCNOCON         1       	//��ȷ��
#define FCRESDATA       2       	//��������Ӧ����֡
#define FCNODATA        3       	//�����ٻ�������

//�������壺���ͱ�ʶ
#define	TIMESTAMP		0x01		//ʱ��
#define DBALL				0x02		//ң��
#define DBYXTIM			0x03		//ң��
#define DBWAVE			0x04		//ң�Ŵ�ʱ��
#define DBPARA			0x05		//¼������
#define DBPROG			0x06		//����
#define FAULTWRG		0x07		//����
#define LED					0x08		//���Ե�
#define FANPAI				0x09		//���Է���
#define	WAKEUP			0x0A		//������Ƶ
#define PHYID				0x0B		//�����ַ
//0823��ӹ�����Ϣ��ʶ
#define  DUANLU			0x0C   //��·����
#define  JIEDI					0x0D   //�ӵع���
#define  BATLOW			0x0E   //��ص����͹���


//�㼯��Ԫ�ڲ�ά��һ�ŵ�ַ��Ӧ��
struct Capture_Address //��Ϊ���趨������ʼ��ʱ���и�ֵ
{
	uint32_t Capture_A_Addres;
	uint32_t Capture_B_Addres;
	uint32_t Capture_C_Addres;
};


//֡����״̬ö��
enum    RXDSTATUS
{
    RXDSTART = 0,       //Ѱ����ʼ��־״̬
    RXDHEAD,            //Ѱ�ұ���ͷ
    RXDCONTINUE         //���պ�������
};

struct  FrameInfo
{
	uint8_t		LinkState;
	uint8_t		TimeOutValue;
	uint8_t		TimeOutCounter;
	uint8_t		FrameNum;					//֡����
	uint8_t		FrameSeq;					//֡���
	uint16_t  	TxdHead;                  	//�������ݵ�ͷ
	uint16_t  	TxdTail;					//�������ݵ�β
	uint16_t  	TxdLength;					//�������ݵĳ���
    uint16_t  	RxdHead;                  	//�������ݵ�ͷ
    uint16_t  	RxdTail;					//�������ݵ�β
    uint16_t  	RxdLength;					//�������ݵĳ���
    enum    	RXDSTATUS RxdStatus;      	//����״̬
    uint8_t		RxdBuf[FRAMEBUFSIZE];       //���ջ����� 1024
    uint8_t		TxdBuf[LPDUSIZE ];       	//���ͻ����� 1024
};

//struct	DLDevInfo
//{
//
//};
//rf֡�ṹ ����֮�⹲13�ֽڣ�13+N
struct PDUFRAME
{
	uint8_t    StartField1;     //��ʼ�ֽ�
	uint32_t   Addr;    		//�����ַ
	uint16_t   Team;    		//��
	uint8_t	   LinePhase;		//��ƫ�Ƽ���ƫ��
	uint8_t    StartField2;     //��ʼ�ֽ�
	uint8_t    Control;         //������
	uint8_t    Len;             //���ݳ��� ��10��
	uint8_t    Data[RFDULEN];   //Ӧ�ò����� num
	uint8_t    CheckCode;       //У����
	uint8_t    EndField;        //�����ַ�
};


//data��ͷ�ṹ
struct DUHead
{
	uint8_t    TypeID;          //���ͱ�ʶ
	uint8_t    FrameNum;        //֡����
	uint8_t    FrameSeq;        //֡���
};

//data���ݽṹ
struct DU
{
    struct 		DUHead Head;
    uint8_t    	Data[RFDULEN-sizeof(struct DUHead)];
};



extern	struct  FrameInfo	FrameRF;
struct  Capture_Address  Collector_List;
extern	uint8_t	RxFlag ;				//�������ݱ�־
extern	uint8_t	TxFlag  ;				//�������ݱ�־






void	APP_RecMIDData(void);
void	Prot_SearchFrame( void);
BOOL	Prot_CheckFrameHead(void);
uint8_t 	CS(void *pbuf, uint16_t count);
BOOL	APP_SettleFrame(void);
void	APP_PriAppProc(uint8_t *pdata, uint8_t	fun);
void	APP_SecAppProc(uint8_t *pdata, uint8_t	fun);
void	APP_SendDataToMID(void);
void	Prot_SendAckFrame(void);
void	Prot_ReplayFrame(uint8_t	type);
void	InitProt(void);
void	Prot_SendFrame(uint8_t dvalid,uint8_t *dat,uint8_t len);


#endif /* PROTO_H_ */
