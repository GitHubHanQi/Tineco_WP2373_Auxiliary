#ifndef _WIFI_RX_H
#define _WIFI_RX_H

#include "includes.h"


#define WIFI_FRAME_BYTE_HEAD     ('`')   // 0x60
#define WIFI_FRAME_BYTE_END      ('\n')  // 0x0A
#define WIFI_FRAME_BYTE_SPLIT    ('\\')  // 0x5C


typedef enum
{
    WifiRxMmiDiscodedPayloadState_Head,
    WifiRxMmiDiscodedPayloadState_Normal,
    WifiRxMmiDiscodedPayloadState_Splited,
} WifiRx_MMI_DiscodedPayload_State_t;



//#define MMI_FRAME_RX_BUF_SIZE     (256 + 128)
//#define MMI_FRAME_RX_BUF_SIZE     (1024 + 512)
#define MMI_FRAME_RX_BUF_SIZE     (1024 + 1024)
typedef struct 
{
    //// 接收帧缓存
    char Buf[MMI_FRAME_RX_BUF_SIZE];            // [payload]，进入解析函数后，仍然留在内存中
    uint16_t Index_In;                          // 接收的时候临时使用，接收完成后会自动清零
    uint16_t Index_Out;
    uint16_t Len;                               // 进入解析函数后，仍然留在内存中，直到下次接收完成
    WifiRx_MMI_DiscodedPayload_State_t State;

    //// 帧的成员
    char PorR;              // 'P')<FP>, 'R')<FR>
    char *pName;
    char *pRemoteClientID;  // 48
    char Type;              // 'q')请求，'p')响应，'m')消息
    char *pReqRespID;
    char PayloadType;       // 'j') 'x') 'b')
    char *pPayload;


    volatile bool_t MMI_Analyizing;

    ////
    uint16_t Tick;          // 检测接收超时用
    uint16_t Water_Mark;

    //
    uint32_t Test_Cnt[5];
    //uint32_t Test_Cnt1[4];
} WifiRx_t;
extern WifiRx_t WifiRx;




void WifiRx_MMI_DiscodedPayload_Clear(void);
void WifiRx_MMI_DiscodedPayload_Len_Add(void);
void WifiRx_ByteAnalyze(char UartRx_Data);
void WifiRx_Task(void);



#endif

