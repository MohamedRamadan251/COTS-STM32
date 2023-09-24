/*
 * S2P_conf.c
 *
 *  Created on: Sep 18, 2022
 *      Author: Mohammed Ramadan
 */




#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "S2P_conf.h"

/*define latch pin
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HS2P_Config_t config_latch_pin =
{
		.PORT = GPIO_PORTA ,
		.PIN  = GPIO_PIN0
};

/*define shift pin
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HS2P_Config_t config_shift_pin =
{
		.PORT = GPIO_PORTA ,
		.PIN  = GPIO_PIN1
};

/*define data pin
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HS2P_Config_t config_data_pin =
{
		.PORT = GPIO_PORTA ,
		.PIN  = GPIO_PIN2
};
