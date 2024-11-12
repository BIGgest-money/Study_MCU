#ifndef  __SMG_H__
#define  __SMG_H__

#include "public.h"

#define SMG_PORT P0

void gsmg_display(u8 pos,u8 num[]);

sbit HCA=P2^2 ;
sbit HCB=P2^3 ;
sbit HCC=P2^4 ;
#endif