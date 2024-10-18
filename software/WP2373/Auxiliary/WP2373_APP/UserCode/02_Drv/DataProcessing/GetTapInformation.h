/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2023-12-27 14:06:29
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-27 14:22:04
 */

#ifndef _GETTAPINFORMATION_H
#define _GETTAPINFORMATION_H
#include "includes.h"

typedef struct {
  uint8_t ColdWaterPress;
  uint8_t SparklingWaterPress;
  uint8_t CoolWaterPress;
} Key_Value_t;
extern Key_Value_t Key;

void GetColdWaterLevel(void);
void GetKeyInformation(void);

void GetCarbonationTankLowVoltage(void);
void GetTapCompressorStopTemp(void);
void EnteringOperatingMode(void);
void ReportDisablePart2Status(void);


#endif