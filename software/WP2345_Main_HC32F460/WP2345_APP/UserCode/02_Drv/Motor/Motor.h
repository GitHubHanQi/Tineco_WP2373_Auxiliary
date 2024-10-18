#ifndef _MOTOR_H
#define _MOTOR_H

#include "includes.h"



typedef enum
{
	Level_0,//ԭ��  ��
	Level_1,//��ϴ 785 ȫ��
	Level_2,//1200ml 1809
	Level_3,//800ml  2833
	Level_4,//600ml  3857
	Level_count

}waste_level_t;

typedef enum
{
	
	MotorState_Foreward,//��ת  ��ԭ��
	MotorState_Inversion,//��ת

}Motor_State_t;

typedef struct
{
	uint32_t Pulse_cnt;//������
	uint32_t rec_Pulse_cnt;//��ԭ����ܵ���������
	Motor_State_t Dir;//����
	uint8_t NowFlowLevel;//0-4��
	uint8_t SetFlowLevel;
	uint8_t MotorStep;//���ư���
	uint8_t ctr_step; //���ƻ�ԭ��
	uint8_t Adjust_Flag;//У׼���

}Motor_t;
extern Motor_t Motor;
extern uint16_t  water_flow_pluse[Level_count];
void Motor_Control(void);
void WasteWater_Motor_Task(void);
void WasteWater_Level_Set(uint8_t level);
void Motor_ZeroPoint(void);
#endif



