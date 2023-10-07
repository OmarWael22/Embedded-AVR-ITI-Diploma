/*
 * RTOS_Program.c

 *
 *  Created on: Sep 4, 2023
 *      Author: Hardware
 */

#include"../../LIB/STD_TYPES.h"

#include"../GIE/GIE_Interface.h"
#include"../TIMER0/TIMER_Interface.h"

#include"RTOS_Private.h"
#include"RTOS_Config.h"
#include"RTOS_Interface.h"

static Task_t SystemTasks[TASK_MAX_NUM]={{NULL_PTR}};   //First element of first struct ==>null ,  others ==>
													//{{NULL,0},{0,0},{0,0}}

u8 RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity, void (*Copy_PTR_TaskFunc)(void),u16 Copy_u16FirstDelay){
	u8 Local_u8ErrorState = OK;
	if(SystemTasks[Copy_u8Priority].TaskFunc == NULL_PTR){
		//put task according to it's priority
		SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc = Copy_PTR_TaskFunc;
		SystemTasks[Copy_u8Priority].state = TASK_RESUMED;
		SystemTasks[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
	}
	else{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

void RTOS_voidStart(void){
	//Tick every 1msec
	TIMER_voidTimer0CompareMatchCallBack(RTOS_voidScheduler);//Function name is PTR to first Line in it
	GIE_voidEnableGlobalInterrupt();
	TIMER_Timer0InitCTC();
}

void RTOS_voidSuspendTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].state  = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].state  = TASK_RESUMED;
}

void RTOS_voidDeletTask(u8 Copy_u8Priority){
	SystemTasks[Copy_u8Priority].TaskFunc = NULL_PTR;
}

static void RTOS_voidScheduler(void){
	u8 Local_u8TaskCounter;
	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_MAX_NUM;Local_u8TaskCounter++){
		if(SystemTasks[Local_u8TaskCounter].state == TASK_RESUMED){
			if(SystemTasks[Local_u8TaskCounter].FirstDelay == 0){
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL_PTR){
					SystemTasks[Local_u8TaskCounter].TaskFunc();	}
				SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity - 1;
			}
			else{
				SystemTasks[Local_u8TaskCounter].FirstDelay -- ;
			}
		}
	}

}





