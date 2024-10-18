#ifndef _SENSOR_H
#define _SENSOR_H

#include "includes.h"

#define STANDARD_AD     (1800)//1862 - 60        // ������ɫ�������ﵽ�ĳ�ʼֵ1800
#define DAC_ADJUST_STEP      (50)                // DACģ��ÿ�ε��ڵĲ���

//#define DAC_DA1_SET         (1365)               // DACģ��DA1ͨ���ĳ�ʼֵ��ԼΪ1V
//#define DAC_DA2_SET         (2110)               // DACģ��DA2ͨ���ĳ�ʼֵ��ԼΪ1.8V
//#define DAC_DA5_SET         (1365)               // DACģ��DA5ͨ���ĳ�ʼֵ��ԼΪ1V
//#define DAC_DA6_SET         (2110)               // DACģ��DA6ͨ���ĳ�ʼֵ��ԼΪ1.8V

//#define Sensor1_LEVEL1      (First_ADC1 + 0.28)
//#define Sensor1_LEVEL2      (First_ADC1 + 0.33)
//#define Sensor1_LEVEL3      (First_ADC1 + 0.38)
//#define Sensor1_LEVEL4      (First_ADC1 + 0.44)
//#define Sensor1_LEVEL5      (First_ADC1 + 0.51)

//#define Sensor2_LEVEL1      (First_ADC2 + 0.28)
//#define Sensor2_LEVEL2      (First_ADC2 + 0.33)
//#define Sensor2_LEVEL3      (First_ADC2 + 0.38)
//#define Sensor2_LEVEL4      (First_ADC2 + 0.44)
//#define Sensor2_LEVEL5      (First_ADC2 + 0.51)


// ��׼����
#define STANDARD_TEMPERATURE       (25)


// Reheatʱ��
#define REHEAT_TIME                (30000)

// ��������濾ʱ��
#define LOW_GRADE_TIME1            (85000)        // 25���µı�׼ʱ�䣬�¶�ÿ����1��ʱ�����1s
#define MIDDLE_GRADE_TIME1         (138000)
#define TOP_GRADE_TIME1            (190000)
#define MORETOP_GRADE_TIME1        (230000)
#define LOW_GRADE_TIME2            (60000)        // �ڶ���ѭ��
#define MIDDLE_GRADE_TIME2         (90000)
#define TOP_GRADE_TIME2            (130000)
#define MORETOP_GRADE_TIME2        (170000)
#define LOW_GRADE_TIME3            (55000)        // ������ѭ��
#define MIDDLE_GRADE_TIME3         (85000)
#define TOP_GRADE_TIME3            (120000)
#define MORETOP_GRADE_TIME3        (155000)

// �������濾ʱ��
#define DEFRSOT_LOW_GRADE_TIME1            (105000)        // 25���µı�׼ʱ�䣬�¶�ÿ����1��ʱ�����1s
#define DEFRSOT_MIDDLE_GRADE_TIME1         (158000)
#define DEFRSOT_TOP_GRADE_TIME1            (210000)
#define DEFRSOT_MORETOP_GRADE_TIME1        (250000)
#define DEFRSOT_LOW_GRADE_TIME2            (80000)        // �ڶ���ѭ��
#define DEFRSOT_MIDDLE_GRADE_TIME2         (110000)
#define DEFRSOT_TOP_GRADE_TIME2            (150000)
#define DEFRSOT_MORETOP_GRADE_TIME2        (190000)
#define DEFRSOT_LOW_GRADE_TIME3            (75000)        // ������ѭ��
#define DEFRSOT_MIDDLE_GRADE_TIME3         (105000)
#define DEFRSOT_TOP_GRADE_TIME3            (140000)
#define DEFRSOT_MORETOP_GRADE_TIME3        (175000)

