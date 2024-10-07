#include "reg52.h"
#include "delay.h"
#include "lcd1602.h"


void main()
{
	LCD_init();//初始化
	LCD_showchar(1,1,'A');
	LCD_showstr(2,1,"pass hhhhhhhyyyyhhhh");
//  LCD_shownum(1,2,666,3);
//  LCD_signalnum(2,5,-12,2);
//	LCD_ShowHexNum(1,5,0x4A,2);
//	LCD_ShowBinNum(2,7,0x02,8);
	while(1)
	{
		void LCD_write_cmd(0x18);
		Delay_25us(1000);
	}
}