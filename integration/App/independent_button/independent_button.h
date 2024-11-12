#ifndef  __INDEPENDENT_BUTTON_H__
#define  __INDEPENDENT_BUTTON_H__


#include "public.h"

sbit KEY1=P3^1;
sbit KEY2=P3^0;
sbit KEY3=P3^2;
sbit KEY4=P3^3;

#define KEY1_VALUE 1
#define KEY2_VALUE 2
#define KEY3_VALUE 3
#define KEY4_VALUE 4//对返回的键值宏定义
#define KEY_VALUELESS 0


u8 key_scan(u8 mode);

#endif