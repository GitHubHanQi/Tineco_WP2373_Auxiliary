#ifndef _PUMP_H
#define _PUMP_H

#include "includes.h"
//#include "Pump_Soft.h"
//#include "Pump_Stable.h"
//#include "Pump_Check.h"


#define Pump_Power_ON()     PORT_SetBits(PortC, Pin10)
#define Pump_Power_OFF()    PORT_ResetBits(PortC, Pin10)
//////// ADC值 转 电流mA 0.2R
#define ADC_2_PUMP_CURRENT(x)      (uint32_t)((uint16_t)(x) *1100 /273)       // ADC/4095*3300/0.2

#define Pump_PWM_MAX  4800
#define Pump_PWM_MIN  600

typedef enum
{
    PumpState_Stop,
    PumpState_Run,
    PumpState_Error,
} Pump_State_t;


typedef struct
{
  uint8_t Cal_Speed_Flag;//采集转速标记
	uint8_t Cal_Speed_cnt;
  uint16_t CalCampture;
	float Motor_Freq[10];
	uint16_t Motor_Cal_Count;
  uint16_t Cal_Timeout1;
	uint16_t Cal_Timeout2;
} Pump_FG_t;

extern Pump_FG_t Pump_FG;

typedef struct 
{
    uint32_t Tick;

    Pump_State_t State;
	  Pump_State_t LastState;

	  uint32_t Current;
    
	  uint16_t PWMValue;
	  uint16_t Speed;
	    // 0正常工作，1关闭
	//////// 故障
    uint32_t ShortCurrent_Cnt;
    uint32_t OverCurrent_Cnt;
	  uint32_t OpenCurrent_cnt;

//    union
//    {
//        uint8_t Error;
//        struct
//        {
//            uint8_t Error_ShortCurrent  :1;
//            uint8_t Error_OverCurrent0  :1;
//            uint8_t Error_OverCurrent1  :1;
//        };
//    };
	  uint8_t Error;
    bool_t Function_Disable;
	
} Pump_t;
extern Pump_t Pump;

extern Pump_t PressurePump;

#define PressurePump_ON()             {if(PressurePump.State != PumpState_Error) PressurePump.State = PumpState_Run;SET_BIT(ValveState, PressurePump_NUM);}
#define PressurePump_OFF()						{PressurePump.State = PumpState_Stop;CLEAR_BIT(ValveState, PressurePump_NUM);}




void Pump_Open(void);
void Pump_Close(void);
void Pump_Error(void);

void Pump_Task(void);
void Pump_Speed_Cal(void);
void Pump_PWMValue_Set(uint16_t a);
void PressurePump_Task(void);



#endif

