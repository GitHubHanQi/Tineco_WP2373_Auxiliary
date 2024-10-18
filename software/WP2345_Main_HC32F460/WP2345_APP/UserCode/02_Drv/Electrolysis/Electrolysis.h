#ifndef _ElECTROLYSIS_H
#define _ElECTROLYSIS_H

#include "includes.h"
 
#define ELECTROLYSIS_5MINS  300000
#define ELECTROLYSIS_30S    30000
 
 
extern  uint32_t Cleanse_Time; // Ïû¶¾ÅäÖÃÊ±¼ä 
//extern void IO_Electrolysis_Init(void);
extern void Electrolysis_Toggle(void);
extern void Electrolysis_Stop(void);
extern void Electrolysis_Task(void);

#endif