extern volatile uint16_t Sensor1_Standard_AD;
extern volatile uint16_t Sensor2_Standard_AD;
extern volatile uint16_t Sensor1_Num;
extern volatile uint16_t Sensor1_Count;
extern volatile uint16_t Sensor12_Count;
extern volatile uint8_t Sensor1_Finsh_Flag;
extern volatile uint8_t Sensor12_Finsh_Flag;
extern volatile uint16_t Sensor2_Num;
extern volatile uint16_t Sensor2_Count;
extern volatile uint16_t Sensor22_Count;
extern volatile uint8_t Sensor2_Finsh_Flag;
extern volatile uint8_t Sensor22_Finsh_Flag;
extern volatile uint8_t Sensor3_Finsh_Flag;
extern volatile uint8_t Manual1_Finish_Flag;
extern volatile uint8_t Manual2_Finish_Flag;

extern volatile uint16_t DA1_Set;      // ����DAC_Raise1�������ѹ����ʼ��ѹΪ1V(ADC_DA1 = 1240),��0.1V�Ĳ������ڣ����50mv(ADC_DA1 = 62)
extern volatile uint16_t DA2_Set;      // ����DACV_1�������ѹ����ʼֵ2234(1.8v),�����ɫ����ʱ��СΪ2048(1.65v)
extern volatile uint16_t DA5_Set;      // ����DAC_Raise2�������ѹ����ʼ��ѹΪ1V(ADC_DA3 = 1240),��0.1V�Ĳ������ڣ����50mv(ADC_DA3 = 62)
extern volatile uint16_t DA6_Set;      // ����DACV_2�������ѹ����ʼֵ2234(1.8v),�����ɫ����ʱ��СΪ2048(1.65v)

extern volatile uint16_t KJudge1,KJudge2;

extern volatile uint16_t AD1_Max;
extern volatile uint16_t AD2_Max;


extern volatile uint16_t Sensor1_Error_Tick;
extern volatile uint16_t Sensor2_Error_Tick;
extern volatile uint16_t Sensor1_Normal_Tick;
extern volatile uint16_t Sensor2_Normal_Tick;

extern volatile uint8_t Sensor_SendError_Flag;

extern volatile uint8_t Clod_Flag1;       // ����ж���־���¶�С��85��Ϊ�����
extern volatile uint8_t Clod_Flag2;       // ����ж���־���¶�С��85��Ϊ�����

typedef enum 
{
	SensorState_Stop,
	SensorState_Start,
	SensorState_Calibrat,
	SensorState_Run,
	SensorState_Disabled,              // ������ʧЧ״̬���û�ѡ���˵�λ���Ǵ������޷��ж��Ƿ������������봫����ʧЧ״̬��ͨ��ʱ����ƽ�����
	SensorState_Error,
}Sensor_State_t;

typedef struct
{
	uint32_t Tick;
	uint8_t Disable_Flag;
	Sensor_State_t State;
}Sensor_t;

extern Sensor_t Sensor1;
extern Sensor_t Sensor2;
//extern Sensor_t Sensor3;

typedef enum
{
	ManualState_Stop,
	ManualState_Start,
	ManualState_Run,
	ManualState_Error
}Manual_State_t;

typedef struct
{
	uint32_t Tick;             // �濾ʱ����ʱ
	uint32_t Heat_Time;        // �濾ʱ��
	uint16_t Refresh_Rate;     // �濾���ȵ�ˢ������
	uint16_t Temperature;      // �۱��¶�
	uint32_t Temperature_Offset;    // �¶�ƫ����
	uint16_t Count;            // �����濾������ֻҪ���ϵ����Ϊ�������濾
	Manual_State_t State;
}Manual_t;

extern Manual_t Manual1;
extern Manual_t Manual2;



void Sensor1_Task(void);
void Sensor2_Task(void);
//void Sensor3_Task(void);
void Sensor_Task(void);
void Manual1_Task(void);
void Manual2_Task(void);

uint16_t Num_Sub(uint16_t a,uint16_t b);




#endif



