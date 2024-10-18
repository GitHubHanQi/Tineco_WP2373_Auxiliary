#ifndef _WaterFlow_H
#define _WaterFlow_H

#include "includes.h"

typedef struct
{
  uint8_t START_1S_FLAG;
	uint32_t plus_Cnt;

	uint8_t cal_flag;
	uint16_t CalCampture;
	uint16_t Cal_irq_Cnt;

	float freq;
	float freq_buff[10];
	uint16_t freq_cnt;
  float averagefreq;
	
	uint16_t Time_Count;
	uint16_t level_L_Time;
	uint16_t level_H_Time;
	
	uint16_t FlowValue;
	uint16_t AverFlowValue;
	
	uint8_t NOTHaveWater;//
	uint8_t Error;

} WaterFlow_t;

extern WaterFlow_t WaterFlow;


void Water_Flow_Cal(void);


#endif