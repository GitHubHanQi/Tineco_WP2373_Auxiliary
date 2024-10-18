/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2024-01-09 17:52:45
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-01-09 18:10:49
 */

#ifndef _GETHOSTINFORMATION_H
#define _GETHOSTINFORMATION_H

#include "includes.h"

typedef struct {
	uint8_t HotWaterTankAddWaterStatus;
	uint8_t HotStatus;
	uint8_t BoilingPointLearningFlag;
	uint8_t CompletionBoilingPointStudyFlag;
	uint8_t ReplaceCoreFlag;
	uint8_t CarbonTankFlush;
	uint8_t AllFlushing;
	uint8_t HostHotTemp;
}HostStatus_t;
extern HostStatus_t HostStatus;

uint8_t Get_HostHotWorkingStats(void);
uint8_t GetSystemErrorStatus(void);
void SendColdWaterTempToScreen(void);
bool GetHostOutWaterStatus(void);
void DistinguishAddWaterOrOutWater(void);
void GetHotWaterTankStatus(void);
void ZeroByKeyFunction(void);
void SendColdWaterStatusToTap(void);
void GetAuxiliaryFunctionSwitchgear(void);
void SendAuxiliaryErrorCode(void);
void GetHostSendAuxiliaryFlushingStatus(void);
void GetWholeMachineWorkStateFlushingStatus(void);

void GetHostReplaceCoreStrongRinseStatus(void);

void GetProductionTestStatus(void);

void GetHostBoilingPointLearning(void);

void GetHostFlushInformation(void);

void GetAuxiliaryLevel(void);



#endif