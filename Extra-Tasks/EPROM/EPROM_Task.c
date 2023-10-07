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
#include "../MCAL/SPI_Driver/SPI_interface.h"
#include "../MCAL/TWI_Driver/TWI_interface.h"
#include "../HAL/EPROM_Driver/EPROM_interface.h"
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"




int main(void)
{	
	DIO_voidSetPortDirection(DIO_PORTD,DIO_OUTPUT_PORT);
	TWI_voidMasterInit(0);
	u16 add=10;
	EEPROM_voidSendDataByte(255,add);
	u8 data=0 ;
	_delay_ms(100);
	EEPROM_voidReadDataByte(&data,add);
	while(1){
		DIO_voidSetPortValue(DIO_PORTD,data);
	}
}
