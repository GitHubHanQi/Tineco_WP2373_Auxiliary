#ifndef _PARAMETER_H
#define _PARAMETER_H

#include "includes.h"


#define pParameterFlash    ((const Parameter_Flash_t *)FLASH_PARAMETER_ADDR_START)    // 指向Flash区域的指针


typedef enum
{
    Requester_Tester,   // 测试机请求
    Requester_App,      // App请求
} Requester_t;

//////// 产品配置
typedef enum
{
    Parameter_ToolConfig_SmartHigh      = 0x10,     // 智能高配
    Parameter_ToolConfig_SmartLow       = 0x11,     // 智能低配
    Parameter_ToolConfig_NonSmart       = 0x12,     // 非智能/功能机
    //
    Parameter_ToolConfig_Supplier       = 0x20,     // 供应商测试
    Parameter_ToolConfig_NoProtect      = 0x21,     // 去保护。不完整的机器也正常运行
    Parameter_ToolConfig_LifeTest       = 0x22,     // 去保护，最大功率。寿命测试
    //
    Parameter_ToolConfig_Unknow         = 0xFF
} Parameter_ToolConfig_t;

typedef enum
{
    Parameter_MaxModeType_Max       = 0x10,     // 强力模式(国际用)
    Parameter_MaxModeType_Suction   = 0x11,     // 吸水模式(国内用)
    Parameter_MaxModeType_Unknow    = 0xFF
} Parameter_MaxModeType_t;




//////// 存储器结构
#define PARAMETER_MARK_SAVED        (0x55)      // 已存储的标志
#define PARAMETER_TOOL_SN_SIZE      (24-1)
#define PARAMETER_WIFI_TYPE_SIZE    (8-1)

// 该结构体的数据需要保存在Flash中
// 24+8+2+2 = 36
typedef struct
{
    // 24   SN号
    char ToolSn_String[PARAMETER_TOOL_SN_SIZE];
    uint8_t ToolSn_Mark;

    // 8    wifi种类，国内、国际
    char WifiType_String[PARAMETER_WIFI_TYPE_SIZE];
    uint8_t WifiType_Mark;

    // 2    高中低配置
    Parameter_ToolConfig_t ToolConfig_Byte;
    uint8_t ToolConfig_Mark;

    // 2    强力模式类型
    Parameter_MaxModeType_t MaxModeType_Byte;
    uint8_t MaxModeType_Mark;
} Parameter_Flash_t;



typedef struct
{
    //////// Flash中提取的常用参数。App使用，Tester不能用
    Parameter_ToolConfig_t ToolConfig_Byte_App;
    Parameter_MaxModeType_t MaxModeType_Byte_App;

    //////// Error
    // 单独的故障
    struct 
    {
        uint8_t ToolSn_Error        :1;
        uint8_t WifiType_Error      :1;
        uint8_t ToolConfig_Error    :1;
        uint8_t MaxModeType_Error   :1;
    };
    // 综合的故障
    uint8_t Error;
} Parameter_t;
extern Parameter_t Parameter;

extern volatile uint8_t PanelVersion[10];
//////// 版本号 ////////
extern const char Parameter_Tool_Version[];

//////// 函数
void Parameter_Read(void);


#include "Parameter_ToolSn.h"
#include "Parameter_WifiType.h"



#endif

