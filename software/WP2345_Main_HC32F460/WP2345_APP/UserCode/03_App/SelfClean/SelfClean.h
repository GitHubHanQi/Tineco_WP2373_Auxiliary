#ifndef _SELFCLEAN_H
#define _SELFCLEAN_H

#include "includes.h"

typedef struct
{
	uint8_t FilterClearingFlag;//滤芯清洗标记
  uint32_t FilterClearingCnt;//清洗时间计数
  uint32_t CheckFilterClearingCnt;//累计时长直到需要清洗
}
FilterClear_t;

extern FilterClear_t FilterClean;


void StrongRinse_Task(void);
void Short_FilterElementClearing(uint32_t ticks);
void Long_FilterElementClearing(uint32_t ticks);
void FilterCheckAndClean(void);

void PureWaterBack(void);








#endif


