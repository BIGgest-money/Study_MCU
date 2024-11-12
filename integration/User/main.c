#include "public.h"
#include "24c02.h"
#include "smg.h"
#include "independent_button.h"
/************************************************************************
本次实验实现的功能是：系统运行时，数码管右 3 位显示0 ，
按 K1 键将数据 写入到 EEPROM 内保存，
按 K2 键读取EEPROM 内保存的数据，
按 K3 键显示数据加 1 ，
按 K4 键显示数据清零，最大能写入的数据是 255 。
*************************************************************************/
#define EEPROM_ADDRESS 0  //定义数据存入EEPROM的地址

void main()
{
	u8 key=0;
	u8 dat=0;
	u8 dat_num[3]={0};//max number 255
	while(1)
	{
		key=key_scan(0);
		if(key==KEY1_VALUE )
			at24c02_write_one_byte(EEPROM_ADDRESS,dat);
		else if(key==KEY2_VALUE )
			dat=at24c02_read_one_byte(EEPROM_ADDRESS);
		else if(key==KEY3_VALUE)
		{
			dat++;
			if (dat==255)dat=255;
		}
		else if(key==KEY4_VALUE )
			dat=0;
		
		
		dat_num[0]=dat/100;//百位
		dat_num[1]=dat%100/10;//十位
		dat_num[2]=dat%100%10;//个位
		
		
		gsmg_display(6,dat_num);
		

	}
}