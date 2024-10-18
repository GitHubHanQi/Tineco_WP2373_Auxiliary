#ifndef _SLAGKEY_H
#define _SLAGKEY_H

#include "includes.h"

typedef enum
{
	SlagKeyState_Unknow,
	SlagKeyState_Release,
	SlagKeyState_Press,
}SlagKey_State_t;

typedef struct
{
	uint32_t Release_Tick;
	uint32_t Press_Tick;
	
	SlagKey_State_t State;
}SlagKey_t;

extern SlagKey_t SlagKey;

extern volatile uint8_t Clean_SlagKey_Flag;

bool_t SlagKey_Read(void);
void SlagKey_Task(void);
void SlagKey_SingleClick_Event(void);


#endif

