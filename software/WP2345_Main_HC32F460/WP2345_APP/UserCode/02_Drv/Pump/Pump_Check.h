#ifndef _PUMP_CHECK_H
#define _PUMP_CHECK_H

#include "includes.h"



//////// ADC值 转 地刷电流mA
//#define ADC_2_PUMP_CURRENT(x)    (uint32_t)((uint64_t)(x) *3300 *1000/100  /4095)      // 采样电阻0.1Ω = 100mΩ
//#define ADC_2_PUMP_CURRENT(x)    (uint32_t)((uint32_t)(x) *33   *1000/1    /4095)
#define ADC_2_PUMP_CURRENT(x)      (uint32_t)((uint32_t)(x) *11   *200       /273)       // 4095*11*200 = 9009000 = 0x897768
// #define ADC_2_PUMP_CURRENT(x)   (uint32_t)((uint32_t)(x) *11   *201       /273)
// #define ADC_2_PUMP_CURRENT(x)   (uint32_t)((uint32_t)(x) *11   *67        /91)        // 4095*11*67 = 3018015 = 0x2E0D1F


//////// 地刷电流mA 转 ADC值
#define PUMP_CURRENT_2_ADC(x)      (uint16_t)((uint32_t)(x) *273 /11/200)



void PumpCheck_ShortCircuit(void);
void PumpCheck_OverCurrent1(void);



#endif

