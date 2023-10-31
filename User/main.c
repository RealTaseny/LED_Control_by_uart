#include "HEADFILE_WYH.H"

KS key = {1, 1, 20};	   // 初始化结构体成员(按键S5默认计次从1次开始，按键S6默认计次从1开始，亮度初始为20)
bit S5_press_flag = 0;	   // S5按键标志位
bit S6_press_flag = 0;	   // S6按键标志位
extern SData Strings_Data; // 字符串结构体
extern bit receive_flag;   // 软件接受标志位

/*
 *函数名：主函数
 *参数：无
 *返回值：无
 *功能：用两个按键分别控制流水灯运行模式以及LED灯亮度
 */
void main(void)
{
	cls_bsp_Periphral(); 	// 关闭板载外设
	bsp_Cls_Nixie();	 		// 关闭数码管
	
  ADC_Init_wyh();
	Uart_Init();
	while (1)
	{
		print_vofa_wyh();
	}
}