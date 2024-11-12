#ifndef  __IIC_H__
#define  __IIC_H__

#include "public.h"

//定义EEPROM控制引脚
sbit IIC_SCL=P2^1;//SCL时钟线
sbit IIC_SDA=P2^0;//SDA数据线

//iic函数
void iic_start();
void iic_stop();
void iic_nack();
void iic_ack();
u8 iic_wait_ack();
void iic_write_byte(u8 dat);
u8 iic_read_byte(u8 ack);



#endif