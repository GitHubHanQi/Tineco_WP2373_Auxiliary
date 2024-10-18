#ifndef _LED_H
#define _LED_H

#include "includes.h"

typedef struct
{
	uint8_t WIFI_Sta;//0灭 1常亮 2闪
  uint8_t Heat_Sta;
  uint8_t FilterRst_Sta;
	uint8_t Upload;//上报标记
	uint32_t tick;
}
LED_Sta_t;

extern LED_Sta_t LED;

void LED_Task(void);


#endif 
