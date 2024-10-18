#ifndef _CONFIG_H
#define _CONFIG_H


//净水器

//////// Tool Version ////////
#define PARAMETER_TOOL_VERSION    "WP2345_Main_HC32F460_1.1.0.3"       
#define DEFAULT_WIFI_TYPE   "v4a2gb"//饮万2.0低配  //"rtjwyz"    饮万1.0


//////// Tool Config ////////
#define DEFAULT_TOOL_CONFIG   Parameter_ToolConfig_Supplier         // 量产程序
//#define DEFAULT_TOOL_CONFIG   Parameter_ToolConfig_NoProtect      // 去保护
//#define DEFAULT_TOOL_CONFIG   Parameter_ToolConfig_LifeTest       // 去保护，功率最大


//////// Max Mode Type ////////
#define DEFAULT_MAX_MODE_TYPE   Parameter_MaxModeType_Max

#define VERSION_IN_SN   ('y')   // 配网字符串中的一个字符，寻找热点

#define Print_Debug
//////// 故障保护  
#define EN_ALL_PROTECT

#define BLUE_PAIR_EN

//IAP用
#define PROJ_NAME "WP2345"
#define MACHINE_NAME "Main"
#define MCU_NAME "HC32F460"
/*******************************************************************************
@Function:   Watch dog  
*******************************************************************************/
#define IWDG_EN



#ifdef EN_ALL_PROTECT


#endif




#define DATA_WATCH   (0)


#define TDS_SET 100




 


#endif
