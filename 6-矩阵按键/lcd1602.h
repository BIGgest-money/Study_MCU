#ifndef _LCD1602_H_
#define _LCD1602_H_

#include <REGX52.H>

#include <intrins.h>


void Delay(unsigned int xms);//延迟函数声明
void lcd1602_write_cmd(unsigned char bin);
void lcd1602_write_dat(unsigned char bin);
void lcd1602_init(void);
void lcd1602_show_str(unsigned char x,unsigned char y,unsigned char*str);
void lcd1602_clear(void);

#endif