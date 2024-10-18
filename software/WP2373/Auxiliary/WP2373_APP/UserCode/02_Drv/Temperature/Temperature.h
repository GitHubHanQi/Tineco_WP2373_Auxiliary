/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2023-12-27 13:50:01
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-27 13:58:50
 */
#ifndef _TEMPERATURE_H
#define _TEMPERATURE_H

#include "includes.h"

typedef enum{
	FirstPowerUp,
	JudgementTrueOrFalse,
	DisplayTrueTemp,
	DisplayFalseTemp,
	TempUp,
}DisplayTemp_Enum;




typedef struct{
	DisplayTemp_Enum DisplayTempStatus;
	int16_t NTC1Temp;
  int16_t NTC2Temp;
	uint32_t NTCCount;
	uint8_t OneNTCNormal;
	uint8_t NTC1ConstantValueErrorFlag;
	uint8_t NTC2ConstantValueErrorFlag;
	uint32_t NTCConstantValueCount;
	uint8_t ErrorFlag;
  int16_t PreviousNTC1Temp;
	int16_t PreviousNTC2Temp;
	uint32_t DisplayCount;
	int16_t DisplayTemp;
	int16_t PreviousTempDisplay;
	
	uint32_t SavePointCnt;
	uint32_t SaveTempCnt;
	int16_t SaveNTC1Temp[25];
	int16_t SaveNTC2Temp[25];
	uint8_t TempErrorLogFlag;
	uint8_t HaveCollect;
	uint32_t HaveCollectCnt;
	uint32_t CollectCnt;
	uint32_t Cnt5s ;
	int16_t Start_Tem;
	int16_t Min_Tem;
	uint32_t Cnt3s;
}Temperature_t;
extern Temperature_t Temperature;


void GetColdWaterBoxTemp(void);
void GetCurrentTemp(void);
int16_t GetNTCTemp(int16_t ADC_Value);
bool GetColdWaterBoxTemp01sLessStopTemp(void);
bool GetColdWaterBoxTemp01sMoreStartTemp(void);

void ScreenTempDisplay_3sUpData(void);
void TempDisplayFunction(void);
void AnalyzeDisplayTemp(void);
void SpecialDisplayTemp(void);


#endif