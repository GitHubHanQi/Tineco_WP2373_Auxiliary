#ifndef _BSP_H
#define _BSP_H

#include "includes.h"


//#include "flash.h"
#include "hc32f46x_efm.h"

//#include "gpio.h"
#include "hc32_ddl.h"

void Bsp_Init(void);
void Bsp_Start(void);
void Bsp_Task(void);
float Bubble_Sort(float *p ,uint8_t len);


#include "Mcu.h"
#include "IO.h"
#include "EXTI.h"
#include "sFlash.h"
#include "sADC.h"
#include "SGM5347.h"
//#include "sDAC.h"
#include "sSPI.h"
#include "WDG.h"

#include "TIM0.h"
#include "TIMA.h"

#include "UART0.h"
#include "UART1.h"
#include "UART2.h"
#include "UART3.h"

#include "IIC.h"


#endif
