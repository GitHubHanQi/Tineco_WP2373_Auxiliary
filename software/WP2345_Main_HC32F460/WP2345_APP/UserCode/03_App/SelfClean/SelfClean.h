#ifndef _SELFCLEAN_H
#define _SELFCLEAN_H

#include "includes.h"

typedef struct
{
	uint8_t FilterClearingFlag;//��о��ϴ���
  uint32_t FilterClearingCnt;//��ϴʱ�����
  uint32_t CheckFilterClearingCnt;//�ۼ�ʱ��ֱ����Ҫ��ϴ
}
FilterClear_t;

extern FilterClear_t FilterClean;


void StrongRinse_Task(void);
void Short_FilterElementClearing(uint32_t ticks);
void Long_FilterElementClearing(uint32_t ticks);
void FilterCheckAndClean(void);

void PureWaterBack(void);








#endif


