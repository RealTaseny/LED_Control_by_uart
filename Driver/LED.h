#ifndef __LED_H__
#define __LED_H__

#include "HEADFILE_WYH.H"

#define LED_TIME 50 // LED延时时间
#define LED P0

void led_mode_switch();
void led_brightness_switch();

#endif