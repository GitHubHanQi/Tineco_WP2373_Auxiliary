#ifndef _PANEL_LCD_H
#define _PANEL_LCD_H
#include "includes.h"
#include "PanelLcd_Tx.h"
#include "PanelLcd_Test.h"


/*  ��������ģʽ  */
//#define FACTOR_TEST   1

//////// ����Ļ�����ݣ��ܳ���51	+4
#define PanelDataLen  						55
extern volatile uint8_t PanelTxBuf[PanelDataLen];
////////////////////////////////////////////////// ֡ͷ
#define FRAME_START_OFFSET					(0)		// 0xF2   ��ʼ��־ 
#define FRAME_FUNC_OFFSET					(1)		// 0xBB   ������	
#define FRAME_LEN_OFFSET					(2)		// 0x32   ���ݳ���	
////////////////////////////////////////////////// ����
#define Panel_SELECT_OFFSET					(3)		// data1  ����ѡ��  
#define MODE_SELECT_OFFSET					(4)		// data2  ģʽѡ��	
#define SOC_PERCENT_OFFSET					(5)		// data3  �����ٷֱ�	
#define SELFCLEAN_PROGRESS_OFFSET			(6)		// data4  ��������	
#define CWT_PERCENT_OFFSET					(7)		// data5  ��ˮ�ٷֱ�	
#define DWT_PERCENT_OFFSET					(8)		// data6  ��ˮ�ٷֱ�	
#define CUR_WATER_HIGH_OFFSET				(9)		// data7  ��ˮ ��λ		
#define CUR_WATER_LOW_OFFSET				(10)	// data8  ��ˮ ��λ		
#define CUR_DISCHARGE_TIME_OFFSET			(11)	// data9  ����ʱ��
#define LCD_BRIGHTNESS_OFFSET				(12)	// data10 ��Ļ����
#define Panel_RED_LED0_OFFSET				(13)	// data11 ��ɫLEDλ��
#define Panel_BLUE_LED0_OFFSET				(14)	// data12 ��ɫLEDλ��
#define Panel_RED_LEDx_OFFSET(x)			(x * 2 + Panel_RED_LED0_OFFSET)		//0~15 [13:43:2] [��ʼ���ճ�������]
#define Panel_BLUE_LEDx_OFFSET(x)			(x * 2 + Panel_BLUE_LED0_OFFSET)		//0~15 [14:44:2]
#define Panel_LED_MODE_OFFSET				(49)	// data43 �ƻ�����ģʽ

// 
#define Panel_Tineco_OFFSET					(50)	// data44 tineco ͼ��
#define Panel_WORK_MODE_OFFSET				(51)	// data45 ��Ļ����ģʽ 
#define Panel_WIFI_VOICE_OFFSET				(52)	// data46 WIFI(bit0) ����(bit1)

////////////////////////////////////////////////// ֡β
#define FRAME_CHECKSUM_OFFSET				(53)    // У��� ȡ���λ
#define FRAME_END_OFFSET					(54)	// 0x7E   ����λ

////////////////////////////////////////////////// ����ģʽ
#define PanelTestWhite						(0x01)    // ��
#define PanelTestBlack						(0x02)    // ��
#define PanelTestRed						(0x03)    // ��
#define PanelTestGreen						(0x04)    // ��
#define PanelTestBlue						(0x05)    // ��
#define PanelTestPic						(0x06)    // ͼƬ



