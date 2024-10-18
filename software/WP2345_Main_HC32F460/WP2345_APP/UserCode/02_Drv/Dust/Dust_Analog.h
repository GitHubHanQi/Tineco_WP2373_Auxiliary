#ifndef _DUST_ANALOG_H
#define _DUST_ANALOG_H

#include "includes.h"



//////// 发射
#define DUST_DAC_MIN		    (VOLTAGE_2_ADC(500))
#define DUST_DAC_STANDARD       (VOLTAGE_2_ADC(2000))  // 460_ (VOLTAGE_2_ADC(2350)) 2000
#define DUST_DAC_MAX		    (VOLTAGE_2_ADC(3300))  // 3300

#define DUST_DAC_OutputLow      (VOLTAGE_2_ADC(800))
#define DUST_DAC_OutputHigh     (VOLTAGE_2_ADC(2000)) // 460_ (VOLTAGE_2_ADC(2350))  2000


//////// 接收
#define DUST_ADC_STANDARD       (VOLTAGE_2_ADC(1000))   // 正常工作的基准电压
#define DUST_ADC_RANGE          (VOLTAGE_2_ADC(400))    // 正常工作的允许误差


#define DUST_ADC_UV             (VOLTAGE_2_ADC(400))      // 高输出时，输入欠压
#define DUST_ADC_OV             (VOLTAGE_2_ADC(1500))     // 低输出时，输入超压

#define DUST_ADC_OutputLow_InputHigh        (VOLTAGE_2_ADC(1800))
#define DUST_ADC_OutputHigh_InputLow        (VOLTAGE_2_ADC(100))  // 196_ (VOLTAGE_2_ADC(300))  


extern volatile uint16_t ADC_Value_DustTemp[3];
extern volatile int16_t Dust_DacOutput;

void Dust_OutputVoltage_Set(uint16_t x);


//////// 发射DAC ///////
void Dust_OutputVoltage_Set(uint16_t x);


/////// 接收ADC ////////
void Dust_InputVoltage_Read(void);
void DustVoltage_Read(void);
bool_t DustVoltage_IsDiff3(uint16_t *pV);

bool_t Dust_Analog_Regulate(void);
bool_t DustVoltage_NotStandardCheck(void);
bool_t DustVoltage_NochangeCheck(void);


////增量式PID
//typedef struct{
//	int SetPoint;		//目标值
//	long SumError;		//误差累计


//	float P;			//比例常数
//	float I;			//积分常数
//	float D;			//微分常数

//	int LastError;		//上次偏差值
//	int PrevError;		//上上次偏差值
//}PID;


#endif
