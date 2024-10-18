#ifndef _USER_DEBUG_H
#define _USER_DEBUG_H



//#include "Debug_List_Thread.h"
#include "Interval.h"


// extern uint32_t Debug_See0;
// extern uint32_t Debug_See1;


// SEGGER_RTT_printf(0, "Hello SEGGER!\n");
// rt_kprintf("Hello World!\n");
// User_Printf("Version: %s\n", PARAMETER_TOOL_VERSION);


// SEGGER_RTT_printf(0, fmt, ##args);
// rt_kprintf(fmt, ##args);
#define User_Printf(fmt, args...)       \
{                                       \
    rt_kprintf(fmt, ##args);            \
}



void Debug_Test(void);


#endif
