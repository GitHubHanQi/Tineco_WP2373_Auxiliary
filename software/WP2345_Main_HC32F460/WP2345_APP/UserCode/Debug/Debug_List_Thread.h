#ifndef _DEBUG_LIST_THREAD
#define _DEBUG_LIST_THREAD

#include "includes.h"




typedef struct
{
    rt_list_t *list;
    rt_list_t **array;
    rt_uint8_t type;
    int nr;             /* input: max nr, can't be 0 */
    int nr_out;         /* out: got nr */
} list_get_next_t;



typedef struct 
{
    char Name[RT_NAME_MAX];
    uint32_t SP;
    uint32_t StackSize;
    uint16_t Water_Mark;
    //uint32_t Percent;
    uint32_t LeftTick;
} RT_Debug_Data_t;


void Debug_List_Thread(void);



#endif

