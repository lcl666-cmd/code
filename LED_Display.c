#include "LED_Display.h"
#include "Timer0.h"

//�ӿڶ���   P0�������ݽӿ� ���߶���ο�ԭ��ͼ
#define	PDat	P0
#define	DP		P02
#define	G1		P11
#define	G2		P25
#define	G3		P24

//����0-9������һ�ܡ�-�������Ͽհף�11�����ֵ�HEX��ʽ
unsigned char NUM_Dat[12]={0X44,0XE7,0X16,0X86,0XA5,0X8C,0X0C,0XE6,0X04,0x84,0XBF,0XFF};
static unsigned char NUM_Show_Count=0;//ˢ��״̬����������ˢ��4λ����
static unsigned char NUM_Show[3];

//ˢ�����֣���Ҫ���һ��ʱ��ˢ��ÿһλ���ֵ�״̬��5mS�Ͳ���
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
	PDat = NUM_Dat[Num[NUM_Show_Count]];//�����������ϣ���ʾ������
	NUM_Show_Count++;//����һ��λ��������
	if(NUM_Show_Count > 2)
		NUM_Show_Count = 0;
}
//��ʾ���֣��ŵ�ѭ���С�
void Show_Num_Loop(void)
{
	Show_Display(NUM_Show);
}
//����Ҫ��ʾ������
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





