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
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);
	
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_INPUT);
	
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	
	LCD_voidInit();
	
	u8* clkwise ="Clock Wise";
	u8* anticlk="Anti-Clock Wise";
	u8 currentDirection=-1;
	u8 prevDirection=-1;
	
	
	while(1){
		
		
		if(DIO_u8GetPinValue(DIO_PORTB,DIO_PIN0)==DIO_LOW){
			
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_LOW);
			
			LCD_voidSendString(clkwise);
			currentDirection=1;
		}
		else if (DIO_u8GetPinValue(DIO_PORTB,DIO_PIN1)==DIO_LOW){
			
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_HIGH);
			LCD_voidSendString(anticlk);
			currentDirection=2;
		}
		else{
			
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN5,DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_HIGH);
			currentDirection=-1;
		}
			
		
		_delay_ms(500);
		LCD_voidClearDisplay();
	}
	
	
}