/* ��̬ͼ||���� data1 -- Panel_SELECT_OFFSET(3) */  
typedef enum
{
	PanelStandBy						= 0x00,		//����
	PanelPairAni						= 0x01,		//��������  (ʱ���� ������)
	PanelPairing						= 0x02,		//������
	PanelPairBreak						= 0x04,		//�����ж�
	PanelPairSuccess					= 0x03,		//�����ɹ�
//����	
	PanelStartPic						= 0x06,     //����ͼƬ
	PanelStartLogo						= 0x07,     //����logo��Ƶ
	PanelStartAni						= 0x08,     //������ʾ��Ƶ

	PanelDischargeNormal				= 0x10,		//�����ŵ����н���
	PanelGotoModeSelect					= 0x11,		//���н���ת��ģʽѡ������ת������(ʱ���� ������)
//����
	PanelFaultDumpSew					= 0x20,		//�㵹��ˮ
	PanelFaultCwtEmpty					= 0x21,		//�����ˮ
	PanelFaultSelfClean					= 0x22,		//�������
	PanelFaultChgBrush					= 0x23,		//������ˢ
	PanelFaultInsBrush					= 0x24,		//��װ��ˢ
	PanelFaultCleanBrush				= 0x25,		//�����ˢ
	PanelFaultPowerLow					= 0x26,		//��������
	PanelFaultSensor					= 0x27,		//�������쳣
	PanelFaultUnDump					= 0x28,		//�밲װ��ˮͰ
	PanelFaultUnMotor					= 0x29,		//�볢������ �������
	PanelFaultUnCharge					= 0x2a,		//����쳣
	
//��ʾ
	PanelHelpDumpSew					= 0x30,		//(12s)(ʱ���� ������)
	PanelHelpCwtEmpty					= 0x31,		//(8s)(ʱ���� ������)
	PanelHelpSelfClean					= 0x32,		//(12s)(ʱ���� ������)
	PanelHelpChgBrush					= 0x33,		//(12s)(ʱ���� ������)
	PanelHelpInsBrush					= 0x34,		//(3s)(ʱ���� ������)
	PanelHelpCleanBrush					= 0x35,		//(3s)(ʱ���� ������)
	PanelHelpPowerLow					= 0x36,		//(3s)(ʱ���� ������)
	PanelHelpSensor						= 0x37,		//(3s)(ʱ���� ������)
	PanelHelpUnDump						= 0x38,		//�밲װ��ˮͰ
	PanelHelpUnMotor					= 0x39,		//�볢������ �������
	PanelHelpUnCharge					= 0x3a,		//����쳣
	
//����� 
	PanelSelfClean						= 0x40,		//����� ��ҳ��
	
	PanelSelfCleanDumpSew				= 0x41,		//����� �㵹��ˮ
	PanelSelfCleanCwtEmpty 				= 0x42,		//����� �����ˮ
	PanelSelfCleanInsBrush				= 0x43,		//����� ��װ��ˢ
	
	PanelSelfCleanBrushClean			= 0x44,		//����� �����ˢ
	PanelSelfCleanSensor				= 0x45,		//����� �������쳣
	PanelSelfCleanUnDump				= 0x46,		//����� �밲װ��ˮͰ
	PanelSelfCleanUnMotor				= 0x47,		//����� �������
	PanelSelfCleanUnCharge				= 0x48,		//����� ������
	
	PanelSelfCleanClose					= 0x4F,		//�ر������
	
//����� �쳣	
	PanelSelfCleanHelpDumpSew			= 0x51,		//������㵹��ˮ
	PanelSelfCleanHelpCwtEmpty			= 0x52,		//����������ˮ
	PanelSelfCleanHelpInsBrush			= 0x53,		//����లװ��ˢ
	
	PanelSelfCleanHelpBrushClean		= 0x54,		//����� �����ˢ
	PanelSelfCleanHelpSensor			= 0x55,		//����� �������쳣	
	PanelSelfCleanHelpUnDump			= 0x56,		//����� �밲װ��ˮͰ
	PanelSelfCleanHelpUnMotor			= 0x57,		//����� �������
	PanelSelfCleanHelpUnCharge			= 0x58,		//����� ������
	
//����
	PanelCleanse						= 0x50,		//����
	PanelCleanseUp						= 0x12,		//��������
	
	PanelPowerOff						= 0x60,		//�ػ�
	PanelCharging						= 0x61,		//���
	PanelChargOTA						= 0x62,		//����
//��ͣˮ����ʾ
	PanelSuspend   						= 0x70, 	//ֱ����ֹ
} Panel_View_t;


typedef enum
{
	PanelSmartMode						= 0x00,		//����ģʽ ������
	PanelSmartModeCleanse				= 0x01,		//����ģʽ
	PanelSuctionMode					= 0x02,		//��ˮģʽ  // MAX
	PanelMicroWaterMode					= 0x03,		//��Һģʽ  // ��ˮ
	PanelMaxMode						= 0x04,		//MAXģʽ  ����
	
} Panel_Mode_t;

