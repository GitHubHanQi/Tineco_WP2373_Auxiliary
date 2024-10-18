#ifndef _PHONE_H
#define _PHONE_H

#include "includes.h"



#include "Phone_Set.h"
#include "Phone_WorkMode.h"
#include "Phone_Error.h"


typedef struct
{
    uint32_t CtrlDataSource_Tick;   // 主机按后不受控0.5s的计数
    bool_t CtrlDataSource;          // 0允许手机控制，1禁止手机控制
    //uint8_t From_Finger_State;      // 0未触摸，1正在触摸


    Phone_WorkMode_t AppState;
    uint8_t SelfClean_State;    // 0关闭，1开启
    uint8_t Clean_Mode;         // 0自动模式，1强力模式，2手动模式 3吸水模式 4消毒模式
	uint8_t CleanModeReport;	// 0自动 
    uint8_t Cleanse;          // 消毒
	uint8_t SuctionorMax;
	
    uint8_t Battery_Percent;    // 0~100, 240
    uint16_t Battery_Capacity;  

    uint8_t Vacuum_Level;
    uint8_t Pump_Level;

    uint8_t Voice_Mute;     // 0~1
    uint8_t Voice_Level;    // 1~5
    uint8_t Voice_Select;   // 1~10

    uint8_t Dust_Mode;
    uint8_t Dust_Value;
	
	uint8_t SelfCleanSubState;  // 自清洁状态
	
    uint16_t Error;
	uint16_t ErrorLog;
} Phone_t;
extern Phone_t Phone;


void Phone_Task(void);





#endif
