#ifndef _APP_UI_H
#define _APP_UI_H

#include "includes.h"


#define VACUUM_POWER_STANDARD	(20)	// »¬ÌõµÄ±ê×¼Öµ
#define VACUUM_POWER_MAX		(100)	// »¬ÌõµÄ×î´óÖµ
#define VACUUM_POWER_HIGH		(70)	// »¬ÌõµÄ×î´óÖµ
#define VACUUM_POWER_MED		(50)	// »¬ÌõµÄ×î´óÖµ

typedef enum
{
	Ui_FingerState_None,
	Ui_FingerState_PanelOnly,
	Ui_FingerState_PhoneOnly,
} Ui_FingerState_t;
extern volatile Ui_FingerState_t Ui_FingerState;

#define PANEL_SOURCE_PANEL	(0)
#define PANEL_SOURCE_TOOL	(1)
extern volatile uint8_t Panel_CtrlDataSource_ToPanel;

#define PHONE_SOURCE_PHONE	(0)
#define PHONE_SOURCE_TOOL	(1)
extern volatile uint8_t Phone_CtrlDataSource_ToPhone;



extern volatile uint16_t Phone_NoFingerTick;
extern volatile bool_t Phone_NoFingerState;



extern volatile uint8_t Phone_FingerState;
extern volatile uint8_t Phone_SpeedMode;
extern volatile uint8_t Phone_SelfCleanMode; 
extern volatile uint8_t Phone_VacuumPower;
extern volatile uint8_t Phone_SuctionMode;



extern volatile uint8_t Ui_SpeedMode;
extern volatile uint8_t Ui_SuctionMode;
extern volatile uint8_t Ui_VacuumPower_FromUi;
extern volatile uint8_t Ui_VacuumPower_ToUi;
extern volatile uint8_t Phone_Power_State;
extern volatile uint8_t Phone_ClearGears;

//void Ui_Clear(void);
//void Ui_Task(void);


#endif

