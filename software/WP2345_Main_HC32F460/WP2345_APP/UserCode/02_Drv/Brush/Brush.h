#ifndef _BRUSH_H
#define _BRUSH_H

#include "includes.h"



// ADC值转 充电器电流mA
//#define ADC_2_BRUSH_CURRENT(x)    (uint32_t)((uint64_t)(x) *3300 *1000/100  /4095)      // 采样电阻0.1Ω = 100mΩ
//#define ADC_2_BRUSH_CURRENT(x)    (uint32_t)((uint32_t)(x) *33   *1000/1    /4095)
#define ADC_2_BRUSH_CURRENT(x)      (uint32_t)((uint32_t)(x) *11   *200       /273)       // 4095*11*200 = 9009000 = 0x897768

//#define ADC_2_BRUSH_CURRENT(x)      (uint32_t)((float_t)(x) *0.1   *3.3      /4095)

// #define ADC_2_BRUSH_CURRENT(x)   (uint32_t)((uint32_t)(x) *11   *201       /273)
// #define ADC_2_BRUSH_CURRENT(x)   (uint16_t)((uint32_t)(x) *11   *67        /91)        // 4095*11*67 = 3018015 = 0x2E0D1F



typedef enum
{
    BrushState_Stop,
    BrushState_Run,
    BrushState_Error,
} Brush_State_t;

typedef enum
{
    BrushError_None,
    BrushError_ShortCurrent,
    BrushError_OverCurrent0,
    BrushError_OverCurrent1,
	BrushError_Uninstalled,
} Brush_Error_t;

typedef struct 
{
    uint32_t Tick;
	uint16_t ErrorTick;
	uint16_t UnInstallTick;
	
    Brush_State_t State;
    Brush_Error_t Error;
	uint16_t SoftTick;
    //
    uint16_t Duty_Target;    // 目标值
    uint16_t Duty_Value;     // 当前实际值
    ////////
    uint16_t Current;
    uint16_t Current_average;
	uint16_t Current_value;
	uint8_t  CurrentFlag;
	
    uint16_t ShortCurrent_Cnt;
    uint16_t OverCurrent0_Cnt;
    uint16_t OverCurrent1_Cnt;
    uint16_t Uninstalled_Cnt;
	
	uint16_t Abrade_Fit[10];
	uint16_t Abrade_Sum[30];
	uint8_t fitnum;
	uint8_t Abrade_Sum_Cnt;
	uint32_t Abrade_Average;
	uint8_t Flag_GetAverage;
	uint8_t Flag_Abrade_Error;
	uint16_t Abrade_Display_Time;
	uint8_t Flag_Abrade_Time;


    //////// Close  0正常工作，1关闭
    uint8_t Function_Disable;
    uint8_t Protect_Close;
	
} Brush_t;
extern Brush_t Brush;




//extern bool_t Flag_Brush_Abrade_Error;
//extern uint16_t Brush_Abrade_Display_Time;
//extern uint32_t Brush_Abrade_Average;

//void Brush_Clear(void);

void Brush_Start(void);
void Brush_Stop(void);
void Brush_Error(void);

void Brush_Task(void);


#include "Brush_Soft.h"
#include "Brush_Stable.h"
#include "Brush_Check.h"



#endif