typedef enum
{
	PanelState_Start					= 0x00,		//��������
    PanelState_Standby					= 0x01,		//Ϩ������
	PanelState_WifiPair					= 0x02,		//�����׶�
    PanelState_DischargeRun				= 0x03,		//�������н׶� 
    PanelState_DischargeModeSelect		= 0x04,		//ģʽ�л�
	PanelState_DischargeFaultRemind		= 0x05,		//��������
	PanelState_DischargeFaultHelp		= 0x06,		//������������
	PanelState_DischargeSuspend			= 0x07,		//ֱ����ͣ
	PanelState_DischargeStop			= 0x08,		//�ػ�
	PanelState_Charge					= 0x09,		//���
	PanelState_SelfClean				= 0x0A,		//�����
	PanelState_SelfCleanFaultRemind		= 0x0B,		//������������
	PanelState_SelfCleanFaultHelp		= 0x0C,		//���������������� 
	PanelState_Cleanse					= 0x0D,		//���� 
	PanelState_CleanseHelp				= 0x0E,		//������������
	PanelState_OTAMCU					= 0x0F,		//����MCU
} Panel_State_t;
// Tineco  ͼ��
typedef enum
{
    PanelTineco_Close,   	// Ϩ��
	PanelTineco_Open,		// ����
	PanelTineco_Blink,		// ��˸
	PanelTineco_Breath,		// ����	
} PanelTineco_State_t;


extern  PanelTineco_State_t TinecoState;
// ʵ�ֵƻ��������
#define  LCD_BLUE2RED_GRADIENT_ONCE    0
#define  LCD_RED2BLUE_GRADIENT_ONCE    1
#define  LCD_BLUE2RED_GRADIENT_CYCLE   2
#define  LCD_RED2BLUE_GRADIENT_CYCLE   3
#define  LCD_CLOSE2BLUE_GRADIENT_ONCE  4

#define  LCD_RED_MAX  				   460
#define  LCD_BLUE_MIN  				   20 
#define  LCD_GRADIENT_STEP    		   20

#define PANEL_LCD_DUTY_MAX                  (100)	// ÿ��LED�����ռ�ձ�
#define PANEL_DUST_DUTY_STEP   				(20)

#define PANEL_NOF_COLOR_LED			    (18)	// ��ɫLED����

#define PANEL_DUST_DUTY_MAX   	((uint16_t)PANEL_DUST_DUTY_STEP * PANEL_NOF_COLOR_LED + PANEL_LCD_DUTY_MAX)    // 20*18+100 = 460

extern Panel_State_t PanelState;
extern Panel_View_t PanelView;
extern Panel_Mode_t PanelMode;

extern Panel_View_t PanelViewBack;

//	���ڼ�ʱ��200ms��һ 
extern uint32_t PanelTaskTicks;			

extern uint8_t SocPercent;  
extern uint8_t SelfCleanPercent;
extern uint8_t LedMode;

extern volatile uint8_t PanelCharge1005;
// ���ڹ��ϻ�
extern uint8_t g_blue_control;
//
extern uint8_t PanelWarningState;
extern uint32_t PanelSelfTicks;

void AppGuiTask(void);

extern void PanelLcd_AllControl(uint8_t BlueDuty, uint8_t RedDuty);
// ����Ϩ��
extern void PanelGoto_Standby(void);
// �����׶�
extern void PanelGoto_WifiPair(void);
// ��������
extern void PanelGoto_DischargeRun(void); 
// ģʽ�л�
extern void PanelGoto_DischargeModeSelect(void);
// �����
extern void PanelGoto_SelfClean(void);
// ��������
extern void PanelGoto_SelfCleanFaultRemind(void);
// �������������
extern void PanelGoto_SelfCleanFaultHelp(void);
// ��������
extern void PanelGoto_DischargeFaultRemind(void);
// ������������
extern void PanelGoto_DischargeFaultHelp(void);
// �ػ�
extern void PanelGoto_DischargeStop(void);
// ���
extern void PanelGoto_Charge(void);
// ����
extern void PanelGoto_OTAMCU(void);
// ����
extern void PanelGoto_Cleanse(void);
// ������������
extern void PanelGoto_CleanseHelp(void);

// Factor Test 
extern void AppGuiTaskDemo(void);
#endif

