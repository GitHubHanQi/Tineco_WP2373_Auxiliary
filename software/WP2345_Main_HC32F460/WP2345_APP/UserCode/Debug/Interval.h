#ifndef _INTERVAL_H
#define _INTERVAL_H

#include "includes.h"

typedef struct 
{
    uint32_t TimerValue_Start;
    
    //
    uint32_t Period;
    uint32_t Period_Min;
    uint32_t Period_Max;

    //
    uint32_t Interval;
    uint32_t Interval_Min;
    uint32_t Interval_Max;
} Interval_t;
extern Interval_t Interval;

extern void Interval_Start(void);
extern void Interval_Stop(void);

#endif
