#include "24c02.h"


/****************************************************************************
* 函 数 名		：at24c02_write_one_byte
* 函 数 功 能	：在AT24c中指定地址写入一个数据
* 输 入				：address:写入数据的目的地址 dat:要写入的数据
* 输 出				：无
*****************************************************************************/

void at24c02_write_one_byte(u8 address,u8 dat)
{
	iic_start();
	iic_write_byte(0xA0);//发送写命令 1010 0000 
	iic_wait_ack();//等待应答
	iic_write_byte(address);//在24c指定地址写入数据
	iic_wait_ack();//等待应答
	iic_write_byte(dat);//发送字节
	iic_wait_ack();//等待应答
	iic_stop();//停止信号
	delay_10us(1);
	
	
}


/****************************************************************************
* 函 数 名		：at24c02_read_one_byte
* 函 数 功 能	：在AT24c中指定地址读一个数据
* 输 入				：address:读数据的地址 
* 输 出				：dat读到的数据
*****************************************************************************/

u8 at24c02_read_one_byte(u8 address)
{
	u8 dat;//定义一个变量 用来接收读到的数据
	iic_start();
	iic_write_byte(0xA0);//发送写命令
	iic_wait_ack();
	iic_write_byte(address);
	iic_wait_ack();
	iic_start();
	iic_write_byte(0xA1);//发送读取数据命令
	iic_wait_ack();
	dat=iic_read_byte(0);// 发送非应答信号 并读取数据
	iic_stop();//停止信号
	return dat;//返回读取的数据
	
}

