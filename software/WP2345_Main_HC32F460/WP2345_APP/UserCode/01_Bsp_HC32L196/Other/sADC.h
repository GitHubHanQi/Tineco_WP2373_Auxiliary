#ifndef _S_ADC_H
#define _S_ADC_H

#include "includes.h"


#define ADC_REF         (3300)
#define ADC_VALUE_MAX   (4095)

#define ADC_2_VOLTAGE(x)    ((uint32_t)(x) *73 /91)       // 4095*73 = 298935 = 0x48FB7
#define VOLTAGE_2_ADC(x)    ((uint32_t)(x) *4095 /3300)


#define ADC_AVG_AMOUNT  (10)     // 滤波用的个数


typedef enum
{
    ADC_CH_DirtyWaterLevel = 0,	//污水桶检测
    ADC_CH_PumpCurrent,			//水泵电流
    ADC_CH_Key,					//AD按键
    ADC_CH_CleanWaterLevel,		//清水桶检测
    ADC_CH_Dust,				//脏污检测
    ADC_CH_BrushCurrent,		//地刷电流检测
    ADC_CH_ChargerVoltage,		//适配器电压检测
//    ADC_CH_Hpea,				//HPEA检测
    ADC_CH_Amount               //通道个数8
} ADC_CH_t;



typedef struct 
{
    uint16_t Value_New[ADC_CH_Amount];
    uint16_t Record[ADC_AVG_AMOUNT][ADC_CH_Amount]; // DMA写入
    uint16_t Value_Filtered[ADC_CH_Amount];
    uint8_t Cnt;
} sADC_t;
extern volatile sADC_t sADC;


void ADC_Init(void);
void ADC_Task(void);


#endif
