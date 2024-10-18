#ifndef _INCLUDES_H
#define _INCLUDES_H

/* system */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
/* renew */
#include "UserStdint.h"
#include "hc32_ddl.h"
//#include "driver.h"

/* config */
#include "Config.h"

/* third part */
#include "SEGGER_RTT.h"
#include "_Func_Lib.h"
#include "Crc8.h"
#include "cJSON.h"

/* bsp */
#include "Bsp.h"

/* drv */
#include "Drv.h"

/* app */
#include "App.h"




///* thread */
#include <rtthread.h>
#include <rthw.h>

#include "UserMain.h"
#include "Thread_Wifi.h"

#include "user_VOFA.h"


#endif
