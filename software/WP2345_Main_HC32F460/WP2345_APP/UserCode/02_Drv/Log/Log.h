#ifndef _LOG_H
#define _LOG_H

#include "includes.h"


//typedef __packed struct
typedef struct
{
  uint32_t Checksum;  // 数据内容+Seq
	
	uint32_t	DischargeSecondTotal;     // 使用总时长（不清空）
	uint8_t  First_Use_Flag; //首次使用
	uint8_t  BoilPointFlag;//沸点学习标记
	uint32_t  BoilPointTem;//沸点值
	uint32_t  Filter_LifeTime;//滤芯寿命
	uint32_t  UseWaterTotal;//累计用水量 
	uint8_t Heat_Enable;//允许加热
	uint8_t SupplyLevel;//补满液位
	uint32_t WifiPressCnt;//按键按键次数
	uint32_t FilterReplaceCnt;//滤芯更换次数
	uint32_t Filter_WaterTotal;//新滤芯用水量
	uint32_t Filter_UseTime;//新滤芯已使用时间

	

  struct{
		uint8_t BitMap[6];
		uint16_t ErrCount[48];
	}fm;
	
} Log_Data_t;
extern Log_Data_t Log_Data;


typedef struct 
{
    uint8_t IsErasing;          // 表示测试机或手机擦除日志，本次工作不再写日志。断电后恢复
    uint8_t IsSaved;
    uint8_t LogX;               // 当前保存日志的块序号，0和1

    ////////
    Log_Data_t pLogData0;      // Flash位置0
    uint16_t Checksum0;
    //
    Log_Data_t pLogData1;      // Flash位置1
    uint16_t Checksum1;

    ////////
    uint32_t Seq;
} Log_Ctrl_t;
extern Log_Ctrl_t Log_Ctrl;
extern volatile uint32_t Datalog_Discharge_Tick_ms;


void Log_Read(void);
void Log_Save(void);
void Log_Erase(void);
void Log_Save_Task(void);


#endif
