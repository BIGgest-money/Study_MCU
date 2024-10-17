#ifndef  __STEP_MOTOR_H__
#define  __STEP_MOTOR_H__
#include "delay.h"

#define STEP_MOTOR_RUN_MAXSPEED 1
#define STEP_MOTOR_RUN_MINSPEED 5

sbit IN4_D=P1^0;
sbit IN3_C=P1^1;
sbit IN2_B=P1^2;
sbit IN1_A=P1^3;


void step_motor_28BYJ48_send_pulse(u8 dir,u8 step);

#endif