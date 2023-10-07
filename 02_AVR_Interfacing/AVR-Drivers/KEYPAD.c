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
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"

int main(void)
{	
	const int SevenSegment[] = {
		0x3F, // 0
		0x06, // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7
		0x7F, // 8
		0x6F, // 9
	
	};
	u8 x= 0;
	DIO_voidSetPortDirection(DIO_PORTC,DIO_OUTPUT_PORT);
	
	KPD_voidInit(x);
	u8 key;
	while(1){

			key=KPD_u8GetPressedKey();
			if(key >=0 && key<=9)
				DIO_voidSetPortValue(DIO_PORTC,SevenSegment[key]);		
			_delay_ms(100);
	}
		
		
	
}

