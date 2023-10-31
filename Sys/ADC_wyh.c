#include "ADC_WYH.h"

u8 ADC_DATA = 0x0000;

void ADC_Init_wyh(void){
	EA = 1;								//允许CPU接收中断
	EADC = 1;							//开启ADC转换中断
	P1ASF |= 0x01;				//选择P1.0口作为A/D端口
	ADC_CONTR = 0x88;			//开启ADC、清空ADC标志位、选择P1.0口作为模拟量输入
	CLK_DIV |= 0X20;			//ADC_RES存高两位、ADC_RESL存低八位
}

void ADC_Proc_wyh(void) interrupt 5
{
	ADC_DATA = ADC_RESL;
	ADC_CONTR = 0x88;
}

float Get_Voltage(void){
	float Voltage;
	Voltage = (ADC_DATA / BIT_WIDTH) * VCC;
	return Voltage;
}