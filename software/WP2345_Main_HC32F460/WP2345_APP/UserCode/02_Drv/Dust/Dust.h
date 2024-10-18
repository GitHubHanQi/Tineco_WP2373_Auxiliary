#ifndef _DUST_H
#define _DUST_H

#include "includes.h"



//#define DUST_CALIBRATE_EN



#define DUST_ERROR_DELAY    (ELAPSE_5s)
#define DUST_INPUT_BUF_SIZE (10)


typedef enum
{
    DustState_Stop,
    DustState_Check_OutputLow,
    DustState_Check_OutputHigh,
    DustState_Calibrate,                // 校准
    DustState_Caculate,                 // 计算
} Dust_State_t;


typedef struct
{
    uint16_t Tick;
    Dust_State_t State;
    bool_t Error;

    uint16_t Output_DAC;
    uint16_t Output_Voltage;
    //uint16_t Input_ADC_Buf[DUST_INPUT_BUF_SIZE];

    //////// 校准
    uint16_t Input_ADC_10ms[DUST_INPUT_BUF_SIZE];
    uint16_t Input_Tick_10ms;
    //
    uint16_t Input_ADC_100ms[DUST_INPUT_BUF_SIZE];
    uint16_t Input_Tick_100ms;


    uint16_t Input_ADC_Flittered;
    //uint16_t Input_Voltage;

//    uint16_t ADC_Value_Check_Low;
//    uint16_t ADC_Value_Check_High;
    uint16_t Analog_Error_Tick;
} Dust_t;
extern Dust_t Dust;



extern bool_t DustSensor_WarnningState;
extern uint16_t Dust_Scale;

void Dust_Clear(void);
void Dust_Start(void);
void Dust_Stop(void);
void Dust_Task(void);



#include "Dust_Analog.h"
#include "Dust_Caculate.h"

#endif
