/**
 * @file VOFA+Json.h
 * @author WuRendi (minos.wu@tineco.com)
 * @brief 解析VOFA传来的Json数据
 * @date 2022-03-25
 *
 * @copyright Copyright (c) 2022 Tineco
 *
 **/
#ifndef _VOFA_Json_H
#define _VOFA_Json_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "cJSON.h"
#define RX_BUF_MAX_SIZE (64)
#define TX_BUF_MAX_SIZE (64)
/**
 * @brief VOFA执行事件
 *
 * @author WuRendi (minos.wu@tineco.com)
 * @date 2022-03-25
 **/
typedef struct
{
  char *key;                          /**< 键值*/
  int32_t (*Callback)(int32_t input); /**< 执行函数*/
} VOFA_CMD_Node;


/**
 * @brief VOFA+解析缓存
 *
 * @author WuRendi (minos.wu@tineco.com)
 * @date 2022-03-25
 **/
typedef struct
{
  char currentChar;                     /**< 当前字符*/
  char lastChar;                        /**< 上一个字符*/
  uint16_t buffIndex;                   /**< 读取索引*/
  uint8_t receiveBuff[RX_BUF_MAX_SIZE]; /**< 读取缓存*/
  uint16_t timeOutCount;                /**< 超时计数*/
} VOFA_Rx_t;

/**
 * @brief VOFA+发送缓存
 *
 * @author WuRendi (minos.wu@tineco.com)
 * @date 2022-03-25
 **/
typedef struct
{
  uint16_t buffIndex;                    /**< 缓存索引*/
  uint16_t buffLen;                      /**< 缓存长度*/
  uint8_t transmitBuff[TX_BUF_MAX_SIZE]; /**< 发送缓存*/
  void (*PrintString)(const char *pStr); /**< 发送*/
} VOFA_Tx_t;

/**
 * @brief VOFA+解析
 *
 * @author WuRendi (minos.wu@tineco.com)
 * @date 2022-03-25
 **/
typedef struct VOFA_Protocol
{
  uint8_t Enable;               /**< 功能开启*/
  VOFA_CMD_Node *VOFA_CMD_List; /**< 指令表*/
  uint16_t VOFA_CMD_List_Size;  /**< 指令表大小*/
  VOFA_Rx_t Receive;            /**< 接收*/
  VOFA_Tx_t Transmit;           /**< 发送*/
  struct VOFA_Protocol *next; /**< 链表*/
} VOFA_Protocol_t;

int8_t VOFA_Register(VOFA_Protocol_t *target);
void VOFA_Task(void);
void VOFA_Enable(VOFA_Protocol_t *target, uint8_t enable);
void VOFA_ReceiveHandler(VOFA_Protocol_t *target, uint8_t input);
void VOFA_Analyze(VOFA_Protocol_t *target);
#endif
