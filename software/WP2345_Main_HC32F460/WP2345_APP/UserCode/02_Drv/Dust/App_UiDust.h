#ifndef _APP_UI_DUST_H
#define _APP_UI_DUST_H

#include "includes.h"




extern volatile uint16_t Panel_DustValue;
extern volatile int16_t Panel_DustValueDelayed;
extern volatile uint8_t Phone_DustValue;
extern volatile uint8_t Flag_PourWater;
extern volatile uint16_t PourWater_cnt;

extern volatile uint16_t VoltageSend,VoltageDAC,VoltageADC;
extern volatile uint16_t Dust_Sensor_Standard;
extern volatile uint16_t Dust_Sensor_Max;
void UiDust_Task(void);


uint16_t PanelDust_DutyFromDust(uint16_t DustValue);
uint16_t UiColorDust_DutyDelay(uint16_t duty);
void PanelDust_Clear(void);



#endif

