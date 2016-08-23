/******************************************************************************
*  	名称：	DATABASE.c
*  	功能：	数据库处理相关，存储波形数据
*  	日期:	2016-8-5
*  	作者:  	赵传强
* 	修改:
******************************************************************************/
#include	"RF_include.h"

struct	WAVE	 Wave;					// 录波缓存 电流电场混存


uint32_t	Faultpoint;					//故障点时标，timer计数器内容
int16_t		FaultWave[FAULTWLEN];		//故障波形备份，发生adc中断时从DBWave中读出，用于上送汇集单元。



/****************************************************************************
 * 名称：BOOL	InitDBWave(void)
 * 功能：初始化录波数据库
 * 输入参数:无
 * 返回值:无
 *****************************************************************************/
void	InitDBWave(void)
{
	memset(&Wave,0,sizeof(struct	WAVE));
	Wave.pReadWave = Wave.Wave;
	Wave.pEndWave = Wave.Wave + DBWLEN - 1;
	Wave.FaultTime = 0;
	Wave.StartTime = 0;
}





