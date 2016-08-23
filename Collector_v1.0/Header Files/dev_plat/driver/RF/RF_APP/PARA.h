/*
 * PARA.h
 *
 *  Created on: 2016-8-9
 *      Author: qd
 */

#ifndef PARA_H_
#define PARA_H_


#pragma pack(1)

struct	PARA
{
	uint16_t	TeamNum;//×éºÅ
	uint8_t		LinePhase;//ÏßÆ«ÒÆ ÏàÆ«ÒÆ
	uint8_t		WaveNUMHead_Para;
	uint8_t		WaveNUMEnd_Para;
	uint8_t		SampleNUMperWave_Para;
	uint8_t		YCPeriod_Para;
	uint8_t		FaultResetTime_Para;


};
//struct	SHORTFAULTPARA
//{
//
//};

#pragma pack()

extern	struct	PARA	SysPara;




BOOL	InitPara(void);




#endif /* PARA_H_ */
