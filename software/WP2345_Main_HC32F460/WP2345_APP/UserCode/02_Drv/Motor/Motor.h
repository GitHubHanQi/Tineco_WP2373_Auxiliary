#ifndef _MOTOR_H
#define _MOTOR_H

#include "includes.h"



typedef enum
{
	Level_0,//原点  关
	Level_1,//冲洗 785 全开
	Level_2,//1200ml 1809
	Level_3,//800ml  2833
	Level_4,//600ml  3857
	Level_count

}waste_level_t;

typedef enum
{
	
	MotorState_Foreward,//正转  回原点
	MotorState_Inversion,//反转

}Motor_State_t;

typedef struct
{
	uint32_t Pulse_cnt;//脉冲数
	uint32_t rec_Pulse_cnt;//从原点后跑的总脉冲数
	Motor_State_t Dir;//方向
	uint8_t NowFlowLevel;//0-4档
	uint8_t SetFlowLevel;
	uint8_t MotorStep;//控制八拍
	uint8_t ctr_step; //控制回原点
	uint8_t Adjust_Flag;//校准标记

}Motor_t;
extern Motor_t Motor;
extern uint16_t  water_flow_pluse[Level_count];
void Motor_Control(void);
void WasteWater_Motor_Task(void);
void WasteWater_Level_Set(uint8_t level);
void Motor_ZeroPoint(void);
#endif



