/*
 * main.c
 *
 * Created: 8/20/2023 3:27:04 PM
 *  Author: Omar
 */ 


#define F_CPU 8000000UL
#include"..\MCAL\DIO_Driver\DIO_interface.h"
#include"../HAL/LCD_Driver/LCD_interface.h"
#include"../HAL/KEYPAD_Driver/KPD_interface.h"
#include "../MCAL/GIE_Driver/GIE_interface.h"
#include"../MCAL/EXTI_Driver/EXTI_interface.h"
#include"../MCAL/ADC_Driver/ADC_interface.h"
#include "../MCAL/TIMER_Driver/TIMER_interface.h"
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"



int main(void)
{		
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
	ADC_voidInit();
	LCD_voidInit();
	
	
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);
		TIMER_voidTimer2FastPWM();
		TIMER_voidTImer0CTCInit();
		
		while(1){
			
			for(u8 i=0;i<20;i++){
				
				TIMER_voidTimer2SetCompareMatchValue(i);
				LCD_voidSendNumber(i);
				
				TIMER_voidSetBusyWaitTimer0_ms(100);
				LCD_voidClearDisplay();
			}
	
			
			
		}
}



