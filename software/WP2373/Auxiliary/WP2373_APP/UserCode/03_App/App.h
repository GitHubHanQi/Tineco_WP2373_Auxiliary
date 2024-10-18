/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2024-01-03 14:09:45
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-01-15 09:17:04
 */

#ifndef _APP_H
#define _APP_H
#include "includes.h"

#include "StrongRinse.h"
#include "OTA.h"
#include "Fault.h"
#include "test.h"
#include "UserState_Goto.h"


typedef enum {
	AppState_Init = 0,
	AppState_ProductionTest,
  AppState_HostStrongRines ,           // 强冲
	AppState_AuxiliaryFlushing,
  AppState_HostBoilingPointLearning,             // 主机沸点学习
  AppState_AuxiliaryNormalOperation,  // 正常运转
	AppState_CarbonTankFlush,
	AppState_AllFlushing,
  AppState_Error,                     // 故障
	AppState_Test,
  AppState_ProgramOTA,                // OTA
	AppState_Program,
} AppState_Enum;

typedef struct {
	AppState_Enum State;
  uint32_t Tick_ms;
	uint8_t NormalOperateFlag;
	uint8_t ClearLoadFlag;
} App_t;
extern App_t App;

void App_Task(void);
void AppStateInitFunction(void);
void NormalGotoProductionTest(void);

void UserState_Goto(AppState_Enum state);






#endif
