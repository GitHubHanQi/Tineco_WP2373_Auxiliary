#ifndef _BoilPoint_H
#define _BoilPoint_H

#include "includes.h"
typedef enum
{
	Unknow_Step=0,//初始化状态
	Drain_Out_Step,//排空
  Supply_Step,//补水
	Heat_Step,//加热
	Learn_Over_Step,//学习完成
	Over_Drain_Out_Step,//排出
	Learn_Err,
} learn_step_t;


typedef struct
{
	uint8_t LearnStep;
	uint32_t DrainOut_tick;//排水
	int16_t MaxHeatTank_Tem;
  int16_t StartHeatTank_Tem;
	uint32_t STimeCnt;//小功率加热时间
  uint8_t LearnStart;//控制功率
  uint32_t LearnHeatTime;//学习时间
  uint16_t TemUP_Tick;//温升时间
	int16_t BoilPointTem;//沸点
	
	uint16_t Heat_Tick;//加热时间

} BoilPoint_t;
extern BoilPoint_t BoilPoint;
void BoilPointLearn(void);













#endif