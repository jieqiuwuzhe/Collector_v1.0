/******************************************************************************
*  	名称：	DataBase.H
*  	日期:	2016-8-5
*  	作者:  	赵传强
******************************************************************************/

#ifndef DATABASE_H_
#define DATABASE_H_

#define	DBWLEN			8000			//按1s存储量，每周波80点，共4000点，8KB，两个adc通道就是16K
#define	FAULTWLEN		3200				//10个周波上送量

struct	WAVE
{
	uint32_t	FaultTime;
	uint32_t	StartTime;
	int16_t		Wave[DBWLEN];
	int16_t		*pReadWave;
	int16_t		*pEndWave;
};

struct	YCInfo
{
	uint16_t	I;				//电流
	uint16_t	U;				//电场
	uint16_t	Tofline;		//线温
	uint16_t	UofB;			//电池电压
};

struct	YXInfo
{

};

extern	struct	WAVE	Wave;

extern	uint32_t	Faultpoint;
extern	int16_t		FaultWave[FAULTWLEN];


void	InitDBWave(void);
















#endif /* DATABASE_H_ */
