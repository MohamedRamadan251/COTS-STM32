/*
 * BUZZER_conf.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohamed Ramadan
 */

#ifndef HAL_BUZZER_BUZZER_CONF_H
#define HAL_BUZZER_BUZZER_CONF_H
/**
 *Options of BUZZER_PORT are :
            *DIO_PORTA
			*DIO_PORTB
			*DIO_PORTC

 *Options of LEDx_PIN are :
            *GPIO_PIN0
			*GPIO_PIN1
			*GPIO_PIN2
			*GPIO_PIN3
			*GPIO_PIN4
			*GPIO_PIN5
			*GPIO_PIN6
			*GPIO_PIN7
			*GPIO_PIN8
			*GPIO_PIN9
			*GPIO_PIN10
			*GPIO_PIN12
			*GPIO_PIN13
			*GPIO_PIN14
			*GPIO_PIN15
*/

/*
 * "for BUZZER_PIN PA13 , PA14 , PA15 are forbidden pins"
 * "for BUZZER_PIN PB2 , PB3 , PB4 are forbidden pins"
 * "for BUZZER_PIN PC13 , PC14 , PC15 are only allowed pins"
 */

/**
 * connection of BUZZER 
*/
#define BUZZER_PORT    GPIO_PORTB
#define BUZZER_PIN     GPIO_PIN15

#endif /* HAL_BUZZER_BUZZER_CONF_H */
