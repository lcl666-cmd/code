//����:www.hongchangzidonghua.com ΢�Ź��ں�:0����1    ��������
#ifndef __ADC_H__
#define __ADC_H__

#include<STC8.h>


#define	A0 5
#define	A1 4
#define	A2 3
#define	A3 2
#define	A4 1
#define	A5 0

//��ʼ��ADC����
void	Init_ADC(void);
//��ȡĳͨ��ADC�ĵ�ѹֵ����λmV
unsigned int	Get_Vol(unsigned char ch);
//����һ��ADCת��
//void	Get_ADC(unsigned char ch);

void Get_Temp(unsigned char *Val);


#endif