#include "UART.H"

bit busy = 0;		  // 发送忙标志位
bit error_flag = 0;	  // 错误帧标志位
bit receive_flag = 0; // 软件接受标志位
SData Strings_Data;	  // 字符串结构体
extern KS key;		  // 按键状态结构体

/*
 *函数名：UART初始化函数
 *作者：王彦皓
 *函数功能：初始化UART串口1，波特率115200bps
 *入口参数：无
 *返回参数：无
 */
void Uart_Init(void) // 115200bps*****Runing@11.0592MHz*******
{
	EA = 1;					 // 允许CPU总中断
	ES = 1;					 // 开启串口中断
	SCON = 0x50;			 // 8位数据,可变波特率
	AUXR |= 0x01;			 // 串口1选择定时器2为波特率发生器
	AUXR &= 0xFB;			 // 定时器时钟12T模式
	T2L = 0xFE;				 // 设置定时初始值
	T2H = 0xFF;				 // 设置定时初始值
	AUXR |= 0x10;			 // 定时器2开始计时
	Strings_Data.Length = 0; // 初始化字符串缓存区长度
}

/*
 *函数名：Uart串口发送字节函数
 *作者：王彦皓
 *函数功能：通过UART串口向上位机发送一个字节数据
 *入口参数：待发送的数据
 *返回参数：无
 */
void Uart_SendByte(u8 Date)
{
	while (busy)
		;
	busy = 1;
	SBUF = Date;
}

/*
 *函数名：指令判别函数
 *作者：王彦皓
 *函数功能：判断上位机发送来的指令是否合法
 *入口参数：无
 *返回参数：无
 */
void correct_error_command(void)
{
	if ((Strings_Data.Length) > (FRAME_LENGTH + 1))
	{
		while (Strings_Data.Length != 0xFF)
		{
			Strings_Data.String[Strings_Data.Length] = '\0';
			Strings_Data.Length--;
		}
		error_flag = 1;
	}
	if (Strings_Data.String[0] != '#' || Strings_Data.String[1] != 'L' || Strings_Data.String[3] != 'P' || Strings_Data.String[5] != '@' || Strings_Data.String[6] != '!')
	{
		while (Strings_Data.Length != 0xFF)
		{
			Strings_Data.String[Strings_Data.Length] = '\0';
			Strings_Data.Length--;
		}
		error_flag = 1;
	}
	if ((Strings_Data.String[2] < '0' || Strings_Data.String[2] > '4'))
	{
		while (Strings_Data.Length != 0xFF)
		{
			Strings_Data.String[Strings_Data.Length] = '\0';
			Strings_Data.Length--;
		}
		error_flag = 1;
	}
	if ((Strings_Data.String[4] < '0' || Strings_Data.String[4] > '5'))
	{
		while (Strings_Data.Length != 0xFF)
		{
			Strings_Data.String[Strings_Data.Length] = '\0';
			Strings_Data.Length--;
		}
		error_flag = 1;
	}
}

/*
 *函数名：UART中断服务函数
 *函数功能：当上位机发送数据来时存入数组，当要发送数据时清空TI与busy位
 *入口参数：无
 *返回参数：无
 */
void Uart_Rountine(void) interrupt 4
{
	if (RI)
	{
		if (error_flag)
			error_flag = 0;
		if (Strings_Data.Length > FRAME_LENGTH)
			Strings_Data.Length = 0;

		Strings_Data.String[Strings_Data.Length] = SBUF;
		Strings_Data.Length++;
		receive_flag = 1;
		RI = 0;
	}
	if (TI)
	{
		busy = 0;
		TI = 0;
	}
}

/*
 *函数名：重定向putchar函数
 *作者：王彦皓
 *函数功能：重定向putchar函数，让printf函数能够正确向上位机发送数据
 *入口参数：要发送的一个字符c
 *返回参数：已发送的字符c
 */
char putchar(char c)
{
	Uart_SendByte(c);
	return c;
}

/*
 *函数名：上位机指令执行函数
 *作者：王彦皓
 *函数功能：判别、解析、执行上位机发送来的指令
 *入口参数：解析指令中的LED模式x和PWM占空比选择位y
 *返回参数：无
 */
void UART_SET_LED(u8 x, u8 y)
{
	if (!error_flag)
	{
		key.S6_press_times = x;
		key.S5_press_times = y;
		printf("已将LED模式设为%bd\r\n",x);
		printf("已将PWM占空比设为%c%bd\r\n",'%',(y*20));
	}
	else if (error_flag)
		printf("你输入了无效的非法指令\r\n");
}