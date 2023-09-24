/*
 * DAC_init.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_DAC_DAC_INIT_H_
#define HAL_DAC_DAC_INIT_H_

/*
	Function Name        : HDAC_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize dac pins as output and initialize systic
*/
void HDAC_voidInit (void) ;

/*
	Function Name        : HDAC_voidPlay
	Function Returns     : void
	Function Arguments   : const u8 AR_u8ArrayOfSong [] , u32 A_u32SizeOfArray
	Function Description : play song selected
*/
void HDAC_voidPlay (const u8 AR_u8ArrayOfSong [] , u32 A_u32SizeOfArray) ;

#endif /* HAL_DAC_DAC_INIT_H_ */
