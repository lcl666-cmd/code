
#include<ADC.h>
#include<Uart_1.h>

#define	Con_ADC	0x80	//配置ADC寄存器
#define	Sta_ADC	0x88	//开始ADC转换
#define	VCC	2500 //5V系统是5000mV;2.5V系统是2500mV

//定义了一个共用体，用于传送ADC数据使用
union
{
	unsigned char a[2];
	unsigned int	Result;
} ADC;

unsigned int Adc_Result=0;//ADC转换结果
//初始化ADC功能
void	Init_ADC(void)
{
	P1ASF	=	0X10;//把对应的IO口设置为模拟输入
	CLK_DIV |= 0X20;//调整结果存放顺序RES 高两位 ，RES_LOW低八位  10位ADC方便
	ADC_CONTR	=	Con_ADC;//打开ADC电源，设置ADC速率
	EADC = 1;//打开ADC中断允许
	ADC_RES = 0;//清空ADC转化结果
}
//获取某通道ADC的电压值，单位mV
unsigned int	Get_Vol(unsigned char ch)
{
	unsigned int Vol;
	float	a;
	ADC_CONTR = Sta_ADC+ch;//打开指定通道的ADC
	while(ADC_CONTR == (Sta_ADC+ch));
	a = Adc_Result;//传送ADC结果
	a *= VCC;
	a /= 1024;
	Vol = a;
	return Vol;
}
//ADC采样中断
void	Isr_ADC(void)	interrupt	5
{
	ADC_CONTR =	Con_ADC;//清空ADC标志位
	ADC.a[0]	=	ADC_RES;
	ADC.a[1]	=	ADC_RESL;
	Adc_Result = ADC.Result;//把ADC结果直接传送过来
}
//计算龋衅餍秃攀茄涛泶衅鳌Ｖ苯佑肨EMP代替

/*
//进行一次ADC转换
void	Get_ADC(unsigned char ch)
{
	ADC_CONTR = Sta_ADC+ch;//打开指定通道的ADC
}
*/

