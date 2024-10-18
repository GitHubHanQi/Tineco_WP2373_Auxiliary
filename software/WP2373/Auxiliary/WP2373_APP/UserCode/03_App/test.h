/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2024-01-27 13:55:05
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-01-27 15:55:27
 */

#ifndef _TEST_H
#define _TEST_H

#include "includes.h"

#define COLDBOXADDWATER_TIME 5000
#define SPARKLINGBOXADDWATER_TIME 3000
#define OUTCOLDWATER_TIME 5000
#define OUTSPARKLINGWATER_TIME 5000
#define OUTCOOLWATER_TIME 5000
#define COMPRESSORRUN_TIME 60000

typedef enum
	{
		TestState_Init = 0,
    TestState_ColdBoxAddWater,
    TestState_SparklingWaterAddColdWater,
    TestState_OutColdWater,
    TestState_OutSparklingWater,
    TestState_OutCoolWater,
	  TestState_Compressor,
		TestState_WaterRoad,
	} 
TestState_Enum;
	

typedef struct {
  TestState_Enum CurrentState;
  uint8_t Flag;
  uint32_t Count;

} Test_t;
extern Test_t Test;

//产测
typedef enum{
	ProductionTestState_Init = 0,
	ProductionTestState_HostTest,
  ProductionTestState_DrainBack,//排冲回模式
  ProductionTestState_Oppressive,//高压模式
  ProductionTestState_Undervoltage,//低压模式
  ProductionTestState_OutWater,//排水模式
  ProductionTestState_EraseLog,//擦除日志模式
	ProductionTestState_HotGutsBoiler,//热胆煲机模式
	ProductionTestState_End,
} ProductionTestState_Enum;


typedef enum{
	ProductionTestOutWater_Init = 0,
	ProductionTestOutWater_OutColdWater,
  ProductionTestOutWater_OutSparklingWater,
  ProductionTestOutWater_End,

} ProductionTestOutWaterState_Enum;

typedef struct {
	ProductionTestState_Enum State;
	uint8_t Flag;
	uint8_t HostTestFlag;
	uint8_t DrainBackFlag;
	uint8_t OppressiveFlag;
	uint8_t UndervoltageFlag;
	uint8_t OutWaterFlag;
	uint8_t HostEraseLogFlag;
	uint8_t HotGutsBoilerFlag;
	uint8_t EraseLogOnlyOneFlag;
	ProductionTestOutWaterState_Enum OutWaterState;
} ProductionTest_t;
extern ProductionTest_t ProductionTest;


//P1测试
void TestFunction(void);
//电气测试
void ElectronicsTestFunction(void);
//产测
void ProductTestFunction(void);
void GotoProductTestMode(void);

#endif
