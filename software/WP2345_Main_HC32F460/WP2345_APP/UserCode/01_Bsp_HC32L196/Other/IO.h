/*
 * @Author: your name
 * @Date: 2020-10-14 10:11:12
 * @LastEditTime: 2020-10-16 10:36:58
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \CL2019_芙万二代_直接\UserCode\01_Bsp_HC32L196\Other\IO.h
 */
#ifndef _IO_H
#define _IO_H

#include "includes.h"


void IO_Init(void);


////////// 测试用端口，64Pin的 MCU 没有这个端口
//#define LED_TEST_PORT           GpioPortD
//#define LED_TEST_PIN            GpioPin14
//#define LED_TEST_OFF()          {Gpio_ClrIO(LED_TEST_PORT, LED_TEST_PIN);}
//#define LED_TEST_ON()           {Gpio_SetIO(LED_TEST_PORT, LED_TEST_PIN);}
//void IO_Led_Test_Init(void);


//////// Button Main
#define BUTTON_MAIN_PORT          GpioPortB
#define BUTTON_MAIN_PIN           GpioPin0
#define BUTTON_MAIN_READ()        (Gpio_GetInputIO(BUTTON_MAIN_PORT, BUTTON_MAIN_PIN))
void IO_Button_Main_Init(void);


//////// Wifi Pair
#define WIFI_PAIR_PORT          GpioPortC
#define WIFI_PAIR_PIN           GpioPin13
#define WIFI_PAIR_READ()        (Gpio_GetInputIO(WIFI_PAIR_PORT, WIFI_PAIR_PIN))
#define BUTTON_WIFI_READ()      WIFI_PAIR_READ()     

//////// Wifi EN
#define WIFI_EN_PORT        GpioPortF
#define WIFI_EN_PIN         GpioPin5
#define WIFI_EN_OFF()       {Gpio_ClrIO(WIFI_EN_PORT, WIFI_EN_PIN);}
#define WIFI_EN_ON()        {Gpio_SetIO(WIFI_EN_PORT, WIFI_EN_PIN);}

void IO_Wifi_Pair_Init(void);


//////// Micro Key 用于识别机身是否倾斜
#define MICRO_KEY_PORT          GpioPortB
#define MICRO_KEY_PIN           GpioPin6


#define MICRO_KEY_READ()        (Gpio_GetInputIO(MICRO_KEY_PORT, MICRO_KEY_PIN))
void IO_Micro_Key_Init(void);

///////  HPEA
#define HPEA_PORT          GpioPortB
#define HPEA_PIN           GpioPin12
#define HPEA_READ()        (Gpio_GetInputIO(HPEA_PORT, HPEA_PIN))
void IO_Hpea_Init(void);

#define BUTTON_UPRIGHT_READ()   MICRO_KEY_READ()    // 兼容CL1879


//////// WT588 语音芯片
#define WT588_POWER_PORT        GpioPortB
#define WT588_POWER_PIN         GpioPin15
#define WT588_POWER_OFF()       {Gpio_SetIO(WT588_POWER_PORT, WT588_POWER_PIN);}   // 负逻辑，高电平关闭电源 
#define WT588_POWER_ON()        {Gpio_ClrIO(WT588_POWER_PORT, WT588_POWER_PIN);}      // {Gpio_ClrIO(WT588_POWER_PORT, WT588_POWER_PIN);}  


#define WT588_CLK_PORT          GpioPortB
#define WT588_CLK_PIN           GpioPin2
#define WT588_CLK_L()           {Gpio_ClrIO(WT588_CLK_PORT, WT588_CLK_PIN);}
#define WT588_CLK_H()           {Gpio_SetIO(WT588_CLK_PORT, WT588_CLK_PIN);}

#define WT588_DATA_PORT         GpioPortB
#define WT588_DATA_PIN          GpioPin10
#define WT588_DATA_L()          {Gpio_ClrIO(WT588_DATA_PORT, WT588_DATA_PIN);}
#define WT588_DATA_H()          {Gpio_SetIO(WT588_DATA_PORT, WT588_DATA_PIN);}

#define WT588_BUSY_PORT         GpioPortA
#define WT588_BUSY_PIN          GpioPin7
#define WT588_BUSY_READ()       (Gpio_GetInputIO(WT588_BUSY_PORT, WT588_BUSY_PIN))

//兼容1879
#define VCLK_HIGH()   {Gpio_SetIO(WT588_CLK_PORT, WT588_CLK_PIN);}
#define VCLK_LOW()	  {Gpio_ClrIO(WT588_CLK_PORT, WT588_CLK_PIN);}
#define VDATA_HIGH()  {Gpio_SetIO(WT588_DATA_PORT, WT588_DATA_PIN);}
#define VDATA_LOW()   {Gpio_ClrIO(WT588_DATA_PORT, WT588_DATA_PIN);}

void IO_WT588_Init(void);
void WT588_IO_DeInit(void);



//////// 电解水的H桥
#define ELECTROLYZE_POWER_PORT  GpioPortB
#define ELECTROLYZE_POWER_PIN   GpioPin8
#define ELECTROLYZE_POWER_OFF() {Gpio_ClrIO(ELECTROLYZE_POWER_PORT, ELECTROLYZE_POWER_PIN);}
#define ELECTROLYZE_POWER_ON()  {Gpio_SetIO(ELECTROLYZE_POWER_PORT, ELECTROLYZE_POWER_PIN);}

#define ELECTROLYZE_A_PORT      GpioPortC
#define ELECTROLYZE_A_PIN       GpioPin8
#define ELECTROLYZE_A_L()       {Gpio_ClrIO(ELECTROLYZE_A_PORT, ELECTROLYZE_A_PIN);}
#define ELECTROLYZE_A_H()       {Gpio_SetIO(ELECTROLYZE_A_PORT, ELECTROLYZE_A_PIN);}

#define ELECTROLYZE_B_PORT      GpioPortC
#define ELECTROLYZE_B_PIN       GpioPin9
#define ELECTROLYZE_B_L()       {Gpio_ClrIO(ELECTROLYZE_B_PORT, ELECTROLYZE_B_PIN);}
#define ELECTROLYZE_B_H()       {Gpio_SetIO(ELECTROLYZE_B_PORT, ELECTROLYZE_B_PIN);}

void Electrolyze_Init(void);


#endif
