/*
 * @Author: your name
 * @Date: 2020-10-26 16:09:52
 * @LastEditTime: 2020-10-29 15:48:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CL2019_芙万二代_直接\UserCode\01_Bsp_HC32L196\TIM\TIM3.h
 */
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

void TIM3_Init(void);


//void Pump_PwmSet(uint16_t Frec, uint16_t Duty);
void Bsp_Pump_Duty_Set(uint16_t x);
extern  void Pump_ALL_Off(void);
extern  void Pump_ALL_On(void);
#endif
