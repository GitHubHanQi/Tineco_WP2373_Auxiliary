#ifndef _USER_MAIN_H
#define _USER_MAIN_H

#include "includes.h"

// sem 1ms
extern rt_sem_t sem_UserTick_1ms;


// MessageQueue MMI
#define MQ_MMI_SIZE         (16)    // 消息队列数据长度。传递2个字符，1个指针 + 数据内容
#define MQ_MMI_AMOUNT       (8)     // 消息队列条数
extern rt_mq_t mq_MMI_Send;


// Event Wifi
#define EVENT_BIT_WIFI_TX   (BIT0)
#define EVENT_BIT_WIFI_RX   (BIT1)
extern rt_event_t event_Wifi;


// mutex Linkage
extern rt_mutex_t mutex_Linkage;
extern uint8_t  levelcount;




void UserMain(void);


#endif
