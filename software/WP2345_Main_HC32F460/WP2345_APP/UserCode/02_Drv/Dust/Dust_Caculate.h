#ifndef _DUST_CACULATE_H
#define _DUST_CACULATE_H

#include "includes.h"


#define DUST_VALUE_MIN  (0)
#define DUST_VALUE_MAX  (300)  // 用作灰尘环的最大值



extern volatile uint8_t DustVoltage_cnt2; 
extern volatile uint32_t  ADC_Value_Average_100ms_F;
void Dust_Caculate(void);



#endif
