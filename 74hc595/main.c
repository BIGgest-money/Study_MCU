#include "regx52.h"
#include "delay.h"
#include "hc595.h"
#define LEDDZ_COL_PORT P0 //对点阵列的端口P0宏定义
u8 hc595_buf[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//A8-A1 低到高
void main()
{
	while(1)
	{
		u8 i;
		LEDDZ_COL_PORT=0x00;//点阵列的端口低电平
		for(i=0;i<8;i++)
		{
			hc595_write_data(0x00);//动态显示 消影
			hc595_write_data(hc595_buf[i]);
			Delay_25us(50000);//延时0.5s 
			
			
		}
	}
}