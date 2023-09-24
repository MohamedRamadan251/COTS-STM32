/*
 * LED_Matrix_conf.c
 *
 *  Created on: Sep 18, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "LED_Matrix_conf.h"

/*connections of rows
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HLED_MATRIX_Config_t config_led_matrix_row [] =
{
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN0} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN1} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN2} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN3} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN4} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN5} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN6} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN7}
} ;

/*connections of cols
*forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
 */
HLED_MATRIX_Config_t config_led_matrix_col [] =
{
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN8 } ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN9 } ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN10} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN11} ,
		{.PORT = GPIO_PORTA , .PIN = GPIO_PIN12} ,
		{.PORT = GPIO_PORTC , .PIN = GPIO_PIN13} ,
		{.PORT = GPIO_PORTC , .PIN = GPIO_PIN14} ,
		{.PORT = GPIO_PORTC , .PIN = GPIO_PIN15}
} ;
