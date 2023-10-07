/*
 * RTOS_Interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Hardware
 */

#ifndef RTOS_STACK_RTOS_RTOS_INTERFACE_H_
#define RTOS_STACK_RTOS_RTOS_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
/**
 *
 * ONLY WORKS FOR SMALL TASKS and FUNCTIONS CAUSE OF INTERRUPT
 *
 * */

/*
 * Copy_u16Periodicity  ==> value in msec
 * Copy_u16FirstDelay   ==> value in msec
 */
u8 RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity, void (*Copy_PTR_TaskFunc)(void),u16 Copy_u16FirstDelay);

void RTOS_voidStart(void);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeletTask(u8 Copy_u8Priority);

#endif /* RTOS_STACK_RTOS_RTOS_INTERFACE_H_ */
