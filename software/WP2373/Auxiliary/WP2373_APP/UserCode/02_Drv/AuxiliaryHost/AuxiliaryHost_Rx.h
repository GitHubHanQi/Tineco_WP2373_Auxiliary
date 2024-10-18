/*
 * @Description:辅机读主机发送的数据
 * @Author: hanqi.zhang
 * @Date: 2023-12-13 14:51:01
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-22 09:49:47
 */

#ifndef _AUXILIARYHOST_RX_H
#define _AUXILIARYHOST_RX_H

#include "includes.h"

#define READHOST_TIMEOUT (5000)

#define AUXILIARYHOST_RX_DATA_SIZE (19)

#define AUXILIARYHOST_RX_HEAD 0xA3
#define AUXILIARYHOST_RX_ADDRESS 0xFA
#define AUXILIARYHOST_RX_LENGTHS (23)

typedef enum {
  AuxiliaryHostState_Disconnect,
	AuxiliaryHostState_Connect,
} AuxiliaryHost_State_Enum;

typedef enum {
  AuxiliaryHostRxState_Head,
  AuxiliaryHostRxState_Address,
  AuxiliaryHostRxState_Lengths,
  AuxiliaryHostRxState_DATA,
  AuxiliaryHostRxState_Checksum,
} AuxiliaryHost_Rx_State_Enum;


//整机工作状态
typedef union {
	uint8_t WholeMachineWorkState_Buf;
	struct WholeMachineWorkStateInfo
	{
		uint8_t Water98Flag:1;
		uint8_t Water45_85Flag:1;
		uint8_t EnjoyDrinkingFlag:1;
		uint8_t CoolWaterFlag:1;
		uint8_t ChildrenlockFlag:1;
		uint8_t SparklingWaterFlag:1;
	  uint8_t ColdWaterFlag:1;
		uint8_t StrongPunchFlag:1;
	}Info;
}AuxiliaryHost_WholeMachineWorkState_Union;

//主机模块状态
typedef union {
	uint8_t ModuleStatus_Buf;
	struct ModuleStatusInfo
	{
		uint8_t ReplaceCore :1;
		uint8_t Heater:2;
		uint8_t NewStudy:1;
		uint8_t InsufficientHotWater:1;
		uint8_t HotWaterVolume:2;
	}Info;
}AuxiliaryHost_ModuleStatus_Union;

//水位
typedef union {
	uint8_t WaterLevel_Buf;
	struct WaterLevelInfo
	{
		uint8_t Level :4;
		uint8_t HotTankAddWater:2;
		uint8_t HotTankUnoccupied:1;
	}Info;
}AuxiliaryHost_WaterLevel_Union;

//辅机上传状态
typedef union {
	uint8_t AuxiliaryReportColdTapStatus_Buf;
	struct AuxiliaryReportColdTapStatusInfo
	{
		uint8_t RefrigerationSwitch:1;
		uint8_t ColdWaterLevel:2;
		uint8_t Refrigeration:1;
    uint8_t AddCoolWater:1;
    uint8_t ColdWaterWarming:1;
	}Info;
}AuxiliaryReportColdTapStatus_Union;

typedef union {
	uint8_t AuxiliaryReportSparklingTapStatus_Buf;
	struct AuxiliaryReportSparklingTapStatusInfo
	{
		uint8_t SparklingSwitch:1;
		uint8_t SparklingWaterLevel:2;
		uint8_t AddColdWater:1;
		uint8_t TankLevel :1;
	}Info;
}AuxiliaryReportSparklingTapStatus_Union;


typedef struct {
	AuxiliaryHost_Rx_State_Enum State;
	AuxiliaryHost_State_Enum StateConnect;
  uint16_t Tick;
  uint16_t DataLen;
  union Rx_t {
    uint8_t Buf[AUXILIARYHOST_RX_DATA_SIZE];
    struct AuxiliaryHost_Info {
      AuxiliaryHost_WaterLevel_Union WaterLevel;
      uint8_t BeeperTimes;
      AuxiliaryHost_ModuleStatus_Union ModuleStatus;
      uint8_t FilterLife;
      uint8_t TroubleCode;
      uint8_t HotTemp;
      uint8_t TDS;
			AuxiliaryReportColdTapStatus_Union AuxiliaryReportColdTapStatus;
			AuxiliaryReportSparklingTapStatus_Union AuxiliaryReportSparklingTapStatus;
      uint8_t DrinkingTemperature;
			AuxiliaryHost_WholeMachineWorkState_Union WholeMachineWorkState;
      uint8_t CoolTemp;
      uint8_t ColdWaterTempSet_APP;
      uint8_t HostState;
      int8_t ColdWaterTemperature;
			uint8_t Reserve1;
			uint8_t Reserve2;
			uint8_t Reserve3;
      uint8_t Frame;
    }Info;
  } Rx;
  uint8_t RxDataCount;
  uint8_t Checksum;
  uint16_t Index;
  uint8_t RxEndFlag;
	uint8_t RxIsOverCanTransmit;
} AuxiliaryHost_Rx_t;
extern AuxiliaryHost_Rx_t AuxiliaryHost_Rx;


typedef enum {
  AuxiliaryHostRxGetVersionState_Head,
	AuxiliaryHostRxGetVersionState_SendAdd,
	AuxiliaryHostRxGetVersionState_ReceiveAdd,
  AuxiliaryHostRxGetVersionState_Function,
	AuxiliaryHostRxGetVersionState_Command,
  AuxiliaryHostRxGetVersionState_DataLength_H,
	AuxiliaryHostRxGetVersionState_DataLength_L,
//  AuxiliaryHostRxGetVersionState_Data,
  AuxiliaryHostRxGetVersionState_Checksum,
	AuxiliaryHostRxGetVersionState_End,
} AuxiliaryHostRx_GetVersion_State_Enum;

typedef struct {
	AuxiliaryHostRx_GetVersion_State_Enum State;
	uint16_t Tick;
	uint8_t RxEndFlag;
	uint8_t Checksum;
	uint8_t DataLen;
	uint8_t RxDataCount;
	uint8_t Index;
	uint8_t Buf[10];
	uint8_t RxIsOverCanTransmit;
}AuxiliaryHost_GetVersion_Rx_t;
extern AuxiliaryHost_GetVersion_Rx_t AuxiliaryHost_GetVersion_Rx;



void AuxiliaryHost_Rx_Clear(void);
void AuxiliaryHost_Rx_Task(void);
void AuxiliaryHost_Rx_Byte_Analysis(uint8_t RxData);
void AuxiliaryHost_Rx_Frame_Analysis(void);


void AuxiliaryHost_GetVersion_Analysis(uint8_t RxData);
void AuxiliaryHost_GetVersion_Rx_Task(void);
#endif