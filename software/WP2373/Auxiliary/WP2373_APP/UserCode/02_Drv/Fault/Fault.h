/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2024-01-23 15:46:02
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-02-21 08:28:48
 */
#ifndef _FAULT_H
#define _FAULT_H

#include "includes.h"
//过流阈值
#define VALVE01OVERCURRENT (600)
#define VALVE02OVERCURRENT (600)
#define VALVE03OVERCURRENT (600)
#define VALVE04OVERCURRENT (600)
#define VALVE05OVERCURRENT (600)
#define BOOSTERPUMPOVERCURRENT (3800)
#define MIXMOTOROVERCURRENT (1000)
#define FANOVERCURRENT (500)//实际堵死250mA
//检测时间
#define VALVE01OVERCURRENTTIME (1000)
#define VALVE02OVERCURRENTTIME (1000) 
#define VALVE03OVERCURRENTTIME (1000)
#define VALVE04OVERCURRENTTIME (1000)
#define VALVE05OVERCURRENTTIME (1000)
#define BOOSTERPUMPOVERCURRENTTIME (200)
#define MIXMOTOROVERCURRENTTIME (1000)
#define FANOVERCURRENTTIME (1000)
//开路电流阈值
#define VALVE01OPENCURRENT (50)
#define VALVE02OPENCURRENT (50)
#define VALVE03OPENCURRENT (50)
#define VALVE04OPENCURRENT (50)
#define VALVE05OPENCURRENT (50)
#define BOOSTERPUMPOPENCURRENT (300)
#define MIXMOTOROPENCURRENT (20)
#define FANOPENCURRENT (50)
//开路检测时间
#define VALVE01OPENCURRENTTIME (3000)
#define VALVE02OPENCURRENTTIME (3000)
#define VALVE03OPENCURRENTTIME (3000)
#define VALVE04OPENCURRENTTIME (3000)
#define VALVE05OPENCURRENTTIME (3000)
#define BOOSTERPUMPOPENCURRENTTIME (3000)
#define MIXMOTOROPENCURRENTTIME (3000)
#define FANOPENCURRENTTIME (3000)

#define NTCCHANGEMAXTIME (600000)
#define NTCMAXTEMP (50)
#define NTCMINTEMP (-10)

#define CommuncationAbnormal                  (0xFE)
#define OutColdWaterValveAbnormal             (0xD1)  //冷水箱出水阀异常
#define OutSparklingWaterValveAbnormal        (0xD2) //气泡水出水阀异常
#define AddCoolWaterValveAbnormal             (0xD3) //冷水箱进水阀异常
#define OutCoolWaterValveAbnormal             (0xD4) //常温水出水阀异常
#define WaterDispenserValveAbnormal           (0xD5) //分水盒出水阀异常
#define BoosterPumpAbnormal                   (0xD6) //增压泵故障
#define NTCAbnormal            								(0xD7) //NTC异常
#define CompressorWorkOverTime   							(0xD8) //压缩机工作异常
#define CarbonTankRefillOverTime   						(0xD9) //碳化罐补水超时
#define ColdWaterBoxAddWaterOverTime    			(0xDA) //冷水箱补水超时
#define CarbonTankOutWaterOverTime      			(0xDB) //碳化罐出水超时
#define OutColdWaterOverTIme         					(0xDC) //冷水出水超时
#define FANAbnormal           								(0xDD) //风扇工作异常
#define MixMotorAbnormal          						(0xDF) //搅拌电机工作异常
#define OverflowAbnormal                      (0xDE) //溢出水位异常


//错误对应位
#define ERR_BIT_VALVE_1				         				(20)         //冷水箱出水阀异常
#define ERR_BIT_VALVE_2				    						(21)         //气泡水出水阀异常
#define ERR_BIT_VALVE_3				    						(22)         //冷水箱进水阀异常
#define ERR_BIT_VALVE_4				    						(23)         //常温水出水阀异常
#define ERR_BIT_VALVE_5			     						  (24)         //分水盒出水阀异常
#define ERR_BIT_BOOSTERPUMP				    			  (25)         //增压泵故障
#define ERR_BIT_NTC				     							  (26)         //NTC异常
#define ERR_BIT_COMPRESSOR				   				  (27)         //压缩机工作异常
#define ERR_BIT_CARBONTANKREFILL				      (28)         //碳化罐补水超时
#define ERR_BIT_COLDWATERBOXADDCOOLWATER			(29)         //冷水箱补水超时 
#define ERR_BIT_FAN				                    (30)        //风扇工作异常   
#define ERR_BIT_MIXMOTOR				              (31)        //搅拌电机工作异常  


//////// ADC值 转 电流mA 0.2R
#define ADCConversionCurrent(x)      (uint32_t)((uint16_t)(x) *1100 /273)       // ADC/4095*3300/0.2
#define BoosterPumpADCConversionCurrent(x)  (uint32_t)((uint16_t)(x) *1100/137) // ADC/4095*3300/0.1
//假设x为一个最大的16位无符号整数，即65535。我们将用这个值来测试这个宏定义会不会导致溢出。
//根据给定的宏定义，我们有: ADCConversionCurrent(65535) = (uint32_t)((uint16_t)(65535) *1100 /273)
//首先，将65535转换为uint16_t，这不会导致溢出，因为65535在16位无符号整数的范围内。然后，我们将这个值乘以1100，然后再除以273。
//(65535 * 1100) / 273 = 26532900 / 273 ≈ 97253.47
//最后，将结果转换为uint32_t，这也不会导致溢出，因为结果仍然在32位无符号整数的范围内。
//因此，根据这个宏定义，即使在最大的16位无符号整数的情况下，也不会导致溢出。

