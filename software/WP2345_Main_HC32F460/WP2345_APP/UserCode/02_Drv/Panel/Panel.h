#ifndef _PANEL_H
#define _PANEL_H

#include "includes.h"


#define PANELLENGTH          1030

typedef struct
{
    uint8_t					Header;
	uint8_t 				Instructions1;
	uint8_t 				Instructions2;
	uint8_t 			    LengthH;
	uint8_t 			    LengthL;
	uint8_t 			    Num;
	uint8_t 				Mode;
	uint8_t 				State;
	uint8_t 				CoverControl;
	uint8_t					CoverState;
	uint8_t					StirState;
	uint8_t					StirDuty;
	uint8_t					StirRunTime;
	uint8_t					StirStopTime;
	uint8_t					StirReversal;
	uint8_t					Heat;
	uint8_t					FeedControl;
	uint8_t					RunStep;
	uint8_t					Temperature;
	uint8_t					Zero;
	uint8_t					Checksum;
}PANEL_RX_T;


typedef struct
{
	uint8_t					Header;
	uint8_t 				Instructions1;
	uint8_t 				Instructions2;
	uint8_t 			    LengthH;
	uint8_t 			    LengthL;
	uint8_t 			    Num;
	uint8_t 				Mode;
	uint8_t 				State;
	uint8_t 				CoverControl;
	uint8_t					CoverState;
	uint8_t					StirState;
	uint8_t					StirDuty;
	uint8_t					StirRunTime;
	uint8_t					StirStopTime;
	uint8_t					StirReversal;
	uint8_t					Heat;
	uint8_t					FeedControl;
	uint8_t					RunStep;
	uint8_t					Temperature;
	uint8_t					Zero;
	uint8_t					WeightH;
	uint8_t					WeightL;
	uint8_t					CoverCurrentH;
	uint8_t					CoverCurrentL;
	uint8_t					StirCurrentH;
	uint8_t					StirCurrentL;
	uint8_t					FeedState;
	uint8_t					CoverStateT;
	uint8_t					Pulse;
	uint8_t					Dir;
	uint8_t					Temp1;
	uint8_t					Temp2;
	uint8_t					Bottom;
	uint8_t					Power;
	uint8_t					Error1;
	uint8_t					Error2;
	uint8_t					Error3;
	uint8_t					Error4;
//	uint32_t				Error;
	uint8_t					Checksum;
}PANEL_TX_T;

typedef enum{
    PanelRxStep_Head = 0,
    PanelRxStep_Cmd1,
    PanelRxStep_Cmd2,
    PanelRxStep_LenH,
    PanelRxStep_LenL,
    PanelRxStep_Num,
    PanelRxStep_Type,
    PanelRxStep_Data,
    PanelRxStep_CRC8,
}PanelRxStep_t;

typedef struct
{
    uint8_t      RxBuf[1300];
    PanelRxStep_t RxStep;
    uint16_t     RxCnt;
    uint16_t     RxDataLen;
    uint8_t     RxCheckSum;
    uint8_t     RxTimeOut1ms;
    uint8_t     Num;
    uint8_t     Type;
    uint8_t     TxBuf[1300];
    uint16_t    TxCnt;
    uint32_t    Display100mscnt; 
}PANEL_T;

extern  PANEL_T  Panel;

extern uint32_t PanelTimeOutCount;
extern volatile uint8_t Panel_Finish_Flag;

void PanelRxFiFo_Handler(uint8_t ch);






#endif




