/*
 * @Author: your name
 * @Date: 2020-10-14 10:11:12
 * @LastEditTime: 2020-10-16 10:36:58
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: 
 */
#ifndef _IO_H
#define _IO_H

#include "includes.h"





////////// 测试用端口，64Pin的 MCU 没有这个端口
//#define LED_TEST_PORT           GpioPortD
//#define LED_TEST_PIN            GpioPin14
//#define LED_TEST_OFF()          {PORT_ResetBits(LED_TEST_PORT, LED_TEST_PIN);}
//#define LED_TEST_ON()           {Gpio_SetIO(LED_TEST_PORT, LED_TEST_PIN);}
//void IO_Led_Test_Init(void);
#define PressurePump_NUM              0//36V增压水泵
#define Hot_OldValve_NUM              6//热陈水
#define SourceValve_NUM               1//进水
#define PureoutValve_NUM              4//纯水出水阀
#define PureheatValve_NUM             2//纯水进加热罐阀
#define DrainOutValve_NUM                5//废水阀
//#define PrimaryValve_NUM              6//初级过滤阀
#define PurebackValve_NUM             3//RO纯水回流阀
#define Pump_Num  6  //无刷泵
#define HeatHighPower_Num 7  //大功率
#define HeatSmallPower_Num 8  //小功率
//////// Input ////////

////// 全功率继电器
#define HighPower_PORT                 PortB
#define HighPower_N_PIN                Pin06
#define HighPowerHeat_N_ON()           PORT_SetBits(HighPower_PORT, HighPower_N_PIN)
#define HighPowerHeat_N_OFF()					 PORT_ResetBits(HighPower_PORT, HighPower_N_PIN)

#define HighPower_L_PIN                Pin07
#define HighPowerHeat_L_ON()           PORT_SetBits(HighPower_PORT, HighPower_L_PIN)
#define HighPowerHeat_L_OFF()					 PORT_ResetBits(HighPower_PORT, HighPower_L_PIN)

////// 小功率可控硅
#define SmallPower_PORT               PortB
#define SmallPower_PIN                Pin04
#define SmallPowerHeat_ON()           PORT_SetBits(SmallPower_PORT, SmallPower_PIN)
#define SmallPowerHeat_OFF()					PORT_ResetBits(SmallPower_PORT, SmallPower_PIN)


/********************
1->进水阀
2->热罐补水
3->纯水回流
4->龙头用水阀
5->温水调控

**********************/
/////热陈水排水阀阀  
#define Hot_DrainOUT_PORT               PortH
#define Hot_DrainOUT_PIN                Pin00
#define Hot_DrainOUTValve_ON()          {PORT_SetBits(Hot_DrainOUT_PORT, Hot_DrainOUT_PIN);SET_BIT(ValveState, Hot_OldValve_NUM);}
#define Hot_DrainOUTValve_OFF()					{PORT_ResetBits(Hot_DrainOUT_PORT, Hot_DrainOUT_PIN);CLEAR_BIT(ValveState, Hot_OldValve_NUM);}


/////进水阀  1
#define Source_PORT                    PortB
#define Source_PIN                     Pin09
#define SourceValve_ON()               {PORT_SetBits(Source_PORT, Source_PIN);SET_BIT(ValveState, SourceValve_NUM);}
#define SourceValve_OFF()						 	 {PORT_ResetBits(Source_PORT, Source_PIN);CLEAR_BIT(ValveState, SourceValve_NUM);}


/////纯水出水阀      4
#define Pureout_PORT                  PortC
#define Pureout_PIN                   Pin14
#define PureoutValve_ON()             {PORT_SetBits(Pureout_PORT, Pureout_PIN);SET_BIT(ValveState, PureoutValve_NUM);}
#define PureoutValve_OFF()					  {PORT_ResetBits(Pureout_PORT, Pureout_PIN);CLEAR_BIT(ValveState, PureoutValve_NUM);}


