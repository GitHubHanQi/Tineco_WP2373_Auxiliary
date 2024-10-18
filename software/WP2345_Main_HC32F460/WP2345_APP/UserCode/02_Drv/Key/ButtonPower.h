#ifndef _BUTTON_POWER_H
#define _BUTTON_POWER_H

#include "includes.h"


#define BUTTON_POWER_DELAY_FILTER   (32)    // ȥ������ʱ�������
#define BUTTON_POWER_DELAY_SHORT    (192)   // �̰�����ʱ�������



typedef enum
{
  ButtonPowerState_Unknow,
  ButtonPowerState_Release,
  ButtonPowerState_Press,
	ButtonPowerState_LongPress,
	ButtonPowerState_LongPress10s,
} ButtonPower_State_t;


typedef struct 
{
    uint32_t Press_Tick;
    uint32_t Release_Tick;
    ButtonPower_State_t State;

    ///uint8_t SingleClick_Flag;// һ��״���ĵ�������Ҫ����ʱ��ʹ��
    uint8_t SingleClick1_Flag;  // �������ͷ�����ʱ
} ButtonPower_t;
extern ButtonPower_t ButtonPower;


bool_t ButtonPower_Read(void);
void ButtonPower_Task(void);
void ButtonPower_SingleClick_Event(void);
void ButtonPower_Long3sClick_Event(void);


#endif
