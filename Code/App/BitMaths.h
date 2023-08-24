/*
 * BitMaths.h
 *
 * Created: 8/21/2023 2:34:53 PM
 *  Author: Khaled_Waleed_Samir_Metwally
 */ 


#ifndef BITMATHS_H_
#define BITMATHS_H_

#define SetBit(Reg,Bit) Reg |=  (1<<Bit)
#define ClrBit(Reg,Bit) Reg &= ~(1<<Bit)
#define TogBit(Reg,Bit) Reg ^=  (1<<Bit)
#define GetBit(Reg,Bit) 1&(Reg>>Bit)

#endif /* BITMATHS_H_ */