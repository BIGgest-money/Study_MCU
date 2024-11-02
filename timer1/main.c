#include "reg52.h"
#include "delay.h"
sbit led1=P2^0;

// 定时器1
void time1_init()
{
	TMOD|=0x10;//定时器1 方式1
	TH1=0xFC;//
	TL1=0x18;//低八位
	ET1=1;//定时器中断允许位
	EA=1;//中断打开
	TR1=1;//打开定时器1
	
	
}

void main()
{
	time1_init();
	while(1)
	{
		
	}
}

void time1() interrupt 3
{
	static u16 i=0;
	i++;
	TH1=0xFC;//重新赋值 没有数据重装载
	TL1=0x18;
	if(i==1000)//1sled灯闪烁
	{
		i=0;
		led1=!led1;
	}
	
}