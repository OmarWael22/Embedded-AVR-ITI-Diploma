/*
 * RTOS_Private.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Hardware
 */

#ifndef RTOS_STACK_RTOS_RTOS_PRIVATE_H_
#define RTOS_STACK_RTOS_RTOS_PRIVATE_H_

#define TASK_RESUMED		1
#define TASK_SUSPENDED		0

#define OK				1
#define NOK				2

typedef struct{
	u16 Periodicity;
	void(*TaskFunc)(void);
	u8 state;
	u16 FirstDelay;
}Task_t;

static void RTOS_voidScheduler(void); //Not to be used rather than in .c file

#endif /* RTOS_STACK_RTOS_RTOS_PRIVATE_H_ */
