
#ifndef _TIM3_H
#define _TIM3_H

#include "includes.h"


typedef struct 
{
    uint16_t RegPeriod;     // 寄存器的TOP值
    uint16_t Frec;          // Hz
    uint16_t Duty;          // 千分比
} TIM3_t;

#define TIME_PREIOR_1MS    3000
#define TIME_PREIOR_2MS    6000
#define TIME_PREIOR_20MS   60000   // 上限65535

#define TIMER4_UNIT                     (M4_TMR41)										//(M4_TMR43)
/* Timer4 OCO */
#define TIMER4_OCO_HIGH_CH              (Timer4OcoOwl)								//	(Timer4OcoOvh)      /* only Timer4OcoOuh  Timer4OcoOvh  Timer4OcoOwh */
/* Timer4 PWM */
#define TIMER4_PWM_CH                  	(Timer4PwmW)									// (Timer4PwmV)        /* only Timer4PwmU  Timer4PwmV  Timer4PwmW */


void TIM3_Init(void);


//void Pump_PwmSet(uint16_t Frec, uint16_t Duty);
void Bsp_Pump_Duty_Set(uint16_t x);

#endif
