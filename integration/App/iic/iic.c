/****************************************************************************
* 函 数 名		：iic_start
* 函 数 功 能	：产生iic起始信号
* 输 入				：无
* 输 出				：无
*****************************************************************************/
#include "iic.h"
void iic_start()
{
	IIC_SDA=1;
	delay_10us(1);
	IIC_SCL=1;
	delay_10us(1);
	IIC_SDA=0;//SDA由高变低 SCL为高电平 数据稳定发送 
	delay_10us(1);
	IIC_SCL=0;//时钟变为低电平 SDA可以改变
	delay_10us(1);
}


/****************************************************************************
* 函 数 名		：iic_stop
* 函 数 功 能	：产生iic停止信号
* 输 入				：无
* 输 出				：无
*****************************************************************************/


void iic_stop()
{
	IIC_SDA=0;
	delay_10us(1);
	IIC_SCL=1;
	delay_10us(1);
	IIC_SDA=1;//SDA由低变高 SCL为高电平 数据停止发送
	delay_10us(1);

}

/****************************************************************************
* 函 数 名		：iic_nack
* 函 数 功 能	：产生非应答信号
* 输 入				：无
* 输 出				：无
*****************************************************************************/


void iic_nack()
{
	IIC_SCL=0;//SCL为低电平时可以改变数据
	IIC_SDA=1;//SDA为高电平 非应答信号
	delay_10us(1);
	IIC_SCL=1;
	delay_10us(1);
	IIC_SCL=0;
	delay_10us(1);
	
}

/****************************************************************************
* 函 数 名		：iic_ack
* 函 数 功 能	：产生应答信号
* 输 入				：无
* 输 出				：无
*****************************************************************************/

void iic_ack()
{
	IIC_SCL=0;//SCL为低电平时可以改变数据
	IIC_SDA=0;//SDA为低电平 应答信号
	delay_10us(1);
	IIC_SCL=1;
	delay_10us(1);
	IIC_SCL=0;
	delay_10us(1);
}



/****************************************************************************
* 函 数 名		：iic_wait_ack
* 函 数 功 能	：等待应答信号
* 输 入				：无
* 输 出				：1,无应答 0，有应答
*****************************************************************************/


u8 iic_wait_ack()
{
	u8 time_temp=0;
	IIC_SCL=1;//数据稳定 
	delay_10us(1);
	while(IIC_SDA)//等待SDA为低电平
	{
		time_temp++;
		if(time_temp>100)//一直等待从机应答 直到超时就停止通信
		{
			iic_stop();
			return 1;//返回1 非应答
		}
	}
		IIC_SCL=0;//否则 从机应答 SCL低电平
		return 0;
	
}





/****************************************************************************
* 函 数 名		：iic_write_byte
* 函 数 功 能	：iic向从机发送一个字节
* 输 入				：dat ,发送一个字节
* 输 出				：无
*****************************************************************************/


void iic_write_byte(u8 dat)
{
	u8 i =0;
	IIC_SCL=0;//时钟为低电平时数据可变 此时将数据写入
	for(i=0;i<8;i++)//字节是一位一位传入，并先传高位
	{
		if((dat&0x80)>0)//先判断高位是1/0
			IIC_SDA=1;
		else
			IIC_SDA=0;
		dat<<=1;
		IIC_SCL=1;//稳定传输数据
		delay_10us(1);
		IIC_SCL=0;
		delay_10us(1);
		
			
}

}

/****************************************************************************
* 函 数 名		：iic_read_byte
* 函 数 功 能	：iic读取一个字节
* 输 入				：ack=1,发送ack,ack=0,发送nack
* 输 出				：receive 读取到的数
*****************************************************************************/

u8 iic_read_byte(u8 ack)
{
	u8 i=0,receive=0;
	
	for(i=0;i<8;i++)//先读高位再读低位
	{
		IIC_SCL=0;
		delay_10us(1);
		IIC_SCL=1;
		delay_10us(1);//数据稳定后开始读数据
		receive<<=1;
		if(IIC_SDA) receive++;//读的是1 数据加一
		delay_10us(1);
		
		
	}
	if(!ack)
		iic_nack();
	else
		iic_ack();
	
	
	return receive;
}



