#ifndef _BSP_H
#define _BSP_H

#include "includes.h"



#include "Mcu.h"
#include "sFlash.h"
#include "WDG.h"
#include "TIMA.h"
#include "IO.h"
#include "sADC.h"
#include "TIM0.h"
#include "UART0.h"
#include "UART2.h"
#include "UART3.h"




void Bsp_Init(void);
void Bsp_Start(void);
void Bsp_Task(void);







#endif
