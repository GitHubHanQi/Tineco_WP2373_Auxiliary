#ifndef _PANEL_LCD_H
#define _PANEL_LCD_H
#include "includes.h"
#include "PanelLcd_Tx.h"
#include "PanelLcd_Test.h"


/*  工厂测试模式  */
//#define FACTOR_TEST   1

//////// 给屏幕的数据，总长度51	+4
#define PanelDataLen  						55
extern volatile uint8_t PanelTxBuf[PanelDataLen];
////////////////////////////////////////////////// 帧头
#define FRAME_START_OFFSET					(0)		// 0xF2   开始标志 
#define FRAME_FUNC_OFFSET					(1)		// 0xBB   功能码	
#define FRAME_LEN_OFFSET					(2)		// 0x32   数据长度	
////////////////////////////////////////////////// 数据
#define Panel_SELECT_OFFSET					(3)		// data1  界面选择  
#define MODE_SELECT_OFFSET					(4)		// data2  模式选择	
#define SOC_PERCENT_OFFSET					(5)		// data3  电量百分比	
#define SELFCLEAN_PROGRESS_OFFSET			(6)		// data4  自清洁进度	
#define CWT_PERCENT_OFFSET					(7)		// data5  清水百分比	
#define DWT_PERCENT_OFFSET					(8)		// data6  污水百分比	
#define CUR_WATER_HIGH_OFFSET				(9)		// data7  耗水 高位		
#define CUR_WATER_LOW_OFFSET				(10)	// data8  耗水 低位		
#define CUR_DISCHARGE_TIME_OFFSET			(11)	// data9  运行时长
#define LCD_BRIGHTNESS_OFFSET				(12)	// data10 屏幕亮度
#define Panel_RED_LED0_OFFSET				(13)	// data11 红色LED位置
#define Panel_BLUE_LED0_OFFSET				(14)	// data12 蓝色LED位置
#define Panel_RED_LEDx_OFFSET(x)			(x * 2 + Panel_RED_LED0_OFFSET)		//0~15 [13:43:2] [起始：终长：步长]
#define Panel_BLUE_LEDx_OFFSET(x)			(x * 2 + Panel_BLUE_LED0_OFFSET)		//0~15 [14:44:2]
#define Panel_LED_MODE_OFFSET				(49)	// data43 灯环工作模式

// 
#define Panel_Tineco_OFFSET					(50)	// data44 tineco 图标
#define Panel_WORK_MODE_OFFSET				(51)	// data45 屏幕工作模式 
#define Panel_WIFI_VOICE_OFFSET				(52)	// data46 WIFI(bit0) 声音(bit1)

////////////////////////////////////////////////// 帧尾
#define FRAME_CHECKSUM_OFFSET				(53)    // 校验和 取最低位
#define FRAME_END_OFFSET					(54)	// 0x7E   结束位

////////////////////////////////////////////////// 测试模式
#define PanelTestWhite						(0x01)    // 白
#define PanelTestBlack						(0x02)    // 黑
#define PanelTestRed						(0x03)    // 红
#define PanelTestGreen						(0x04)    // 绿
#define PanelTestBlue						(0x05)    // 蓝
#define PanelTestPic						(0x06)    // 图片



