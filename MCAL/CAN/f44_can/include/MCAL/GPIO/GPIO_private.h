/*******************************************************************************************
* ! Title : GPIO_interface
* ! File Name : GPIO_interface.h
* ! Description : This file has the Prototypes of the Public functions
* ! Compiler : GNU ARM Cross Compiler
* ! Target : STM32F446xxxx Micro-controller
********************************************************************************************/
/*******************************************************************************************
* LOG :
* VERSION    AUTHOR              DATE              DESCRIPTION
* v1.0       Abdelrahman Hossam  27 JAN,2021       - Initial creation
********************************************************************************************/

/*
 * This file is part of the OP Coders Graduation Project.
 * ********************************************************************************************************************************
 * This module contains the GPIO Private Configurations Needed in Source Code
 * ********************************************************************************************************************************
 * To SET the Clock State for a peripheral you must choose the BUS which the Peripheral is connected to.
 */



/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_PRIV_H
#define __GPIO_PRIV_H

#define GPIO_ResetMask (0b1111)
/**************************************************/
/* Description : Definitions for GPIO Base Address */
/**************************************************/
#define GPIOA ((volatile GPIOX*) 0x40020000)
#define GPIOB ((volatile GPIOX*) 0x40020400)
#define GPIOC ((volatile GPIOX*) 0x40020800)
#define GPIOD ((volatile GPIOX*) 0x40020C00)
#define GPIOE ((volatile GPIOX*) 0x40021000)
#define GPIOF ((volatile GPIOX*) 0x40021400)
#define GPIOG ((volatile GPIOX*) 0x40021800)
#define GPIOH ((volatile GPIOX*) 0x40021C00)


/********************************************************/
/* Description : GPIO Registers mapping using structure */
/********************************************************/
typedef struct
{

	/*GPIO port mode register*/
	volatile u32 GPIOx_MODER;
	volatile u32 GPIOx_OTYPER;
	volatile u32 GPIOx_OSPEEDER;
	volatile u32 GPIOx_PUPDR;

	/*Port input data register*/
	volatile u32 GPIO_IDR;
	/*Port output data register*/
	volatile u32 GPIO_ODR;
	/*Port bit set/reset register*/
	volatile u32 GPIO_BSRR;
	/*Port configuration lock register*/
	volatile u32 GPIO_LCKR;
	volatile u32 GPIOx_AFRL;
	volatile u32 GPIOx_AFRH;

}GPIOX;

/********************************************************/
/* Description : GPIO PINS Definition					*/
/********************************************************/
#define PIN_0   0
#define PIN_1   1
#define PIN_2   2
#define PIN_3   3
#define PIN_4   4
#define PIN_5   5
#define PIN_6   6
#define PIN_7   7
#define PIN_8   8
#define PIN_9   9
#define PIN_10  10
#define PIN_11  11
#define PIN_12  12
#define PIN_13  13
#define PIN_14  14
#define PIN_15  15

#define LCKK         16
#define GPIO_Lock    1
#define GPIO_Unlock  0

#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4
#define PORT_E 5
#define PORT_F 6
#define PORT_G 7
#define PORT_H 8




/*
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode
*/
#define INPUT_MODE  0
#define OUTPUT_MODE 1
#define AF_MODE     2
#define ANALOG_MODE 3


/*
OTy: Port x configuration bits (y = 0..15)
These bits are written by software to configure the output type of the I/O port.
0: Output push-pull (reset state)
1: Output open-drain
*/
#define PUSH_PULL_MODE  0
#define OPEN_DRAIN_MODE 1

/*
 * OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O output speed.
00: Low speed
01: Medium speed
10: Fast speed
11: High speed
 */
#define LOW_SPEED_MODE     0
#define MEDIUM_SPEED_MODE  1
#define FAST_SPEED_MODE    2
#define HIGH_SPEED_MODE    3


/*
 * Bits 2y:2y+1 PUPDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O pull-up or pull-down
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved
 */

#define NOPULL_NOPUSH_MODE  0
#define PULL_UP_MODE        1
#define PULL_DOWN_MODE      2


#define NORMAL_MODE   1
#define LOW_POWER_MODE 0


#define AF_0 	0
#define AF_1 	1
#define AF_2 	2
#define AF_3 	3
#define AF_4 	4
#define AF_5 	5
#define AF_6 	6
#define AF_7 	7
#define AF_8 	8
#define AF_9 	9
#define AF_10	10
#define AF_11	11
#define AF_12	12
#define AF_13	13
#define AF_14	14
#define AF_15   15


#endif /* __GPIO_PRIV_H */
