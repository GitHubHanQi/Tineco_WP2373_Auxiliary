#ifndef _APP_VACUUM_H
#define _APP_VACUUM_H

#include "includes.h"


extern uint8_t Bldc_Duty;

#define VACUUM_PWM_DUTY_MAX		    ((uint16_t)(1000))
#define VACUUM_PWM_DUTY_STANDARD	((uint16_t)(VACUUM_PWM_DUTY_MAX * 0.40))
#define VACUUM_PWM_DUTY_MIN		    ((uint16_t)(VACUUM_PWM_DUTY_MAX * 0))
#define VACUUM_PWM_DUTY_HIGH		((uint16_t)(900))

extern uint8_t VacuumEnable;
extern uint8_t VacuumDuty;
extern uint8_t VaccumDutyBack;


__STATIC_INLINE void VACUUM_ENABLE(void)
{
	VacuumEnable = 1;
	//HAL_GPIO_WritePin(MOTOR_EN_GPIO_Port, MOTOR_EN_Pin, GPIO_PIN_SET);
}

__STATIC_INLINE void VACUUM_DISABLE(void)
{
	VacuumEnable = 0;
	//HAL_GPIO_WritePin(MOTOR_EN_GPIO_Port, MOTOR_EN_Pin, GPIO_PIN_RESET);
}


//#define POWER_120W_DUST     80
#define POWER_120W_DUST     150
#define POWER_90W_DUST     60

typedef enum 
{
    POWER50W,     // 语音播放
    POWER90W,     // 低档
    POWER120W,    // 高档
    POWER150W     // 不用
} enum_Power_State_t;

typedef enum
{
	VacuumState_Stop,
	VacuumState_Check,
	VacuumState_Run
} Vacuum_State_t;
extern volatile Vacuum_State_t Vacuum_State;
extern volatile uint32_t Vacuum_Tick;
extern enum_Power_State_t Power_State;

extern const uint16_t MotorPower[];
void Vacuum_Start(void);
void Vacuum_Stop(void);
void Vacuum_AuTo(void);
void Vacuum_Task(void);
void Vacuum_Level_Set(void);

typedef enum
{
	VacuumLevel_Auto,
	VacuumLevel_L,    //  90w
	VacuumLevel_M,	  //  120w
	VacuumLevel_H	  //  150w
} Vacuum_Level_t;


extern volatile Vacuum_Level_t VacuumLevel_x;

//////// 从电池包获取的电机信息
extern uint8_t Vacuum_FG;     // 0持续1.5s低电平，1持续1.5s高电平，2正在翻转
extern uint32_t Vacuum_RPM;   // 

#endif

