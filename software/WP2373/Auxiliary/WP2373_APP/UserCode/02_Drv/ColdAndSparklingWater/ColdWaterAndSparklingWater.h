/*
 * @Description:冷水、气泡水实现状态机
 * @Author: hanqi.zhang
 * @Date: 2023-12-18 11:16:23
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-21 11:14:26
 */

#ifndef _COLDWATERANDSPARKLINGWATER_H
#define _COLDWATERANDSPARKLINGWATER_H

#include "includes.h"

// 各个电磁阀和泵以及压缩机的状态
typedef struct {
  uint8_t Motor_01_Flag;  //出冷水阀
  uint8_t Motor_02_Flag;   //出气泡水阀
  uint8_t Motor_03_Flag;  //加常温水阀
  uint8_t Motor_04_Flag;    //出常温水阀
	uint8_t Motor_05_Flag;
  uint8_t BoosterPump_Flag;//增压泵
	uint8_t BoosterCoolPump_Flag;//常温水泵
	uint8_t Mix_Motor_Flag;
	uint8_t Fan_Flag;
} MotorBoostFlag_t;
extern MotorBoostFlag_t MotorBoostFlag;

typedef struct {
	uint8_t Flag;
	uint32_t CountOpen;
	uint32_t CountClose;
}MixMotorVariable_t;
extern MixMotorVariable_t MixMotorVariable;

typedef enum {
  CompressorInit = 0,
  CompressorStart,
  CompressorWorking,
  CompressorClose ,
  Compressor5minSanitisation
} CompressorStatus_Enum;

typedef struct {
  CompressorStatus_Enum Status;
  uint8_t CompressorIsWorking;
  uint32_t Compressor5min;
	uint8_t StopTemp;
	uint8_t WorkTemp;
	uint8_t CloseStatus;
	uint32_t ProtectCount;
	uint8_t ErrorFlag;
	uint32_t MixMotorCount;
	uint32_t FirstStart;
	uint32_t Compressor30min;
	uint8_t SpecialFlag;
} Compressor_t;
extern Compressor_t Compressor;

//主机正常工作状态
typedef enum {
  AuxiliaryNormalWorkInit = 0,
  OutOfColdWater,
  OutOfSparklingWater,
  OutOfCoolWater ,
  ColdWaterBoxAddCoolWater,
	SparklingWaterBoxAddColdWater,
	ProfitterAddCoolWater,
	DealKeyInformation
} AuxiliaryNormalWorkStatus_Enum;

typedef struct {
  AuxiliaryNormalWorkStatus_Enum Status;

} AuxiliaryNormalWork_t;
extern AuxiliaryNormalWork_t AuxiliaryNormalWork;


// 冷水箱
typedef struct {
  uint8_t OutWaterIsWorking;
	int16_t BoxTemp;
	uint32_t Temp01sCount_LessStopTemp;
	uint32_t Temp01sCount_MoreStartTemp;
	uint8_t WaterLevelSensor_H ;
	uint32_t Count_H;
  uint8_t WaterLevelSensor_L ;
	uint32_t Count_L;
	uint32_t SENSOR_H_Count;
	uint8_t AddCoolWaterCom;
	uint8_t OverflowFlag;
	uint8_t AddCoolWaterFlag;
	uint8_t ErrorFlag;
	uint32_t ProtectCount;
	uint8_t Level;
	uint8_t WarmFlag;
	uint16_t EmptyCount;
} ColdWaterBox_t;
extern ColdWaterBox_t ColdWaterBox;

typedef enum {
  ColdWaterOpen,
	ColdWaterWait,
  ColdWaterClose,
} ColdWaterStatus_Enum;

typedef struct {
  ColdWaterStatus_Enum Status;
	uint8_t HostOutWater;
	uint32_t OpenMidCount;
	uint32_t CloseMidCount;
	uint32_t Delay3sAdd;
} ColdWater_t;
extern ColdWater_t ColdWater;

typedef enum {
  AddCoolWaterOpen,
  AddCoolWaterWait,
  AddCoolWaterClose
} AddCoolWaterStatus_Enum;

typedef struct {
  AddCoolWaterStatus_Enum Status;
  uint32_t Tick;
  uint8_t AddCoolWaterOrOutCoolWaterFlag ;
} AddCoolWater_t;
extern AddCoolWater_t AddCoolWater;

// 气泡水
typedef struct {
  uint8_t OutSparklingIsWorking;
	uint8_t AddColdWaterFlag;
	uint32_t ProtectCount;
	uint8_t ErrorFlag;
	uint16_t CloseDelayCnt;
	uint8_t Level;
} SparklingWaterBox_t;
extern SparklingWaterBox_t SparklingWaterBox;

