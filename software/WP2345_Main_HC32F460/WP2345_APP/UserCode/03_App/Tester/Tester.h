#ifndef _TESTER_H
#define _TESTER_H

#include "includes.h"


typedef struct
{
    uint32_t Tick;

    enum
    {
        TesterPanelState_AllOff,
        TesterPanelState_AllOnRed,
        TesterPanelState_AllOnBlue,
		TesterPanelState_AllOnGreen,
	    TesterPanelState_AllOnWhite,
    } PanelTester_State;

    uint8_t Percent;
} Tester_t;
extern Tester_t Tester;


void Tester_Start(void);
void Tester_Stop(void);
void Tester_Task(void);


#endif

