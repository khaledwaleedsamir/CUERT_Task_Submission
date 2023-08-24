/*
 * Timer0.h
 *
 * Created: 8/22/2023 12:44:51 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/* Only needed options in timer0 are implemented.*/

// Includes
#include "Timer0Cfg.h"
#include "StdTypes.h"
#include "BitMaths.h"
#include "Reg.h"


// Macros
#define NON_INVERTED          0
#define INVERTED              1

#define FAST_PWM0              1
#define PHASE_CORRECT_PWM0     2

// Functions Prototypes
void M_Timer0_Start(void);
void M_Timer0_Stop(void);
void M_Timer0_Pwm0Init(void);
void M_Timer0_Pwm0SetDutyCycle(u8);
void M_Timer0_Pwm0Start(void);
void M_Timer0_Pwm0Stop(void);

#endif /* TIMER0_H_ */