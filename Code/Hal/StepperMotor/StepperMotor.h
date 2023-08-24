/*
 * StepperMotor.h
 *
 * Created: 8/23/2023 1:54:24 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

// Includes
#include "StepperMotorCfg.h"
#include "Dio.h"
#include "StdTypes.h"
#define F_CPU 16000000UL
#include <util/delay.h>

// Functions Prototypes
void H_StepperMotor_Init(void);
void H_StepperMotor_Right(u8 Local_u8_Angle);
void H_StepperMotor_Left(u8 Local_u8_Angle);
void H_StepperMotor_Off(void);


#endif /* STEPPERMOTOR_H_ */