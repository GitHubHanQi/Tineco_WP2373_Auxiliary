#ifndef _EXTI_H
#define _EXTI_H

#include "includes.h"

// 充电口

void EXTI_Init(void);
void TDS_Init(void);
//#define EXIT_IN_PORT				PortB       //DC适配器(GPIO输入)
//#define EXIT_IN_PIN					Pin01
//过零检测
#define LINE_CROSS_PORT        PortB
#define LINE_CROSS_PIN         Pin05
//流量计
#define FLOWMETER_PORT        PortC
#define FLOWMETER_PIN         Pin06

//#define CHARGE_CHECK_READ()			PORT_GetBit(EXIT_IN_PORT,EXIT_IN_PIN)

#define LINE_CROSS_READ()       PORT_GetBit(LINE_CROSS_PORT, LINE_CROSS_PIN)

void ExtInt05_Callback(void);  //过零检测上升沿检测
void ExtInt11_Callback(void);
void ExtInt08_Callback(void);
void ExtInt07_Callback(void);
void ExtInt06_Callback(void);
#endif
