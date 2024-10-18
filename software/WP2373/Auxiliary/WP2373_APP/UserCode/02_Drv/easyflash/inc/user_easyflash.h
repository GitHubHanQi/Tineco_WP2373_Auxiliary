#ifndef _USER_EASYFLASH_H_
#define _USER_EASYFLASH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <easyflash.h>
#include "includes.h"

#define ENV_DEV_SN              "SN"
#define ENV_DEV_SN_FLAG 				"SN_flag"


#define CALIBRATION_MAX_NUMS    (1)

typedef struct
{
    uint8_t type;       //1:firmware; 2:image; 3:menu; 4:voice; 5:font

} update_ctrl_t;

#define DEV_SN_LEN      (20)
#define DEV_NAME_LEN    (15)
typedef struct
{
    uint32_t boot_times;            //启动次数
	  int guide;
    char dev_sn[DEV_SN_LEN + 1];    //设备SN号
    char dev_name[DEV_NAME_LEN + 1];
    uint32_t FirstFlushFlag;
	  uint32_t AllUserTime;
} sys_param_t;

extern sys_param_t sys_para;


void Read_SN(uint8_t *destin);
void Write_SN(uint8_t *SN_Value);
void Env_ReadSn(void);
void Env_WriteSn(const char *sn, uint8_t len);
void Env_ReadFirstFlush(void);
void Env_WriteFirstFlush(void);
void Env_ReadAllUserTime(void);
void Env_WriteAllUserTime(void);

void Wtite_Judge(void);



void user_easyflash_init(void);

#ifdef __cplusplus
}
#endif
#endif
