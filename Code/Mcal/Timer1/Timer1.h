/*
 * Timer1.h
 *
 * Created: 8/23/2023 9:20:22 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

/* This Driver was created specifically for this task and only the needed features are implemented. */

// Includes 
#include "StdTypes.h"
#include "Reg.h"
#include "BitMaths.h"
#include <avr/interrupt.h>

// Functions Prototypes
void M_Timer1_Init(void);
void M_Timer1_Start(void);
void M_Timer1_SetCallBack(void(*)(void));


#endif /* TIMER1_H_ */