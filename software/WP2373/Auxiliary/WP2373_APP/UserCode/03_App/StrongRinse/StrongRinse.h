/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2024-01-15 09:35:24
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-01-15 10:09:37
 */
#ifndef _STRONGRINSE_H
#define _STRONGRINSE_H

#include "includes.h"

typedef enum{
	AuxiliaryFlushing_Init = 0,
	AuxiliaryFlushing_AddCoolWaterToColdWaterBox,
	AuxiliaryFlushing_AddColdWaterToCarbonationTank1,
	AuxiliaryFlushing_AddColdWaterToCarbonationTank2,
	AuxiliaryFlushing_AddColdWaterToCarbonationTank3,
	AuxiliaryFlushing_AddColdWaterToCarbonationTank4,
	AuxiliaryFlushing_OutSparklingWater1,
	AuxiliaryFlushing_OutSparklingWater2,
	AuxiliaryFlushing_OutColdWater,
	AuxiliaryFlushing_End,
}AuxiliaryFlushingStatus_t;

typedef struct{
	uint8_t Flag;
	uint8_t NeedFlushingFlag;
	AuxiliaryFlushingStatus_t Status;
	uint32_t OutColdWaterCnt;
	uint32_t CommunicationDelay;
	uint8_t HostReplyAuxiliaryFlushingFlag;
	uint8_t WholeMachineWorkStateFlushingFlag;
	
	uint32_t BoilingPointLearnCnt;
	uint32_t SparklingAddCnt;
	uint32_t OutSparklingWater2Cnt;
	uint32_t FlushOverFlag;
	
	uint32_t MaxFlushTime;
	
}AuxiliaryFlushing_t;
extern AuxiliaryFlushing_t AuxiliaryFlushing;

void StrongRinseFunction(void);
void AuxiliaryFlushingFunction(void);
void AuxiliaryFlushInfo(void);

void WaitHostBoilingPointLearning(void);
void NormalGotoStrongRinse(void);
void NormalGotoBoilingPointLearning(void);

void NormalGotoCarbonTankFlush(void);
void NormalGotoAllFlushing(void);

void CarbonTankFlushFunction(void);
void AllFlushingFunction(void);


#endif