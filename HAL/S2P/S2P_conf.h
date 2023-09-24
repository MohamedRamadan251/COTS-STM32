/*
 * S2P_conf.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_S2P_S2P_CONF_H_
#define HAL_S2P_S2P_CONF_H_

/*declaration HS2P_Config_t*/
typedef struct
{
	u8 PORT ;
	u8 PIN  ;
}HS2P_Config_t;

/*define number of S2P used*/
#define NUMBER_OF_SHIFT_REG 2

#endif /* HAL_S2P_S2P_CONF_H_ */
