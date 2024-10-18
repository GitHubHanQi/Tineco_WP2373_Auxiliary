#ifndef _BoilPoint_H
#define _BoilPoint_H

#include "includes.h"
typedef enum
{
	Unknow_Step=0,//��ʼ��״̬
	Drain_Out_Step,//�ſ�
  Supply_Step,//��ˮ
	Heat_Step,//����
	Learn_Over_Step,//ѧϰ���
	Over_Drain_Out_Step,//�ų�
	Learn_Err,
} learn_step_t;


typedef struct
{
	uint8_t LearnStep;
	uint32_t DrainOut_tick;//��ˮ
	int16_t MaxHeatTank_Tem;
  int16_t StartHeatTank_Tem;
	uint32_t STimeCnt;//С���ʼ���ʱ��
  uint8_t LearnStart;//���ƹ���
  uint32_t LearnHeatTime;//ѧϰʱ��
  uint16_t TemUP_Tick;//����ʱ��
	int16_t BoilPointTem;//�е�
	
	uint16_t Heat_Tick;//����ʱ��

} BoilPoint_t;
extern BoilPoint_t BoilPoint;
void BoilPointLearn(void);













#endif