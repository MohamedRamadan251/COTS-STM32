/*
 * IR_conf.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "IR_conf.h"

/*connections of IR pin
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HIR_config_t IR_config =
{
		.PORT = GPIO_PORTB ,
		.PIN  = GPIO_PIN15
};
