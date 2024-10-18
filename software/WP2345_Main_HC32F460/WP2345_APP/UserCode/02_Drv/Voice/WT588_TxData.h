#ifndef _WT588_TX_DATA_H
#define _WT588_TX_DATA_H

#include "includes.h"


#define Voice_Sound1 				0xFFE7
#define Voice_Sound2 				0xFFE9
#define Voice_Sound3 				0xFFEB
#define Voice_Sound4 				0xFFED
#define Voice_Sound5 				0xFFEF
#define Voice_DisEnFlash 			0xFFFD // 释放
#define Voice_EnFlash 				0xFFFC // 重新获取
#define Voice_Stop 					0xFFFE
#define WT588_CMD_Volume0           ((uint16_t)0xFFE0)    // 0~15，默认15
#define WT588_CMD_ReleaseFlash      ((uint16_t)0xFFFD)
#define WT588_CMD_TakeFlash         ((uint16_t)0xFFFC)

// NUM  
#define  VoiceNUM00                 (0x00) 
#define  VoiceNUM01                 (0x01) 
#define  VoiceNUM02                 (0x02)     
#define  VoiceNUM03                 (0x03) 
#define  VoiceNUM04                 (0x04)     
#define  VoiceNUM05                 (0x05) 
#define  VoiceNUM06                 (0x06)     
#define  VoiceNUM07                 (0x07) 
#define  VoiceNUM08                 (0x08)  
#define  VoiceNUM09                 (0x09)     
#define  VoiceNUM0A                 (0x0A) 
#define  VoiceNUM0B                 (0x0B) 
#define  VoiceNUM0C                 (0x0C) 
#define  VoiceNUM0D                 (0x0D) 
#define  VoiceNUM0E                 (0x0E) 
#define  VoiceNUM0F                 (0x0F) 

#define  VoiceNUM10                 (0x10) 
#define  VoiceNUM11                 (0x11) 
#define  VoiceNUM12                 (0x12) 
#define  VoiceNUM13                 (0x13) 
#define  VoiceNUM14                 (0x14) 
#define  VoiceNUM15                 (0x15) 
#define  VoiceNUM16                 (0x16) 
#define  VoiceNUM17                 (0x17) 
#define  VoiceNUM18                 (0x18) 
#define  VoiceNUM19                 (0x19) 
#define  VoiceNUM1A                 (0x1A) 
#define  VoiceNUM1B                 (0x1B) 
#define  VoiceNUM1C                 (0x1C) 
#define  VoiceNUM1D                 (0x1D) 
#define  VoiceNUM1E                 (0x1E) 
#define  VoiceNUM1F                 (0x1F) 

#define  VoiceNUM20                 (0x20) 
#define  VoiceNUM21                 (0x21) 
#define  VoiceNUM22                 (0x22) 
#define  VoiceNUM23                 (0x23) 
#define  VoiceNUM24                 (0x24) 
#define  VoiceNUM25                 (0x25) 
#define  VoiceNUM26                 (0x26) 
#define  VoiceNUM27                 (0x27) 
#define  VoiceNUM28                 (0x28) 
#define  VoiceNUM29                 (0x29) 
#define  VoiceNUM2A                 (0x2A) 
#define  VoiceNUM2B                 (0x2B) 
#define  VoiceNUM2C                 (0x2C) 
#define  VoiceNUM2D                 (0x2D) 
#define  VoiceNUM2E                 (0x2E) 
#define  VoiceNUM2F                 (0x2F) 

#define  VoiceNUM30                 (0x30) 
#define  VoiceNUM31                 (0x31) 
#define  VoiceNUM32                 (0x32) 
#define  VoiceNUM33                 (0x33) 
#define  VoiceNUM34                 (0x34) 
#define  VoiceNUM35                 (0x35) 
#define  VoiceNUM36                 (0x36) 
#define  VoiceNUM37                 (0x37) 
#define  VoiceNUM38                 (0x38) 
#define  VoiceNUM39                 (0x39) 
#define  VoiceNUM3A                 (0x3A) 
#define  VoiceNUM3B                 (0x3B) 
#define  VoiceNUM3C                 (0x3C) 
#define  VoiceNUM3D                 (0x3D) 
#define  VoiceNUM3E                 (0x3E) 
#define  VoiceNUM3F                 (0x3F) 

