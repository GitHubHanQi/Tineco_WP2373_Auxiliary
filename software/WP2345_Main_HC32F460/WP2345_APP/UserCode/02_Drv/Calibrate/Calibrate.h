#ifndef _CALIBRATE_H
#define _CALIBRATE_H

#include "includes.h"


typedef enum
{
    CalibrateType_None,     // 正常工作
    CalibrateType_Brush,    // 校准地刷
    CalibrateType_Pump,     // 校准水泵
} Calibrate_Type_t;


typedef struct 
{
    Calibrate_Type_t Type;
    uint16_t Duty;
} Calibrate_t;
extern Calibrate_t Calibrate;


void Calibrate_Set(Calibrate_Type_t Type, uint16_t Value);



#endif
