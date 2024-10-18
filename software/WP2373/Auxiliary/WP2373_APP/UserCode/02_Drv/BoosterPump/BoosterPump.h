/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2023-12-27 09:20:55
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-27 13:30:24
 */
#ifndef _BOOSTERPUMP_H
#define _BOOSTERPUMP_H
#include "includes.h"
typedef struct {
  uint8_t FirstStart;
  uint8_t Flag;
  uint32_t Cnt;
	uint8_t CommTesterOpenFlag;
} BoosterPump_t;
extern BoosterPump_t BoosterPump;


void BoosterPumpWorkingMore1min(void);
bool Pump_C1_ON(void);//返回bool，判断软启动是否实现
void Pump_C1_OFF(void);

void CommTesterOpenBoosterPump(void);

#endif