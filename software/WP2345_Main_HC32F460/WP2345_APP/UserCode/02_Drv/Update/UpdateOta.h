#ifndef _UPDATE_OTA_H
#define _UPDATE_OTA_H

#include "includes.h"


#define OTA_FRAME_SIZE           (256)


#define OTA_ERROR_Unknow            (0x00)
#define OTA_ERROR_NotCharge         (0x01)  // 不在充电状态
#define OTA_ERROR_WrongCmd          (0x02)  // 收到错误的指令，不在OTA状态就收到后面的语句
#define OTA_ERROR_FlashError        (0x03)  // 存储器读写错误
#define OTA_ERROR_Offset0x200       (0x04)  // 偏移地址比上一个地址小0x200，可能是第二个手机干扰
#define OTA_ERROR_OtaReIn           (0x05)  // 已经处于OTA状态，不可以再次进入
#define OTA_ERROR_NoPageZero        (0x06)  // 缺少Page 0数据

#define OTA_ERROR_BinProjectName    (0x07)  // bin文件项目错误(bin文件前6个字节表示项目名字)
#define OTA_ERROR_BinChecksum       (0x08)  // 写入Back区域完成后校验checksum错误
#define OTA_ERROR_BinSize           (0x09)  // bin文件自带的size错误 (超范围)
									// 0x09：bin文件自带的size错误 (超范围)
									// 0x0A：bin文件自带的checksum错误 (低字节不是0x00)
									// 0x0B：Payload字符错误（不是’0’~’F’的十六进制字符）
#define OTA_ERROR_Memory            (0x0C)  // 存储器擦除失败
#define OTA_ERROR_Check            (0x0D)  // 0x0D：写入Front区的数据checksum错误
#define OTA_ERROR_BatteryCease		(0x0E)  // 电池包处于休眠状态，不可以开始更新


#define OTA_ERROR_NotXDigit     (0x0B)  // Payload 不是十六进制字符



typedef struct
{
    ////////
    uint8_t SendAddr;
    uint8_t ReceiveAddr;
    uint8_t Cmd0;
    uint8_t Cmd1;
    uint16_t FrameLength;
    uint8_t Data[512 + 64];
    uint8_t Checksum;
    //
	
    uint16_t FlashLength;
    uint32_t Offset;    // 偏移地址
    uint16_t OtaPage;   // 256B
} UpdataOta_Rx_t;
extern UpdataOta_Rx_t UpdataOta_RxFrame;

typedef struct
{
    uint8_t SendAddr;
    uint8_t ReceiveAddr;
    uint8_t Cmd0;
    uint8_t Cmd1;
    uint16_t Length;
    uint8_t Data[32];
    uint8_t Checksum;
} UpdataOta_Tx_t;
extern UpdataOta_Tx_t UpdataOta_Tx;



typedef enum
{
    OtaState_Normal,        // 正常工作
    //OtaState_GotoOta,       // 发送给Sound进入ota的指令
    OtaState_WriteData,     // 等待手机数据，转发给Sound
    //OtaState_ReadData,      // 等待Sound返回数据
    //OtaState_WaitCopy,      // 等待复制完成，大约需要10s
} Ota_State_t;


typedef struct 
{
    uint32_t OverTimeTick;
    Ota_State_t State;
    uint16_t Seq;
    uint8_t ret;        // 0有错误，1正确

    //
    char Project_String[16];    // 项目名，字符串
    char Position_String[16];   // 部位，字符串
    uint32_t Length;    // 0x20
    uint32_t Checksum;  // 0x24
	
	uint32_t Checksum_Calc;
    //
    uint32_t MemoryWriteBlocks; // 32KB
    uint32_t MemoryErasePages;  // 存储器擦除用到的页数。MCU：512B一页，语音：4KB一页   // MCU 不需要，只有语音需要
    uint32_t MemoryWritePages;  // 存储器写入用到的页数。MCU：512B一页，语音：256B一页
    uint32_t OtaPages;          // 手机发送的页数。256B一页

    //
    uint32_t OtaPage;   // 当前的页数
} UpdateOta_t;
extern UpdateOta_t UpdateOta;




void UpdataOta_Start(void);
void UpdataOta_Stop(void);


void UpdataOta_Task(void);
void UpdataOta_PayloadAnalyize(char *pPayload);




#include "UpdateOtaMcu.h"
//#include "UpdateOtaVoice.h"
//#include "UpdateOtaVoice_Rx.h"


#endif
