#ifndef  __LCD1602_H__
#define  __LCD1602_H__

#include "delay.h"

void LCD_write_cmd(u8 cmd);
void LCD_write_data(u8 dat);
void LCD_init(void);
void LCD_setcursor(u8 line,u8 column);
void LCD_showchar(u8 line,u8 column,u8 Char);
void LCD_showstr(u8 line,u8 column,u8* str);
u16 pow(u16 x,u16 y);
void LCD_shownum(u8 line,u8 column,u16 num,u8 length);
void LCD_signalnum(u8 line,u8 column,int num,u8 length);
void LCD_ShowHexNum(u8 line,u8 column,u16 num,u8 length);
void LCD_ShowBinNum(u8 line,u8 column,u16 num,u8 length);

#endif