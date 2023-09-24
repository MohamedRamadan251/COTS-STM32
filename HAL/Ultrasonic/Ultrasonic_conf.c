/*
 * Ultrasonic_conf.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_init.h"

#include "Ultrasonic_private.h"
#include "Ultrasonic_init.h"

Ultrasonic_t Ultrasonic1_Conf =
{
		.TrigPort = GPIO_PORTB ,
		.TrigPin  = GPIO_PIN6  ,
		.EchoPort = GPIO_PORTB ,
		.EchoPin  = GPIO_PIN0
};
