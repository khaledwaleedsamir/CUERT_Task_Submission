/*
 * CUERT_Task.c
 *
 * Created: 8/21/2023 2:31:20 PM
 * Author : Khaled_Waleed_Samir_Metwally
 */ 

// Includes
#include "BitMaths.h"
#include "StdTypes.h"
#include "Dio.h"
#include "Lcd.h"
#include "Timer0.h"
#include "DcMotor.h"
#include "StepperMotor.h"
#include "Uart.h"
#include "Timer1.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>

// System Macros
#define WRONG   2
#define CORRECT 1 

//System Variables
u8 Global_u8_Seconds = 0;
u8 Global_u8_Mins = 0;
u8 Global_u8_Hours = 0;

u8 Global_u8_Speed = 0;
u8 Global_u8_Angle = 0;
s8 Global_u8_TotalAngle = 0;

// Functions

/* Function Name : A_Main_UartReceiveFrame
 * Description   : This function is responsible for receiving the 8 bytes of the data frame specified.
 * Parameters    : Pointer to an array of u8 (Local_u8_Frame). 
 * Return        : void.
 */
void A_Main_UartReceiveFrame(u8* Local_u8_Frame)
{
	for(u8 Local_u8_Counter = 0; Local_u8_Counter < 8; Local_u8_Counter++)
	{
		Local_u8_Frame[Local_u8_Counter] = M_Uart_ReceiveByte();
	}
}


/* Function Name : A_Main_CheckFrame
 * Description   : This function is responsible for checking if the frame is correct.
 * Parameters    : Pointer to an array of u8 (Local_u8_Frame). 
 * Return        : u8 check result (CORRECT or WRONG).
 */
u8 A_Main_CheckFrame(u8* Local_u8_Frame)
{
	/* The Following two variables are used to get the speed and the angle of rotation and check if they match the 
	   required values speed:(0-->100) and angle:(0-->45) subtracting 48 (ASCII value for 0) and multiplying each digit by its decimal weight.*/
	
	Global_u8_Speed = ((Local_u8_Frame[0] - 48)*100 + (Local_u8_Frame[1] - 48)*10 + (Local_u8_Frame[2] - 48));
	Global_u8_Angle = ((Local_u8_Frame[4] - 48)*10 + (Local_u8_Frame[5] - 48));
	
	if(Global_u8_Speed > 100)
	{
		return WRONG;
	}
	if(Global_u8_Angle > 45)
	{
		return WRONG;
	}
	
	/* The Following checks the bytes in the frame responsible for the direction of motion and the rotation. */
	
	if(Local_u8_Frame[3] != 'F' && Local_u8_Frame[3] != 'B' )
	{
		return WRONG;
	}
	if(Local_u8_Frame[6] != 'R' && Local_u8_Frame[6] != 'L')
	{
		return WRONG;
	}
	/*Finally the check for the stop bit*/
	if(Local_u8_Frame[7] != 'E')
	{
		return WRONG;
	}
	
	/* Reach here if all the parameters are correct. */
	return CORRECT;
}


/* Function Name : A_Main_Timer1CallBack
 * Description   : This function is the call back function for timer1 for displaying the time.
 * Parameters    : void.
 * Return        : void.
 */
void A_Main_Timer1CallBack(void)
{
	/* Incrementing the seconds after each call back and checking for 60 seconds and 60 minutes and 12 hours to update the time on screen. */
	Global_u8_Seconds++;
	
	/* Case 60 Seconds (1 Minute complete)*/
	if(Global_u8_Seconds == 60)
	{
		Global_u8_Seconds = 0;
		Global_u8_Mins++;
		H_Lcd_Goto(2,20);  // Go to the second digit in the seconds to change it to 0. 
		H_Lcd_WriteNumber(0);
		H_Lcd_Goto(2,18);
		if(Global_u8_Mins >= 10)
		{
			H_Lcd_WriteCommand(0x10); //Shift writing left to write two digits numbers.
		}
		H_Lcd_WriteNumber(Global_u8_Mins);
	}
	
	/* Case 60 Minutes (1 Hour complete)*/
	if(Global_u8_Mins == 60)
	{
		Global_u8_Mins = 0;
		Global_u8_Hours++;
		H_Lcd_Goto(2,17);
		H_Lcd_WriteNumber(0);
		H_Lcd_Goto(2,15);
		if(Global_u8_Hours >= 10)
		{
			H_Lcd_WriteCommand(0x10); //Shift writing left to write two digits numbers.
		}
		H_Lcd_WriteNumber(Global_u8_Hours);
	}
	
	/* Checking for 12 hours to change to PM*/
	if(Global_u8_Hours == 12)
	{
		H_Lcd_Goto(2,23);
		H_Lcd_WriteString("PM");
	}
	
	/* Checking for 24 hours to reset day*/
	if(Global_u8_Hours == 24)
	{
		H_Lcd_Goto(2,14);
		H_Lcd_WriteNumber(0); // Go to the second digit in the hours to change it to 0. 
		Global_u8_Hours = 0;
		Global_u8_Mins  = 0;
		Global_u8_Seconds = 0;
		H_Lcd_Goto(2,23);
		H_Lcd_WriteString("AM");
	}
	
	/*Displaying Seconds*/
	H_Lcd_Goto(2,21);
	if(Global_u8_Seconds >= 10)
	{
		H_Lcd_WriteCommand(0x10); //Shift writing left to write two digits numbers.
	}
	H_Lcd_WriteNumber(Global_u8_Seconds);
}

