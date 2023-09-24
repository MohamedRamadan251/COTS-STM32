/*
 * S2P_init.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_S2P_S2P_INIT_H_
#define HAL_S2P_S2P_INIT_H_

/**
	Function Name        : HS2P_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initial GPIO pins for S2P
*/
void HS2P_voidInit (void) ;

/**
	Function Name        : HS2P_voidSendData
	Function Returns     : void
	Function Arguments   : u32 A_u32Data
	Function Description : send data to S2P
*/
void HS2P_voidSendData (u32 A_u32Data) ;

#endif /* HAL_S2P_S2P_INIT_H_ */
