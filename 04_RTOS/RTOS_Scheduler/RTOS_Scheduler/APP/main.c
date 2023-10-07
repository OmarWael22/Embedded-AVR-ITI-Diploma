/*
 * main.c
 *
 * Created: 9/4/2023 10:23:23 PM
 *  Author: Omar
 */ 
#include <avr/io.h>
#include "../RTOS_Scheduler/RTOS/RTOS_interface.h"

void LED1_TASK(void);
void LED2_TASK(void);
void LED3_TASK(void);
int main(void)
{	DDRA=0b00000111;
	RTOS_voidCreateTask(0,1000,LED1_TASK,0);
	RTOS_voidCreateTask(1,2000,LED2_TASK,1);
	RTOS_voidCreateTask(2,3000,LED3_TASK,2);
	/* Replace with your application code */
	while (1)
	{
	}
}
void LED1_TASK(void){
	//TOG LED
	//LED PA0
	PORTA ^= (1<<0);
}
void LED2_TASK(void){
	PORTA ^= (1<<1);
}
void LED3_TASK(void){
	PORTA ^= (1<<2);
}