#ifndef _NTC_H
#define _NTC_H

#include "includes.h"


typedef struct
{
    uint8_t Error;//1是开路 2是短路
    uint16_t OPEN_Cnt;
	  uint16_t SHORT_Cnt;

} NTC_Sta;

extern NTC_Sta NTC_Hot;
extern NTC_Sta NTC_Cool;

int16_t Cal_NTC_Mixed(uint32_t dat);
int16_t Cal_NTC_HeatTank(uint32_t dat);
int16_t Cal_NTC_Cool(uint32_t dat);
void Temperature_Task();




#endif