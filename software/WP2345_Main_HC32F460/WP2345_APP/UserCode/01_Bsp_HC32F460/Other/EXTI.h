#ifndef _EXTI_H
#define _EXTI_H

#include "includes.h"

// ����

void EXTI_Init(void);
void TDS_Init(void);
//#define EXIT_IN_PORT				PortB       //DC������(GPIO����)
//#define EXIT_IN_PIN					Pin01
//������
#define LINE_CROSS_PORT        PortB
#define LINE_CROSS_PIN         Pin05
//������
#define FLOWMETER_PORT        PortC
#define FLOWMETER_PIN         Pin06

//#define CHARGE_CHECK_READ()			PORT_GetBit(EXIT_IN_PORT,EXIT_IN_PIN)

#define LINE_CROSS_READ()       PORT_GetBit(LINE_CROSS_PORT, LINE_CROSS_PIN)

void ExtInt05_Callback(void);  //�����������ؼ��
void ExtInt11_Callback(void);
void ExtInt08_Callback(void);
void ExtInt07_Callback(void);
void ExtInt06_Callback(void);
#endif
