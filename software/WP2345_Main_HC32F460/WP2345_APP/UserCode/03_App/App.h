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

#define	SET_BIT(x, bit)	  (x |=  (1 << bit))	/* �����bitλ */
#define	CLEAR_BIT(x, bit)	(x &= ~(1 << bit))	/* �����bitλ */


typedef enum
{
	AppState_StrongRinse,//ǿ��
	AppState_Study,//�е�ѧϰ
	AppState_NormalWork,//��������
//	AppState_WifiPair,//WIFI����
	AppState_Err,        //����  
	AppState_Test,       //���� 
	AppState_Program,    //IAP����    
	AppState_ProgramOTA, //��������  
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
	uint8_t LockFlag;//ͯ�� �������ȡ����
	int16_t HeatTank_Tem;//����ˮ���¶�
  int16_t Cool_Tem;//��ˮ�¶�
	uint8_t Err_Code;//����������
	uint16_t SystemErrFlag;//�������� ÿһ��bit��Ӧһ������
	uint8_t BeepCount;//�������켸��
	SupplyWater_t SuppleWater;//��ˮ���
	uint8_t KeepWarmFlag;//���±��
	uint8_t ShowHeatFlag;//���ȱ��-������ͷ��ʾ
	uint8_t HeatOverFlag;//��ˮ��������λ
	uint8_t ForbidFlag;//��ֹ��ˮ���
	uint8_t StandbyFlag;//��������
	uint8_t DrainFlag;//��ˮ���
	uint8_t PureWaterBackFlag;//����
	uint8_t ReplaceFilterElement;//������о���
	uint32_t WaterTotal;//������ˮ��
	uint32_t WaterTotal_1;//������ˮ��
	uint32_t LastWaterTotal;//������ˮ��
	waste_level_t AdjustDrainOUT_Level;//��ˮ��������λ
	uint16_t Unlock_tick;//����δ������ʱ
}Work_Para_t;
extern Work_Para_t Work_Para;

extern uint16_t  ValveState;

void App_Task(void);
void CloseAllLoad(void);
void SystemErrorProess(void);
void Valve_Test(void);
#endif
