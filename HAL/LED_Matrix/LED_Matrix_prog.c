/*
 * LED_Matrix_prog.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../HAL/S2P/S2P_init.h"
#include "../../MCAL/SYSTIC/SYSTIC_init.h"
#include "LED_Matrix_private.h"
#include "LED_Matrix_conf.h"
#include "LED_Matrix_init.h"

extern HLED_MATRIX_Config_t config_led_matrix_row [] ;
extern HLED_MATRIX_Config_t config_led_matrix_col [] ;
void HLEDMTX_voidInit (void)
{
	/*iterator for for loop*/
	u8 L_u8Counter ;
	for (L_u8Counter = 0 ; L_u8Counter < LED_MATRIX_ROW ; L_u8Counter ++)
	{
		/*initalize col pins as output*/
		MGPIO_voidInit(&config_output_pin_push_pull              ,
				        config_led_matrix_row [L_u8Counter].PORT ,
						config_led_matrix_row [L_u8Counter].PIN) ;
	}
	for (L_u8Counter = 0 ; L_u8Counter < LED_MATRIX_ROW ; L_u8Counter ++)
	{
		/*initalize row pins as output*/
		MGPIO_voidInit(&config_output_pin_push_pull      ,
				config_led_matrix_col [L_u8Counter].PORT ,
				config_led_matrix_col [L_u8Counter].PIN) ;
	}
	/*initalize system timer*/
	MSTK_voidInit() ;
}

void HLED_MTXvoidDisplayFrame (u8 AR_u8Frame [])
{
	/*iterator for first for loop*/
	u32 L_u8Counter1  ;
	/*iterator for nested for loop*/
	u8  L_u8Counter2 ;
	for (L_u8Counter1 = 0 ; L_u8Counter1 < FRAME_DELAY ; L_u8Counter1 ++)
	{
		for (L_u8Counter2 = 0 ; L_u8Counter2 < LED_MATRIX_COL ; L_u8Counter2 ++)
		{
			/*disable all columns*/
			HLED_MTXvoidDisableAllCol () ;
			/*set row value*/
			HLED_MTXvoidSetRowValue   (~AR_u8Frame [L_u8Counter2]) ;
			/*set current columns*/
			HLED_MTXvoidSetCurrentCol (L_u8Counter2) ;
			/*delay for suitable frequancy*/
			MSTK_voidSetBusyWait(3) ; /*3 milli seconds*/
		}
	}
}

static void HLED_MTXvoidDisableAllCol ()
{
	/*iterator for for loop*/
	u8 L_u8Counter ;
	for (L_u8Counter = 0 ; L_u8Counter < LED_MATRIX_COL ; L_u8Counter ++)
	{
		/*disable all cols as first step*/
		MGPIO_voidSetPinValue(config_led_matrix_col [L_u8Counter].PORT ,
				              config_led_matrix_col [L_u8Counter].PIN  , GPIO_LOW) ;
	}
}

static void HLED_MTXvoidSetRowValue   (u8 A_u8RowValue)
{
	/*iterator for for loop*/
	u8 L_u8Counter ;
	/*set row value*/
	for (L_u8Counter = 0 ; L_u8Counter < LED_MATRIX_COL ; L_u8Counter ++)
	{
		MGPIO_voidSetPinValue(config_led_matrix_row [L_u8Counter].PORT ,
				              config_led_matrix_row [L_u8Counter].PIN  ,
							  READ_BIT (A_u8RowValue , L_u8Counter))   ;
	}
}

static void HLED_MTXvoidSetCurrentCol (u8 A_u8ColNo)
{
	/*enable current col*/
	MGPIO_voidSetPinValue(config_led_matrix_col [A_u8ColNo].PORT ,
					      config_led_matrix_col [A_u8ColNo].PIN  , GPIO_HIGH) ;
}
