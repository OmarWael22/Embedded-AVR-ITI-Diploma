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
	LCD_voidInit();
	KPD_voidInit();
	
	u8 Local_u8Key;
	u8 Local_ServoDegree=0;
	while(1){
		Local_u8Key=KPD_u8GetPressedKey();
		
		if(Local_u8Key==KPD_CLEAR){
			LCD_voidClearDisplay();
			Local_ServoDegree=0;
		}
		else if (Local_u8Key==KPD_ENTER){
			
			LCD_voidSendString("  Degree");
			LCD_voidGoTOXY(1,0);
			LCD_voidSendString("applied to servo");
			
			// applying to servo 
			TIMER_voidTimer1Init();
			TIMER_voidTimer1SetOverFlowValue(20000);
			//servo angle 0 to 180 
			// 0 ---> comp match value =1000
			// 180 ---> comp match value 2000
			u16 Local_CompVal= 1000+( (Local_ServoDegree*1000.0)/180.0 );
			
			
			TIMER_voidTimer1ChannelASetCompareMatchValue(Local_CompVal);
			
		}
			
		else if(Local_u8Key!=KPD_NO_PRESS){
			
			LCD_voidSendNumber(Local_u8Key);
			Local_ServoDegree=Local_ServoDegree*10+Local_u8Key;
			
			
		
	}
}
}



