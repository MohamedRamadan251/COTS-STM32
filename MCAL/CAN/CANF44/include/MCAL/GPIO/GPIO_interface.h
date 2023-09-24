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
 * This module contains the GPIO APIs Decleration
 * ********************************************************************************************************************************
 * This file provides Eleven functions be called from user application
 * 1- MGPIO_voidIntialization: This Function Enables the CLK for All GPIOs Peripherals, with normal or low power mode choosing the mode is made
 * 							   in the configuration file. This call is made inside the "main.c" file.
 * 2- MGPIO_SetPortStatus : This Function Enables & Disables the CLK for GPIOs Peripherals which you enter
 * 	  						This call is made inside the "main.c" file.
 * 3- MGPIO_SetPortStatusLowPower: This Function Enables & Disables the CLK for GPIOs Peripherals which you enter in Low Powe Mode
 * 	  						       This call is made inside the "main.c" file.
 * 4- MGPIO_ResetPortStatus:This Function Resets the Port Clock, this Call is made in the main.c
 * 5- MGPIO_voidSetPinInput:This Function detects the Input Mode For the Pin
 * 							This call is made in the main.c
 * 6- MGPIO_voidSetPinOutputOrAF :This Function sets the PIN to AF or General Output Mode with Spped anf type of needed output.
 * 7- MGPIO_AtomicSet(u8 copy_PinNumber, u8 copy_u8PortNumber):- This Function Sets the Pin Value (High) Using
 * 																Atomic Access
 * 8- MGPIO_AtomicReset(u8 copy_PinNumber, u8 copy_u8PortNumber):- This Function Clears the Pin Value (Low) Using
 * 																  Atomic Access
 * 9-MGPIO_vidLockPin (u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8Statue):- This Function lock or unlock
 * 																					the GPIO pin from being configured
 * 10-MGPIO_voidAF This Function is to enable which AF Function is given to this Pin, This call is made in the main.
 * ********************************************************************************************************************************
 * The Startup Code Sets all the GPIOs to be OFF except some of PORT A and B PINS.
 * Reset values:
 * 0xA800 0000 for port A
 * 0x0000 0280 for port B
 * 0x0000 0000 for other ports
 * ********************************************************************************************************************************
 * Sequence To initialize GPIO CLock
 * - use GPIO Initialization Function  MGPIO_voidIntialization after set the required Configuration in the Configure File
 * - In case you need to Switch The CLK to OFF for the GPIOs use MGPIO_SetPortStatus if normal mode is used &
 *   MGPIO_SetPortStatusLowPower if Low Power mode is used.
 * ********************************************************************************************************************************
 * To SET the Clock State for a peripheral you must choose the BUS which the Peripheral is connected to.
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_INT_H
#define __GPIO_INT_H

/********************************************************/
/* Description : GPIO PINS Definition					*/
/********************************************************/
#define PIN0  PIN_0
#define PIN1  PIN_1
#define PIN2  PIN_2
#define PIN3  PIN_3
#define PIN4  PIN_4
#define PIN5  PIN_5
#define PIN6  PIN_6
#define PIN7  PIN_7
#define PIN8  PIN_8
#define PIN9  PIN_9
#define PIN10 PIN_10
#define PIN11 PIN_11
#define PIN12 PIN_12
#define PIN13 PIN_13
#define PIN14 PIN_14
#define PIN15 PIN_15

#define LCKK         16
#define GPIO_Lock    1
#define GPIO_Unlock  0

#define PORTA PORT_A
#define PORTB PORT_B
#define PORTC PORT_C
#define PORTD PORT_D
#define PORTE PORT_E
#define PORTF PORT_F
#define PORTG PORT_G
#define PORTH PORT_H


#define AF0    AF_0
#define AF1    AF_1
#define AF2    AF_2
#define AF3    AF_3
#define AF4    AF_4
#define AF5    AF_5
#define AF6    AF_6
#define AF7    AF_7
#define AF8    AF_8
#define AF9    AF_9
#define AF10   AF_10
#define AF11   AF_11
#define AF12   AF_12
#define AF13   AF_13
#define AF14   AF_14
#define AF15   AF_15


/*
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode
*/
#define INPUT  INPUT_MODE
#define OUTPUT OUTPUT_MODE
#define AF     AF_MODE
#define ANALOG ANALOG_MODE


/*
OTy: Port x configuration bits (y = 0..15)
These bits are written by software to configure the output type of the I/O port.
0: Output push-pull (reset state)
1: Output open-drain
*/
#define PUSH_PULL  PUSH_PULL_MODE
#define OPEN_DRAIN OPEN_DRAIN_MODE

/*
 * OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O output speed.
00: Low speed
01: Medium speed
10: Fast speed
11: High speed
 */
