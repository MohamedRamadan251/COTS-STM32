/*
 * IR-init.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_IR_IR_INIT_H_
#define HAL_IR_IR_INIT_H_

/****************************************
       -------------------------------
       |ON/OFF|   Mode   |   Mute    |
       |------|----------|-----------|
       | Puse |Shift Left|Shift Right|
       |------|----------|-----------|
       |  EQ  |   VOL-   |   VOL+    |
       |------|----------|-----------|
       |  0   |   PRT    |   U/SD    |
       |------|----------|-----------|
       |  1   |    2     |     3     |
       |------|----------|-----------|
       |  4   |    5     |     6     |
       |------|----------|-----------|
       |  7   |    8     |     9     |
       -------------------------------
*****************************************/
/*define returns of function HIR_u8GetPushedPuttonOfRemote*/
#define ON_OFF       69
#define MODE         70
#define MUTE         71
#define PUSE         68
#define SHIFT_LEFT   64
#define SHIFT_RIGHT  67
#define EQ           7
#define VOL_MINEUS   21
#define VOL_PLUS     9
#define ZERO         22
#define PRT          25
#define U_SD         13
#define ONE          12
#define TWO          24
#define THREE        94
#define FOUR         8
#define FIVE         28
#define SIX          90
#define SEVEN        66
#define EIGHT        82
#define NINE         74

void HIR_voidInit (void) ;

u8 HIR_u8GetPushedPuttonOfRemote (void) ;

#endif /* HAL_IR_IR_INIT_H_ */
