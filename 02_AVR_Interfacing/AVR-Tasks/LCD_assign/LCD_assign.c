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
	LCD_voidInit();
	u8* name ="omar"; 
	LCD_voidSendString(name);
	
	u8 xpos=0;
	u8 ypos=0;
	
	while(1){
		
		for (ypos=0;ypos<16;ypos++){
			
		LCD_voidGoTOXY(xpos,ypos);
		LCD_voidSendString(name);
		TOG_BIT(xpos,0);
		_delay_ms(250);
		LCD_voidClearDisplay();
		
		
		}
		
	}
}



