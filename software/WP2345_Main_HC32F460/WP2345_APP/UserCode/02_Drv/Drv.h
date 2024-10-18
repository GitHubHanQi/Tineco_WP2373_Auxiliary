#ifndef _DRV_H
#define _DRV_H

#include "includes.h"


void Drv_Init(void);
void Drv_Task(void);


// 数据抓取
__ALIGNED(4) extern volatile double Test_Vector[6];

#include "Fault.h"


#include "Key.h"
#include "Motor.h"
#include "Sensor.h"
#include "BTRx.h"
#include "Linecross.h"
#include "Panel.h"
#include "PanelAnalyze.h"
#include "music.h"

#include "Wifi.h"
#include "CommTester.h"
//#include "Phone.h"

//#include "PanelLcd.h"

#include "Log.h"
#include "Parameter.h"
#include "Update.h"
#include "UpdateOta.h"
#include "NFC.h"
#include "IIC.h"
#include "WaterLevel.h"
#include "Pump.h"
#include "NTC.h"
#include "GD25Q80.h"
//#include "Calibrate.h"
#include "TDS.h"
#include "WaterFlow.h"
#include "LED.h"

#include "Ble.h"
#include "Wifi.h"

#endif
