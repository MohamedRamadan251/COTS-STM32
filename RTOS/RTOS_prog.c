/*
 * RTOS_prog.c
 *
 *  Created on: Sep 19, 2022
 *      Author: Mohammed Ramadan
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/SYSTIC/SYSTIC_init.h"
#include "RTOS_private.h"
#include "RTOS_config.h"
#include "RTOS_init.h"

/*array of tasks in system*/
Task R_structSystemTasks [MAX_NO_OF_TASKS] = {0} ;

/*array to check the timming of task*/
u32   R_u8TaskTiming      [MAX_NO_OF_TASKS]       ;

Task R_structEmpty = {0} ;
u8 RTOS_u8CreatTask (void (*Copy_TaskHandler)(void) ,
		             u32     Copy_u32periodicity    ,
		             u32     Copy_u32priority       ,
					 u32     Copy_u32FirstDelay     )
{
	u8 L_u8ErrorState = 0 ;
	/*verify that the priority index with in the correct range*/
	if (Copy_u32priority < MAX_NO_OF_TASKS)
	{
		if (R_structSystemTasks [Copy_u32priority].TaskHandler == 0)
		{
			/*create task*/
			R_structSystemTasks [Copy_u32priority].TaskHandler  = Copy_TaskHandler ;
			R_structSystemTasks [Copy_u32priority].periodicity  = Copy_u32periodicity ;
			R_u8TaskTiming      [Copy_u32priority]              = Copy_u32FirstDelay ;
			/*inital state of task is runing*/
			R_structSystemTasks [Copy_u32priority].TaskRunState = RunSTate ;
		}
		else
		{
			/*the required periority is already reserved*/
			L_u8ErrorState = 2 ;
		}
	}
	else
	{
		/*wrong priority*/
		L_u8ErrorState = 1 ;
	}
	/*if L_u8ErrorState equal 0 : then the task has been ceriation
	 *                            and you in correct statte
	 *
	 *if L_u8ErrorState equal 1 : error state
	 *                            wrong priority
	 *
	 *if L_u8ErrorState equal 2 : error state
	 *                            the required periority is already reserved
	 */
	return L_u8ErrorState ;
}

void RTOS_voidScheduler (void)
{
	/*counter for for loop*/
	u8 L_u8Counter ;
	/*loop for all  tasks*/
	for (L_u8Counter = 0 ; L_u8Counter < MAX_NO_OF_TASKS ; L_u8Counter ++)
	{
		/*check for the task ceriation*/
		if (R_structSystemTasks [L_u8Counter].TaskHandler != 0)
		{
			/*check for task is running or suspended*/
			if (R_structSystemTasks [L_u8Counter].TaskRunState == RunSTate)
			{
				if (R_u8TaskTiming [L_u8Counter] == 0)
				{
					/*run the task*/
					R_structSystemTasks [L_u8Counter].TaskHandler () ;
					/*reload the periodicity*/
					R_u8TaskTiming [L_u8Counter] = R_structSystemTasks [L_u8Counter].periodicity ;
				}
				else
				{
					R_u8TaskTiming [L_u8Counter] -- ;
				}
			}
		}
	}
}

u8 RTOS_u8DeleteTask (u32 Copy_u32priority)
{
	u8 L_u8ErrorState = 0 ;
	/*verify that the task has been cerieated*/
	if (R_structSystemTasks [Copy_u32priority].TaskHandler != 0)
	{
		/*task exist , execute the removable*/
		R_structSystemTasks [Copy_u32priority] = R_structEmpty ;
	}
	else
	{
		/*Task not exist*/
		L_u8ErrorState = 1 ;
	}
	/*if L_u8ErrorState equal 0 : then the task has been removed
	 *                            and you in correct statte
	 *
	 *if L_u8ErrorState equal 1 : error state
	 *                            Task not exist
	 */
	return L_u8ErrorState ;
}

u8 RTOS_u8SuspendTask (u32 Copy_u32priority)
{
	u8 L_u8ErrorState = 0 ;
	/*verify that the task has been cerieated or not*/
	if (R_structSystemTasks [Copy_u32priority].TaskHandler != 0)
	{
		/*task exist , execute the suspended*/
		R_structSystemTasks [Copy_u32priority].TaskRunState = RunSTate ;
	}
	else
	{
		/*Task not exist*/
		L_u8ErrorState = 1 ;
	}
	/*if L_u8ErrorState equal 0 : then the task has been Suspended
	 *                            and you in correct statte
	 *
	 *if L_u8ErrorState equal 1 : error state
	 *                            Task not exist
	 */
	return L_u8ErrorState ;
}

u8 RTOS_u8ResumeTask (u32 Copy_u32priority)
{
	u8 L_u8ErrorState = 0 ;
		/*verify that the task has been cerieated or not*/
		if (R_structSystemTasks [Copy_u32priority].TaskHandler != 0)
		{
			/*task exist , execute the resumed*/
			R_structSystemTasks [Copy_u32priority].TaskRunState = RunSTate ;
		}
		else
		{
			/*Task not exist*/
			L_u8ErrorState = 1 ;
		}
		/*if L_u8ErrorState equal 0 : then the task has been run
		 *                            and you in correct statte
		 *
		 *if L_u8ErrorState equal 1 : error state
		 *                            Task not exist
		 */
		return L_u8ErrorState ;
}

void RTOS_voidStartOS (void)
{
	MSTK_voidInit() ;
	MSTK_voidSetIntervalPeriodic(TICK_TIME , RTOS_voidScheduler) ;
}

