#ifndef _WarmWater_H
#define _WarmWater_H

#include "includes.h"

#define Dead_Time 35

typedef struct
{
	uint8_t TargetTem;//目标温度
  uint8_t TemErr1;//冷水与目标温度差
  uint8_t TemErr2;//热水与目标温度差
	float HotScale;//热水比例
  float CoolScale;//冷水比例
	uint16_t MixRatioCnt;//调控混合水
} MixWater_t;

extern MixWater_t MixWater;

extern uint32_t D_Time_cnt;
void WarmWaterCtr(void);
void waterFlowControl(float Ratio); 

#endif