#ifndef _CHARGER_H
#define _CHARGER_H

#include "includes.h"



//////// 充电器电压
// 有无充电器
#define CHARGER_THRESHOLD_UnderVoltage_L    (1500 *CELL_AMOUNT)     // 无充电器时实测值为7V
#define CHARGER_THRESHOLD_UnderVoltage_H    (2000 *CELL_AMOUNT)

// 是否过压
#define CHARGER_THRESHOLD_OverVoltage_L     (5000 *CELL_AMOUNT)
#define CHARGER_THRESHOLD_OverVoltage_H     (5500 *CELL_AMOUNT)




typedef struct 
{
    uint32_t Tick;
    uint8_t State;

    uint16_t ADC_Value;
    uint16_t Voltage;
} Charger_t;


extern Charger_t Charger;

void Charger_Task(void);


#endif