#define LOW_SPEED     LOW_SPEED_MODE
#define MEDIUM_SPEED  MEDIUM_SPEED_MODE
#define FAST_SPEED    FAST_SPEED_MODE
#define HIGH_SPEED    HIGH_SPEED_MODE


/*
 * Bits 2y:2y+1 PUPDRy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O pull-up or pull-down
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved
 */

#define NOPULL_NOPUSH NOPULL_NOPUSH_MODE
#define PULL_UP       PULL_UP_MODE
#define PULL_DOWN     PULL_DOWN_MODE

/******************************************************************************/
/*Function: MGPIO_voidIntialization		                         			  */
/*I/P Parameters: void			            								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function initialize the GPIO using the RCC Enable		          */
/******************************************************************************/
void MGPIO_voidIntialization (void);

/******************************************************************************/
/*Function: MGPIO_SetPortStatus		                            			  */
/*I/P Parameters: Copy_u8PortNumber		Copy_8uStatus   					  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Change the GPIO state using the RCC Enable		          */
/******************************************************************************/
/*Port Number:-PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH        */
/*Status :- ON, OFF															  */
/******************************************************************************/
void MGPIO_SetPortStatus(u8 Copy_u8PortNumber, u8 Copy_8uStatus);

/******************************************************************************/
/*Function: MGPIO_SetPortStatusLowPower		                            	  */
/*I/P Parameters: Copy_u8PortNumber		Copy_8uStatus   					  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Change the GPIO state using the RCC Enable in Low Power  */
/******************************************************************************/
/*Port Number:-PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH        */
/*Status :- ON, OFF															  */
/******************************************************************************/
void MGPIO_SetPortStatusLowPower(u8 Copy_u8PortNumber, u8 Copy_8uStatus);

/******************************************************************************/
/*Function: MGPIO_ResetPortStatus			                            	  */
/*I/P Parameters: Copy_u8PortNumber		Copy_8uStatus   					  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Change the GPIO reset state using the RCC Enable         */
/******************************************************************************/
/*Port Number:-PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH        */
/*Status :- ON, OFF															  */
/******************************************************************************/
void MGPIO_ResetPortStatus(u8 Copy_u8PortNumber, u8 Copy_8uStatus);

/**********************************************************************************************/
/*Function: MGPIO_voidSetPinInput                           								  */
/*I/P Parameters: Copy_u8PortNumber Copy_u8PinNumber Copy_u8OInputType	Copy_u8PullType 	  */
/*Returns:it returns no thing		                           								  */
/*Desc:This Function Set the GPIOpin to one of inpust Mode			         				  */
/**********************************************************************************************/
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*Port Number: PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH			  		      */
/*Direction:   INPUT, ANALOG																  */
/*Pull Type:   NOPULL_NOPUSH,  PULL_UP,  PULL_DOWN											  */
/**********************************************************************************************/
void MGPIO_voidSetPinInput (u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber, u8 Copy_u8OInputType, u8 Copy_u8PullType);

/**********************************************************************************************/
/*Function: MGPIO_voidSetPinOutputOrAF                         								  */
/*I/P Parameters: Copy_u8PortNumber Copy_u8PinNumber Copy_u8OutputType	Copy_u8OutputSpeed 	  */
/*Returns:it returns no thing		                           								  */
/*Desc:This Function Set the GPIOpin to one of Output Mode			         				  */
/**********************************************************************************************/
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*Port Number:   PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG    			  		      */
/*Output Mode:   OUTPUT, AF															 		  */
/*Output Type:   PUSH_PULL, OPEN_DRAIN														  */
/*Output Speed:  LOW_SPEED,  MEDIUM_SPEED,  FAST_SPEED,   HIGH_SPEED						  */
/**********************************************************************************************/
void MGPIO_voidSetPinOutputOrAF (u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber, u8 Copy_u8OutputMode ,u8 Copy_u8OutputType, u8 Copy_u8OutputSpeed);

/**********************************************************************************************/
/*Function: MGPIO_AtomicSet				                          						      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Set the GPIO pin output value using atomic access                        */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG       				      */
/**********************************************************************************************/
void MGPIO_AtomicSet (u8 copy_u8PortNumber,u8 copy_PinNumber);

/**********************************************************************************************/
/*Function: MGPIO_AtomicReset				                          					      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Reset the GPIO pin output value using atomic access                      */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG 					      */
/**********************************************************************************************/
void MGPIO_AtomicReset( u8 copy_u8PortNumber,u8 copy_PinNumber);


/**********************************************************************************************/
/*Function: MGPIO_voidAF				                          			    		      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber  copy_u8AFNumber 						  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function set the GPIO pin to alternate function with number                       */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG 					      */
/*       AF Number from AF0 to AF15															  */
/**********************************************************************************************/
void MGPIO_voidAF(u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8AFNumber);

#endif /* __GPIO_INT_H */
