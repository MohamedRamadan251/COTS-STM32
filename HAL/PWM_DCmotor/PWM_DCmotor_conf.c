/*
 * PWM_DCmotor_conf.c
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


DCmotor_Type M1 =
{
		.FirstTimerType      = TIM2_TYPE     ,
		.SecondTimerType     = TIM2_TYPE     ,
		.FirstChannelNumber  = TIM_CHANNEL_1 ,
		.SecondChannelNumber = TIM_CHANNEL_2
};
