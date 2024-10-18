#ifndef _APP_VACUUM_PERIOD_H
#define _APP_VACUUM_PERIOD_H

#include "includes.h"


//    1ms   1000Hz  60000rpm
//   10ms    100Hz   6000rpm
//  100ms     10Hz    600rpm
// 1000ms      1Hz     60rpm


// 48340rpm     805.6Hz     1.24ms
#define VACUUM_CONVERT_rpm_us(x)   (60 * 1000000 / (float64_t)(x))


#define VacuumPeriod_Record_SIZE    (12)
extern volatile uint32_t VacuumPeriod_Record[];
extern volatile uint32_t VacuumPeriod_Value;


extern volatile uint32_t VacuumSpeed_Record;
extern volatile uint16_t VacuumPeriod_Tick;

extern volatile bool_t VacuumPeriod_ErrorState;
//extern volatile bool_t DuctBlockHalf_ErrorState;
//extern volatile bool_t DuctBlockAll_ErrorState;        // ���ȫ��
extern volatile bool_t Bldc_ErrorState;


//uint32_t VacuumPeriod_us2rpm(uint32_t us);
void VacuumPeriod_Clear(void);
void VacuumPeriod_Task(void);

void VacuumPeriod_Int_Isr(uint16_t x);
void VacuumPeriod_Overflow_Isr(void);




#endif

