/*
 * SSD_conf.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "SSD_conf.h"

/*connections of ssd1
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HSSD_Config_t config_SSD_1 [] =
{
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN0} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN1} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN2} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN3} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN4} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN5} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN6}
};

/*connections of ssd1
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HSSD_Config_t config_SSD_2 [] =
{
		{.PORT = GPIO_PORTB , .PIN = GPIO_PIN0} ,
		{.PORT = GPIO_PORTB , .PIN = GPIO_PIN1} ,
		{.PORT = GPIO_PORTB , .PIN = GPIO_PIN5} ,
		{.PORT = GPIO_PORTB , .PIN = GPIO_PIN6} ,
		{.PORT = GPIO_PORTB , .PIN = GPIO_PIN7} ,
		{.PORT = GPIO_PORTB , .PIN = GPIO_PIN8} ,
		{.PORT = GPIO_PORTB , .PIN = GPIO_PIN9}
};
