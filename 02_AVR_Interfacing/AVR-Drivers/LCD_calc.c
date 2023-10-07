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
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"


u32 excute(u16 operand1 ,u16 operand2, u8 operator);
int main(void)
{	
	LCD_voidInit();
	KPD_voidInit();
	u8 OperandCount=0;
	u16 Operand1=0;
	u16 Operand2=0;
	u32 result=0;
	u8 Operator=0;
	u8 ARR_Operators[]={'+','-','/','*'};
	while(1){
		
		u8 key = KPD_u8GetPressedKey();
		
		if(key==KPD_CLEAR){
			
			LCD_voidClearDisplay();
		}
		else if (key==KPD_ENTER){
			LCD_voidSendData('=');
			result=excute(Operand1,Operand2,Operator);
			LCD_voidSendNumber(result);
		}
		else if (ISOperator(key)){
			Operator=key;
			OperandCount++;
			LCD_voidSendData(ARR_Operators[key-14]);
			
			
		}
		else if(key!=KPD_NO_PRESS)
			LCD_voidSendNumber(key);
			if(OperandCount==0)
				Operand1= Operand1*10 + key;
			
			else
				Operand2= Operand2 *10 + key;
	}
	
}
u32 excute(u16 operand1 ,u16 operand2, u8 operator);

