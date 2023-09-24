/*
 * KP_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "KP_private.h"
#include "KP_conf.h"
#include "KP_int.h"

/*delay function*/
#define ARM_DELAY(d)   do{unsigned long int i=(d * 5000); while(i--){asm("nop");}}while(0)

#if KP_COL_PORT == GPIO_PORTC || KP_ROW_PORT == GPIO_PORTC
    #error "Not enogh pins to PORTC"
#endif

#if KP_COL_PORT == GPIO_PORTA && COL_START > GPIO_PIN9
    #error "for PORTA pins 13 , 14 , 15 are forbidden"
#endif

#if KP_COL_PORT == GPIO_PORTB && COL_START < GPIO_PIN4
    #error "for PORTB pins 2 , 3 , 4 are forbidden"
#endif

#if KP_COL_PORT == GPIO_PORTB && COL_START > GPIO_PIN7 && COL_START < GPIO_PIN13
    #error "for PORTB pins 2 , 3 , 4 are forbidden"
#endif


#if KP_ROW_PORT == GPIO_PORTA && ROW_START > GPIO_PIN9
    #error "for PORTA pins 13 , 14 , 15 are forbidden"
#endif

#if KP_ROW_PORT == GPIO_PORTB && ROW_START < GPIO_PIN4
    #error "for PORTB pins 2 , 3 , 4 are forbidden"
#endif

#if KP_ROW_PORT == GPIO_PORTB && ROW_START > GPIO_PIN7 && ROW_START < GPIO_PIN13
    #error "for PORTB pins 2 , 3 , 4 are forbidden"
#endif

#if KP_ROW_PORT == KP_COL_PORT
    #error "KP_ROW_PORT == KP_COL_PORT"
#endif
extern MGPIO_Config_t config_input_pin_pull_up    ;
extern MGPIO_Config_t config_output_pin_push_pull ;

void HKP_voidKpInt (void) 
{
	/* Set Columns as Output & High */
	MGPIO_voidInit (&config_output_pin_push_pull ,
			         KP_COL_PORT                 ,
					 COL_START  +  0             ) ;
	MGPIO_voidInit (&config_output_pin_push_pull ,
				     KP_COL_PORT                 ,
			    	 COL_START  +  1             ) ;
	MGPIO_voidInit (&config_output_pin_push_pull ,
			         KP_COL_PORT                 ,
					 COL_START  +  2             ) ;
	MGPIO_voidInit (&config_output_pin_push_pull ,
				     KP_COL_PORT                 ,
					 COL_START  +  3             ) ;
	
	MGPIO_voidSetPinValue (KP_COL_PORT , COL_START  +  0 , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (KP_COL_PORT , COL_START  +  1 , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (KP_COL_PORT , COL_START  +  2 , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (KP_COL_PORT , COL_START  +  3 , GPIO_HIGH) ;

	/** Set Rows as Inputs & Pulled up */
	MGPIO_voidInit (&config_input_pin_pull_up ,
			         KP_ROW_PORT              ,
					 ROW_START  +  0          ) ;
	MGPIO_voidInit (&config_input_pin_pull_up ,
				     KP_ROW_PORT              ,
			    	 ROW_START  +  1          ) ;
	MGPIO_voidInit (&config_input_pin_pull_up ,
			         KP_ROW_PORT              ,
					 ROW_START  +  2          ) ;
	MGPIO_voidInit (&config_input_pin_pull_up ,
				     KP_ROW_PORT              ,
					 ROW_START  +  3          ) ;
}

u8 HKP_u8GetPressedKey (void)
{
	u8 L_u8Column ;
	u8 L_u8Row    ;
    u8 L_u8PinVal ;
    u8 L_u8PressedKey = NOT_PRESSED;
	
	/**external loop to active current column that be checked */
	for (L_u8Column = COL_START ; L_u8Column < COL_START + 4 ; L_u8Column ++)
	{
		/**active current column by make it output low */
		MGPIO_voidSetPinValue (KP_COL_PORT , L_u8Column , GPIO_LOW) ;
		
		/**internal loop to loop to each row 
		   and check pressed key that common current row and current column */
		for (L_u8Row = ROW_START ; L_u8Row < ROW_START + 4 ; L_u8Row ++)
		{
			
			/** read value of key that common current row and current column */
			L_u8PinVal = MGPIO_voidGetPinValue (KP_ROW_PORT , L_u8Row) ;
			
			/** if key is pressed ====> (MDIO_u8GetPinVal == 0) */
			if (L_u8PinVal == PRESSED)
			{
				/**get the value of the pressed key*/
				L_u8PressedKey = G_u8SwitchVal [L_u8Column - COL_START][L_u8Row - ROW_START] ;
				
				/**wait untill leave the button */
				while (MGPIO_voidGetPinValue (KP_ROW_PORT , L_u8Row) == PRESSED) ;
				
				/** wait 20 ms for debouncing */
				ARM_DELAY (DELAY_FOR_DRBOUNCING) ;
			}
		}
		
		/**deactive current column by make it output low */
		MGPIO_voidSetPinValue (KP_COL_PORT , L_u8Column , GPIO_HIGH) ;
	}
	return L_u8PressedKey ;
}
