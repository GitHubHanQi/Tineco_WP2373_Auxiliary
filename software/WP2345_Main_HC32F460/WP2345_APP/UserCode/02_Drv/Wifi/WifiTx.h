#ifndef _WIFI_TX_H
#define _WIFI_TX_H

#include "includes.h"


//////// 发送wifi的数据
#define MMI_FRAME_TX_BUF_SIZE   (512)

typedef struct 
{
    uint16_t ReqRespID;     // 每次发送累加
    uint8_t Frame_Buf[MMI_FRAME_TX_BUF_SIZE];
    uint16_t Frame_Len;
    uint16_t Water_Mark;
    //

    #ifdef WIFI_SEQUENCE
        uint16_t Seq;
    #endif
} WifiTx_t;
extern WifiTx_t WifiTx;



//////// 跨线程发送的消息列队的数据，总长度8
typedef struct 
{
    char PorR;          // 'PR'
    char Type;          // 'qpm'
    const char *pName;
    //
    uint32_t u32Data0;
} Wifi_Message_Queue_t;


void WifiTx_mq(char PorR, char Type, const char *pName);
void WifiTx_mq_LogAdd(uint32_t Error);

void WifiTx_Test(void);




#endif
