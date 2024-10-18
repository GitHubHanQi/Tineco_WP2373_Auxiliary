#ifndef _TIM2_H
#define _TIM2_H

#include "includes.h"

#define TMR_UNIT            (M4_TMR02)
#define TMR_Period          (4800)



void TIM02_A_Init(void);

void Timer02A_CallBack(void);

#endif
