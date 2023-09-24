/*
 * LED_Matrix_private.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_LED_MATRIX_LED_MATRIX_PRIVATE_H_
#define HAL_LED_MATRIX_LED_MATRIX_PRIVATE_H_

/*define number of igsplaying one frame*/
#define FRAME_DELAY 50

/*declaration config_output_pin_push_pull*/
extern MGPIO_Config_t config_output_pin_push_pull ;

/**
	Function Name        : HLED_MTXvoidDisableAllCol
	Function Returns     : void
	Function Arguments   : void
	Function Description : disable all col
*/
static void HLED_MTXvoidDisableAllCol () ;

/**
	Function Name        : HLED_MTXvoidSetRowValue
	Function Returns     : void
	Function Arguments   : u8 A_u8RowValue
	Function Description : write current val to row
*/
static void HLED_MTXvoidSetRowValue   (u8 A_u8RowValue);

/**
	Function Name        : HLED_MTXvoidSetCurrentCol
	Function Returns     : void
	Function Arguments   : u8 A_u8ColNo
	Function Description : enable current col
*/
static void HLED_MTXvoidSetCurrentCol (u8 A_u8ColNo);

#endif /* HAL_LED_MATRIX_LED_MATRIX_PRIVATE_H_ */
