#ifndef _PUMP_STABLE_H
#define _PUMP_STABLE_H

#include "includes.h"



typedef struct
{
    uint16_t Voltage;
    uint16_t Duty;
} Pump_Parameter_t;



void Pump_Stable_Task(void);

void Set_Pump_Level(void);
void Auto_Pump_Level(void);

#ifdef MOREWATER
extern  uint8_t g_morewater;
#endif


#if (PUMP_TYPE == PUMP_TYOE_PERISTALTIC)
	#define PUMP_30ML_MULTIPLE   1.75
	#define PUMP_100ML_MULTIPLE  1.9
	extern Pump_Parameter_t Pump_Parameter_30[];
	extern Pump_Parameter_t Pump_Parameter_100[];
#elif (PUMP_TYPE == PUMP_TYOE_ELECTROMAGNETIC)
	#define PUMP_30ML_MULTIPLE   1
	#define PUMP_100ML_MULTIPLE  1	
	#define PUMP_X2_K			4.003e-5
	#define PUMP_X1_K			0.09048
	#define PUMP_K				115.5
	
//	#define PUMPCHOPPER  1
#endif

#endif

