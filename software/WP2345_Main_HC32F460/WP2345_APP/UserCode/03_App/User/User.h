#ifndef _User_H
#define _User_H

#include "includes.h"

typedef enum
{
	User_Stop,//ֹͣ��ˮ
	User_Cool,//����ˮ
	User_45,    //45��ˮ 
	User_85,    //85��ˮ
	User_98,    //98��ˮ  
	SYSTEM_STOP, //ϵͳֹͣ
} User_State_t;
extern User_State_t UserState;//�û�����״̬
extern uint8_t Demand_Temerature;//�趨���޼������¶�
extern uint16_t UnLockCont;//����δ������ʱ

typedef struct
{
	uint8_t status; //1�� 0��
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
                               
extern ValveCurrent_t SourceValve;//��ˮ
extern ValveCurrent_t PureoutValve;//��ˮ��ˮ��
extern ValveCurrent_t PureheatValve;//��ˮ�����ȹ޷�
extern ValveCurrent_t DrainOutValve;//��ˮ��
extern ValveCurrent_t PurebackValve;//RO��ˮ������


void UseWaterCtr(void);
void ChildLockCheck(void);
void StandbyCheck(void);
void DrainOutHotWaterCtr(void);
void ReplaceFilterCheck(void);
void AdjustDrainOUTValve(void);


#endif
