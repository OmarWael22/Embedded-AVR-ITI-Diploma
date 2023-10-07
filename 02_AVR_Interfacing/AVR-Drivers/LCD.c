/*
 * main.c
 *
 * Created: 8/20/2023 3:27:04 PM
 *  Author: Omar
 */ 


#define F_CPU 8000000UL
#include"..\MCAL\DIO_Driver\DIO_interface.h"
#include"../HAL/LCD_Driver/LCD_interface.h"
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"

int main(void)
{
	LCD_voidInit();
	
		
	
	LCD_voidSendData('o');
	LCD_voidSendData('m');
	LCD_voidSendData('a');
	LCD_voidSendData('r');
	u8 ac=0;
	 while (1)
	 {
		 _delay_ms(100); // Wait for some time

		 // Shift the entire display to the right (S/C=1, R/L=1)
		LCD_voidShiftDisplay(LCD_SHIFT_R);
	 }
		
		
	
}