/* 静态图||动画 data1 -- Panel_SELECT_OFFSET(3) */  
typedef enum
{
	PanelStandBy						= 0x00,		//待机
	PanelPairAni						= 0x01,		//配网动画  (时长： 待补充)
	PanelPairing						= 0x02,		//配网中
	PanelPairBreak						= 0x04,		//配网中断
	PanelPairSuccess					= 0x03,		//配网成功
//开机	
	PanelStartPic						= 0x06,     //开机图片
	PanelStartLogo						= 0x07,     //开机logo视频
	PanelStartAni						= 0x08,     //开机提示视频

	PanelDischargeNormal				= 0x10,		//正常放电运行界面
	PanelGotoModeSelect					= 0x11,		//运行界面转至模式选择界面的转场动画(时长： 待补充)
//故障
	PanelFaultDumpSew					= 0x20,		//倾倒污水
	PanelFaultCwtEmpty					= 0x21,		//请加清水
	PanelFaultSelfClean					= 0x22,		//请自清洁
	PanelFaultChgBrush					= 0x23,		//更换滚刷
	PanelFaultInsBrush					= 0x24,		//安装滚刷
	PanelFaultCleanBrush				= 0x25,		//清理滚刷
	PanelFaultPowerLow					= 0x26,		//电量过低
	PanelFaultSensor					= 0x27,		//传感器异常
	PanelFaultUnDump					= 0x28,		//请安装污水桶
	PanelFaultUnMotor					= 0x29,		//请尝试重启 电机故障
	PanelFaultUnCharge					= 0x2a,		//充电异常
	
//提示
	PanelHelpDumpSew					= 0x30,		//(12s)(时长： 待补充)
	PanelHelpCwtEmpty					= 0x31,		//(8s)(时长： 待补充)
	PanelHelpSelfClean					= 0x32,		//(12s)(时长： 待补充)
	PanelHelpChgBrush					= 0x33,		//(12s)(时长： 待补充)
	PanelHelpInsBrush					= 0x34,		//(3s)(时长： 待补充)
	PanelHelpCleanBrush					= 0x35,		//(3s)(时长： 待补充)
	PanelHelpPowerLow					= 0x36,		//(3s)(时长： 待补充)
	PanelHelpSensor						= 0x37,		//(3s)(时长： 待补充)
	PanelHelpUnDump						= 0x38,		//请安装污水桶
	PanelHelpUnMotor					= 0x39,		//请尝试重启 电机故障
	PanelHelpUnCharge					= 0x3a,		//充电异常
	
//自清洁 
	PanelSelfClean						= 0x40,		//自清洁 主页面
	
	PanelSelfCleanDumpSew				= 0x41,		//自清洁 倾倒污水
	PanelSelfCleanCwtEmpty 				= 0x42,		//自清洁 请加清水
	PanelSelfCleanInsBrush				= 0x43,		//自清洁 安装滚刷
	
	PanelSelfCleanBrushClean			= 0x44,		//自清洁 清理滚刷
	PanelSelfCleanSensor				= 0x45,		//自清洁 传感器异常
	PanelSelfCleanUnDump				= 0x46,		//自清洁 请安装污水桶
	PanelSelfCleanUnMotor				= 0x47,		//自清洁 电机故障
	PanelSelfCleanUnCharge				= 0x48,		//自清洁 充电故障
	
	PanelSelfCleanClose					= 0x4F,		//关闭自清洁
	
//自清洁 异常	
	PanelSelfCleanHelpDumpSew			= 0x51,		//自清洁倾倒污水
	PanelSelfCleanHelpCwtEmpty			= 0x52,		//自清洁请加清水
	PanelSelfCleanHelpInsBrush			= 0x53,		//自清洁安装滚刷
	
	PanelSelfCleanHelpBrushClean		= 0x54,		//自清洁 清理滚刷
	PanelSelfCleanHelpSensor			= 0x55,		//自清洁 传感器异常	
	PanelSelfCleanHelpUnDump			= 0x56,		//自清洁 请安装污水桶
	PanelSelfCleanHelpUnMotor			= 0x57,		//自清洁 电机故障
	PanelSelfCleanHelpUnCharge			= 0x58,		//自清洁 充电故障
	
//消毒
	PanelCleanse						= 0x50,		//消毒
	PanelCleanseUp						= 0x12,		//消毒正向
	
	PanelPowerOff						= 0x60,		//关机
	PanelCharging						= 0x61,		//充电
	PanelChargOTA						= 0x62,		//升级
//暂停水量显示
	PanelSuspend   						= 0x70, 	//直立静止
} Panel_View_t;


typedef enum
{
	PanelSmartMode						= 0x00,		//智能模式 无消毒
	PanelSmartModeCleanse				= 0x01,		//消毒模式
	PanelSuctionMode					= 0x02,		//吸水模式  // MAX
	PanelMicroWaterMode					= 0x03,		//溶液模式  // 清水
	PanelMaxMode						= 0x04,		//MAX模式  国内
	
} Panel_Mode_t;

