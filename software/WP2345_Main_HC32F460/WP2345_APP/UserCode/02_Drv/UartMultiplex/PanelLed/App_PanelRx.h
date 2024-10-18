#ifndef _APP_PANEL_RX_H
#define _APP_PANEL_RX_H

#include "includes.h"


#define PANEL_RX_NOF_FRAME_MAX		(10)	// 接收的数据域长度上限
#define PANEL_RX_DataLength			(0+2)		// 数据长度
#define PANEL_RX_FingerState_Pos	(1+2)		// 0不接触，1正在接触
#define PANEL_RX_DischargeMode_Pos	(2+2)		// 0自动放电，1手动放电
#define PANEL_RX_VacuumPower_Pos	(3+2)		// 0~0x64
#define PANEL_RX_Version1			(4+2)
#define PANEL_RX_Version2			(5+2)



#define PANEL_RX_LENGTH   40

extern volatile uint8_t PanelRx_Tick;


typedef enum
{
	PanelRxState_Head,
	PanelRxState_Func,
	PanelRxState_Len,
	PanelRxState_Data,
	PanelRxState_Checksum,
	PanelRxState_End
} enum_PanelRx_State_t;
extern volatile enum_PanelRx_State_t PanelRx_State;

extern uint8_t Panel_RxBuf[];
extern volatile uint8_t PanelRx_Index;
extern volatile uint8_t PanelRx_Len;
extern volatile uint8_t PanelRx_Checksum;
extern volatile _Bool 	Flag_Panel_ReceiveEnd;

extern void PanelRx_Check(void);
void PanelRx_Clear(void);
void PanelRx_Task(void);
void PanelRx_ISR(uint8_t UartRx_Data);
void PanelRx_Analyize(void);

#endif

