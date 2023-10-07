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
	// pot 0 ---> 255
	// servo 1000--->2000
	// val = 1000+ pot* (2000-1000)/(255-0) 
	
	//ADC_voidInit();
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
	TIMER_voidTimer1Init();
	TIMER_voidTimer1SetOverFlowValue(20000);
	
	LCD_voidInit();
		
		while(1){
			
			//u16 Local_read=ADC_u8StartConversion(0);
			//LCD_voidSendNumber(Local_read);
			//u16 Local_matchval= 1000+Local_read*4;
			TIMER_voidTimer1ChannelASetCompareMatchValue(1800);
			_delay_ms(100);
			LCD_voidClearDisplay();
			
			
		}
			
}



