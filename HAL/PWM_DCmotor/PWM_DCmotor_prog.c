/*
 * PWM_DCmotor_prog.c
 *
 *  Created on: Mar 8, 2023
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/Timer/Timer_init.h"

#include "PWM_DCmotor_private.h"
#include "PWM_DCmotor_conf.h"
#include "PWM_DCmotor_init.h"


void HDC_init (DCmotor_Type M1)
{
	MTimer_voidInit(M1.FirstTimerType) ;
	if (M1.FirstTimerType != M1.SecondTimerType)
	{
		MTimer_voidInit(M1.SecondTimerType) ;
	}
}

void HDC_CounterClockWise  (DCmotor_Type M1 , u16 A_u16CaptureValue )
{
	MTimer_voidPWM(M1.FirstTimerType     ,
			       M1.FirstChannelNumber ,
				   A_u16CaptureValue
				   )                     ;

	MTimer_voidPWM(M1.SecondTimerType     ,
                   M1.SecondChannelNumber ,
				   0
				   )                      ;
}

void HDC_ClockWise  (DCmotor_Type M1 , u16 A_u16CaptureValue)
{
	MTimer_voidPWM(M1.FirstTimerType     ,
				   M1.FirstChannelNumber ,
				   0
				   )                     ;

	MTimer_voidPWM(M1.SecondTimerType     ,
	               M1.SecondChannelNumber ,
				   A_u16CaptureValue
				   )                      ;
}

void HDC_Stop  (DCmotor_Type M1)
{
	MTimer_voidPWM(M1.FirstTimerType     ,
				   M1.FirstChannelNumber ,
				   0
				   )                     ;

	MTimer_voidPWM(M1.SecondTimerType     ,
	               M1.SecondChannelNumber ,
				   0
				   )                      ;
}
