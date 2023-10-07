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
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"

void led1(void);
void led2(void);

int main(void)
{		
		//leds
		DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
		// adc 0 to 255  pot 0 to 5 V 
		// 1v ---> 255/5 = 51   
		// 1.5 --> 1.5*51 
		// 3 V --> 3*51
		
		//ADC PIN 
		DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
		
		LCD_voidInit();
		ADC_voidInit();
		
		u8 Local_u8Read=0;
		u16 Local_u8VRead=0;
		u8 temp=0;
	
	while(1){
		
		Local_u8Read=ADC_u8StartConversion(0);
		//step = vref / res  = 5/ 2^8
		// Local_u8VRead = ((u32)Local_u8Read*(5000UL))/255UL;
		temp=Local_u8VRead/10;
		LCD_voidSendNumber(Local_u8Read);
		
		if(Local_u8Read>=40)
			DIO_voidSetPortValue(DIO_PORTB,0b00000000);
		
		else  
			DIO_voidSetPortValue(DIO_PORTB,0b00000111);
		
		_delay_ms(1000);
		LCD_voidClearDisplay();
	}
}