typedef enum {
  SparklingWaterOpen = 0,
  SparklingWaterWait,
  SparklingWaterClose
} SparklingWaterStatus_Enum;

typedef struct {
  SparklingWaterStatus_Enum Status;
	uint8_t LowVoltageFlag;
	uint32_t VoltageCnt;
	uint8_t CloseStatus;
} SparklingWater_t;
extern SparklingWater_t SparklingWater;

typedef enum {
	FlushPipe = 0,
	FlushPipeWait,
	CoolWaterValveClose,
	AddColdWaterWait,
  AddColdWaterClose,
} AddColdWaterStatus_Enum;


//typedef enum {
//  AddColdWaterOpen = 0,
//	AddColdWaterWait,
//  AddColdWaterClose,
//} AddColdWaterStatus_Enum;

typedef struct {
  AddColdWaterStatus_Enum Status;
	
} AddColdWater_t;
extern AddColdWater_t AddColdWater;

//常温水
typedef enum {
  CoolWaterOpen = 0,
	CoolWaterWait,
  CoolWaterClose
} CoolWaterStatus_Enum;

typedef struct{
	uint8_t Flag;
	CoolWaterStatus_Enum Status;
	uint8_t OutofCoolWaterIsWorking;
}CoolWater_t;
extern CoolWater_t CoolWater;

//食万
typedef enum{
	ProfitterAddWaterOpen = 0,
	ProfiterAddWaterWait,
	ProfitterAddWaterClose
}ProfitterAddWaterStatus_Enum;

typedef struct{
	ProfitterAddWaterStatus_Enum Status;
	uint8_t ProfitterOpenFlag;
	uint8_t WifiOpenFlag;
	uint8_t AddWaterFlag;
	uint32_t TimeCnt;
	uint8_t WifiErrorFlag;
	uint8_t AddWaterTime;
}ProfitterAddWater_t;
extern ProfitterAddWater_t ProfitterAddWater;

//压缩机运行状态机
void CompressorOperation(void);

//辅机正常通信状态机
void AuxiliaryNormalWorkingFunction(void);

void CheckInitStatus(void);
bool CheckColdWaterCondition(void);
bool CheckSparklingWaterCondition(void);
bool CheckCoolWaterCondition(void);
bool CheckAddCoolWaterCondition(void);
bool CheckAddColdWaterCondition(void);
bool CheckProfitterCondition(void);
bool CheckDealKeyInformationCondition(void);





//功能实现状态机
void OutOfColdWaterFunction(void);
void ColdWaterBoxAddCoolWaterFunction(void);
void OutOfSparklingWaterFunction(void);
void SparklingWaterBoxAddColdWaterFunction(void);
void OutOfCoolWaterFunction(void);
void ProfitterAddCoolWaterFunction(void);
void DealKeyInformationFunction(void);

//外设底层驱动
bool ColdWaterOutWaterOpenFunction(void);

bool ColdWaterOutWaterCloseFunction(void);

void CoolWaterOutWaterOpenFunction(void);

void CoolWaterOutWaterCloseFunction(void);

void SparklingWaterOutWaterOpenFunction(void);

void SparklingWaterOutWaterCloseFunction(void);

void AddCoolWaterOpenFunction(void);

void AddCoolWaterCloseFunction(void);

bool AddColdWaterOpenFunction(void);

void AddColdWaterCloseFunction(void);

void RefrigerationOpenFunction(void);

void RefrigerationCloseFunction(void);

void ProfiteeringAddWaterOpenFunction(void);

void ProfiteeringAddWaterCloseFunction(void);

//单独开关负载
void OpenOutColdWaterValveFunction(void);
void OpenOutSparklingWaterValveFunction(void);
void OpenAddCoolWaterValveFunction(void);
void OpenOutCoolWaterValveFunction(void);
void OpenProfitterValveFunction(void);
bool OpenBoostPumpFunction(void);
void OpenMixMotorFunction(void);
void OpenFanFunction(void);
void OpenCompressFunction(void);

void CloseOutColdWaterValveFunction(void);
void CloseOutSparklingWaterValveFunction(void);
void CloseAddCoolWaterValveFunction(void);
void CloseOutCoolWaterValveFunction(void);
void CloseProfitterValveFunction(void);
void CloseBoostPumpFunction(void);
void CloseMixMotorFunction(void);
void CloseFanFunction(void);
void CloseCompressFunction(void);

void RefrigerateMixMotorFunction(void);



#endif
