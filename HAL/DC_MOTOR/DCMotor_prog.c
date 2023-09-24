/*
 * DCMotor_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "../DC_MOTOR/DCMotor_conf.h"
#include "../DC_MOTOR/DCMotor_int.h"

#if (PORT_DC_T1 == GPIO_PORTA) || (PORT_DC_T2 == GPIO_PORTA)
    #if PIN_DC_T1 > GPIO_PIN12
        #error  "for PIN_DC_T1 and PORT_DC_T2 PA13 , PA14 , PA15 are forbidden pins"
    #endif
#endif

#if (PORT_DC_T1 == GPIO_PORTB) || (PORT_DC_T2 == GPIO_PORTB)
    #if PIN_DC_T1 >= GPIO_PIN2 && LED_PIN <= GPIO_PIN4
        #error  "for PIN_DC_T1 and PORT_DC_T2 PB2 , PB3 , PB4 are forbidden pins"
    #endif
#endif

#if (PORT_DC_T1 == GPIO_PORTC) || (PORT_DC_T2 == GPIO_PORTC)
    #if PIN_DC_T1 < GPIO_PIN13
        #error  "for PIN_DC_T1 and PORT_DC_T2 PC13 , PC14 , PC15 are only allowed pins"
    #endif
#endif

extern MGPIO_Config_t config_output_pin_push_pull ;
void HDC_voidInt   (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** Set direction of PORT_DC_T1 to output */
	    MGPIO_voidInit(&config_output_pin_push_pull ,
	    		        PORT_DC_T1                  ,
						PIN_DC_T1                 ) ;

		/** Set direction of PORT_DC_T2 to output */
	    MGPIO_voidInit(&config_output_pin_push_pull ,
	    		        PORT_DC_T2                  ,
						PIN_DC_T2                 ) ;
	#endif
}
void HDC_voidRoCw  (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** value of PIN_DC_T1 is one & value of PIN_DC_T2 is zero */
	    MGPIO_voidSetPinValue(PORT_DC_T1 , PIN_DC_T1, GPIO_HIGH) ;
	    MGPIO_voidSetPinValue(PORT_DC_T2 , PIN_DC_T2, GPIO_LOW ) ;
	#endif
}
void HDC_voidRoCcw (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** value of PIN_DC_T1 is zero & value of PIN_DC_T2 is one */
	    MGPIO_voidSetPinValue(PORT_DC_T1 , PIN_DC_T1, GPIO_LOW ) ;
        MGPIO_voidSetPinValue(PORT_DC_T2 , PIN_DC_T2, GPIO_HIGH) ;
	#endif
}
void HDC_voidStop  (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** value of PIN_DC_T1 is zero & value of PIN_DC_T2 is zero */
	    MGPIO_voidSetPinValue(PORT_DC_T1 , PIN_DC_T1, GPIO_LOW) ;
	    MGPIO_voidSetPinValue(PORT_DC_T2 , PIN_DC_T2, GPIO_LOW) ;
	#endif
}
