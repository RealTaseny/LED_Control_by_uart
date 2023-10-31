#ifndef __KEY__H_
#define __KEY__H_

#include "HEADFILE_WYH.H"

#define down_flag 0
#define up_flag 1
sbit S5 = P3 ^ 2;
sbit S6 = P3 ^ 3;

typedef struct KEY_STATE
{
	u8 S5_press_times; // 按压计次S5（控制工作模式）
	u8 S6_press_times; // 按压计次S6（控制工作模式）
	u8 Led_brightness; // LED亮度
} KS;

void Key_Init(void);

#endif