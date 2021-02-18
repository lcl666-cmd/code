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

//IIC中断
void I2C_Isr() interrupt 24 using 0
{
	P_SW2 = 0x80;
    if (I2CMSST & 0x40)
    {
        I2CMSST &= ~0x40;                       //清中断标志
        busy = 0;
    }
	P_SW2 = 0;
}
//发送START命令
void IIC_Start(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x81;//发送START命令
    Check_Busy();
	P_SW2 = 0;
}
//IIC发送数据
void IIC_SendData(unsigned char dat)
{
	P_SW2 = 0x80;
    I2CTXD = dat;                               //写数据到数据缓冲区
    busy = 1;
    I2CMSCR = 0x82;                             //发送SEND命令
    Check_Busy();
	P_SW2 = 0;
}
//发送读ACK命令
void IIC_RecvACK(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x83;                             //发送读ACK命令
    Check_Busy();
	P_SW2 = 0;
}
//IIC接收数据
unsigned char IIC_RecvData(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x84;                             //发送RECV命令
    Check_Busy();
	P_SW2 = 0;
    return I2CRXD;
}
//发送ACK命令
void IIC_SendACK(void)
{
	P_SW2 = 0x80;
    I2CMSST = 0x00;                             //设置ACK信号
    busy = 1;
    I2CMSCR = 0x85;                             //发送ACK命令
    Check_Busy();
	P_SW2 = 0;
}
//发送NACK命令
void IIC_SendNAK(void)
{
	P_SW2 = 0x80;
    I2CMSST = 0x01;                             //设置NAK信号
    busy = 1;
    I2CMSCR = 0x85;                             //发送NACK命令
    Check_Busy();
	P_SW2 = 0;
}
//发送STOP命令
void IIC_Stop(void)
{
	P_SW2 = 0x80;
    busy = 1;
    I2CMSCR = 0x86;                             //发送STOP命令
    Check_Busy();
	P_SW2 = 0;
	
	SDA = 1;
	SCL = 1;
}
//初始化IIC
void Init_IIC(void)
{
	
    P_SW2 = 0x80;
    I2CCFG = 0xC0;//使能I2C主机模式
    I2CMSST = 0x00;
		P_SW2 = 0x00;
		SDA = 1;
		SCL = 1;
}

//





