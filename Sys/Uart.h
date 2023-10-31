#ifndef __UART_H__
#ifndef __UART_H__

#include "HEADFILE_WYH.H"

#define FRAME_LENGTH 6

void Uart_Init(void);
void Uart_SendByte(u8 Date);
void correct_error_command(void);
void UART_SET_LED(u8 x,u8 y);

#endif