#define  VoiceNUM40                 (0x40) 
#define  VoiceNUM41                 (0x41) 
#define  VoiceNUM42                 (0x42) 
#define  VoiceNUM43                 (0x43) 
#define  VoiceNUM44                 (0x44) 
#define  VoiceNUM45                 (0x45) 
#define  VoiceNUM46                 (0x46) 
#define  VoiceNUM47                 (0x47) 
#define  VoiceNUM48                 (0x48) 
#define  VoiceNUM49                 (0x49) 
#define  VoiceNUM4A                 (0x4A) 
#define  VoiceNUM4B                 (0x4B) 
#define  VoiceNUM4C                 (0x4C) 
#define  VoiceNUM4D                 (0x4D) 
#define  VoiceNUM4E                 (0x4E) 
#define  VoiceNUM4F                 (0x4F) 

#ifdef LCD_INTERNATIONAL
#define ACOUNTB  	(0) 
#define INTER_MaxVoiceNum    (80)
#else
#define ACOUNTB  	(0)
#endif

#define Voice_Idle					(VoiceNUM00 + ACOUNTB)   //静音
#define Voice_WiFiPleaseCon			(VoiceNUM01 + ACOUNTB)   //请配网
#define Voice_WiFiConning			(VoiceNUM02 + ACOUNTB)   //联网中
#define Voice_WiFiConnectted		(VoiceNUM03 + ACOUNTB)   //连接成功
// 语音提示	
#define Voice_On					(VoiceNUM04 + ACOUNTB)   //开启语音
#define Voice_Off					(VoiceNUM05 + ACOUNTB)   //关闭语音

#define Voice_ReStarted		    	(VoiceNUM06 + ACOUNTB)   //已恢复出厂设置

// 模式切换	
#define Voice_SmartMode				(VoiceNUM07 + ACOUNTB)   //智能模式
#define Voice_SuctionMode			(VoiceNUM08 + ACOUNTB)   //吸水模式
#define Voice_SensorSolid			(VoiceNUM09 + ACOUNTB)   //溶液模式
#define Voice_MaxMode				(VoiceNUM0A + ACOUNTB)   //强力模式	
#define Voice_ClearWaterMode		(VoiceNUM0B + ACOUNTB)   //清水模式	


#define Voice_LowVoltage10			(VoiceNUM0C + ACOUNTB)   //电池电量不足  10
#define Voice_LowVoltage20			(VoiceNUM0D + ACOUNTB)   //电量低，请充电 20
#define Voice_CleanTankError		(VoiceNUM0E + ACOUNTB)   //清水桶缺水或溶液，请加水或溶液
#define Voice_InfraRedError  		(VoiceNUM0F + ACOUNTB)   //请检查传感器，保证使用效果(红外脏污传感器)
#define Voice_DustSensorError  		(VoiceNUM10 + ACOUNTB)   //请进行自清洁，保证使用效果(全红状态)
#define Voice_PutOnCharge			(VoiceNUM11 + ACOUNTB)   //请放回底座自清洁
#define Voice_BrushDirty			(VoiceNUM12 + ACOUNTB)   //滚刷清洁效果不佳，建议更换
#define Voice_DirtyTankError		(VoiceNUM13 + ACOUNTB)   //污水桶已满，请清理污水桶 
#define Voice_NoBucket				(VoiceNUM14 + ACOUNTB)   //请安装污水桶
#define Voice_BrushError			(VoiceNUM15 + ACOUNTB)   //清理滚刷
#define Voice_NoBrush				(VoiceNUM16 + ACOUNTB)   //安装滚刷,完成后请重启
#define Voice_MotorError			(VoiceNUM17 + ACOUNTB)   //联系客服

// 关机	
#define Voice_DisChargeClosing		(VoiceNUM18 + ACOUNTB)   //关机中
#define Voice_DisChargeOver			(VoiceNUM19 + ACOUNTB)   //已关机，请放回底座
// 充电
#define Voice_StartCharge			(VoiceNUM1A + ACOUNTB)	 //开始充电
#define Voice_StartCharge1			(VoiceNUM1B + ACOUNTB)	 //清洁度检测中
#define Voice_StartCharge2			(VoiceNUM1C + ACOUNTB)	 //请清理污水桶，避免异味
#define Voice_StartCharge3			(VoiceNUM1D + ACOUNTB)	 //请开启自清洁	
#define Voice_SelfCharge			(VoiceNUM1E + ACOUNTB)   //电量不足，正在充电

#define Voice_SelfCleanning			(VoiceNUM1F + ACOUNTB)   //开始自清洁