int main(void)
{
	/* System Initialization */
	H_Lcd_Init();
	M_Uart_Init();
	H_DcMotor_Init();
	H_StepperMotor_Init();
	M_Timer1_Init();
	u8 Local_u8_Frame[8];  //Array of u8 to receive the frame bytes.
	
	H_Lcd_WriteString("    Initialization Complete!    ");
	_delay_ms(500);
	H_Lcd_Clear();
	
	H_Lcd_WriteString("    Speed: 00% Direction:+00    "); // Initial Setup all set to 0.
	
	/* Setting timer 1 callback and starting the timer to display the time on screen. */
	M_Timer1_SetCallBack(A_Main_Timer1CallBack);
	M_Timer1_Start();
	H_Lcd_NextLine();
	H_Lcd_WriteString("        Time: 00:00:00 AM        ");
	
	
    while (1) 
    {
		A_Main_UartReceiveFrame(Local_u8_Frame);
		/*Checking if the received frame is correct,8 bytes must be received in order to continue.*/
		
		
		/* Case 1: The Frame is Incorrect. */
		if(A_Main_CheckFrame(Local_u8_Frame) == WRONG)
		{
			H_Lcd_Goto(2,1);
			H_Lcd_WriteString("Wrong!");
			_delay_ms(500);
			H_Lcd_Goto(2,1);
			H_Lcd_WriteString("      ");
		}
		
		/* Case 2: The Frame is Correct. */
		if(A_Main_CheckFrame(Local_u8_Frame) == CORRECT)
		{
			/* Setting the DC motor and Stepper motor According to the received frame. */
			
			/* 1- DC MOTOR */
			if(Local_u8_Frame[3] == 'F')
			{
				H_DcMotor_SetDirection(ACW);
			}
			else if(Local_u8_Frame[3] == 'B')
			{
				H_DcMotor_SetDirection(CW);
			}
			H_DcMotor_SetSpeed(Global_u8_Speed);
			H_DcMotor_Start();
			
			/* Displaying the Set speed for the DC MOTOR on the LCD*/
			H_Lcd_Goto(1,12);
			if(Global_u8_Speed>=10)
			{
				H_Lcd_WriteCommand(0x10);
				if(Global_u8_Speed == 100)
				{
					H_Lcd_WriteCommand(0x10); // shift left on the LDC to write third digit (100).
				}
			}
			if(Global_u8_Speed < 10)
			{
				H_Lcd_Goto(1,10);
				H_Lcd_WriteString(" 0"); //to clear the first 2 digits from any previous state.
				
			}
			H_Lcd_WriteNumber(Global_u8_Speed);
			
			
			/* 2- STEPPER MOTOR */
			if(Local_u8_Frame[6] == 'R')
			{
			    Global_u8_TotalAngle = Global_u8_TotalAngle + Global_u8_Angle;
				H_StepperMotor_Right(Global_u8_Angle);
			}
			if(Local_u8_Frame[6] == 'L')
			{
				Global_u8_TotalAngle = Global_u8_TotalAngle - Global_u8_Angle;
				H_StepperMotor_Left(Global_u8_Angle);
			}
			
			/* Displaying the current stepper motor angle on the LCD with the +VE and -VE sign based on the direction of rotation. */
			if(Global_u8_TotalAngle<0)
			{
				H_Lcd_Goto(1,25);
				H_Lcd_WriteChar('-');
			}
			else if(Global_u8_TotalAngle>=0)
			{
				H_Lcd_Goto(1,25);
				H_Lcd_WriteChar('+');
			}
			H_Lcd_Goto(1,27);
			if(abs(Global_u8_TotalAngle) >= 10)
			{
				H_Lcd_WriteCommand(0x10);
			}
			H_Lcd_WriteNumber(Global_u8_TotalAngle);
			if(abs(Global_u8_TotalAngle) < 10)
			{
				H_Lcd_Goto(1,26);
				H_Lcd_WriteChar('0'); //to clear the second digit from any previous state.
			}
		}
		/* End of Correct frame case.*/
    }
	/* End of While Loop.*/
}
/* End of the main function.*/
