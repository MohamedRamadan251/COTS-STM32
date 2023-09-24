/*
 * DCMotor_conf.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
 
#ifndef HAL_DC_MOTOR_DCMOTOR_CONF_H_
#define HAL_DC_MOTOR_DCMOTOR_CONF_H_

/*
 **Connection of DC Motor
 *Options of PORT_DC_T1
        *GPIO_PORTA
        *GPIO_PORTB
        *GPIO_PORTC
		
 *Options of PORT_DC_T2
        *GPIO_PORTA
        *GPIO_PORTB
        *GPIO_PORTC
		
 *Options of PIN_DC_T1
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
        *GPIO_PIN11
        *GPIO_PIN12
        *GPIO_PIN13
        *GPIO_PIN14
        *GPIO_PIN15
		
  *Options of PIN_DC_T2
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
        *GPIO_PIN11
        *GPIO_PIN12
        *GPIO_PIN13
        *GPIO_PIN14
        *GPIO_PIN15
 */

/*
 * "for DC_MOTOR_PIN PA13 , PA14 , PA15 are forbidden pins"
 * "for DC_MOTOR_PIN PB2 , PB3 , PB4 are forbidden pins"
 * "for DC_MOTOR_PIN PC13 , PC14 , PC15 are only allowed pins"
 */

#define PORT_DC_T1   GPIO_PORTA
#define PIN_DC_T1    GPIO_PIN0
#define PORT_DC_T2   GPIO_PORTA
#define PIN_DC_T2    GPIO_PIN1

#endif  /*HAL_DC_MOTOR_DCMOTOR_CONF_H_*/
