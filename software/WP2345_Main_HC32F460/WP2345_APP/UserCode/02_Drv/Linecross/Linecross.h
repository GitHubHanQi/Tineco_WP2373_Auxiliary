#ifndef _LINECROSS_H
#define _LINECROSS_H

#include "includes.h"


typedef struct
{
	uint8_t time_delay;
	uint8_t wait_flag;
	uint8_t Line_Count;
}Linecross_t;
extern Linecross_t Linecross;


typedef enum
{
    Heat_Stop,
    Heat_HighPower,
    Heat_SmallPower,
	  Heat_Err,
} Heat_State_t;


typedef struct
{
	Heat_State_t State;
	uint32_t tick;
  int16_t Start_Heat_Tem;
}Heat_t;

extern Heat_t Heat;

void Real_LineCross_Task(void);
void Heat_Task(void);
void SmallHeat_Zero_OPEN(void);
void Heat_Status_Set(Heat_State_t State);
#endif

