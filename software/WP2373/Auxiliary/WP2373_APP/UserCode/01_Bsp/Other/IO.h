/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2023-12-19 17:22:45
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-21 14:55:50
 */

#ifndef _IO_H
#define _IO_H

#include "includes.h"

//////// Output ////////

////// 冷水电磁阀出水
#define COLDWATER_OUT_Valve_PORT PortB
#define COLDWATER_OUT_Valve_PIN Pin08
#define COLDWATER_OUT_Valve_ON() \
  PORT_SetBits(COLDWATER_OUT_Valve_PORT, COLDWATER_OUT_Valve_PIN)
#define COLDWATER_OUT_Valve_OFF() \
  PORT_ResetBits(COLDWATER_OUT_Valve_PORT, COLDWATER_OUT_Valve_PIN)

////// 气泡水出水
#define SPARKLINGWATER_OUT_Valve_PORT PortB
#define SPARKLINGWATER_OUT_Valve_PIN Pin07
#define SPARKLINGWATER_OUT_Valve_ON() \
  PORT_SetBits(SPARKLINGWATER_OUT_Valve_PORT, SPARKLINGWATER_OUT_Valve_PIN)
#define SPARKLINGWATER_OUT_Valve_OFF() \
  PORT_ResetBits(SPARKLINGWATER_OUT_Valve_PORT, SPARKLINGWATER_OUT_Valve_PIN)

/////常温水出水
#define COOLWATER_OUT_Valve_PORT PortB
#define COOLWATER_OUT_Valve_PIN Pin05
#define COOLWATER_OUT_Valve_ON() \
  PORT_SetBits(COOLWATER_OUT_Valve_PORT, COOLWATER_OUT_Valve_PIN)
#define COOLWATER_OUT_Valve_OFF() \
  PORT_ResetBits(COOLWATER_OUT_Valve_PORT, COOLWATER_OUT_Valve_PIN)

/////冷水箱进水
#define COOLWATER_IN_Valve_PORT PortB
#define COOLWATER_IN_Valve_PIN Pin06
#define COOLWATER_IN_Valve_ON() \
  PORT_SetBits(COOLWATER_IN_Valve_PORT, COOLWATER_IN_Valve_PIN)
#define COOLWATER_IN_Valve_OFF() \
  PORT_ResetBits(COOLWATER_IN_Valve_PORT, COOLWATER_IN_Valve_PIN)

/////碳化罐增压泵 -改用PWM软启动
#define Pump_C1_PORT PortA
#define Pump_C1_PIN Pin11


/////搅拌电机
#define Mix_Motor_PORT PortA
#define Mix_Motor_PIN Pin10
#define Mix_Motor_ON() PORT_SetBits(Mix_Motor_PORT, Mix_Motor_PIN)
#define Mix_Motor_OFF() PORT_ResetBits(Mix_Motor_PORT, Mix_Motor_PIN)

////风扇
#define Fan_Control_PORT PortA
#define Fan_Control_PIN Pin09
#define Fan_Control_ON() PORT_SetBits(Fan_Control_PORT, Fan_Control_PIN)
#define Fan_Control_OFF() PORT_ResetBits(Fan_Control_PORT, Fan_Control_PIN)

/////UV
#define Pump_C2_PORT PortA
#define Pump_C2_PIN Pin08
#define Pump_C2_ON() PORT_SetBits(Pump_C2_PORT, Pump_C2_PIN)
#define Pump_C2_OFF() PORT_ResetBits(Pump_C2_PORT, Pump_C2_PIN)

// 压缩机运行
#define COMPRESSSOR_PORT PortB
#define COMPRESSSOR_PIN Pin09
#define COMPRESSSOR_ON() PORT_SetBits(COMPRESSSOR_PORT, COMPRESSSOR_PIN)
#define COMPRESSSOR_OFF() PORT_ResetBits(COMPRESSSOR_PORT, COMPRESSSOR_PIN)

