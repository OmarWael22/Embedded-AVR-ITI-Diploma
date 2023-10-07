/*
 * main.c
 *
 * Created: 8/20/2023 3:27:04 PM
 *  Author: Omar
 */ 


#define F_CPU 8000000UL
#include <stdio.h>
#include"..\MCAL\DIO_Driver\DIO_interface.h"
#include"../HAL/LCD_Driver/LCD_interface.h"
#include"../HAL/KEYPAD_Driver/KPD_interface.h"
#include "../MCAL/GIE_Driver/GIE_interface.h"
#include"../MCAL/EXTI_Driver/EXTI_interface.h"
#include"../MCAL/ADC_Driver/ADC_interface.h"
#include "../MCAL/TIMER_Driver/TIMER_interface.h"
#include "../MCAL/USART_Driver/USART_interface.h"
#include"../MCAL/WDT_Driver/WDT_interface.h"
#include "../MCAL/SPI_Driver/SPI_interface.h"
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"



void SendData(void);
int main(void)
{
		// input pull up switch
		DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
		//output led
		DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_OUTPUT);

		SPI_voidMasterInit();
		
		EXTI_voidInit(EXTI_INT0,EXTI_FALLING_EDGE);
		EXTI_voidSetCallBackINT0(&SendData);
		GIE_voidEnableGlobalInt();
	while(1){
		
		
	}
}
void SendData(void){
	
	static u8 counter=0;
	static u8 ledstate=1;
	SPI_u8Transceiver(counter);
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN3,ledstate);
	counter++;
	counter=counter%16;
	TOG_BIT(ledstate,0);
}