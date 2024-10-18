#ifndef _TIM1_H
#define _TIM1_H

#include "includes.h"


void TIM1_Init(void);

void TIM1_CHA_DutySet(uint16_t x);
void Brush_Duty_Set(uint16_t x);



//void Motor_Brush_Duty_Set(uint16_t MotorDuty);


#endif
