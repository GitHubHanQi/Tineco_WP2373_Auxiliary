#ifndef _BRUSH_SOFT_H
#define _BRUSH_SOFT_H

#include "includes.h"



#define BRUSH_DUTY_MIN      (200)   // 软启动开始的占空比
#define BRUSH_DUTY_MAX      (1000)  // TOP

extern void Brush_Soft_Task(void);
extern void Brush_Duty_Target_Set(uint16_t x);

#endif

