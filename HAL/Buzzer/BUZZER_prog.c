/*
 * BUZZER_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "BUZZER_int.h"
#include "BUZZER_private.h"
#include "BUZZER_conf.h"

#if BUZZER_PORT == GPIO_PORTA
    #if BUZZER_PIN > GPIO_PIN12
        #error  "for BUZZER_PIN PA13 , PA14 , PA15 are forbidden pins"
    #endif
#endif

#if BUZZER_PORT == GPIO_PORTB
    #if BUZZER_PIN >= GPIO_PIN2 && BUZZER_PIN <= GPIO_PIN4
        #error  "for BUZZER_PIN PB2 , PB3 , PB4 are forbidden pins"
    #endif
#endif

#if BUZZER_PORT == GPIO_PORTC
    #if BUZZER_PIN < GPIO_PIN13
        #error  "for BUZZER_PIN PC13 , PC14 , PC15 are only allowed pins"
    #endif
#endif

extern MGPIO_Config_t config_output_pin_push_pull ;

void HBUZZER_voidBUZZERInitial (void)
{
	/** select direction of buzzer as output */
	MGPIO_voidInit(&config_output_pin_push_pull ,
				    BUZZER_PORT                 ,
				    BUZZER_PIN                  ) ;
}

void HBUZZER_voidBUZZEROn (void)
{
	/**make buzzer on (it's pin is high)*/
	MGPIO_voidSetPinValue(BUZZER_PORT , BUZZER_PIN , GPIO_HIGH) ;
}

void HBUZZER_voidBUZZEROff (void)
{
	/**make buzzer off (it's pin is low)*/
	MGPIO_voidSetPinValue(BUZZER_PORT , BUZZER_PIN , GPIO_LOW) ;
}

void HBUZZER_voidBUZZERToggle (void)
{
	/**inverse the status of buzzer*/
	MGPIO_voidTogPinValue(BUZZER_PORT , BUZZER_PIN) ;
}
