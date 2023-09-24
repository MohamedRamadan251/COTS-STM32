/*
 * KP_conf.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohamed Ramadan
 */

#ifndef HAL_KEY_PAD_KP_CONF_H
#define HAL_KEY_PAD_KP_CONF_H
#include "KP_private.h"
#include "KP_conf.h"
#include "KP_int.h"
/**
 * Key Pad connections 
 * Options :
        *GPIO_PORTA
		*GPIO_PORTB
*/
#define KP_ROW_PORT  GPIO_PORTA
#define KP_COL_PORT  GPIO_PORTB

/**
 * Options of first Column connection 
 */ 
#define COL_START   GPIO_PIN5

/**
 * Options of first Row connection 
 */
#define ROW_START   GPIO_PIN7

/**
 *Define Size of Rows & Columns
 */
#define ROW_SIZE    4
#define COL_SIZE    4


#endif /* HAL_KEY_PAD_KP_CONF_H */
