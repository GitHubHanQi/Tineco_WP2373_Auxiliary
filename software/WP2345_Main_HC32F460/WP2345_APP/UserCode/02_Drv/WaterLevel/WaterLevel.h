#ifndef _Water_Level_H
#define _Water_Level_H

#include "includes.h"

#define Level_AD_Max  2700
#define Level_AD_Min  2200
#define Level_AD_Mid  2500

typedef enum
{
	LevelState_Unknow = 0,//δ֪
	LevelState_Empty = 1,
	LevelState_Small = 2,
	LevelState_Mid = 3,
	LevelState_Full = 4,
}LevelState_t;

typedef struct
{
	uint16_t Small_Tick;
	uint16_t Mid_Tick;
	uint16_t High_Tick;
	uint16_t Empty_Tick;
	uint16_t Unknow_Tick;
	LevelState_t State;
	uint8_t WaterLevel_Check;
	uint8_t Percent;
	uint8_t err;
}WaterLevel_t;


extern WaterLevel_t WaterLevel_Inf;

void WaterLevel_Task();
void WaterLevel_Check();
void WaterLevel_Check1();


#endif