// 分水盒1-3
#define CVALUE1_CONTROL_PORT PortB
#define CVALUE1_CONTROL_PIN Pin04
#define CVALUE1_CONTROL_ON() \
  PORT_SetBits(CVALUE1_CONTROL_PORT, CVALUE1_CONTROL_PIN)
#define CVALUE1_CONTROL_OFF() \
  PORT_ResetBits(CVALUE1_CONTROL_PORT, CVALUE1_CONTROL_PIN)

#define CVALUE2_CONTROL_PORT PortD
#define CVALUE2_CONTROL_PIN Pin02
#define CVALUE2_CONTROL_ON() \
  PORT_SetBits(CVALUE2_CONTROL_PORT, CVALUE2_CONTROL_PIN)
#define CVALUE2_CONTROL_OFF() \
  PORT_ResetBits(CVALUE2_CONTROL_PORT, CVALUE2_CONTROL_PIN)

//#define CVALUE3_CONTROL_PORT PortC
//#define CVALUE3_CONTROL_PIN Pin12
//#define CVALUE3_CONTROL_ON() \
//  PORT_SetBits(CVALUE3_CONTROL_PORT, CVALUE3_CONTROL_PIN)
//#define CVALUE3_CONTROL_OFF() \
//  PORT_ResetBits(CVALUE3_CONTROL_PORT, CVALUE3_CONTROL_PIN)

// 碳化罐
#define LEVEL_EN_PORT PortB
#define LEVEL_EN_PIN Pin12
#define LEVEL_EN_ON() PORT_SetBits(LEVEL_EN_PORT, LEVEL_EN_PIN)
#define LEVEL_EN_OFF() PORT_ResetBits(LEVEL_EN_PORT, LEVEL_EN_PIN)

//蓝灯
#define LED3_PORT PortB
#define LED3_PIN Pin10
#define LED3_EN_ON() PORT_SetBits(LED3_PORT, LED3_PIN)
#define LED3_EN_OFF() PORT_ResetBits(LED3_PORT, LED3_PIN)

//////// Input ////////

// KEY
//#define KEY_COLDWATER_PORT PortC
//#define KEY_COLDWATER_PIN Pin09
//#define KEY_COLDWATER_STATUS() \
//  PORT_GetBit(KEY_COLDWATER_PORT, KEY_COLDWATER_PIN)

//#define KEY_SPARKLINGWATER_PORT PortC
//#define KEY_SPARKLINGWATER_PIN Pin08
//#define KEY_SPARKLINGWATER_STATUS() \
//  PORT_GetBit(KEY_SPARKLINGWATER_PORT, KEY_SPARKLINGWATER_PIN)

//#define KEY_COOLWATER_PORT PortB
//#define KEY_COOLWATER_PIN Pin13
//#define KEY_COOLWATER_STATUS() \
//  PORT_GetBit(KEY_COOLWATER_PORT, KEY_COOLWATER_PIN)

// 冷水箱液位
#define SENSOR_H1_PORT PortC
#define SENSOR_H1_PIN Pin11
#define SENSOR_H1_STATUS() PORT_GetBit(SENSOR_H1_PORT, SENSOR_H1_PIN)

#define SENSOR_L1_PORT PortC
#define SENSOR_L1_PIN Pin10
#define SENSOR_L1_STATUS() PORT_GetBit(SENSOR_L1_PORT, SENSOR_L1_PIN)

//碳化罐低压检测
#define LOW_VOLTAGE_DETECTION_PORT PortB
#define LOW_VOLTAGE_DETECTION_PIN Pin02
#define LOW_VOLTAGE_STATUS() PORT_GetBit(LOW_VOLTAGE_DETECTION_PORT, LOW_VOLTAGE_DETECTION_PIN)

//冷水箱防溢出检测
#define HALL_PORT PortC
#define HALL_PIN Pin13
#define OVERFLOW_PREVENTION_STATUS() PORT_GetBit(HALL_PORT, HALL_PIN)

//FG
#define FG_PORT PortC
#define FG_PIN Pin09


void IO_Init(void);
void IO_Input_Init(void);
void IO_Output_Init(void);
void IO_Event_Init(void);
void ExtInt09_Callback(void);




#endif
