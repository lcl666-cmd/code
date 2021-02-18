//STC8A8K 系列硬件IIC
#ifndef __IIC_H__
#define __IIC_H__
#include<STC8.h>

//初始化IIC
void Init_IIC(void);

//发送START命令
void IIC_Start(void);

//IIC发送数据
void IIC_SendData(unsigned char dat);

//发送读ACK命令
void IIC_RecvACK(void);

//IIC接收数据
unsigned char IIC_RecvData(void);

//发送ACK命令
void IIC_SendACK(void);

//发送NACK命令
void IIC_SendNAK(void);

//发送STOP命令
void IIC_Stop(void);


#endif







