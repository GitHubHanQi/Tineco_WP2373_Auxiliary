#ifndef _PUMP_SOFT_H
#define _PUMP_SOFT_H

#include "includes.h"


#if (PUMP_TYPE == PUMP_TYOE_ELECTROMAGNETIC)
	#define PUMP_DUTY_MIN      (10)   // 软启动开始的占空比
#elif (PUMP_TYPE == PUMP_TYOE_PERISTALTIC)
	#define PUMP_DUTY_MIN      (1)   //  蠕动泵以周期来控制
#endif

#define PUMP_DUTY_MAX      (1000)  // TOP

//extern void Pump_Soft_Task(void);
extern void Pump_Duty_Target_Set(uint16_t x);

#endif

