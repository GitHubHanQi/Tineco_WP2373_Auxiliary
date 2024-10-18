/*
 * @Description: 
 * @Author: hanqi.zhang
 * @Date: 2024-01-31 14:14:24
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-02-01 09:33:09
 */

#ifndef _AUXILIARYREPORT_H
#define _AUXILIARYREPORT_H

#include "includes.h"

void ReportColdWaterBoxRequestAddWater(void);
void ReportColdWaterBoxTemperature(void);
void ReportHostAuxiliaryStatus(void);
void ReportColdWaterBoxAddCoolWaterStatus(void);
void ReportAuxiliaryErrorCodeToHost(void);
void AnalyAddCoolWaterOrOutCoolWater(void);
void ReportAuxiliaryFlushingReply(void);

#endif