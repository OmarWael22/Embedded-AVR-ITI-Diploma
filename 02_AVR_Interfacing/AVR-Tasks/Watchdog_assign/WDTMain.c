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
#include "../MCAL/USART_Driver/USART_interface.h"
#include"../MCAL/WDT_Driver/WDT_interface.h"
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"



int main(void)
{	
	
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
	_delay_ms(100);
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
	WDT_voidInit();
	
	
	while(1){
		
		WDT_voidReset();
	}
	
}



