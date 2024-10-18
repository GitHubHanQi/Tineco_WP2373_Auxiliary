/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2023-12-19 17:22:45
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-20 16:31:00
 */

#ifndef _S_ADC_H
#define _S_ADC_H

#include "includes.h"

#define ADC_REF (3300)
#define ADC_VALUE_MAX (4095)

#define ADC_2_VOLTAGE(x) \
  ((uint32_t)(x) * 73 / 91)  // 4095*73 = 298935 = 0x48FB7     AD值转电压值
#define VOLTAGE_2_ADC(x) ((uint32_t)(x) * 4095 / 3300)  // 电压值转AD值

#define ADC1_CHANNEL_NUM (14)

#define ADC1_SA_CHANNEL_SAMPLE_TIME                                         \
  {                                                                         \
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, \
        0x30, 0x30                                                          \
  }
#define ADC1_SA_CHANNEL_COUNT ADC1_CHANNEL_NUM
#define ADC1_CHANNEL                                                    \
  (ADC1_CH0 | ADC1_CH1 | ADC1_CH2 | ADC1_CH3 | ADC1_CH4 | ADC1_CH5 |    \
   ADC1_CH6 | ADC1_CH7 | ADC1_CH9 | ADC1_CH10 | ADC1_CH11 | ADC1_CH12 | \
   ADC1_CH13 | ADC1_CH14)
#define ADC1_INT_PRIORITY DDL_IRQ_PRIORITY_12

#define ADC_AVG_AMOUNT (10)  // 滤波用的个数

#define TEMPERATURE_NTC1_PORT PortA
#define TEMPERATURE_NTC1_PIN Pin00

#define CARBONATION_TANK_HIGH_PORT PortA
#define CARBONATION_TANK_HIGH_PIN Pin01

#define CARBONATION_TANK_LOW_PORT PortA
#define CARBONATION_TANK_LOW_PIN Pin02

#define TEMPERATURE_NTC2_PORT PortB
#define TEMPERATURE_NTC2_PIN Pin01

////// 冷水电磁阀出水
#define COLDWATER_OUT_7_1_PORT PortC
#define COLDWATER_OUT_7_1_PIN Pin00

////// 气泡水出水
#define SPARKLINGWATER_OUT_7_2_PORT PortC
#define SPARKLINGWATER_OUT_7_2_PIN Pin01

/////常温水进水
#define COOLWATER_IN_7_3_PORT PortC
#define COOLWATER_IN_7_3_PIN Pin02

/////常温水进水
#define COOLWATER_OUT_7_4_PORT PortC
#define COOLWATER_OUT_7_4_PIN Pin03

/////碳化罐增压泵
#define PMCS1_PORT PortA
#define PMCS1_PIN Pin03

/////搅拌电机
#define PMCS3_PORT PortA
#define PMCS3_PIN Pin04

////风扇
#define PMCS2_PORT PortA
#define PMCS2_PIN Pin05

/////常温进水泵
#define PMCS4_PORT PortA
#define PMCS4_PIN Pin06

// 分水盒1
#define CVALUE_7_5_PORT PortA
#define CVALUE_7_5_PIN Pin07

// 分水盒2
#define CVALUE_7_6_PORT PortC
#define CVALUE_7_6_PIN Pin04





typedef enum {
  ADC_CH_NTC1,
  ADC_CH_Carbonation_Tank_Low,
  ADC_CH_Carbonation_Tank_High,
  ADC_CH_NTC2,
  ADC_CH_COLDWATER_OUT_7_1,
  ADC_CH_SPARKLINGWATER_OUT_7_2,
  ADC_CH_COOLWATER_IN_7_3,
  ADC_CH_COOLWATER_OUT_7_4,
  ADC_CH_PMCS1,
  ADC_CH_PMCS3,
  ADC_CH_PMCS2,
  ADC_CH_PMCS4,
  ADC_CH_CVALUE_7_5,
  ADC_CH_CVALUE_7_6,
  ADC_CH_Amount  // 通道个数
} ADC_CH_t;

typedef struct {
  uint16_t Value_New[ADC_CH_Amount];
  uint16_t Record[ADC_AVG_AMOUNT][ADC_CH_Amount];  // DMA写入
  uint16_t Value_Filtered[ADC_CH_Amount];
  uint8_t Cnt;
} sADC_t;
extern volatile sADC_t sADC;


typedef struct {
	bool CarbonationTankHighOpen;
	uint16_t CarbonationTankHighOpenCount;
	bool CarbonationTankHighClose;
	uint16_t CarbonationTankHighCloseCount;
	bool CarbonationTankLowOpen;
	uint16_t CarbonationTankLowOpenCount;
	uint8_t ProbeEnableFlag;
	uint32_t Cnt;
	uint32_t HighLevel;
	uint32_t LowLevel;
}FilterAD_Bool_t;
extern FilterAD_Bool_t FilterAD_Bool;

void sADC_Init(void);
void ADC_Task(void);
void Adc1_IrqCallBack(void);

bool FilterFunction(int *input, int *count_t,int ComparisonValue);
bool FilterADBiggerThanFunction(uint16_t AD_Num,uint16_t Time,uint16_t CompareValue,uint16_t* pCount);
bool FilterADLessThanFunction(uint16_t AD_Num,uint16_t Time,uint16_t CompareValue,uint16_t* pCount);
void CarbonTankFilterADTask(void);
void PreventingPolarisationFunction(void);
#endif
