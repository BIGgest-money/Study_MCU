#include "reg52.h"
#include "step_motor.h"
#include "delay.h"

void step_motor_28BYJ48_send_pulse(u8 dir,u8 step)
{
	u8 temp=step;
	if(dir)temp=7-step;//0:顺 1：逆时针
	switch(temp)
	{
		case 1:IN1_A=1;IN2_B=1;IN3_C=1;IN4_D=0;break;
		case 2:IN1_A=1;IN2_B=1;IN3_C=0;IN4_D=0;break;
		case 3:IN1_A=1;IN2_B=1;IN3_C=0;IN4_D=1;break;
		case 4:IN1_A=1;IN2_B=0;IN3_C=0;IN4_D=1;break;
		case 5:IN1_A=1;IN2_B=0;IN3_C=1;IN4_D=1;break;
		case 6:IN1_A=0;IN2_B=0;IN3_C=1;IN4_D=1;break;
		case 7:IN1_A=0;IN2_B=1;IN3_C=1;IN4_D=1;break;
		case 8:IN1_A=0;IN2_B=1;IN3_C=1;IN4_D=0;break;
		
		
	}
}
