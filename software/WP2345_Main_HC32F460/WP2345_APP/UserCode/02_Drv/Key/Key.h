#ifndef _KEY_H
#define _KEY_H

#include "includes.h"


typedef enum
{
	State_Unknow = 0,//上电初始
	State_Installed = 1,//已安装
	State_Uninstalled = 2//未安装
}Dec_State_t;

typedef struct
{
	uint32_t Release_Tick;
	uint32_t Press_Tick;
	Dec_State_t State;
}KeyState_t;

extern KeyState_t Cover;
extern KeyState_t Level_Socket;

extern KeyState_t WIFI_KEY;
extern KeyState_t HEAT_KEY;
extern KeyState_t FilterRst_KEY;


void Key_Init(void);
void Key_Task(void);
void Cover_Check();
void WaterLevel_Socket_Check();
void LowVoltageButton_Check();
void ButtonWifi_Task(void);
void ButtonHeat_Task(void);
void ButtonFilterRst_Task(void);

#endif
