#ifndef _User_H
#define _User_H

#include "includes.h"

typedef enum
{
	User_Stop,//停止用水
	User_Cool,//常温水
	User_45,    //45度水 
	User_85,    //85度水
	User_98,    //98度水  
	SYSTEM_STOP, //系统停止
} User_State_t;
extern User_State_t UserState;//用户请求状态
extern uint8_t Demand_Temerature;//设定的无极调温温度
extern uint16_t UnLockCont;//解锁未操作计时

typedef struct
{
	uint8_t status; //1开 0关
	uint16_t Current;           
	uint16_t OverCurrent_cnt;
	uint16_t OpenCurrent_cnt;	
	enum{
		VALVE_ERR_NONE,
		VALVE_ERR_OPEN_CURRENT,
		VALVE_ERR_OVER_CURRENT,
	}error;
}
ValveCurrent_t;
                               
extern ValveCurrent_t SourceValve;//进水
extern ValveCurrent_t PureoutValve;//纯水出水阀
extern ValveCurrent_t PureheatValve;//纯水进加热罐阀
extern ValveCurrent_t DrainOutValve;//排水阀
extern ValveCurrent_t PurebackValve;//RO纯水回流阀


void UseWaterCtr(void);
void ChildLockCheck(void);
void StandbyCheck(void);
void DrainOutHotWaterCtr(void);
void ReplaceFilterCheck(void);
void AdjustDrainOUTValve(void);


#endif
