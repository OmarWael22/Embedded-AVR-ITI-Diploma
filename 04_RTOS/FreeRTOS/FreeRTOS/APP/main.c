/*
 * main.c
 *
 * Created: 8/20/2023 3:27:04 PM
 *  Author: Omar
 */ 


#define F_CPU 8000000UL
#include "../MCAL/DIO_interface.h"
//free rtos
#include "../FreeRTOS/FreeRTOS.h"
#include "../FreeRTOS/task.h"
void led1(void *pv);


int main(void)
{	
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	xTaskCreate(led1,NULL_PTR,100,NULL_PTR,1,NULL_PTR);
	vTaskStartScheduler();
	while(1);
}

void led1(void *pv){
	
	static u8 state=0;
	while(1){
		DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,state);
		TOG_BIT(state,0);
		vTaskDelay(500);
		
	}
	
}