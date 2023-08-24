/*
 * DcMotor.c
 *
 * Created: 8/22/2023 12:52:33 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 

#include "DcMotor.h"

void H_DcMotor_Init(void)
{
	M_Dio_PinMode(DCMOTOR_PIN1,OUTPUT);
	M_Dio_PinMode(DCMOTOR_PIN2,OUTPUT);
	M_Timer0_Pwm0Init();
}
void H_DcMotor_SetDirection(u8 Local_u8_Direction)
{
	switch(Local_u8_Direction)
	{
		case CW:
		M_Dio_PinWrite(DCMOTOR_PIN1,LOW);
		M_Dio_PinWrite(DCMOTOR_PIN2,HIGH);
		break;
		case ACW:
		M_Dio_PinWrite(DCMOTOR_PIN1,HIGH);
		M_Dio_PinWrite(DCMOTOR_PIN2,LOW);
		break;
		default:                    break;
	}
}
void H_DcMotor_SetSpeed(u8 Local_u8_Speed)
{
	M_Timer0_Pwm0SetDutyCycle(Local_u8_Speed);
}
void H_DcMotor_Start(void)
{
	M_Timer0_Pwm0Start();
}
void H_DcMotor_Stop(void)
{
	M_Timer0_Pwm0Stop();
}