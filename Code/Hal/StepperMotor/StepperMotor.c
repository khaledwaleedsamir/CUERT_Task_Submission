/*
 * StepperMotor.c
 *
 * Created: 8/23/2023 1:54:08 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 

#include "StepperMotor.h"

void H_StepperMotor_Init(void)
{
	M_Dio_PinMode(STEPPER_MOTOR_PIN1,OUTPUT);
	M_Dio_PinMode(STEPPER_MOTOR_PIN2,OUTPUT);
	M_Dio_PinMode(STEPPER_MOTOR_PIN3,OUTPUT);
	M_Dio_PinMode(STEPPER_MOTOR_PIN4,OUTPUT);
	
}
void H_StepperMotor_Off(void)
{
	M_Dio_PinWrite(STEPPER_MOTOR_PIN1,LOW);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN2,LOW);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN3,LOW);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN4,LOW);
}
void H_StepperMotor_Right(u8 Local_u8_Angle)
{
	for(int i=0;i<(Local_u8_Angle/4);i++)
	{
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,HIGH);
		_delay_ms(100);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,HIGH);
		_delay_ms(100);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,LOW);
		_delay_ms(100);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,LOW);
		_delay_ms(100);
	}
	M_Dio_PinWrite(STEPPER_MOTOR_PIN1,HIGH);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN2,LOW);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN3,LOW);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN4,HIGH);
	_delay_ms(100);
}
void H_StepperMotor_Left(u8 Local_u8_Angle)
{
	for(int i=0;i<(Local_u8_Angle/4);i++)
	{
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,HIGH);
		_delay_ms(100);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,LOW);
		_delay_ms(100);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,LOW);
		_delay_ms(100);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN1,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN2,LOW);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN3,HIGH);
		M_Dio_PinWrite(STEPPER_MOTOR_PIN4,HIGH);
		_delay_ms(100);
	}
	M_Dio_PinWrite(STEPPER_MOTOR_PIN1,HIGH);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN2,LOW);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN3,LOW);
	M_Dio_PinWrite(STEPPER_MOTOR_PIN4,HIGH);
	_delay_ms(100);
}