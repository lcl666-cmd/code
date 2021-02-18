#include "IIC.h"

#define I2CCFG          (*(unsigned char volatile xdata *)0xfe80)
#define I2CMSCR         (*(unsigned char volatile xdata *)0xfe81)
#define I2CMSST         (*(unsigned char volatile xdata *)0xfe82)
#define I2CSLCR         (*(unsigned char volatile xdata *)0xfe83)
#define I2CSLST         (*(unsigned char volatile xdata *)0xfe84)
#define I2CSLADR        (*(unsigned char volatile xdata *)0xfe85)
#define I2CTXD          (*(unsigned char volatile xdata *)0xfe86)
#define I2CRXD          (*(unsigned char volatile xdata *)0xfe87)

#define 	SDA  P14
#define  	SCL  P15

bit busy;

void Check_Busy(void)
{
	unsigned int i=0;
	while(busy)
	{
		i++;
		if(i>20000)
			return;
	}
}

//IIC�ж�
void I2C_Isr() interrupt 24 using 0
{
	P_SW2 = 0x80;
    if (I2CMSST & 0x40)
    {
        I2CMSST &= ~0x40;                       //���жϱ�־
        busy = 0;
    }
	P_SW2 = 0;
}
//����START����
void IIC_Start(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x81;//����START����
    Check_Busy();
	P_SW2 = 0;
}
//IIC��������
void IIC_SendData(unsigned char dat)
{
	P_SW2 = 0x80;
    I2CTXD = dat;                               //д���ݵ����ݻ�����
    busy = 1;
    I2CMSCR = 0x82;                             //����SEND����
    Check_Busy();
	P_SW2 = 0;
}
//���Ͷ�ACK����
void IIC_RecvACK(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x83;                             //���Ͷ�ACK����
    Check_Busy();
	P_SW2 = 0;
}
//IIC��������
unsigned char IIC_RecvData(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x84;                             //����RECV����
    Check_Busy();
	P_SW2 = 0;
    return I2CRXD;
}
//����ACK����
void IIC_SendACK(void)
{
	P_SW2 = 0x80;
    I2CMSST = 0x00;                             //����ACK�ź�
    busy = 1;
    I2CMSCR = 0x85;                             //����ACK����
    Check_Busy();
	P_SW2 = 0;
}
//����NACK����
void IIC_SendNAK(void)
{
	P_SW2 = 0x80;
    I2CMSST = 0x01;                             //����NAK�ź�
    busy = 1;
    I2CMSCR = 0x85;                             //����NACK����
    Check_Busy();
	P_SW2 = 0;
}
//����STOP����
void IIC_Stop(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x86;                             //����STOP����
    Check_Busy();
	P_SW2 = 0;
	
	SDA = 1;
	SCL = 1;
}
//��ʼ��IIC
void Init_IIC(void)
{
	
    P_SW2 = 0x80;
    I2CCFG = 0xC0;//ʹ��I2C����ģʽ
    I2CMSST = 0x00;
		P_SW2 = 0x00;
		SDA = 1;
		SCL = 1;
}

//





