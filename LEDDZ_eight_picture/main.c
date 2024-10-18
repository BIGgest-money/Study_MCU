#include "reg52.h"
#include "hc595.h"
#include "delay.h"
#define DZ_PORT P0
u8 DZ_picture_row[8]={0x10,0x20,0x46,0x36,0x36,0x46,0x20,0x10};
u8 DZ_picture_col[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

void main()
{
	u8 i=0;
	while(1)
	{
		
		for(i=0;i<8;i++)
		{
			DZ_PORT=DZ_picture_col[i];//按列扫描 第一列的行点亮 第二列的行点亮
			hc595_write_data(DZ_picture_row[i]);
			Delay_25us(10);
			hc595_write_data(0x00);
		}
		
	}
}