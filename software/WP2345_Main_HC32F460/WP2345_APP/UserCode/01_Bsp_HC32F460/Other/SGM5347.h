#ifndef _SGM5347_H
#define _SGM5347_H

#include "includes.h"


//#define DAC_CLK_HIGH()		PORT_SetBits(COVER_RELAY_PORT, COVER_RELAY_PIN)  
//#define DAC_CLK_LOW()		PORT_ResetBits(COVER_RELAY_PORT, COVER_RELAY_PIN) 

//#define DAC_DATA_HIGH()		PORT_SetBits(ANDROID_PORT, ANDROID_PIN)  
//#define DAC_DATA_LOW()		PORT_ResetBits(ANDROID_PORT, ANDROID_PIN)

//#define DAC_LD_HIGH()		PORT_SetBits(BT_RST_PORT, BT_RST_PIN)
//#define DAC_LD_LOW()		PORT_ResetBits(BT_RST_PORT, BT_RST_PIN)


//#define    DAC_SGM
#define    DAC_3PEAK


#ifdef DAC_SGM
// DAC通道   SGM
#define CHANNEL1     (0x00)                // 通道1
#define CHANNEL2     (0x01)                // 通道2
#define CHANNEL3     (0x02)                // 通道3
#define CHANNEL4     (0x03)                // 通道4
#define CHANNEL5     (0x04)                // 通道5
#define CHANNEL6     (0x05)                // 通道6
#define CHANNEL7     (0x06)                // 通道7
#define CHANNEL8     (0x07)                // 通道8

// 操作模式
#define DAC_WRM      (0x08)                // 写寄存器模式
#define DAC_WTM      (0x09)                // 直写模式

#endif

#ifdef DAC_3PEAK
// DAC通道  3PEAK
#define CHANNEL1     (0x00)                // 通道A
#define CHANNEL2     (0x02)                // 通道B
#define CHANNEL3     (0x04)                // 通道C
#define CHANNEL4     (0x06)                // 通道D
#define CHANNEL5     (0x08)                // 通道E
#define CHANNEL6     (0x0A)                // 通道F
#define CHANNEL7     (0x0C)                // 通道G
#define CHANNEL8     (0x0E)                // 通道H

#endif



//#define DAC_POWERDOWN     (0x01)           // 掉电


void SGM5347_Task(void);
void SGM5347_Set(uint32_t channel,uint32_t DacData);
#endif