/////纯水进加热罐阀 2
#define Pureheat_PORT                 PortH
#define Pureheat_PIN                  Pin02
#define PureheatValve_ON()            {PORT_SetBits(Pureheat_PORT, Pureheat_PIN);SET_BIT(ValveState, PureheatValve_NUM);}
#define PureheatValve_OFF()						{PORT_ResetBits(Pureheat_PORT, Pureheat_PIN);CLEAR_BIT(ValveState, PureheatValve_NUM);}


/////排水调节阀--- 5
#define DrainOut_PORT                    PortC
#define DrainOut_PIN                     Pin15
#define DrainOutValve_ON()              {PORT_SetBits(DrainOut_PORT, DrainOut_PIN); SET_BIT(ValveState, DrainOutValve_NUM);}
#define DrainOutValve_OFF()							{PORT_ResetBits(DrainOut_PORT, DrainOut_PIN);CLEAR_BIT(ValveState, DrainOutValve_NUM);}


/////初级过滤阀  
//#define Primary_PORT                  PortH
//#define Primary_PIN                   Pin01
//#define PrimaryValve_ON()             {PORT_SetBits(Primary_PORT, Primary_PIN);SET_BIT(ValveState, PrimaryValve_NUM);}
//#define PrimaryValve_OFF()				    {PORT_ResetBits(Primary_PORT, Primary_PIN);CLEAR_BIT(ValveState, PrimaryValve_NUM);}


////RO纯水回流阀    3
#define Pureback_PORT                 PortC
#define Pureback_PIN                  Pin13
#define PurebackValve_ON()            {PORT_SetBits(Pureback_PORT, Pureback_PIN);SET_BIT(ValveState, PurebackValve_NUM);}
#define PurebackValve_OFF()					  {PORT_ResetBits(Pureback_PORT, Pureback_PIN);CLEAR_BIT(ValveState, PurebackValve_NUM);}


/////36V增压水泵---改用PWM
#define PressurePump_PORT             PortB
#define PressurePump_PIN              Pin08
//#define PressurePump_ON()             PORT_SetBits(PressurePump_PORT, PressurePump_PIN)
//#define PressurePump_OFF()						PORT_ResetBits(PressurePump_PORT, PressurePump_PIN)


//TDS 使能
#define   TDS_EN_PORT     PortA
#define   TDS_EN_PIN      Pin15
#define   TDS_EN_ON()      PORT_ResetBits(PortA, Pin15)
#define   TDS_EN_OFF()     PORT_SetBits(PortA, Pin15)

//液位
#define LEVEL_EN_PORT     PortA
#define LEVEL_EN_PIN      Pin12
#define LEVEL_EN_ON()     PORT_ResetBits(LEVEL_EN_PORT, LEVEL_EN_PIN);
#define LEVEL_EN_OFF()    PORT_SetBits(LEVEL_EN_PORT, LEVEL_EN_PIN);

//可变废水阀
#define WasteValve1_PORT     PortB
#define WasteValve1_PIN      Pin02

#define WasteValve2_PORT     PortB
#define WasteValve2_PIN      


#define WasteValve3_PORT     PortB
#define WasteValve3_PIN      Pin12

#define WasteValve4_PORT     PortB
#define WasteValve4_PIN      Pin13

//WIFI EN
#define WIFI_EN_PORT   PortB
#define WIFI_EN_PIN    Pin03
#define WIFI_EN_OFF()           PORT_ResetBits(WIFI_EN_PORT, WIFI_EN_PIN);
#define WIFI_EN_ON()            PORT_SetBits(WIFI_EN_PORT, WIFI_EN_PIN);

//无刷泵
#define Pump_Power_PORT  PortC
#define Pump_Power_PIN   Pin10

//UV
#define UV_PORT  PortA
#define UV_PIN   Pin11

//四相五线电机
#define Motor_A_PORT  PortB
#define Motor_A_PIN   Pin02

#define Motor_B_PORT  PortB
#define Motor_B_PIN   Pin10

#define Motor_C_PORT  PortB
#define Motor_C_PIN   Pin12

#define Motor_D_PORT  PortB
#define Motor_D_PIN   Pin13

void IO_Init(void);
void IO_Input_Init(void);
void IO_Output_Init(void);
void mDelay(unsigned int ms);

void NTC_LEVEL_CHECK(uint8_t dat);



#endif
