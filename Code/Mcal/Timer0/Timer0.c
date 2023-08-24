/*
 * Timer0.c
 *
 * Created: 8/22/2023 12:44:39 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 

/* Only needed options in timer0 are implemented.*/

#include "Timer0.h"

void M_Timer0_Start(void)
{  
	#if   TIMER_0_PRESCALER == 1024
	SetBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif TIMER_0_PRESCALER == 256
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#endif
}
void M_Timer0_Stop(void)
{
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	ClrBit(TCCR0,2);
}

void M_Timer0_Pwm0Init(void)
{ 
	SetBit(DDRB,3);     //to make PB3 output
	#if   PWM0_MODE == FAST_PWM0
	SetBit(TCCR0,3);
	SetBit(TCCR0,6);
	     #if   FAST_PWM0_MODE == NON_INVERTED
	     ClrBit(TCCR0,4);
	     SetBit(TCCR0,5);
	     
	     #elif FAST_PWM0_MODE == INVERTED
	     SetBit(TCCR0,4);
	     SetBit(TCCR0,5);
	     
	     #endif
	#elif PWM0_MODE == PHASE_CORRECT_PWM0
	ClrBit(TCCR0,3);
	SetBit(TCCR0,6);
	
	     #if   PHASE_CORRECT_PWM0MODE == NON_INVERTED
	     ClrBit(TCCR0,4);
	     SetBit(TCCR0,5);
	     #elif PHASE_CORRECT_PWM0MODE == INVERTED
	     SetBit(TCCR0,4);
	     SetBit(TCCR0,5);
	     #endif
	#endif
	

}
void M_Timer0_Pwm0SetDutyCycle(u8 Local_u8_DutyCycle)
{
	#if   PWM0_MODE == FAST_PWM0
	     #if   FAST_PWM0_MODE == NON_INVERTED
	        OCR0 = (((Local_u8_DutyCycle*256)/100)-1);
		 #endif
	#elif PWM0_MODE == PHASE_CORRECT_PWM0	
	     #if   PHASE_CORRECT_PWM0MODE == NON_INVERTED
	        OCR0 = ((Local_u8_DutyCycle*255)/100);
	     #endif
	#endif	 	
}
void M_Timer0_Pwm0Start(void)
{
	M_Timer0_Start();
}
void M_Timer0_Pwm0Stop(void)
{
	M_Timer0_Stop();
}
