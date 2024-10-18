#ifndef _PHONE_ERROR_H
#define _PHONE_ERROR_H


#define PHONE_ERROR_BLDC_MOTOR              (BIT0)  // 1_吸尘电机故障
#define PHONE_ERROR_DUCT_BLOCK_HALF         (BIT1)  // 2_风道半堵
#define PHONE_ERROR_DUCT_BLOCK_ALL          (BIT2)  // 4_风道全堵
#define PHONE_ERROR_BRUSH                   (BIT3)  // 8_地刷过流
#define PHONE_ERROR_DUST                    (BIT4)  // 16_灰尘传感器故障
#define PHONE_ERROR_PANEL					(BIT5)  // 32_触控屏没有通信，没有触控屏
#define PHONE_ERROR_BMS_TEMPERATURE			(BIT6)  // 64_充电时过温
#define PHONE_ERROR_BMS_COMM				(BIT7)  // 128_电池没有通信
#define PHONE_ERROR_BMS_CHARGE_OVER_TIME    (BIT8)  // 256_充电超时
#define PHONE_ERROR_BMS_CURRENT             (BIT9)  // 512_充电时过流
#define PHONE_ERROR_DIRTYTANK				(BIT10) // 1024_污水桶满
#define PHONE_ERROR_PURETANK				(BIT11) // 2048_清水桶缺水
#define PHONE_ERROR_BRUSH_NOMOTOR			(BIT12) // 4096_地刷未安装
#define PHONE_ERROR_BRUSH_ABRADE			(BIT13) // 8192_地刷磨损
#define PHONE_ERROR_UN_DUMP					(BIT14) // 16384_污水桶未安装
#define PHONE_ERROR_PUMP					(BIT15) // 32768_水泵短路堵塞过流

void ToolError_Set(uint16_t flag);
void ToolError_Reset(uint16_t flag);
void ToolError_ResetBms(void);


void Phone_Error_Task(void);



#endif
