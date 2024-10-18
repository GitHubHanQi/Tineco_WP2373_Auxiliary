#ifndef _S_DAC_H
#define _S_DAC_H

#include "includes.h"



#define DAC_VALUE_MAX   (4095)




void DAC_Init(void);
void DAC_ValueSet(uint16_t x);
//void DAC_Test(void);


#endif
