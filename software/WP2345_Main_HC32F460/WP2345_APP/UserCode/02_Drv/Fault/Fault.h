#ifndef _FAULT_H
#define _FAULT_H

#include "includes.h"

#define ERR_BIT_Level_Socket				    (1)         //液位传感器故障 E1
#define ERR_BIT_Heat				            (2)         //加热故障       E2
#define ERR_BIT_Pump				            (3)         //无刷泵故障     E3
#define ERR_BIT_PressurePump				    (4)         //增压泵故障     E4
#define ERR_BIT_WaterFlow				        (5)         //流量计故障     E5
#define ERR_BIT_FaucetComm				      (6)         //龙头通信故障   FE
#define ERR_BIT_SourceValve				      (7)         //纯水进水阀故障   C1
#define ERR_BIT_PureoutValve				    (8)         //纯水出水阀故障   C2
#define ERR_BIT_PurebackValve				    (9)         //纯水回流阀故障   C3
#define ERR_BIT_PureheatValve				    (10)        //纯水进加热罐阀故障   C4
#define ERR_BIT_DrainOutValve				    (11)        //排水阀故障    C5
#define ERR_BIT_SourceTDS				        (12)        //源水TDS故障   C6
#define ERR_BIT_PureTDS				          (13)        //纯水TDS故障   C7
#define ERR_BIT_BoilPoint				        (14)        //沸点学习故障   B1
#define ERR_BIT_Supply				          (15)        //补水超时故障   B2
#define ERR_BIT_NTC_HOT				          (16)        //NTC1故障
#define ERR_BIT_NTC_COOL				        (17)        //NTC2故障

void err_code_bitmap_set(uint8_t bit);
void ErrorBitMap_Set(uint8_t err_bit);
void ErrorBitMap_Clr(uint8_t err_bit);
void ErrorBitMap_Rst(void);

#endif
