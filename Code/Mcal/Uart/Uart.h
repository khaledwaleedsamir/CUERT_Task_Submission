/*
 * Uart.h
 *
 * Created: 8/21/2023 3:28:35 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 


#ifndef UART_H_
#define UART_H_

// Includes
#include "UartCfg.h"
#include "StdTypes.h"
#include "BitMaths.h"
#include "Reg.h"

// Macros
#define PARITY_DISABLED 1
#define PARITY_EVEN     2
#define PARITY_ODD      3

// Functions Prototypes
void M_Uart_Init(void);
void M_Uart_TransmitByte(u8);
u8   M_Uart_ReceiveByte(void);

#endif /* UART_H_ */