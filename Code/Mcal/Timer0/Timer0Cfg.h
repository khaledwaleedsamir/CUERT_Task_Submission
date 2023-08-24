/*
 * Timer0Cfg.h
 *
 * Created: 8/22/2023 12:45:03 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 


#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_

/* Some options in the configuration file are not implemented in this driver only needed options are implemented.*/

// Select Oscillation Frequency in MHz
#define F_OSC              16

/* Select Timer0 prescaler
   option 1 -> [1024]
   option 2 -> [256]     */
#define TIMER_0_PRESCALER 1024


/* Select PWM mode
  option 1 -> [FAST_PWM]
  option 2 -> [PHASE_CORRECT_PWM] */
#define  PWM0_MODE  PHASE_CORRECT_PWM0

/* Select Fast PWM0 mode
   option 1 -> [NON_INVERTED]
   option 2 -> [INVERTED] */
#define  FAST_PWM0_MODE  NON_INVERTED

/* Select Phase Correct PWM0 Mode
   option 1 -> [NON_INVERTED]
   option 2 -> [INVERTED]  */
#define  PHASE_CORRECT_PWM0MODE  NON_INVERTED



#endif /* TIMER0CFG_H_ */