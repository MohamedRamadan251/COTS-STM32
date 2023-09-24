/*
 * LED_Matrix_conf.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_LED_MATRIX_LED_MATRIX_CONF_H_
#define HAL_LED_MATRIX_LED_MATRIX_CONF_H_

/*maximum number of cols*/
#define LED_MATRIX_ROW  8

/*maximum number of rows*/
#define LED_MATRIX_COL  8

/*define HLED_MATRIX_Config_t*/
typedef struct
{
	u8 PORT ;
	u8 PIN ;
}HLED_MATRIX_Config_t;


#endif /* HAL_LED_MATRIX_LED_MATRIX_CONF_H_ */