typedef enum{
	LogAndReportTempError = 0,
	GetNormalNTCSensorTemp,
}TempErrorStatus_Enum;

typedef struct {
  uint8_t HostErrorFlag;
  uint8_t AuxiliaryErrorFlag;
  uint8_t AllLoadFlag;
	uint8_t AuxiliaryErrorCode;
	uint8_t CommunicationError;
	uint8_t OutOfColdWaterValveError;
	uint8_t OutOfSparklingWaterValveError;
	uint8_t AddCoolWaterValveError;
	uint8_t OutOfCoolWaterValveError;
	uint8_t ProfitterAddWaterValveError;
	uint8_t OverflowError;
	uint32_t OverflowErrorCount;
	uint8_t BoosterPumpError;
	uint8_t MixMotorError;
	
	uint8_t AddCarbonTankError;
	uint8_t AddCoolWaterError;

	TempErrorStatus_Enum TempErrorStatus;
	uint8_t FaultBit[5];
	uint8_t SpecificFaultBit;
} Fault_t;
extern Fault_t Fault;

typedef struct {
  uint8_t Status;  // 1开 0关
  uint16_t Current;
  uint8_t OverErrorFlag;
  uint8_t OpenErrorFlag;
  uint16_t OverCurrent_cnt;
  uint16_t OpenCurrent_cnt;
  enum {
    VALVE_ERR_NONE = 0,
    VALVE_ERR_OPEN_CURRENT,
    VALVE_ERR_OVER_CURRENT,
  } Error;
	uint32_t Count;
	uint8_t NumberOfExceptions;
	uint8_t ThreeErrorFlag;
	//埋点使用

  uint16_t Current_BUF[25];
  uint32_t Current_BUF_Cnt;
} ValveCurrent_t;
extern ValveCurrent_t Motor_01_Check;  // 出冷水阀
extern ValveCurrent_t Motor_02_Check;  // 出气泡水阀
extern ValveCurrent_t Motor_03_Check;  // 出常温水阀
extern ValveCurrent_t Motor_04_Check;  // 加温水阀
extern ValveCurrent_t Motor_05_Check;  // 食万加水阀
extern ValveCurrent_t BoosterPump_Check ;//增压泵
extern ValveCurrent_t Mix_Motor_Check ;//搅拌电机
extern ValveCurrent_t Fan_Check ;//风扇

typedef enum{
	BoosterPumpReboot_Init = 0,
	BoosterPumpReboot_Close,
	BoosterPumpReboot_Open,
	BoosterPumpReboot_ReportError,
}BoosterPumpReboot_enum;

typedef struct{
	BoosterPumpReboot_enum status;
	uint8_t RebootCount;
	uint32_t Count;
}BoosterPumpReboot_t;
extern BoosterPumpReboot_t BoosterPumpReboot;

typedef enum{
	MixMotorReboot_Init = 0,
	MixMotorReboot_Close,
	MixMotorReboot_Open,
	MixMotorReboot_ReportError,
}MixMotorReboot_enum;

typedef struct{
	MixMotorReboot_enum status;
	uint8_t RebootCount;
	uint32_t Count;
}MixMotorReboot_t;
extern MixMotorReboot_t MixMotorReboot;



//搅拌电机速度检测
typedef enum{
	Delay3s,
	Collect1sEnable,
	Collect1sStart,
	Stop9sCaculate,
	Stop9s,
}MotorCollect_ENUM;

typedef struct{
	MotorCollect_ENUM MotorCollect;
	uint32_t Cnt3s ;
  uint32_t Cnt1s ;
  uint32_t Cnt9s ;
  uint32_t RotationSpeed ;
  uint8_t RotationSpeedErrFlag ;
}MixSpeed_t;
extern MixSpeed_t MixSpeed;

extern  uint16_t Mix_Motor_Cnt;
extern uint8_t Mix_Motor_Retry;

void wholeMachineErrorDetection(void);
void HostSystemErrorDetection(void);
void AuxiliarySystemErrorDetection(void);
void AuxiliaryAllStatusInit(void);
void AuxiliaryLoadErrorInitFunction(void);
void CloseAllLoadFunction(void);
void CloseAllLoad(void);


void ValveADConversionCurrent(void);
void CurrentDetectionFunction(uint8_t ValveOrPumpState,
                              ValveCurrent_t *Motor_Num_Check,
                              uint16_t OverValue, uint16_t OverTime,
                              uint16_t OpenValue, uint16_t OpenTime,
															uint8_t ERR_BIT_SourceValve);
void CurrentDetectionFunction1(uint8_t ValveOrPumpState,
                              ValveCurrent_t *Motor_Num_Check,
                              uint16_t OverValue, uint16_t OverTime,
                              uint16_t OpenValue, uint16_t OpenTime,
															uint8_t ERR_BIT_SourceValve);
void FaultDetectionTask(void);
void SparklingAddColdWaterProtectionFunction(void);
void CommunicationFaultDetection(void);
void NTCFaultDetectionFunction(void);
void NTCNumericalConstantAnomaly(void);
bool FaultCollectionTask(void);

void AddColdWaterBoxOutTime(void);
void AddCarbonTankOutTime(void);
//void CompressorOutTime(void);

//日志
void Log_SaveError(const char* errorDescribe, uint32_t errorMessage);

void SetFaultBit(uint8_t* faultCode, uint8_t bitPos);

//埋点
void SavePlantSeeding(ValveCurrent_t *Motor_Num_Check,uint16_t MAX_SIZE);

void MixMotorTripleReboot(void);
void MixmotorSpeed(void);
#endif