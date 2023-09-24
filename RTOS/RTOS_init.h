/*
 * RTOS_init.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef RTOS_RTOS_INIT_H_
#define RTOS_RTOS_INIT_H_

/**
	Function Name        : RTOS_u8CreatTask
	Function Returns     : u8 Error states
	                       *if L_u8ErrorState equal 0 : then the task has been ceriation
	                                                    and you in correct statte

	                       *if L_u8ErrorState equal 1 : error state
	                                                    wrong priority

	                       *if L_u8ErrorState equal 2 : error state
	                                                    the required periority is already reserved
	Function Arguments   : void (*Copy_TaskHandler)(void)
                           u32     Copy_periodicity
                           u32     Copy_priority
                           u32     Copy_FirstDelay
	Function Description : cereate task into stack
*/
u8 RTOS_u8CreatTask (void (*Copy_TaskHandler)(void),
		             u32     Copy_periodicity        ,
		             u32     Copy_priority           ,
					 u32     Copy_FirstDelay       ) ;

/**
	Function Name        : RTOS_voidScheduler
	Function Returns     : void
	Function Arguments   : void
	Function Description : call task at certain time
*/
void RTOS_voidScheduler (void) ;

/**
	Function Name        : RTOS_u8DeleteTask
	Function Returns     : u8 Error states
                           *if L_u8ErrorState equal 0 : then the task has been removed
	                                                    and you in correct statte

                           *if L_u8ErrorState equal 1 : error state
	                                                    Task not exist
	Function Arguments   : u32 Copy_periodicity
	Function Description : delete task from stack
*/
u8 RTOS_u8DeleteTask (u32 Copy_priority) ;

/**
	Function Name        : RTOS_u8ResumeTask
	Function Returns     : u8 Error states
                           *if L_u8ErrorState equal 0 : then the task has been resummed
	                                                    and you in correct statte

                           *if L_u8ErrorState equal 1 : error state
	                                                    Task not exist
	Function Arguments   : u32 Copy_periodicity
	Function Description : resume task
*/
u8 RTOS_u8ResumeTask (u32 Copy_priority) ;

/**
	Function Name        : RTOS_u8SuspendTask
	Function Returns     : u8 Error states
                           *if L_u8ErrorState equal 0 : then the task has been suspended
	                                                    and you in correct statte

                           *if L_u8ErrorState equal 1 : error state
	                                                    Task not exist
	Function Arguments   : u32 Copy_periodicity
	Function Description : suspend task
*/
u8 RTOS_u8SuspendTask (u32 Copy_priority) ;

/**
	Function Name        : RTOS_u8SuspendTask
	Function Returns     : void
	Function Arguments   : void
	Function Description : start os to start systic to call schedular
*/
void RTOS_voidStartOS (void) ;
#endif /* RTOS_RTOS_INIT_H_ */
