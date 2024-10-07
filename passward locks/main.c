#include "reg52.h"
#include "delay.h"
#include "MatrixKey.h"
#include "lcd1602.h"


void main()
{
	
	u8 key=0,count=0;
	u16 password=0;//0-9输入的密码
	LCD_init();//初始化
	LCD_showstr(1,1,"password");//显示屏显示password
	while(1)
	{
		key = matrix_key();//按键返回的键值
		if(key)//判断按键是否按下
		{
			
			if(key<=10)//s1-s10 输入0-9 用10替代0
			{
				if(count<4)//判断输入密码次数 即长度
				{
					password*=10;//密码左移1位
					password+=key%10;//获取一位密码
					count++;
				}
					LCD_shownum(2,1,password,4);//更新显示
			}
			if(key==11)//如果按键11按下，即确认密码
			{
				if(password==2345)
				{
					LCD_showstr(1,11,"right");
					password=0;//清除密码
					count=0;//计数清零
					LCD_shownum(2,1,password,4);//显示密码
				}
				else
				{
					LCD_showstr(1,11,"false");
					password=0;//清除密码
					count=0;//计数清零
					LCD_shownum(2,1,password,4);
				}
			}
			if(key==12)//如果按键12按下，则输入的密码取消
			{
				password=0;//清除密码
				count=0;//计数清零
				LCD_showstr(1,11,"     ");//清除右上角提示信息
				LCD_shownum(2,1,password,4);
			}
		}
	}
		
	
}