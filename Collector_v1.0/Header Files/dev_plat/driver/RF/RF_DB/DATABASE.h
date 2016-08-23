/******************************************************************************
*  	���ƣ�	DataBase.H
*  	����:	2016-8-5
*  	����:  	�Դ�ǿ
******************************************************************************/

#ifndef DATABASE_H_
#define DATABASE_H_

#define	DBWLEN			8000			//��1s�洢����ÿ�ܲ�80�㣬��4000�㣬8KB������adcͨ������16K
#define	FAULTWLEN		3200				//10���ܲ�������

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
	uint16_t	I;				//����
	uint16_t	U;				//�糡
	uint16_t	Tofline;		//����
	uint16_t	UofB;			//��ص�ѹ
};

struct	YXInfo
{

};

extern	struct	WAVE	Wave;

extern	uint32_t	Faultpoint;
extern	int16_t		FaultWave[FAULTWLEN];


void	InitDBWave(void);
















#endif /* DATABASE_H_ */
