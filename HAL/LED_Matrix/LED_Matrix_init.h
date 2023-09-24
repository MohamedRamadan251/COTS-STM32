/*
 * LED_Matrix_init.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_LED_MATRIX_LED_MATRIX_INIT_H_
#define HAL_LED_MATRIX_LED_MATRIX_INIT_H_

/**
	Function Name        : HLEDMTX_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initial GPIO pins for rows and cols
*/
void HLEDMTX_voidInit (void) ;

/**
	Function Name        : HLED_MTXvoidDisplayFrame
	Function Returns     : void
	Function Arguments   : u8 AR_u8Frame []
	Function Description : display frame
*/
void HLED_MTXvoidDisplayFrame (u8 AR_u8Frame []) ;

#endif /* HAL_LED_MATRIX_LED_MATRIX_INIT_H_ */
