#ifndef _APP_PANEL_H
#define _APP_PANEL_H

#include "includes.h"


typedef enum
{
    PanelType_WithPanel      = 0x10,
    PanelType_WithoutPanel   = 0x11,
    PanelType_UnknowPanel    = 0xFF
} Panel_Type_t;
extern volatile uint8_t Panel_TxBuf[PANEL_TX_NOF_FRAME];
//extern volatile Panel_Type_t Panel_Type;

#define VACUUM_POWER_STANDARD	(20)	// �����ı�׼ֵ
#define VACUUM_POWER_MAX		(100)	// ���������ֵ
#define VACUUM_POWER_HIGH		(70)	// ���������ֵ
#define VACUUM_POWER_MED		(50)	// ���������ֵ


extern volatile uint16_t Panel_ErrorTick;
extern volatile uint8_t Panel_ErrorState;


extern volatile uint8_t Panel_FingerState;
extern volatile uint8_t Panel_SpeedMode;
extern volatile uint8_t Panel_SuctionMode;
extern volatile uint8_t Panel_VacuumPower;



void Panel_Task(void);




#endif

