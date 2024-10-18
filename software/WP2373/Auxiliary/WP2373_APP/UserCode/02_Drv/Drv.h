#ifndef _DRV_H
#define _DRV_H

#include "includes.h"
#include "AuxiliaryHost_Rx.h"
#include "AuxiliaryHost_Tx.h"
#include "AuxiliaryTap_Rx.h"
#include "AuxiliaryTap_Tx.h"
#include "ColdWaterAndSparklingWater.h"
#include "BoosterPump.h"
#include "Temperature.h"
#include "GetTapInformation.h"
#include "user_easyflash.h"
#include "GetHostInformation.h"

#include "AuxiliaryReport.h"
#include "Wifi.h"
#include "Update.h"
#include "Parameter.h"
#include "CommTester.h"
#include "CommTester_Rx_Byte.h"
#include "CommTester_Rx_Frame.h"
#include "CommTester_Tx.h"
#include "CommTester_Tx_Frame.h"

#include "Upload.h"

void Drv_Init(void);
void Drv_Task(void);







#endif
