#ifndef _PARAMETER_H
#define _PARAMETER_H

#include "includes.h"


//////// 产品配置
typedef enum
{
    Parameter_ToolConfig_Unknow     = 0xFF,     // 量产用，不指定 Tool Config
    Parameter_ToolConfig_SmartHigh  = 0x10,     // 智能高配，有屏幕
    Parameter_ToolConfig_SmartLow   = 0x11,     // 智能低配，无屏幕
    //Parameter_ToolConfig_NonSmart   = 0x12,     // 非智能
} Parameter_Tool_Config_t;

//////// 测试模式
typedef enum
{
    Parameter_TestMode_None         = 0xFF,     // 正常工作
    Parameter_TestMode_LifeTest     = 0x10,     // 寿命测试
    Parameter_TestMode_SupplierTest = 0x11,     // 供应商测试
} Parameter_Test_Mode_t;


//////// 存储器结构
#define PARAMETER_MARK_SAVED        (0x55)      // 已存储的标志
#define PARAMETER_TOOL_SN_SIZE      (24-1)
#define PARAMETER_TOOL_TYPE_SIZE    (8-1)

// 该结构体的数据需要保存在Flash中
// 24+8+2+2 = 36
typedef struct
{
    // 24   SN号
    char ToolSn_String[PARAMETER_TOOL_SN_SIZE];     // 
    uint8_t ToolSn_Mark;

    // 8    wifi种类，国内、国际
    char WifiType_String[PARAMETER_TOOL_TYPE_SIZE]; // 
    uint8_t WifiType_Mark;

    // 2    高中低配置
    Parameter_Tool_Config_t ToolConfig_Byte;        // 
    uint8_t ToolConfig_Mark;

    // 2    正常模式，寿命测试，供应商测试
    Parameter_Test_Mode_t TestMode_Byte;
    uint8_t TestMode_Mark;
} Parameter_Flash_t;
extern Parameter_Flash_t Parameter_Flash;



//////// 数据错误信息
//#define PARAMETER_ERROR_TOOL_CONFIG     (BIT0)
//#define PARAMETER_ERROR_TOOL_SN         (BIT2)
//#define PARAMETER_ERROR_WIFI_TYPE       (BIT2)
typedef struct
{
    uint8_t Error;
    struct 
    {
        uint8_t ToolConfig_Error    :1;
        uint8_t ToolSn_Error        :1;
        uint8_t WifiType_Error      :1;
    };
} Parameter_t;
extern Parameter_t Parameter;



//////// 版本号 ////////
extern const char Parameter_Tool_Version[];



// //////// 函数
void Parameter_Read_Flash(void);
void Parameter_Write_Flash(void);

void Parameter_Read(void);
void Parameter_Is_Error(void);

// void Parameter_Test(void);


// #include "Parameter_ToolSn.h"


extern volatile uint8_t ToolSn[];
extern const uint8_t ToolVersion[];
extern uint8_t VoiceVersion[];

extern volatile uint8_t PanelVersion[10];



#endif

