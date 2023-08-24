/*
 * Timer1.c
 *
 * Created: 8/23/2023 9:20:10 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 

/* This Driver was created specifically for this task and only the needed features are implemented. */

#include "Timer1.h"

void (*CallBack)(void);

void M_Timer1_Init(void)
{
	/* Timer 1 operation in normal mode.*/
	ClrBit(TCCR1A,0);
	ClrBit(TCCR1A,1);
	ClrBit(TCCR1B,3);
	ClrBit(TCCR1B,4);
	
	SetBit(TIMSK,2);  // Overflow Interrupt Enable.
	SetBit(SREG,7);   // Global Interrupt Enable.
}
void M_Timer1_Start(void)
{
	// Timer 1 Prescaler set to 256
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	SetBit(TCCR1B,2);
	
	TCNT1 = 3036;  //This value corresponds to approx. 1 second using 256 prescaler and 16MHz clock.
}

void M_Timer1_SetCallBack(void(*Ptr)(void))
{
	CallBack = Ptr;
}
ISR(TIMER1_OVF_vect)
{
    CallBack();
}