#ifndef _S_DAC_H
#define _S_DAC_H

#include "includes.h"



#define DAC_VALUE_MAX   (4095)

#define DAC_RAISE_MAX   (550)
#define DAC_RAISE_MIN   (75)

extern uint16_t Led1_IRay_Set;
extern uint16_t Led2_IRay_Set;




void DAC_Init(void);
void TIMA_5_6_Init(void);
void PWM_DA1_ValueSet(uint16_t value);
void PWM_DA2_ValueSet(uint16_t value);
void PWM_DA3_ValueSet(uint16_t value);
void PWM_DA4_ValueSet(uint16_t value);
void PWM_LED1_ValueSet(uint16_t value);
void PWM_DAC_ValueSet(void);

#endif
