#ifndef __HEADFILE_WYH_H__
#define __HEADFILE_WYH_H__

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long int u32;

typedef struct STRINGS_DATA
{
	u8 Length;
	char String[20];
}SData;

#include <STC15F2K60S2.H>
#include <STDIO.H>
#include <intrins.h>
#include "ADC_WYH.H"
#include "VOFA_WYH.H"
#include "Init.h"
#include "UART.H"
#include "DELAY.H"

#endif