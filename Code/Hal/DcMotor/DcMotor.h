/*
 * DcMotor.h
 *
 * Created: 8/22/2023 12:52:49 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

// Includes
#include "DcMotorCfg.h"
#include "Dio.h"
#include "Timer0.h"
#include "StdTypes.h"

// Macros
#define CW    1  //CW is backward movement.
#define ACW   2  //ACW is forward movement.

// Functions Prototypes
void H_DcMotor_Init(void);
void H_DcMotor_SetDirection(u8);
void H_DcMotor_SetSpeed(u8);
void H_DcMotor_Start(void);
void H_DcMotor_Stop(void);

#endif /* DCMOTOR_H_ */