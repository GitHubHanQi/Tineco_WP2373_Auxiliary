#ifndef _WarmWater_H
#define _WarmWater_H

#include "includes.h"

#define Dead_Time 35

typedef struct
{
	uint8_t TargetTem;//Ŀ���¶�
  uint8_t TemErr1;//��ˮ��Ŀ���¶Ȳ�
  uint8_t TemErr2;//��ˮ��Ŀ���¶Ȳ�
	float HotScale;//��ˮ����
  float CoolScale;//��ˮ����
	uint16_t MixRatioCnt;//���ػ��ˮ
} MixWater_t;

extern MixWater_t MixWater;

extern uint32_t D_Time_cnt;
void WarmWaterCtr(void);
void waterFlowControl(float Ratio); 

#endif