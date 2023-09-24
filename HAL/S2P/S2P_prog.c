/*
 * S2P_prog.c
 *
 *  Created on: Sep 18, 2022
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../MCAL/SYSTIC/SYSTIC_init.h"
#include "S2P_conf.h"
#include "S2P_private.h"
#include "S2P_init.h"

extern HS2P_Config_t config_latch_pin ;
extern HS2P_Config_t config_shift_pin ;
extern HS2P_Config_t config_data_pin  ;

void HS2P_voidInit (void)
{
	MGPIO_voidInit(&config_output_pin_push_pull ,
			        config_latch_pin.PORT       ,
					config_latch_pin.PIN      ) ;

	MGPIO_voidInit(&config_output_pin_push_pull ,
			        config_shift_pin.PORT       ,
			        config_shift_pin.PIN      ) ;

	MGPIO_voidInit(&config_output_pin_push_pull ,
			        config_data_pin.PORT        ,
			        config_data_pin.PIN       ) ;
}

void HS2P_voidSendData (u32 A_u32Data)
{
	s8 L_s8Counter ;
	for (L_s8Counter = ((8 * NUMBER_OF_SHIFT_REG) - 1) ; L_s8Counter >= 0 ; L_s8Counter --)
	{
		MGPIO_voidSetPinValue(config_data_pin.PORT                ,
				              config_data_pin.PIN                 ,
							  READ_BIT (A_u32Data , L_s8Counter)) ;

		HS2P_voidShiftData () ;
	}
	HS2P_voidLatchData () ;
}

static void HS2P_voidShiftData (void)
{
	MGPIO_voidSetPinValue(config_shift_pin.PORT ,
			              config_shift_pin.PIN  ,
			              GPIO_HIGH           ) ;
	MSTK_voidSetBusyWait(1) ;
	MGPIO_voidSetPinValue(config_shift_pin.PORT ,
			              config_shift_pin.PIN  ,
				          GPIO_LOW            ) ;
	MSTK_voidSetBusyWait(1) ;
}

static void HS2P_voidLatchData (void)
{
	MGPIO_voidSetPinValue(config_latch_pin.PORT ,
			              config_latch_pin.PIN  ,
			              GPIO_HIGH           ) ;
	MSTK_voidSetBusyWait(1) ;
	MGPIO_voidSetPinValue(config_latch_pin.PORT ,
			              config_latch_pin.PIN  ,
				          GPIO_LOW           ) ;
	MSTK_voidSetBusyWait(1) ;
}
