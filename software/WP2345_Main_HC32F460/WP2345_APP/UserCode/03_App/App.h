#ifndef _APP_H
#define _APP_H

#include "SelfClean.h"
#include "WifiPair.h"
#include "BoilPoint.h"
#include "WarmWater.h"
#include "SupplyWater.h"
#include "Heat.h"
#include "User.h"
#include "includes.h"

#define	SET_BIT(x, bit)	  (x |=  (1 << bit))	/* 清零第bit位 */
#define	CLEAR_BIT(x, bit)	(x &= ~(1 << bit))	/* 清零第bit位 */


typedef enum
{
	AppState_StrongRinse,//强冲
	AppState_Study,//沸点学习
	AppState_NormalWork,//正常工作
//	AppState_WifiPair,//WIFI配网
	AppState_Err,        //故障  
	AppState_Test,       //测试 
	AppState_Program,    //IAP升级    
	AppState_ProgramOTA, //本机升级  
} App_State_t;


typedef struct
{
  uint32_t Tick_ms;
  App_State_t State;
} App_t;
extern App_t App;


typedef enum
{
	Supply_stop=0,
	Supply_run,
	Supply_pause,	
}SupplyWater_t;


typedef struct
{
	uint8_t LockFlag;//童锁 后面可能取消了
	int16_t HeatTank_Tem;//加热水胆温度
  int16_t Cool_Tem;//冷水温度
	uint8_t Err_Code;//主机故障码
	uint16_t SystemErrFlag;//主机故障 每一个bit对应一个故障
	uint8_t BeepCount;//蜂鸣器响几声
	SupplyWater_t SuppleWater;//补水标记
	uint8_t KeepWarmFlag;//保温标记
	uint8_t ShowHeatFlag;//加热标记-控制龙头显示
	uint8_t HeatOverFlag;//热水加热完置位
	uint8_t ForbidFlag;//禁止用水标记
	uint8_t StandbyFlag;//超长待机
	uint8_t DrainFlag;//排水标记
	uint8_t PureWaterBackFlag;//回流
	uint8_t ReplaceFilterElement;//更换滤芯标记
	uint32_t WaterTotal;//单次用水量
	uint32_t WaterTotal_1;//单次用水量
	uint32_t LastWaterTotal;//单次用水量
	waste_level_t AdjustDrainOUT_Level;//废水阀调整档位
	uint16_t Unlock_tick;//解锁未操作计时
}Work_Para_t;
extern Work_Para_t Work_Para;

extern uint16_t  ValveState;

void App_Task(void);
void CloseAllLoad(void);
void SystemErrorProess(void);
void Valve_Test(void);
#endif
