/*
 * DAC_conf.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "DAC_conf.h"

/*connections of DAC pins
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HDAC_Config_t config_DAC_pins [] =
{
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN0} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN1} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN2} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN3} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN4} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN5} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN6} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN7}
};
