
#include<ADC.h>
#include<Uart_1.h>

#define	Con_ADC	0x80	//����ADC�Ĵ���
#define	Sta_ADC	0x88	//��ʼADCת��
#define	VCC	2500 //5Vϵͳ��5000mV;2.5Vϵͳ��2500mV

//������һ�������壬���ڴ���ADC����ʹ��
union
{
	unsigned char a[2];
	unsigned int	Result;
} ADC;

unsigned int Adc_Result=0;//ADCת�����
//��ʼ��ADC����
void	Init_ADC(void)
{
	P1ASF	=	0X10;//�Ѷ�Ӧ��IO������Ϊģ������
	CLK_DIV |= 0X20;//����������˳��RES ����λ ��RES_LOW�Ͱ�λ  10λADC����
	ADC_CONTR	=	Con_ADC;//��ADC��Դ������ADC����
	EADC = 1;//��ADC�ж�����
	ADC_RES = 0;//���ADCת�����
}
//��ȡĳͨ��ADC�ĵ�ѹֵ����λmV
unsigned int	Get_Vol(unsigned char ch)
{
	unsigned int Vol;
	float	a;
	ADC_CONTR = Sta_ADC+ch;//��ָ��ͨ����ADC
	while(ADC_CONTR == (Sta_ADC+ch));
	a = Adc_Result;//����ADC���
	a *= VCC;
	a /= 1024;
	Vol = a;
	return Vol;
}
//ADC�����ж�
void	Isr_ADC(void)	interrupt	5
{
	ADC_CONTR =	Con_ADC;//���ADC��־λ
	ADC.a[0]	=	ADC_RES;
	ADC.a[1]	=	ADC_RESL;
	Adc_Result = ADC.Result;//��ADC���ֱ�Ӵ��͹���
}
//����ȣ��������ͺ�������������ֱ����TEMP����

/*
//����һ��ADCת��
void	Get_ADC(unsigned char ch)
{
	ADC_CONTR = Sta_ADC+ch;//��ָ��ͨ����ADC
}
*/

