/*
 * TIMER_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Hardware
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

//TIMER0

void TIMER_Timer0InitCTC(void);  //Function to initialize Timer0 to be in Normal or CTC Mode

void TIMER_Timer0CompareValue(u8 Copy_Preload_Compare_Value); //Function to save input value as preload or compare depending on Mode

void TIMER_voidTimer0CompareMatchCallBack(void(*ISR10_PTR)(void)); //pointer to the ISR CTC Function


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
