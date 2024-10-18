#ifndef _APP_PANEL_TX_H
#define _APP_PANEL_TX_H

#include "includes.h"



#define PANEL_TX_NOF_COLOR_LED			    (18)	// 彩色LED个数
#define PANEL_TX_NOF_DATA                   (49)	// 数据域的个数
#define PANEL_TX_NOF_FRAME                  (PANEL_TX_NOF_DATA + 5) // 请求帧的长度

#define PANEL_LED_DUTY_MAX                  (100)	// 每个LED的最大占空比

//// 与手机互动
#define PANEL_TX_SpeedModeSource_Pos        (0)     // 调速模式数据来源（0=来源于Panel，1=来源于主控板
#define PANEL_TX_SpeedModeRequired_Pos      (1)     // 主控板要求的调速模式（0=自动调速模式，1=手动调速模式
#define PANEL_TX_VacuumPowerSource_Pos      (2)     // 显示条数据来源（0=来源于Panel，1=来源于主控板
#define PANEL_TX_VacuumPowerRequired_Pos    (3)     // 主控板要求的显示条长度（0~100
//// 白色灯
#define PANEL_TX_VacuumEn_Pos  			    (4)		// 滑条显示（0不显示，1显示，2显示条闪烁）
    #define PANEL_TX_VacuumEn_AllOff            (0)     // 全不显示
    #define PANEL_TX_VacuumEn_AllOn             (1)     // 全显示
    #define PANEL_TX_VacuumEn_FlashSlow         (2)     // 慢闪
    #define PANEL_TX_VacuumEn_FlashFast         (3)     // 快闪
    #define PANEL_TX_VacuumEn_SlipOff           (4)     // 滑条不显示
    #define PANEL_TX_VacuumEn_SlipAutoOff       (5)     // 滑条和Auto不显示
#define PANEL_TX_BmsPercent_Pos 		    (5)		// 电量值和故障代码及电量值显示状态（0-199，0xE1—0xE9)(关闭=0xF0)
    #define PANEL_TX_BmsPercent_OFF             (0xF0)
#define PANEL_TX_IconSelfClean_Pos  		        (6)		// 电量图标（0熄灭，1绿色常亮，2绿色闪烁，3红色常量，4红灯闪烁）
    #define PANEL_TX_IconSelfClean_OFF                (0)
    #define PANEL_TX_IconSelfClean_GREEN_ON           (1)
    #define PANEL_TX_IconSelfClean_GREEN_FLASH        (2)
    #define PANEL_TX_IconSelfClean_RED_ON             (3)
    #define PANEL_TX_IconSelfClean_RED_FLASH          (4)
    #define PANEL_TX_IconSelfClean_GreenAndRed        (5)
#define PANEL_TX_IconTineco_Pos	            (7)		// tineco 图标（0熄灭，1常亮，2闪烁，3呼吸）
#define PANEL_TX_IconWifi_Pos  		        (8)		// Wifi图标（0熄灭，1常亮，2慢闪，3快闪）
    #define PANEL_TX_IconWifi_OFF               (0)     // 熄灭
    #define PANEL_TX_IconWifi_ON                (1)     // 常亮
    #define PANEL_TX_IconWifi_FlashSlow         (2)     // 慢闪
    #define PANEL_TX_IconWifi_FlashFast         (3)     // 快闪
#define PANEL_TX_IconBrush_Pos              (9)     // 地刷图标（0熄灭，1常亮，2闪烁）
#define PANEL_TX_IconDuty_Pos               (10)    // 污水图标（0熄灭，1常亮，2闪烁）
	#define PANEL_TX_SMGFlash 			0x10    //数码管慢闪
	#define PANEL_TX_SMGFastFlash 			0x20    //数码管快闪
#define PANEL_TX_IconPure_Pos               (11)    // 清水 灰尘传感器图标（0熄灭，1常亮，2闪烁）
	#define PANEL_TX_DustRedFlash 			0x10    //灰尘传感器图标
	#define PANEL_TX_DustBlueFlash 			0x20    //灰尘传感器图标
//// 彩色灯 // x = 0~17
#define PANEL_TX_Red0_Pos				    (12)	// L1红色
#define PANEL_TX_Blue0_Pos			        (13)	// L1蓝色
#define PANEL_TX_Red_Pos(x)			        (x * 2 + PANEL_TX_Red0_Pos)	    // Lx红色(L17红色=46)   // x=0~17
#define PANEL_TX_Blue_Pos(x)			    (x * 2 + PANEL_TX_Blue0_Pos)	// Lx蓝色(L17蓝色=47)
//// 调试
#define PANEL_TX_Test_Pos				    (48)	// 调试位（0正常工作，1测试LED，2测试触摸条）



extern bool_t Simple_Type;
extern const uint8_t PanelTx_None[];
extern const uint8_t PanelTx_AllOnA[];
extern const uint8_t PanelTx_AllOnB[];


extern volatile uint8_t PanelTx_Buf[];
extern volatile _Bool PanelTx_Flag;

extern volatile _Bool LED_LightRingFlag;
extern volatile uint16_t SensorSetting_100ms;
void Panel_PrintFrame(const uint8_t *PanelTx_Buf);
void PanelTx_Task(void);

typedef enum
{
	PanelSmartMode						= 0x00,		//智能模式 无消毒
	PanelSuctionMode					= 0x01,		//吸水模式
	PanelSmartModeCleanse				= 0x02,		//消毒模式
	PanelMicroWaterMode					= 0x03,		//溶液模式
	PanelClose,
} Panel_Mode_t;
extern Panel_Mode_t PanelMode;

void Panel_SetIcon_Wifi(void);
void Panel_SetDustCycle(uint8_t BlueDuty, uint8_t RedDuty);


void Panel_SetDemonstrator(void);

void Panel_LowLevel_Transmit(uint8_t *pbuf, uint16_t len);

//功率条
extern volatile uint8_t VacuumPowerRequiredValue;
// Demo 
#define TIME_MS_FOR_DEMO    (TimeMs + 1000 + 250)
#define DEMONSTRATOR_TICK_PERIOD      (ELAPSE_10s)
extern volatile int64_t Demonstrator_TimeMs;
extern volatile uint16_t Demonstrator_VacuumPower;
extern volatile uint16_t Demonstrator_DustNum;
void Demonstrator_Start(void);
void Demonstrator_Task(void);



#endif

