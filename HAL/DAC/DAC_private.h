/*
 * DAC_private.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_DAC_DAC_PRIVATE_H_
#define HAL_DAC_DAC_PRIVATE_H_

/*define number of DAC pins*/
#define DAC_PINS_NO  8

#define TIME_BETWEEN_EACH_SAMPLE 0.125
/*declaration config_output_pin_push_pull*/
extern MGPIO_Config_t config_output_pin_push_pull ;

/*
	Function Name        : DAC_ISR
	Function Returns     : void
	Function Arguments   : void
	Function Description : play song selected (output elements of array every 125us)
*/
static void DAC_ISR(void) ;

#endif /* HAL_DAC_DAC_PRIVATE_H_ */
