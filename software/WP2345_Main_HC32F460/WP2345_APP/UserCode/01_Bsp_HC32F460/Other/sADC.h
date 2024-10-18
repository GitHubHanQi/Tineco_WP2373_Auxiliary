#ifndef _S_ADC_H
#define _S_ADC_H

#include "includes.h"


#define ADC_REF         (3300)
#define ADC_VALUE_MAX   (4095)

#define ADC_2_VOLTAGE(x)    ((uint32_t)(x) *73 /91)       // 4095*73 = 298935 = 0x48FB7     AD值转电压值
#define VOLTAGE_2_ADC(x)    ((uint32_t)(x) *4095 /3300)           // 电压值转AD值

#define ADC1_CHANNEL_NUM		(14)
//#define ADC2_CHANNEL_NUM		(4)

#define ADC1_SA_CHANNEL_SAMPLE_TIME { 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30}
#define ADC1_SA_CHANNEL_COUNT       ADC1_CHANNEL_NUM
#define ADC1_CHANNEL                (ADC1_CH0|ADC1_CH1|ADC1_CH2|ADC1_CH3|ADC1_CH6|ADC1_CH7|ADC1_CH8|ADC1_CH9|ADC1_CH10|ADC1_CH11|ADC1_CH12|ADC1_CH13|ADC1_CH14|ADC1_CH15)
#define ADC1_INT_PRIORITY           DDL_IRQ_PRIORITY_12

//#define ADC2_SA_CHANNEL_SAMPLE_TIME { 0x30, 0x30, 0x30, 0x30}
//#define ADC2_SA_CHANNEL_COUNT       ADC2_CHANNEL_NUM
//#define ADC2_CHANNEL                (ADC2_CH3|ADC2_CH6|ADC2_CH2|ADC2_CH5)
//#define ADC2_INT_PRIORITY           DDL_IRQ_PRIORITY_09


#define ADC_AVG_AMOUNT  (10)     // 滤波用的个数




typedef enum
{
	ADC_CH_Valve1 = 0,  //纯水进      
	ADC_CH_Valve2 = 1,  //废水阀      
	ADC_CH_Valve3 = 2,  //初级过滤阀           
	ADC_CH_Valve4 = 3,  //RO 纯水回流阀
	ADC_CH_Valve5 = 4,  //进水阀电流 
	ADC_CH_Valve6 = 5,  //纯水出水阀 
	ADC_CH_Valve7 = 6,	//热陈水换向阀
	ADC_CH_PressurePump = 7,    //36V增压水泵           
	ADC_CH_WaterLevel_25 = 8,    //液位         
	ADC_CH_WaterLevel_50 = 9,             
	ADC_CH_WaterLevel_75 = 10,
  ADC_CH_WaterLevel_100 = 11, 	
	ADC_CH_NTC1 = 12,      //加热胆温度
  ADC_CH_TDS1 = 13,      //TDS上冷水温
  ADC_CH_Amount         //通道个数
} ADC_CH_t;


#define NTC_TAB_NUMS  190




typedef struct 
{
    uint16_t Value_New[ADC_CH_Amount];
    uint16_t Record[ADC_AVG_AMOUNT][ADC_CH_Amount]; // DMA写入
    uint16_t Value_Filtered[ADC_CH_Amount];
    uint8_t Cnt;
} sADC_t;
extern volatile sADC_t sADC;


void sADC_Init(void);
void ADC_Task(void);
void Adc1_IrqCallBack(void);
void Adc2_IrqCallBack(void);

int16_t Cal_NTC_Tem(uint32_t dat);


#endif
