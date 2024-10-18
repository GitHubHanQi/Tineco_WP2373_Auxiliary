#ifndef _WDG_H
#define _WDG_H

#include "includes.h"



#ifdef IWDG_EN
	#define WDG_EN
#endif
	
void WDG_Init(void);
void WDG_Start(void);
void WDG_Feed(void);



#endif
