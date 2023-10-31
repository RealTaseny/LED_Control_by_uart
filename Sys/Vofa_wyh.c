#include "VOFA_WYH.H"

struct Frame FrameData = {0.000001,0x00,0x00,0x80,0x7f};
extern u8 ADC_DATA;

void Uart_Sendtail_wyh(void){
	u8 i;
	for (i = 0;i < 4;i++) Uart_SendByte(FrameData.tail[i]);
}

void print_vofa_wyh(void){
	FrameData.fdata[0] += 2;
	printf("CH1:%f\n",FrameData.fdata[0]);
//	Uart_Sendtail_wyh();
}