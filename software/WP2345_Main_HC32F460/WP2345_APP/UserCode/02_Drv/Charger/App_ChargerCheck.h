#ifndef _APP_CHARGER_CHECK_H
#define _APP_CHARGER_CHECK_H


#include "includes.h"


extern uint32_t ChargeCheck_Tick_ms;

typedef enum
{
	ChargerCheckState_Unknow,
	ChargerCheckState_ChargerOff,
	ChargerCheckState_ChargerOn
} ChargerCheck_State_t;

extern volatile ChargerCheck_State_t ChargerCheck_State;

extern volatile ChargerCheck_State_t ChargerCheck_VoltageState;

extern volatile bool_t ChargeStateKeep1005;

void ChargerCheck_Task(void);





#endif

