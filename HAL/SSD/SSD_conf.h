/*
 * SSD_conf.h
 *
 *  Created on: May 24, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_SSD_SSD_CONF_H_
#define HAL_SSD_SSD_CONF_H_
/**
*Options of A_u8SsdId 
       *SSD1_ID
	   *SSD2_ID

*Options of A_u8Num 
       *DISPLAY_0
	   *DISPLAY_1 
	   *DISPLAY_2 
	   *DISPLAY_3 
	   *DISPLAY_4 
	   *DISPLAY_5 
	   *DISPLAY_6 
	   *DISPLAY_7 
	   *DISPLAY_8 
	   *DISPLAY_9 
    OR any integer from 0 to 9
	   
*/
/*define HSSD_Config_t*/
typedef struct
{
	u8 PORT ;
	u8 PIN ;
}HSSD_Config_t;

/**
*SSD PORT Control  
*Options :
       *GPIO_PORTA
	   *GPIO_PORTB
	   *GPIO_PORTC
*/
#define SSD1EN_PORT GPIO_PORTC
#define SSD2EN_PORT GPIO_PORTC

/**
*SSD PIN Control  
*Options :
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
 *forbidden pins
 *PORTA ---> PIN13 , PIN14 , PIN15
 *PORTB ---> PIN2  , PIN3  , PIN4
*/
#define SSD1EN_PIN  GPIO_PIN13
#define SSD2EN_PIN  GPIO_PIN14

/**
*SSD type  
*Options :
       *COMM_CATHODE
	   *COMM_ANODE
*/
#define SSD_TYPE   COMM_CATHODE

#endif /* HAL_SSD_SSD_CONF_H_ */
