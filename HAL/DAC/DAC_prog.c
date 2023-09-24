/*
 * DAC_prog.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Mohammed Ramadan
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../MCAL/SYSTIC/SYSTIC_init.h"

#include "DAC_private.h"
#include "DAC_conf.h"
#include "DAC_init.h"

/*define config_DAC_pins []*/
extern HDAC_Config_t config_DAC_pins [] ;

/*constant pointer to point to array of song*/
const u8 * GP_u8PointerToArrayOfSong ;

/*global variadle to store size of array of song*/
static u32  GS_u32SizeOfArray ;
void HDAC_voidInit (void)
{
	/*iterator for for loop*/
	u8 L_u8Counter ;
	for (L_u8Counter = 0 ; L_u8Counter < DAC_PINS_NO ; L_u8Counter ++)
	{
		/*initalize DAC pins as output*/
		MGPIO_voidInit(&config_output_pin_push_pull        ,
				        config_DAC_pins [L_u8Counter].PORT ,
				        config_DAC_pins [L_u8Counter].PIN) ;
	}
	/*initalize system timer*/
	MSTK_voidInit() ;
}

void HDAC_voidPlay (const u8 AR_u8ArrayOfSong [] , u32 A_u32SizeOfArray)
{
	GP_u8PointerToArrayOfSong = AR_u8ArrayOfSong ;
	GS_u32SizeOfArray = A_u32SizeOfArray ;
	/*go to DAC function every 0.125us*/
	MSTK_voidSetIntervalPeriodic(TIME_BETWEEN_EACH_SAMPLE , DAC_ISR);
}

static void DAC_ISR(void)
{
	/*iterator for for array of song*/
    static u32 song_iterator = 0;
    /*iterator for for loop*/
    u8 L_u8Counter ;
    /*loop to DAC pins to outout elment of array (one sample)*/
	for (L_u8Counter = 0 ; L_u8Counter < 8 ; L_u8Counter ++)
	{
		MGPIO_voidSetPinValue(config_DAC_pins [L_u8Counter].PORT ,
				              config_DAC_pins [L_u8Counter].PIN  ,
							  READ_BIT(GP_u8PointerToArrayOfSong [song_iterator] , L_u8Counter)
							                                   ) ;
	}
	/*increment iterator for for array of song until reach to end of array then assign to 0*/
	if(song_iterator < GS_u32SizeOfArray)
	{
		song_iterator++;
	}
	else
	{
		song_iterator = 0 ;
	}

}
