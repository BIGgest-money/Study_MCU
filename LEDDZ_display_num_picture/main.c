#include "reg52.h"
#include "delay.h"
#include "hc595.h"
#define LEDDZ_COL_PORT P0

u8 LEDDZ_ROW[8]={0x00,0x7E,0x81,0x81,0x81,0x7E,0x00,0x00};//点阵行 显示数字0的数据
u8 LEDDZ_COL[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};//点阵列 

void main()
{
	u8 i=0;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			LEDDZ_COL_PORT=LEDDZ_COL[i];//扫描列
			hc595_write_data(LEDDZ_ROW[i]);//将当前所扫描列的行数据传入函数
			Delay_25us(40);//稳定显示
			hc595_write_data(0x00);//动态扫描 消影
		  Delay_25us(40);
		}
	}
}