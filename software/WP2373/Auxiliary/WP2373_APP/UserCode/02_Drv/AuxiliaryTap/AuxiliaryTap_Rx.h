/*
 * @Description:辅机读龙头的数据
 * @Author: hanqi.zhang
 * @Date: 2023-12-13 08:44:36
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-22 16:28:11
 */

#ifndef _AUXILIARYTAP_RX_H
#define _AUXILIARYTAP_RX_H

#include "includes.h"

#define READTAP_TIMEOUT (5000)
#define AUXILIARYTAP_RX_DATA_SIZE (12)

#define DELAY_5S (5000)

#define AUXILIARYTAP_RX_HEAD (0xA3)
#define AUXILIARYTAP_RX_ADDERSS (0xAD)
#define AUXILIARYTAP_RX_LENGTHS (16)

typedef enum {
  AuxiliaryTapState_Disconnect,
	AuxiliaryTapState_Connect,
} AuxiliaryTap_State_Enum;

typedef enum {
  AuxiliaryTapRxState_Head,
  AuxiliaryTapRxState_Address,
  AuxiliaryTapRxState_Lengths,
  AuxiliaryTapRxState_Data,
  AuxiliaryTapRxState_Checksum,
} AuxiliaryTap_Rx_State_Enum;


typedef union {
	uint8_t AuxiliaryTap_User_Buf;
	struct TapUserInfo
	{
		uint8_t ChildrenlockFlag:1;
		uint8_t Water98Flag:1;
		uint8_t Water45_85Flag:1;
		uint8_t EnjoyDrinkingFlag:1;
		uint8_t CoolWaterFlag:1;
		uint8_t SparklingWaterFlag:1;
	  uint8_t ColdWaterFlag:1;
	}Info;
}AuxiliaryTap_User_Union;

//上传数据
typedef union {
	uint8_t AuxiliaryReportFlag_t;
	struct AuxiliaryReportFlagInfo
	{
		uint8_t ReportHotFlag:1;
		uint8_t BoilingPointRelearningFlag:1;
		uint8_t OpenHotFlag:1;
		uint8_t HotWaterLevel:2;
		uint8_t AppColdWaterFlag:1;
		uint8_t AppSparklingWaterFlag:1;
		uint8_t SetColdWaterTemp:1;
	}Info;
}AuxiliaryReportFlag_Union;


//辅机部分状态
typedef union {
	uint8_t AuxiliaryPartStatus_t;
	struct AuxiliaryPartStatusInfo
	{
		uint8_t AddCoolWaterFlag:1;
		uint8_t AddColdWaterFlag:1;
		uint8_t AuxiliaryCarbonTank:1;
		uint8_t RefrigerationFlag:1;
		uint8_t SparklingLevel:2;
		uint8_t ColdWaterLevel:2;
//		uint8_t ColdWaterLevel:1;

	}Info;
}AuxiliaryPartStatus_Union;

//辅机部分状态2
typedef union {
	uint8_t AuxiliaryPart2Status_t;
	struct AuxiliaryPart2StatusInfo
	{
		uint8_t AuxiliaryFlushingFlag:1;
		uint8_t FlushOverFlag:1;
		uint8_t WarmingFlag:1;

	}Info;
}AuxiliaryPart2Status_Union;


typedef struct {
  uint16_t Tick;
  AuxiliaryTap_State_Enum StateConnect;
  AuxiliaryTap_Rx_State_Enum State;
  uint16_t DataLen;
  union Tap_Rx{
      uint8_t Buf[AUXILIARYTAP_RX_DATA_SIZE]; 
		  struct AuxiliaryTap_Info_t {
				AuxiliaryTap_User_Union User;
				uint8_t HotTemp;
				uint8_t SettingColdTemp;
				uint8_t ColdTemp;
				AuxiliaryReportFlag_Union AuxiliaryReportFlag;
				AuxiliaryPartStatus_Union AuxiliaryPartStatus;
				uint8_t AuxiliaryFault;
				uint8_t NewStudy;
				AuxiliaryPart2Status_Union AuxiliaryPart2Status;
				uint8_t Reserve2;
				uint8_t Version;
				uint8_t Frame;
    } Info;
  }Rx;
  uint8_t Checksum;
  uint16_t Index;
  uint8_t RxEndFlag;
	uint8_t RxDataCount;
	uint8_t RxIsOverCanTransmit;
	uint8_t AddressCode;
} AuxiliaryTap_Rx_t;
extern AuxiliaryTap_Rx_t AuxiliaryTap_Rx;



void AuxiliaryTap_Rx_Clear(void);
void AuxiliaryTap_Rx_Task(void);
void AuxiliaryTap_Rx_Byte_Analysis(uint8_t RxData);
void AuxiliaryTap_Rx_Frame_Analysis(void);

#endif
