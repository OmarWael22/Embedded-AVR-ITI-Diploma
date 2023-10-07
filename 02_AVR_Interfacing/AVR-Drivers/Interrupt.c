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
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"

void led1(void);
void led2(void);

int main(void)
{		
		//leds
		DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	
		DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
		DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
		// pull up
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
		
		EXTI_voidInit(EXTI_INT0,EXTI_FALLING_EDGE);
		EXTI_voidInit(EXTI_INT1,EXTI_ANY_LOGIC);
		EXTI_voidSetCallBackINT0(&led1);
		EXTI_voidSetCallBackINT1(&led2);
		
		GIE_voidEnableGlobalInt();
		
		while(1);
	
}

void led1(){
	
	static u8 led1_state=0;
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,led1_state);
	TOG_BIT(led1_state,0);
	
}

void led2(){
	
	static u8 led2_state=0;
	DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,led2_state);
	TOG_BIT(led2_state,0);
	
}

