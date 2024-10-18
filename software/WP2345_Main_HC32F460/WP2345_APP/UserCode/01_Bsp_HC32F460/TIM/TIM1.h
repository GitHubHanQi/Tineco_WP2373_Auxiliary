#ifndef _TIM1_H
#define _TIM1_H

#include "includes.h"


void TIM1_Init(void);
//void TIMA_4_Init(void);
//void TIMA_6_Init(void);

void TIM1_CHA_DutySet(uint16_t x);
void Brush_Duty_Set(uint16_t x);
void DAC_ValueSet3(uint16_t value);
//void DAC_ValueSet4(uint16_t value);

void TIMA1_6_Foc_Levl(en_timera_specify_output_t enOutputSta);



#endif
