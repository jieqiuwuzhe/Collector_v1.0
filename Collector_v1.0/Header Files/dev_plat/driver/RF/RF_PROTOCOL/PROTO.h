/******************************************************************************
*  	名称：	PROTO.H
*  	日期:	2016-8-5
*  	//20160823  修改添加汇集单元端部分代码    Root
******************************************************************************/

#ifndef PROTO_H_
#define PROTO_H_

//宏定义
#define LPDUSIZE        268     	// 链路层报文的最大长度255+13
#define FRAMEBUFSIZE    1024    	// 接收缓冲区的最大长度
#define	STARTCODE		0x68		// 串口数据头  所有本地维护口数据都要这样弄
#define	ENDCODE			0x16		// 串口数据尾
#define	RFDULEN			255			// 帧数据域长度

//线偏移相偏移
#define	LINEOFFSET		0xFC		//线
#define	PHASEOFFSET		0x03		//相

//控制域结构
#define FUNCODE 		0x0F		//功能码
#define SFV     		0x10		//后续帧有效                                				  X
#define PRM     		0x40		//启动站标志
#define DIR     		/*0x80*/	0x00	//传输方向 ：汇集单元发送为1，采集单元发送为0    X

//prm定义
#define	PRMPRI			0x40
#define	PRMSEC			0x00
//始发站功能码FUNCODE  PRM=1
#define FCRESETUSE      0       	    //复位进程
#define FCRESETFAULT    1       	//复位故障
#define FCSENDDATANA    2       	//发送数据，不需要应答
#define FCSENDDATA      3       	//发送数据，需要应答
#define FCREQUESTD      4       	//请求数据
#define FCREPORTFAULT  5    		//报告故障（采集单元主动）

//从动站功能码定义PRM=0
#define FCCON           0       	    //肯定确认
#define FCNOCON         1       	//否定确认
#define FCRESDATA       2       	//以数据响应请求帧
#define FCNODATA        3       	//无所召唤的数据

//数据域定义：类型标识
#define	TIMESTAMP		0x01		//时标
#define DBALL				0x02		//遥测
#define DBYXTIM			0x03		//遥信
#define DBWAVE			0x04		//遥信带时标
#define DBPARA			0x05		//录波数据
#define DBPROG			0x06		//参数
#define FAULTWRG		0x07		//程序
#define LED					0x08		//测试灯
#define FANPAI				0x09		//测试翻牌
#define	WAKEUP			0x0A		//唤醒射频
#define PHYID				0x0B		//物理地址
//0823添加故障信息标识
#define  DUANLU			0x0C   //短路故障
#define  JIEDI					0x0D   //接地故障
#define  BATLOW			0x0E   //电池电量低故障


//汇集单元内部维护一张地址对应表
struct Capture_Address //作为可设定参数初始化时进行赋值
{
	uint32_t Capture_A_Addres;
	uint32_t Capture_B_Addres;
	uint32_t Capture_C_Addres;
};


//帧接收状态枚举
enum    RXDSTATUS
{
    RXDSTART = 0,       //寻找起始标志状态
    RXDHEAD,            //寻找报文头
    RXDCONTINUE         //接收后续报文
};

struct  FrameInfo
{
	uint8_t		LinkState;
	uint8_t		TimeOutValue;
	uint8_t		TimeOutCounter;
	uint8_t		FrameNum;					//帧数量
	uint8_t		FrameSeq;					//帧序号
	uint16_t  	TxdHead;                  	//处理数据的头
	uint16_t  	TxdTail;					//处理数据的尾
	uint16_t  	TxdLength;					//处理数据的长度
    uint16_t  	RxdHead;                  	//处理数据的头
    uint16_t  	RxdTail;					//处理数据的尾
    uint16_t  	RxdLength;					//处理数据的长度
    enum    	RXDSTATUS RxdStatus;      	//接收状态
    uint8_t		RxdBuf[FRAMEBUFSIZE];       //接收缓冲区 1024
    uint8_t		TxdBuf[LPDUSIZE ];       	//发送缓冲区 1024
};

//struct	DLDevInfo
//{
//
//};
//rf帧结构 数据之外共13字节，13+N
struct PDUFRAME
{
	uint8_t    StartField1;     //起始字节
	uint32_t   Addr;    		//物理地址
	uint16_t   Team;    		//组
	uint8_t	   LinePhase;		//线偏移及相偏移
	uint8_t    StartField2;     //起始字节
	uint8_t    Control;         //控制域
	uint8_t    Len;             //数据长度 第10个
	uint8_t    Data[RFDULEN];   //应用层数据 num
	uint8_t    CheckCode;       //校验码
	uint8_t    EndField;        //结束字符
};


//data域头结构
struct DUHead
{
	uint8_t    TypeID;          //类型标识
	uint8_t    FrameNum;        //帧数量
	uint8_t    FrameSeq;        //帧序号
};

//data数据结构
struct DU
{
    struct 		DUHead Head;
    uint8_t    	Data[RFDULEN-sizeof(struct DUHead)];
};



extern	struct  FrameInfo	FrameRF;
struct  Capture_Address  Collector_List;
extern	uint8_t	RxFlag ;				//接收数据标志
extern	uint8_t	TxFlag  ;				//发送数据标志






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
