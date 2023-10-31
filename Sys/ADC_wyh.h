#ifndef __ADC_WYH_H__
#define __ADC_WYH_H__

#include "headfile_wyh.h"

#define VCC 5
#define BIT_WIDTH 256

void ADC_Init_wyh(void);
float Get_Voltage(void);

#endif