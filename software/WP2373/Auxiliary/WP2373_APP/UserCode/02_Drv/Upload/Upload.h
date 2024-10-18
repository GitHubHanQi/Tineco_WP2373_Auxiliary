#ifndef _UPLOAD_H
#define _UPLOAD_H

#include "includes.h"

typedef struct
{
  uint8_t Flag;
  // 制冷状态事件
  uint8_t Compressor;
  uint32_t CompressorCnt;
  int16_t NTC1;
  int16_t NTC2;
  int16_t ShowTemp;
	
  uint8_t ColdingUploadFlag;
  // 碳化罐事件
  uint8_t CarbonationTankUploadFlag;
  uint8_t CarbonTankWorkStatus;
	uint8_t CarbonationTankUploadEnd;
  uint32_t CarbonTankCnt;
  uint32_t OpenCnt;
  uint16_t HighLiquidLevel[20];
  uint16_t LowLiquidLevel[20];
  uint8_t ErrorFlag;

} UploadSend_t;

extern UploadSend_t UploadSend;

uint16_t StringCopy(volatile uint8_t *pStrTo, const uint8_t *pStrFrom);
void PlantSeedlingTask(void);

#endif