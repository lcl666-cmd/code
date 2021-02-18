//STC8A8K ϵ��Ӳ��IIC
#ifndef __IIC_H__
#define __IIC_H__
#include<STC8.h>

//��ʼ��IIC
void Init_IIC(void);

//����START����
void IIC_Start(void);

//IIC��������
void IIC_SendData(unsigned char dat);

//���Ͷ�ACK����
void IIC_RecvACK(void);

//IIC��������
unsigned char IIC_RecvData(void);

//����ACK����
void IIC_SendACK(void);

//����NACK����
void IIC_SendNAK(void);

//����STOP����
void IIC_Stop(void);


#endif







