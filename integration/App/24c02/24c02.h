#ifndef  __24C02_H__
#define  __24C02_H__


#include "iic.h"
void at24c02_write_one_byte(u8 address,u8 dat);
u8 at24c02_read_one_byte(u8 address);


#endif