#ifndef _BATTERY_H
#define _BATTERY_H

#include "includes.h"


#define BATTERY_CELL_AMOUNT     (6)     // 串联的电池个数



#define BMS_STR_VERSION_MAX     (12)
#define BMS_STR_ID_MAX          (8+10+3)  // // 8)日期，10)SN

typedef enum
{
    BmsType_Dc,
    BmsType_True,
    //BmsType_Tester
} Battery_Type_t;


typedef struct 
{
    uint32_t Tick;

    bool_t IsReady;

    uint8_t Persent;
    uint16_t Voltage;


    bool_t Type_IsIdenfified;
    Battery_Type_t Type_Byte;


    bool_t Version_IsReady;
    char Version_String[BMS_STR_VERSION_MAX];

    bool_t Id_IsReady;
    char Id_String[BMS_STR_ID_MAX];

    bool_t Voltage_IsReady;
    uint32_t Voltage_Total;

    bool_t CurTemp_IsReady;
    uint16_t Current;           // 电流
    uint16_t Temperature;       // 温度

    bool_t Capacity_IsReady;    //// 完成标志
    uint8_t Percent;

    uint8_t SelfState;             // 电池状态
    
    uint16_t Capacity_Total;  // 总容量
	
//	uint16_t Capacity_Single[6];  // 单节容量
	
    uint16_t LoopTimes;


} Battery_t;
extern Battery_t Battery;


void Battery_Task(void);
void Battery_GetId_String(char *pStr);
void Battery_GetVersion_Strring(char *pStr);

#endif
