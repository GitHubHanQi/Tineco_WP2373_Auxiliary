#ifndef _SENSOR_H
#define _SENSOR_H

#include "includes.h"

#define STANDARD_AD     (1800)//1862 - 60        // 期望颜色传感器达到的初始值1800
#define DAC_ADJUST_STEP      (50)                // DAC模块每次调节的步长

//#define DAC_DA1_SET         (1365)               // DAC模块DA1通道的初始值，约为1V
//#define DAC_DA2_SET         (2110)               // DAC模块DA2通道的初始值，约为1.8V
//#define DAC_DA5_SET         (1365)               // DAC模块DA5通道的初始值，约为1V
//#define DAC_DA6_SET         (2110)               // DAC模块DA6通道的初始值，约为1.8V

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


// 标准室温
#define STANDARD_TEMPERATURE       (25)


// Reheat时间
#define REHEAT_TIME                (30000)

// 新鲜面包烘烤时间
#define LOW_GRADE_TIME1            (85000)        // 25℃下的标准时间，温度每上升1℃时间减少1s
#define MIDDLE_GRADE_TIME1         (138000)
#define TOP_GRADE_TIME1            (190000)
#define MORETOP_GRADE_TIME1        (230000)
#define LOW_GRADE_TIME2            (60000)        // 第二次循环
#define MIDDLE_GRADE_TIME2         (90000)
#define TOP_GRADE_TIME2            (130000)
#define MORETOP_GRADE_TIME2        (170000)
#define LOW_GRADE_TIME3            (55000)        // 第三次循环
#define MIDDLE_GRADE_TIME3         (85000)
#define TOP_GRADE_TIME3            (120000)
#define MORETOP_GRADE_TIME3        (155000)

// 冷藏面包烘烤时间
#define DEFRSOT_LOW_GRADE_TIME1            (105000)        // 25℃下的标准时间，温度每上升1℃时间减少1s
#define DEFRSOT_MIDDLE_GRADE_TIME1         (158000)
#define DEFRSOT_TOP_GRADE_TIME1            (210000)
#define DEFRSOT_MORETOP_GRADE_TIME1        (250000)
#define DEFRSOT_LOW_GRADE_TIME2            (80000)        // 第二次循环
#define DEFRSOT_MIDDLE_GRADE_TIME2         (110000)
#define DEFRSOT_TOP_GRADE_TIME2            (150000)
#define DEFRSOT_MORETOP_GRADE_TIME2        (190000)
#define DEFRSOT_LOW_GRADE_TIME3            (75000)        // 第三次循环
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

extern volatile uint16_t DA1_Set;      // 调节DAC_Raise1的输出电压，初始电压为1V(ADC_DA1 = 1240),以0.1V的步长调节，最低50mv(ADC_DA1 = 62)
extern volatile uint16_t DA2_Set;      // 调节DACV_1的输出电压，初始值2234(1.8v),面包颜色较深时减小为2048(1.65v)
extern volatile uint16_t DA5_Set;      // 调节DAC_Raise2的输出电压，初始电压为1V(ADC_DA3 = 1240),以0.1V的步长调节，最低50mv(ADC_DA3 = 62)
extern volatile uint16_t DA6_Set;      // 调节DACV_2的输出电压，初始值2234(1.8v),面包颜色较深时减小为2048(1.65v)

extern volatile uint16_t KJudge1,KJudge2;

extern volatile uint16_t AD1_Max;
extern volatile uint16_t AD2_Max;


extern volatile uint16_t Sensor1_Error_Tick;
extern volatile uint16_t Sensor2_Error_Tick;
extern volatile uint16_t Sensor1_Normal_Tick;
extern volatile uint16_t Sensor2_Normal_Tick;

extern volatile uint8_t Sensor_SendError_Flag;

extern volatile uint8_t Clod_Flag1;       // 冷机判定标志，温度小于85认为是冷机
extern volatile uint8_t Clod_Flag2;       // 冷机判定标志，温度小于85认为是冷机

typedef enum 
{
	SensorState_Stop,
	SensorState_Start,
	SensorState_Calibrat,
	SensorState_Run,
	SensorState_Disabled,              // 传感器失效状态（用户选择了档位但是传感器无法判断是否放入面包，进入传感器失效状态，通过时间控制结束）
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
	uint32_t Tick;             // 烘烤时长计时
	uint32_t Heat_Time;        // 烘烤时间
	uint16_t Refresh_Rate;     // 烘烤进度的刷新速率
	uint16_t Temperature;      // 槽壁温度
	uint32_t Temperature_Offset;    // 温度偏移量
	uint16_t Count;            // 连续烘烤计数，只要不断电就认为是连续烘烤
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