#define Voice_SelfClean1			(VoiceNUM20 + ACOUNTB)   //滚刷清洗
#define Voice_SelfClean2			(VoiceNUM21 + ACOUNTB)   //管道清洗
#define Voice_SelfClean3			(VoiceNUM22 + ACOUNTB)   //智能检测
#define Voice_SelfClean4			(VoiceNUM23 + ACOUNTB)   //深度清洁	

#define Voice_SelfCleanCom			(VoiceNUM24 + ACOUNTB)   //自清洁完成
#define Voice_SelfCleanClo			(VoiceNUM25 + ACOUNTB)   //自清洁关闭

#define Voice_SelfCleanDirty		(VoiceNUM26 + ACOUNTB)   //杂物过多 
#define Voice_SelfCleanChannel		(VoiceNUM27 + ACOUNTB)   //请清理污水桶及其下方管道，避免异味
#define Voice_SleepRestart		    (VoiceNUM28 + ACOUNTB)   //休眠中，请重新放置底座

#define Voice_OTAPrograming			(VoiceNUM29 + ACOUNTB)   //固件升级中
#define Voice_OTAProgramed		    (VoiceNUM2A + ACOUNTB)   //固件升级成功，请使用
#define Voice_OTAChanging		    (VoiceNUM2B + ACOUNTB)   //语音替换中
#define Voice_OTAChanged		    (VoiceNUM2C + ACOUNTB)   //语音替换成功
#define Voice_OTALeave			    (VoiceNUM2D + ACOUNTB)   //请勿离开底座

#define Voice_TipsError				(VoiceNUM2E + ACOUNTB)   //故障音效
#define Voice_TipsTineco			(VoiceNUM2F + ACOUNTB)   //5.提示音
#define Voice_TipsMode				(VoiceNUM30 + ACOUNTB)   //3.模式切换音
#define Voice_TipsSuccessed			(VoiceNUM31 + ACOUNTB)   //8.成功提示音
#define Voice_TipsLowPower			(VoiceNUM32 + ACOUNTB)   //4.电量低提示音

#define Voice_CleanseMode			(VoiceNUM33 + ACOUNTB)   //除菌模式	

#define Voice_SelfCleanseError		(VoiceNUM34 + ACOUNTB)   //取消制备，开始清洗
#define Voice_ChargeError			(VoiceNUM35 + ACOUNTB)	 //充电异常

// 消毒
#define Voice_CleanSetWarning		(VoiceNUM36 + ACOUNTB)   //请确保有水
#define Voice_CleanseStart			(VoiceNUM37 + ACOUNTB)   //除菌液制备中,请稍后
#define Voice_Cleanse50				(VoiceNUM38 + ACOUNTB)   //除菌液制备50%
#define Voice_CleanseStop			(VoiceNUM39 + ACOUNTB)   //除菌液已全部制备完成，开始清洁

// 开机说明	
#define Voice_Start0				(VoiceNUM3A + ACOUNTB)   //新手教程
#define Voice_Start1				(VoiceNUM3B + ACOUNTB)   //清水桶
#define Voice_Start2				(VoiceNUM3C + ACOUNTB)   //污水桶
#define Voice_Start3				(VoiceNUM3D + ACOUNTB)   //滚刷
#define Voice_Start4				(VoiceNUM3E + ACOUNTB)   //滚刷上盖
#define Voice_Start5				(VoiceNUM3F + ACOUNTB)   //开关键
#define Voice_Start6				(VoiceNUM40 + ACOUNTB)   //操作键 5s
#define Voice_Start7				(VoiceNUM41 + ACOUNTB)   //自清洁按键
#define Voice_Start8				(VoiceNUM42 + ACOUNTB)   //设置键
#define Voice_Start9				(VoiceNUM43 + ACOUNTB)   //长按WI

// 预留
// 0x44 --- 0x4F H

#define VOICE_CMD_MAX               (159)
#define WT588_TX_SIZE   (16)



void WT588_WriteData(uint16_t Data);
void WT588_Tx_Clear(void);
void WT588_Tx_AddOneData(uint16_t Data);
void WT588_Tx_InsertOneData(uint16_t Pos, uint16_t Data);
void WT588_Tx_RemoveOneData(uint16_t Pos);
void WT588_Tx_ReplaceOneData(uint16_t Pos, uint16_t Data);
void WT588_Tx_SetOnlyOneData(uint16_t Data);

void WT588_TxData_Task(void);




#endif

