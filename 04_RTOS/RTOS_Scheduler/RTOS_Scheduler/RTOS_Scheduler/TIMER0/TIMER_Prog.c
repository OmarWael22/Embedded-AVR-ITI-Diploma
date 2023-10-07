/*
 * TIMER_Prog.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Hardware
 */
#include<avr/io.h>

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

#include "TIMER_Config.h"
#include "TIMER_Interface.h"


//Global Function PTR
void (*TIMER0_CTC_ISR_PTR)(void) = 0x00;


//Prescaller Table
/**		CS22 CS21 CS20 Description

		0 0 0	No clock source (Timer/Counter stopped).
		0 0 1 	clkT2S/(No prescaling)
		0 1 0 	clkT2S/8 (From prescaler)
		0 1 1 	clkT2S/32 (From prescaler)
		1 0 0 	clkT2S/64 (From prescaler)
		1 0 1 	clkT2S/128 (From prescaler)
		1 1 0 	clkT2S/256 (From prescaler)
		1 1 1 	clkT2S/1024 (From prescaler)
  */
void TIMER_Timer0InitCTC(void){
	//Clearing bit 6 in TCCR0 for both Modes
	CLR_Bit(TCCR0,6);
	Set_Bit(TCCR0,3);
	//OCR
	OCR0 = TIMER0_u8COMPARE_MATCH_VALUE;
	//Enable CTC Interrupt
	Set_Bit(TIMSK,1);
	//Set Prescaller Value 64
	Set_Bit(TCCR0,0);
	Set_Bit(TCCR0,1);
	CLR_Bit(TCCR0,2);
}

void TIMER_Timer0CompareValue(u8 Copy_Preload_Compare_Value){
	//set Compare Match Value
	OCR0 = Copy_Preload_Compare_Value;
}


void TIMER_voidTimer0CompareMatchCallBack(void(*ISR10_PTR)(void)){
	if(ISR10_PTR != 0x00)
		TIMER0_CTC_ISR_PTR = ISR10_PTR;
}


//CTC ISR
void __vector_10(void) __attribute__((signal));  //minus 1 from Datasheet as it should started from 0 not 1
void __vector_10(void){
	if(TIMER0_CTC_ISR_PTR!=0x00)
		TIMER0_CTC_ISR_PTR();

}