typedef enum
{
	PanelState_Start					= 0x00,		//开机动画
    PanelState_Standby					= 0x01,		//熄屏待机
	PanelState_WifiPair					= 0x02,		//配网阶段
    PanelState_DischargeRun				= 0x03,		//正常运行阶段 
    PanelState_DischargeModeSelect		= 0x04,		//模式切换
	PanelState_DischargeFaultRemind		= 0x05,		//故障提醒
	PanelState_DischargeFaultHelp		= 0x06,		//故障引导动画
	PanelState_DischargeSuspend			= 0x07,		//直立暂停
	PanelState_DischargeStop			= 0x08,		//关机
	PanelState_Charge					= 0x09,		//充电
	PanelState_SelfClean				= 0x0A,		//自清洁
	PanelState_SelfCleanFaultRemind		= 0x0B,		//自清洁故障提醒
	PanelState_SelfCleanFaultHelp		= 0x0C,		//自清洁故障引导动画 
	PanelState_Cleanse					= 0x0D,		//消毒 
	PanelState_CleanseHelp				= 0x0E,		//消毒引导动画
	PanelState_OTAMCU					= 0x0F,		//升级MCU
} Panel_State_t;
// Tineco  图标
typedef enum
{
    PanelTineco_Close,   	// 熄灭
	PanelTineco_Open,		// 常亮
	PanelTineco_Blink,		// 闪烁
	PanelTineco_Breath,		// 呼吸	
} PanelTineco_State_t;


extern  PanelTineco_State_t TinecoState;
// 实现灯环所需变量
#define  LCD_BLUE2RED_GRADIENT_ONCE    0
#define  LCD_RED2BLUE_GRADIENT_ONCE    1
#define  LCD_BLUE2RED_GRADIENT_CYCLE   2
#define  LCD_RED2BLUE_GRADIENT_CYCLE   3
#define  LCD_CLOSE2BLUE_GRADIENT_ONCE  4

#define  LCD_RED_MAX  				   460
#define  LCD_BLUE_MIN  				   20 
#define  LCD_GRADIENT_STEP    		   20

#define PANEL_LCD_DUTY_MAX                  (100)	// 每个LED的最大占空比
#define PANEL_DUST_DUTY_STEP   				(20)

#define PANEL_NOF_COLOR_LED			    (18)	// 彩色LED个数

#define PANEL_DUST_DUTY_MAX   	((uint16_t)PANEL_DUST_DUTY_STEP * PANEL_NOF_COLOR_LED + PANEL_LCD_DUTY_MAX)    // 20*18+100 = 460

extern Panel_State_t PanelState;
extern Panel_View_t PanelView;
extern Panel_Mode_t PanelMode;

extern Panel_View_t PanelViewBack;

//	用于计时，200ms加一 
extern uint32_t PanelTaskTicks;			

extern uint8_t SocPercent;  
extern uint8_t SelfCleanPercent;
extern uint8_t LedMode;

extern volatile uint8_t PanelCharge1005;
// 用于故障环
extern uint8_t g_blue_control;
//
extern uint8_t PanelWarningState;
extern uint32_t PanelSelfTicks;

void AppGuiTask(void);

extern void PanelLcd_AllControl(uint8_t BlueDuty, uint8_t RedDuty);
// 待机熄屏
extern void PanelGoto_Standby(void);
// 配网阶段
extern void PanelGoto_WifiPair(void);
// 正常运行
extern void PanelGoto_DischargeRun(void); 
// 模式切换
extern void PanelGoto_DischargeModeSelect(void);
// 自清洁
extern void PanelGoto_SelfClean(void);
// 自清洁故障
extern void PanelGoto_SelfCleanFaultRemind(void);
// 自清洁引导动画
extern void PanelGoto_SelfCleanFaultHelp(void);
// 故障提醒
extern void PanelGoto_DischargeFaultRemind(void);
// 故障引导动画
extern void PanelGoto_DischargeFaultHelp(void);
// 关机
extern void PanelGoto_DischargeStop(void);
// 充电
extern void PanelGoto_Charge(void);
// 升级
extern void PanelGoto_OTAMCU(void);
// 消毒
extern void PanelGoto_Cleanse(void);
// 消毒引导动画
extern void PanelGoto_CleanseHelp(void);

// Factor Test 
extern void AppGuiTaskDemo(void);
#endif

