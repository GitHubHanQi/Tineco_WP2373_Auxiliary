#ifndef _BSP_H
#define _BSP_H

#include "includes.h"


//#include "reset.h"
//#include "bt.h"



//#include "flash.h"
#include "hc32f46x_efm.h"

//#include "adc.h"
//#include "dac.h"
//#include "gpio.h"
//#include "timer3.h"
//#include "uart.h"
//#include "opa.h"
//#include "spi.h"
#include "hc32_ddl.h"




//#include "wdt.h"


void Bsp_Init(void);
void Bsp_Start(void);
void Bsp_Task(void);



#include "Mcu.h"
#include "IO.h"
#include "EXTI.h"
#include "sFlash.h"
#include "sADC.h"
#include "sDAC.h"
#include "sSPI.h"
#include "WDG.h"

#include "TIM0.h"
#include "TIM1.h"
#include "TIM2.h"
#include "TIM3.h"

#include "UART0.h"
#include "UART1.h"
#include "UART2.h"
#include "UART3.h"


#endif
