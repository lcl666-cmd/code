#include "LED_Display.h"
#include "Timer0.h"

//接口定义   P0口是数据接口 接线定义参考原理图
#define	PDat	P0
#define	DP		P02
#define	G1		P11
#define	G2		P25
#define	G3		P24

//定义0-9，加上一杠“-”，加上空白，11个数字的HEX格式
unsigned char NUM_Dat[12]={0X44,0XE7,0X16,0X86,0XA5,0X8C,0X0C,0XE6,0X04,0x84,0XBF,0XFF};
static unsigned char NUM_Show_Count=0;//刷新状态，用于轮流刷新4位数字
static unsigned char NUM_Show[3];

//刷新数字，需要间隔一定时间刷新每一位数字的状态，5mS就不错。
void Show_Display(unsigned char *Num)
{
	if((NUM_Show_Count+1) == 1)
		G1 = 0;
	else
		G1 = 1;
	if((NUM_Show_Count+1) == 2)
		G2 = 0;
	else
		G2 = 1;
	if((NUM_Show_Count+1) == 3)
		G3 = 0;
	else
		G3 = 1;
	PDat = NUM_Dat[Num[NUM_Show_Count]];//在数据总线上，显示出内容
	NUM_Show_Count++;//更新一下位数计数器
	if(NUM_Show_Count > 2)
		NUM_Show_Count = 0;
}
//显示数字，放到循环中。
void Show_Num_Loop(void)
{
	Show_Display(NUM_Show);
}
//设置要显示的数字
void Set_Num(int Num)
{
	
	if(Num > 99)
		Num = 99;
	if(Num < -99)
		Num = -99;
	
	if(Num >= 0)
	{
		NUM_Show[0] = 11;
		
	}
	if(Num < 0)
	{
		NUM_Show[0] = 10;
		Num = Num * -1 ;
	}
	
	NUM_Show[1] = Num / 10;
	NUM_Show[2] = Num % 10;
	
}

//





