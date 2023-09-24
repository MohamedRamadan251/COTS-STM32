/*
 * TFT_private.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_TFT_TFT_PRIVATE_H_
#define HAL_TFT_TFT_PRIVATE_H_

#define SLPOUT_CMD         0x11
#define COLOR_MODE_CMD     0x3A
#define COLOR_MODE_ID      0x05
#define DISPLAY_ON_CMD     0x29
#define SET_X_POS_CMD      0x2A
#define SET_Y_POS_CMD      0x2B
#define SET_SEND_IMAGE_CMD 0x2C
#define SIZE_OF_IMAGE      20479

const u8 FONT_CHARS[96][7] =
{
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0  }, // (space)
		{ 4 , 4 , 4 , 4 , 4 , 0 , 4  }, // !
		{ 10, 10, 10, 0 , 0 , 0 , 0  }, // "
		{ 10, 10, 31, 10, 31, 10, 10 }, // #
		{ 4 , 30, 5 , 14, 20, 15, 4  }, // $
		{ 3 , 19, 8 , 4 , 2 , 25, 24 }, // %
		{ 6 , 9 , 5 , 2 , 21, 9 , 22 }, // &
		{ 6 , 4 , 2 , 0 , 0 , 0 , 0  }, // '
		{ 8 , 4 , 2 , 2 , 2 , 4 , 8  }, // (
		{ 2 , 4 , 8 , 8 , 8 , 4 , 2  }, // )
		{ 0 , 10, 4 , 31, 4 , 10, 0  }, // *
		{ 0 , 4 , 4 , 31, 4 , 4 , 0  }, // +
		{ 0 , 0 , 0 , 0 , 6 , 4 , 2  }, // ,
		{ 0 , 0 , 0 , 31, 0 , 0 , 0  }, // -
		{ 0 , 0 , 0 , 0 , 0 , 6 , 6  }, // .
		{ 0 , 16, 8 , 4 , 2 , 1 , 0  }, // /
		{ 14, 17, 25, 21, 19, 17, 14 }, // 0
		{ 4 , 6 , 4 , 4 , 4 , 4 , 14 }, // 1
		{ 14, 17, 16, 8 , 4 , 2 , 31 }, // 2
		{ 31, 8 , 4 , 8 , 16, 17, 14 }, // 3
		{ 8 , 12, 10, 9 , 31, 8 , 8  }, // 4
		{ 31, 1 , 15, 16, 16, 17, 14 }, // 5
		{ 12, 2 , 1 , 15, 17, 17, 14 }, // 6
		{ 31, 16, 8 , 4 , 2 , 2 , 2  }, // 7
		{ 14, 17, 17, 14, 17, 17, 14 }, // 8
		{ 14, 17, 17, 30, 16, 8 , 6  }, // 9
		{ 0 , 6 , 6 , 0 , 6 , 6 , 0  }, // :
		{ 16, 8 , 4 , 2 , 4 , 8 , 16 }, // ;
		{ 16, 8 , 4 , 2 , 4 , 8 , 16 }, // <
		{ 0 , 0 , 31, 0 , 31, 0 , 0  }, // =
		{ 1 , 2 , 4 , 8 , 4 , 2 , 1  }, // >
		{ 14, 17, 16, 8 , 4 , 0 , 4  }, // ?
		{ 14, 17, 16, 22, 21, 21, 14 }, // @
		{ 14, 17, 17, 17, 31, 17, 17 }, // A
		{ 15, 17, 17, 15, 17, 17, 15 }, // B
		{ 14, 17, 1 , 1 , 1 , 17, 14 }, // C
		{ 7 , 9 , 17, 17, 17, 9 , 7  }, // D
		{ 31, 1 , 1 , 15, 1 , 1 , 31 }, // E
		{ 31, 1 , 1 , 7 , 1 , 1 , 1  }, // F
		{ 14, 17, 1 , 1 , 25, 17, 14 }, // G
		{ 17, 17, 17, 31, 17, 17, 17 }, // H
		{ 14, 4 , 4 , 4 , 4 , 4 , 14 }, // I
		{ 28, 8 , 8 , 8 , 8 , 9 , 6  }, // J
		{ 17, 9 , 5 , 3 , 5 , 9 , 17 }, // K
		{ 1 , 1 , 1 , 1 , 1 , 1 , 31 }, // L
		{ 17, 27, 21, 17, 17, 17, 17 }, // M
		{ 17, 17, 19, 21, 25, 17, 17 }, // N
		{ 14, 17, 17, 17, 17, 17, 14 }, // O
		{ 15, 17, 17, 15, 1 , 1 , 1  }, // P
		{ 14, 17, 17, 17, 21, 9 , 22 }, // Q
		{ 15, 17, 17, 15, 5 , 9 , 17 }, // R
		{ 30, 1 , 1 , 14, 16, 16, 15 }, // S
		{ 31, 4 , 4 , 4 , 4 , 4 , 4  }, // T
		{ 17, 17, 17, 17, 17, 17, 14 }, // U
		{ 17, 17, 17, 17, 17, 10, 4  }, // V
		{ 17, 17, 17, 21, 21, 27, 17 }, // W
		{ 17, 17, 10, 4 , 10, 17, 17 }, // X
		{ 17, 17, 10, 4 , 4 , 4 , 4  }, // Y
		{ 31, 16, 8 , 4 , 2 , 1 , 31 }, // Z
		{ 28, 4 , 4 , 4 , 4 , 4 , 28 }, // [
		{ 0 , 1 , 2 , 4 , 8 , 16, 0  }, // "\"
		{ 7 , 4 , 4 , 4 , 4 , 4 , 7  }, // ]
		{ 4 , 10, 17, 0 , 0 , 0 , 0  }, // ^
		{ 0 , 0 , 0 , 0 , 0 , 0 , 31 }, // _
		{ 2 , 4 , 8 , 0 , 0 , 0 , 0  }, // `
		{ 0 , 0 , 14, 16, 30, 17, 30 }, // a
		{ 1 , 1 , 13, 19, 17, 17, 15 }, // b
		{ 0 , 0 , 14, 1 , 1 , 17, 14 }, // c
		{ 16, 16, 22, 25, 17, 17, 30 }, // d
		{ 0 , 0 , 14, 17, 31, 1 , 14 }, // e
		{ 12, 18, 2 , 7 , 2 , 2 , 2  }, // f
		{ 0 , 0 , 30, 17, 30, 16, 12 }, // g
		{ 1 , 1 , 13, 19, 17, 17, 17 }, // h
		{ 4 , 0 , 6 , 4 , 4 , 4 , 14 }, // i
		{ 8 , 0 , 12, 8 , 8 , 9 , 6  }, // j
		{ 2 , 2 , 18, 10, 6 , 10, 18 }, // k
		{ 6 , 4 , 4 , 4 , 4 , 4 , 14 }, // l
		{ 0 , 0 , 10, 21, 21, 17, 17 }, // m
		{ 0 , 0 , 13, 19, 17, 17, 17 }, // n
		{ 0 , 0 , 14, 17, 17, 17, 14 }, // o
		{ 0 , 0 , 15, 17, 15, 1 , 1  }, // p
		{ 0 , 0 , 22, 25, 30, 16, 16 }, // q
		{ 0 , 0 , 13, 19, 1 , 1 , 1  }, // r
		{ 0 , 0 , 14, 1 , 14, 16, 15 }, // s
		{ 2 , 2 , 7 , 2 , 2 , 18, 12 }, // t
		{ 0 , 0 , 17, 17, 17, 25, 22 }, // u
		{ 0 , 0 , 17, 17, 17, 10, 4  }, // v
		{ 0 , 0 , 17, 17, 21, 21, 10 }, // w
		{ 0 , 0 , 17, 10, 4 , 10, 17 }, // x
		{ 0 , 0 , 17, 17, 30, 16, 14 }, // y
		{ 0 , 0 , 31, 8 , 4 , 2 , 31 }, // z
		{ 8 , 4 , 4 , 2 , 4 , 4 , 8  }, // {
		{ 4 , 4 , 4 , 4 , 4 , 4 , 4  }, // |
		{ 2 , 4 , 4 , 8 , 4 , 4 , 2  }, // }
		{ 0 , 4 , 8 , 31, 8 , 4 , 0  }, // ->
		{ 0 , 4 , 2 , 31, 2 , 4 , 0  }, // <-
};

/**
	Function Name        : HTFT_voidWriteCmd
	Function Returns     : void
	Function Arguments   : u8 A_u8SpiType
	Function Description : send command
*/
static void HTFT_voidWriteCmd (u8 A_u8SpiType , u16 A_u16Cmd) ;

/**
	Function Name        : HTFT_voidWriteData
	Function Returns     : void
	Function Arguments   : u8 A_u8SpiType
	Function Description : send data
*/
static void HTFT_voidWriteData (u8 A_u8SpiType , u16 A_u16Data) ;

/**
	Function Name        : HTFT_voidReset
	Function Returns     : void
	Function Arguments   : void
	Function Description : reset sequance of tft
*/
static void HTFT_voidReset (void) ;


#endif /* HAL_TFT_TFT_PRIVATE_H_ */