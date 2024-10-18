#ifndef _APP_UI_DATA_H
#define _APP_UI_DATA_H

#include "includes.h"

#define Ui_GRADUALLY_PUMP30    20
#define Ui_GRADUALLY_PUMP50    50
#define Ui_GRADUALLY_PUMP75    70
#define Ui_GRADUALLY_PUMP100    100

#define Ui_GRADUALLY_POWER90W     30
#define Ui_GRADUALLY_POWER120W    70
#define Ui_GRADUALLY_POWER150W    100

#define FPcft_REPEAT_TIMES    (2)
extern volatile uint8_t FRcft_RepeatTimes_FirstForce;
extern volatile uint8_t FRcft_RepeatTimes;
extern volatile uint8_t FRcft_WorkingMode;
extern volatile uint8_t FRcft_CtrlDataSource;
extern volatile uint8_t FRcft_SpeedModeRequired;
extern volatile uint8_t FRcft_SuctionModeRequired;
extern volatile uint8_t FRcft_VacuumPowerRequired;
extern volatile uint8_t FRcft_WaterDisplacementRequired;
extern volatile uint8_t FRcft_MotorDisplacementRequired;
extern volatile uint8_t FRcft_MuteStateRequired;
extern volatile uint8_t FRcft_VoiceLevel;
extern volatile uint8_t FRcft_SensorRequired;
extern volatile uint8_t FRcft_BmsPercent;
extern volatile uint8_t FRcft_DustValue;
extern volatile uint16_t FRcft_Error;


#define BIT0    (1<<0u)
#define BIT1    (1<<1u)
#define BIT2    (1<<2u)
#define BIT3    (1<<3u)
#define BIT4    (1<<4u)
#define BIT5    (1<<5u)
#define BIT6    (1<<6u)
#define BIT7    (1<<7u)
#define BIT8    (1<<8u)
#define BIT9    (1<<9u)
#define BIT10   (1<<10u)
#define BIT11   (1<<11u)
#define BIT12   (1<<12u)
#define BIT13   (1<<13u)

#define ERROR_VACUUM_MOTOR      (BIT0)  // 吸尘电机故障
#define ERROR_DUCT_BLOCK_HALF   (BIT1)  // 滤芯半堵
#define ERROR_DUCT_BLOCK_ALL    (BIT2)  // 风道全堵
#define ERROR_BRUSH_MOTOR       (BIT3)  // 地刷过流
#define ERROR_DUST              (BIT4)  // 灰尘传感器故障
#define ERROR_PANEL             (BIT5)  // 触控屏没有通信，没有触控屏
#define ERROR_BMS_TEMPERATURE   (BIT6)  // 充电时过温
#define ERROR_BMS_COMM          (BIT7)  // 电池没有通信
#define ERROR_BMS_TIME          (BIT8)  // 充电超时
#define ERROR_BMS_CURRENT       (BIT9)  // 充电时过流

#define ERROR_DIRTYTANK         (BIT10)  // 污水桶满
#define ERROR_PURETANK          (BIT11)  // 清水桶缺水
#define ERROR_BRUSH_NOMOTOR     (BIT12)  // 地刷未安装
#define ERROR_BRUSH_ABRADE      (BIT13)  // 地刷磨损
#define ERROR_UN_DUMP			(BIT14) // 16384_污水桶未安装
#define ERROR_PUMP				(BIT15) //

extern volatile uint16_t Ui_Error_ToPhone;


//void UiData_Task(void);
//void FRcft_TimesSet(void);

extern volatile uint16_t ToolError_Value;
extern volatile uint16_t ToolError_ValueLast;
extern volatile uint16_t ToolError_ToUi;


void ToolError_Set(uint16_t flag);
void ToolError_Reset(uint16_t flag);
void ToolError_ResetBms(void);
bool_t ToolError_Check(uint16_t flag);



//void LogAppend_Tx(void);

#endif

