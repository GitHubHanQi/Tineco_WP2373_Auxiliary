#ifndef _APP_PARAMETER_H
#define _APP_PARAMETER_H

#include "includes.h"



////extern volatile uint8_t ToolSn[];
//extern const uint8_t ToolVersion[];
////extern uint8_t VoiceVersion[];

//extern volatile uint8_t PanelVersion[10];


//////// BMS

//extern volatile Battery_Type_t Battery.Type_Byte;
//extern volatile bool_t Battery.Type_IsIdenfified;



//#define BMS_STR_VERSION_MAX     (12)
//extern volatile bool_t Battery.Version_IsReady;
//extern volatile uint8_t Battery.Version_String[];

//#define BMS_STR_ID_MAX          (8+10+3)  // // 8)日期，10)SN
//extern volatile bool_t Battery.Id_IsReady;
//extern volatile uint8_t Battery.Id_String[];



//extern volatile uint32_t Battery.Voltage_Total;
//extern volatile uint32_t BmsVoltageC1;
//extern volatile uint32_t BmsVoltageC2;
//extern volatile uint32_t BmsVoltageC3;
//extern volatile uint32_t BmsVoltageC4;
//extern volatile uint32_t BmsVoltageC5;
//extern volatile uint32_t BmsVoltageC6;

//extern volatile uint16_t Battery.Current;           // 电流
//extern volatile uint16_t Battery.Temperature;       // 温度


#define BMS_CAPACITY_SHORTAGEE  (10)    // 电量<=10%
#define BMS_CAPACITY_SHORTAGE   (20)    // 电量<=20%
//extern volatile uint8_t Battery.Percent;    // 电量百分比(%) 0~100
//extern volatile uint8_t Battery.SelfState;         // 电池状态，0)正常, 1)异常
    #define BMS_SELF_STATE_Normal       (0x00)  // 未知
    #define BMS_SELF_STATE_Discharge    (0x1A)  // 正常放电
    #define BMS_SELF_STATE_Charge       (0x0A)  // 正常充电
    #define BMS_SELF_STATE_OverHeat     (0x01)  // 充电时过热
    #define BMS_SELF_STATE_OverCurrent  (0x02)  // 充电时过流
    #define BMS_SELF_STATE_1005         (0xF0)  // 充满100%再过5分钟
    #define BMS_SELF_STATE_OverTime     (0xF1)  // 充电超时
//extern volatile uint16_t Battery.Capacity;
//extern volatile uint16_t Battery.LoopTimes;

//extern volatile bool_t Battery.Voltage_IsReady;
//extern volatile bool_t Battery.CurTemp_IsReady;
//extern volatile bool_t Battery.Capacity_IsReady;



#endif

