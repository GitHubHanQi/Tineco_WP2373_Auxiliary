/**
 * @file user_VOFA.h
 * @author WuRendi (minos.wu@tineco.com)
 * @brief
 * @date 2022-03-25
 *
 * @copyright Copyright (c) 2022 Tineco
 *
 **/
#ifndef _USER_VOFA_H
#define _USER_VOFA_H

#include "includes.h"
#include "VOFA+Json.h"

extern VOFA_Protocol_t user_VOFA_BT;

typedef enum
{
	VOFA_Chart_None = 0, /**< 无打印*/
	VOFA_Chart_Sensor,	 /**< 打印传感器数值*/
	VOFA_Chart_Weight,	 /**< 打印电机状态*/
	VOFA_Chart_Current,	 /**< 打印负载电流*/
} VOFA_Chart_ENUM;

/**
 * @brief VOFA调试
 *
 * @author WuRendi (minos.wu@tineco.com)
 * @date 2022-03-25
 **/
typedef struct
{
	VOFA_Chart_ENUM VOFA_Chart_State; /**< 传感器打印状态*/
	uint8_t feedBoxIndex;			  /**< 加料顺序*/
	int32_t feedWeight;				  /**< 加料重量*/
	int32_t feedPushTime;				  /**< 排料时间*/
	int32_t currentWeight;			  /**< 当前重量*/
	int32_t assistCount;			  /**< 辅助计时器*/
} VOFA_Debug_t;

extern VOFA_Debug_t VOFA_Debug;

void VOFA_Init(void);

void VOFA_ChartPrint_Task(void);

#endif
