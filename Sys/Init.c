#include "INIT.H"
/*
 *函数名：关闭板载外设
 *参数：无
 *返回值：无
 *功能：关闭板载外设
 */
void cls_bsp_Periphral(void)
{
	P2 &= 0x1F; // 清空P2高三位
	P2 |= 0xA0; // 选通Y5C
	P0 = 0x00;	// 关闭外设
	Delay(1);
	P2 &= 0x1F; // 清空P2高三位
	P2 |= 0x80; // 选通Y4C
	P0 = 0xFF;	// 关闭LED
	Delay(1);
	P2 &= 0x1F;
}

/*
 *函数名：LED初始化函数
 *参数：无
 *返回值：无
 *功能：初始化LED，选通Y4C
 */
void bsp_Led_Init(void)
{
	P2 &= 0x1F; // 清空P2高三位
	Delay(1);
	P2 |= 0x80; // 选通Y4C
}

/*
 *函数名：数码管初始化函数
 *参数：无
 *返回值：无
 *功能：初始化数码管，选通Y7C
 */
void bsp_Cls_Nixie(void)
{
	P2 &= 0x1F;
	P2 |= 0xE0;
	Delay(1);
	P0 = 0xFF;
	P2 &= 0x1F;
}
