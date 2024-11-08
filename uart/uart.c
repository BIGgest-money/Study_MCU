#include "delay.h"
#include "reg52.h"


/***
实验名称：串口通信实验
实验现象：当串口助手发送数据给单片机，单片机原封不动转发给串口助手显示

***/

/***
函数功能：串口通信中断配置函数
输入：baud 装载初始值
***/
void uart_init(u8 baud)
{
	TMOD|=0x20;//T1计数器 工作方式2
	SCON=0x50;//串口工作方式1 允许接收
	PCON=0x80;//波特率加倍
	TH1=baud;//计数器重装初始值
	TL1=baud;//计数器初始值
	ES=1;//打开串口中断
	EA=1;//打开总中断
	TR1=1;//打开计数器
	
	
}


void main()
{
	uart_init(0xFA);//波特率为9600
	while(1)
	{	
		
	}
}

void uart() interrupt 4
{
  u8 re_data;
	RI=0;//清除中断标志位 接收
	re_data=SBUF;//缓存 移位寄存器
	SBUF=re_data;//将接收到的数据放入发送寄存器
	while(!TI);//判断是否数据发送完成
	TI=0;//清除发送完成标志位
	
}