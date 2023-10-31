#include "DELAY.H"

/*
 *函数名：软件延时函数(0 - 65535毫秒)
 *参数：需要延时的毫秒数
 *返回值：无
 *功能：进行软件延时(需要占用CPU资源)
 */
void Delay(u16 xms) //@11.0592MHz
{
	while (xms)
	{
		unsigned char data i, j;
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j)
				;
		} while (--i);

		xms--;
	}
}