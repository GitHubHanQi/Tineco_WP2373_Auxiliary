#ifndef _LED_H
#define _LED_H

#include "includes.h"

typedef struct
{
	uint8_t WIFI_Sta;//0�� 1���� 2��
  uint8_t Heat_Sta;
  uint8_t FilterRst_Sta;
	uint8_t Upload;//�ϱ����
	uint32_t tick;
}
LED_Sta_t;

extern LED_Sta_t LED;

void LED_Task(void);


#endif 
