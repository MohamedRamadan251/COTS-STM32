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
 * This module contains the GPIO APIs Implementation
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


/****************************************/
/* 			     Directives 			*/
/****************************************/

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/LIB.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/MCAL/RCC/RCC_interface.h"
#include "../include/MCAL/RCC/RCC_private.h"
#include "../include/MCAL/RCC/RCC_configuration.h"

#include "../include/MCAL/GPIO/GPIO_interface.h"
#include "../include/MCAL/GPIO/GPIO_private.h"
#include "../include/MCAL/GPIO/GPIO_configuration.h"

// ----------------------------------------------------------------------------

/******************************************************************************/
/*Function: MGPIO_voidIntialization		                         			  */
/*I/P Parameters: void			            								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function initialize the GPIO using the RCC Enable		          */
/******************************************************************************/
void MGPIO_voidIntialization (void)
{

#if POWER_MODE == NORMAL_MODE
	MRCC_voidSetPeripheralclock(AHB1,GPIOA_Enable,GPIO_PORTA_STATUS);
	MRCC_voidSetPeripheralclock(AHB1,GPIOB_Enable,GPIO_PORTB_STATUS);
	MRCC_voidSetPeripheralclock(AHB1,GPIOC_Enable,GPIO_PORTC_STATUS);
	MRCC_voidSetPeripheralclock(AHB1,GPIOD_Enable,GPIO_PORTD_STATUS);
	MRCC_voidSetPeripheralclock(AHB1,GPIOE_Enable,GPIO_PORTE_STATUS);
	MRCC_voidSetPeripheralclock(AHB1,GPIOF_Enable,GPIO_PORTF_STATUS);
	MRCC_voidSetPeripheralclock(AHB1,GPIOG_Enable,GPIO_PORTG_STATUS);
	MRCC_voidSetPeripheralclock(AHB1,GPIOH_Enable,GPIO_PORTH_STATUS);
#elif POWER_MODE == LOW_POWER_MODE
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOA_Enable,GPIO_PORTA_STATUS);
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOB_Enable,GPIO_PORTB_STATUS);
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOC_Enable,GPIO_PORTC_STATUS);
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOD_Enable,GPIO_PORTD_STATUS);
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOE_Enable,GPIO_PORTE_STATUS);
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOF_Enable,GPIO_PORTF_STATUS);
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOG_Enable,GPIO_PORTG_STATUS);
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,GPIOH_Enable,GPIO_PORTH_STATUS);
#endif
}
/******************************************************************************/
/*Function: MGPIO_SetPortStatus		                            			  */
/*I/P Parameters: Copy_u8PortNumber		Copy_8uStatus   					  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Change the GPIO state using the RCC Enable		          */
/******************************************************************************/
/*Port Number:-PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH        */
/*Status :- ON, OFF															  */
/******************************************************************************/
void MGPIO_SetPortStatus(u8 Copy_u8PortNumber, u8 Copy_8uStatus)
{
	MRCC_voidSetPeripheralclock(AHB1,Copy_u8PortNumber,Copy_8uStatus);
}
/******************************************************************************/
/*Function: MGPIO_SetPortStatusLowPower		                            	  */
/*I/P Parameters: Copy_u8PortNumber		Copy_8uStatus   					  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Change the GPIO state using the RCC Enable in Low Power  */
/******************************************************************************/
/*Port Number:-PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH        */
/*Status :- ON, OFF															  */
/******************************************************************************/
void MGPIO_SetPortStatusLowPower(u8 Copy_u8PortNumber, u8 Copy_8uStatus)
{
	MRCC_voidSetPeripheralclockLowPowerMode(AHB1,Copy_u8PortNumber,Copy_8uStatus);
}
/******************************************************************************/
/*Function: MGPIO_ResetPortStatus			                            	  */
/*I/P Parameters: Copy_u8PortNumber		Copy_8uStatus   					  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Change the GPIO reset state using the RCC Enable         */
/******************************************************************************/
/*Port Number:-PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH        */
/*Status :- ON, OFF															  */
/******************************************************************************/
void MGPIO_ResetPortStatus(u8 Copy_u8PortNumber, u8 Copy_8uStatus)
{
	MRCC_voidResetPeripheralclock(AHB1,Copy_u8PortNumber,Copy_8uStatus);
}

/**********************************************************************************************/
/*Function: MGPIO_voidSetPinInput                           								  */
/*I/P Parameters: Copy_u8PortNumber Copy_u8PinNumber Copy_u8OInputType	Copy_u8PullType 	  */
/*Returns:it returns no thing		                           								  */
/*Desc:This Function Set the GPIOpin to one of inpust Mode			         				  */
/**********************************************************************************************/
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*Port Number: PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG,  PORTH			  		      */
/*Direction:   INPUT, ANALOG, AF															  */
/*Pull Type:   NOPULL_NOPUSH,  PULL_UP,  PULL_DOWN											  */
/**********************************************************************************************/
void MGPIO_voidSetPinInput (u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber, u8 Copy_u8OInputType, u8 Copy_u8PullType)
{
	switch (Copy_u8PortNumber)
	{
  	 case PORTA:
  		 CLR_BIT(GPIOA->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOA->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOA->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOA->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOA->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOA->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 case PORTB:
  		 CLR_BIT(GPIOB->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOB->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOB->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2+1)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOB->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOB->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOB->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 case PORTC:
  		 CLR_BIT(GPIOC->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOC->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOC->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2+1)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOC->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOC->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOC->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 case PORTD:
  		 CLR_BIT(GPIOD->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOD->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOD->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOD->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOD->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOD->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 case PORTE:
  		 CLR_BIT(GPIOE->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOE->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOE->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOE->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOE->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOE->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 case PORTF:
  		 CLR_BIT(GPIOF->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOF->GPIOx_MODER,(Copy_u8PinNumber*2));  //Clear Second Bit
  		 GPIOF->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2+1)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOF->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOF->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOF->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 case PORTG:
  		 CLR_BIT(GPIOG->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOG->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOG->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOG->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOG->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOG->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 case PORTH:
  		 CLR_BIT(GPIOH->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOH->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOH->GPIOx_MODER |= (Copy_u8OInputType<<(Copy_u8PinNumber*2)); //Set the Input Type Analog or general Input
  		 CLR_BIT(GPIOH->GPIOx_PUPDR,(Copy_u8PinNumber*2));    //Clear First Bit
  		 CLR_BIT(GPIOH->GPIOx_PUPDR,(Copy_u8PinNumber*2+1));  //Clear Second Bit
  		 GPIOH->GPIOx_PUPDR|= (Copy_u8PullType<<(Copy_u8PinNumber*2)); //Set the Input push pull type
  		 break;
  	 default: break;
	}
}


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
void MGPIO_voidSetPinOutputOrAF (u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber, u8 Copy_u8OutputMode ,u8 Copy_u8OutputType, u8 Copy_u8OutputSpeed)
{
	switch (Copy_u8PortNumber)
	{
	  case PORTA:
		  /* Set OUTPUT Mode */
		  CLR_BIT(GPIOA->GPIOx_MODER,(Copy_u8PinNumber*2));    //Clear First Bit
		  CLR_BIT(GPIOA->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
		  GPIOA->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
		  /* Set OUTPUT Type */
		  switch (Copy_u8OutputType)
		  {
		   case PUSH_PULL: CLR_BIT(GPIOA->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
		   	   	   	   	   break;
		   case OPEN_DRAIN:SET_BIT(GPIOA->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
		   	   	   	   	   break;
		   default: break;
		  }
		  /* Out Speed Configure */
		  CLR_BIT(GPIOA->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
		  CLR_BIT(GPIOA->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
		  GPIOA->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
	      break;

		  case PORTB:
			  /* Set OUTPUT Mode */
			  CLR_BIT(GPIOB->GPIOx_MODER,(Copy_u8PinNumber*2));    //Set First Bit
			  CLR_BIT(GPIOB->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOB->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
			  /* Set OUTPUT Type */
			  switch (Copy_u8OutputType)
			  {
			   case PUSH_PULL: CLR_BIT(GPIOB->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
			   	   	   	   	   break;
			   case OPEN_DRAIN:SET_BIT(GPIOB->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
			   	   	   	   	   break;
			   default: break;
			  }
			  /* Out Speed Configure */
			  CLR_BIT(GPIOB->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
			  CLR_BIT(GPIOB->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOB->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
		  break;

		  case PORTC:
			  /* Set OUTPUT Mode */
			  CLR_BIT(GPIOC->GPIOx_MODER,(Copy_u8PinNumber*2));    //Set First Bit
			  CLR_BIT(GPIOC->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOC->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
			  /* Set OUTPUT Type */
			  switch (Copy_u8OutputType)
			  {
			   case PUSH_PULL: CLR_BIT(GPIOC->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
							   break;
			   case OPEN_DRAIN:SET_BIT(GPIOC->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
							   break;
			   default: break;
			  }
			  /* Out Speed Configure */
			  CLR_BIT(GPIOC->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
			  CLR_BIT(GPIOC->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOC->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
		  break;

		  case PORTD:
			  /* Set OUTPUT Mode */
			  CLR_BIT(GPIOD->GPIOx_MODER,(Copy_u8PinNumber*2));    //Set First Bit
			  CLR_BIT(GPIOD->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOD->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
			  /* Set OUTPUT Type */
			  switch (Copy_u8OutputType)
			  {
			   case PUSH_PULL: CLR_BIT(GPIOD->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
							   break;
			   case OPEN_DRAIN:SET_BIT(GPIOD->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
							   break;
			   default: break;
			  }
			  /* Out Speed Configure */
			  CLR_BIT(GPIOD->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
			  CLR_BIT(GPIOD->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOD->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
		  break;

		  case PORTE:
			  /* Set OUTPUT Mode */
			  CLR_BIT(GPIOE->GPIOx_MODER,(Copy_u8PinNumber*2));    //Set First Bit
			  CLR_BIT(GPIOE->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOE->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
			  /* Set OUTPUT Type */
			  switch (Copy_u8OutputType)
			  {
			   case PUSH_PULL: CLR_BIT(GPIOE->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
							   break;
			   case OPEN_DRAIN:SET_BIT(GPIOE->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
							   break;
			   default: break;
			  }
			  /* Out Speed Configure */
			  CLR_BIT(GPIOE->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
			  CLR_BIT(GPIOE->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOE->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
		  break;

		  case PORTF:
			  /* Set OUTPUT Mode */
			  CLR_BIT(GPIOF->GPIOx_MODER,(Copy_u8PinNumber*2));    //Set First Bit
			  CLR_BIT(GPIOF->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOF->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
			  /* Set OUTPUT Type */
			  switch (Copy_u8OutputType)
			  {
			   case PUSH_PULL: CLR_BIT(GPIOF->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
							   break;
			   case OPEN_DRAIN:SET_BIT(GPIOF->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
							   break;
			   default: break;
			  }
			  /* Out Speed Configure */
			  CLR_BIT(GPIOF->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
			  CLR_BIT(GPIOF->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOF->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
		  break;

		  case PORTG:
			  /* Set OUTPUT Mode */
			  CLR_BIT(GPIOG->GPIOx_MODER,(Copy_u8PinNumber*2));    //Set First Bit
			  CLR_BIT(GPIOG->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOG->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
			  /* Set OUTPUT Type */
			  switch (Copy_u8OutputType)
			  {
			   case PUSH_PULL: CLR_BIT(GPIOG->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
							   break;
			   case OPEN_DRAIN:SET_BIT(GPIOG->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
							   break;
			   default: break;
			  }
			  /* Out Speed Configure */
			  CLR_BIT(GPIOG->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
			  CLR_BIT(GPIOG->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOG->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
		  break;
		  case PORTH:
			  /* Set OUTPUT Mode */
			  CLR_BIT(GPIOH->GPIOx_MODER,(Copy_u8PinNumber*2));    //Set First Bit
			  CLR_BIT(GPIOH->GPIOx_MODER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOH->GPIOx_MODER |= (Copy_u8OutputMode<<(Copy_u8PinNumber*2)); //Set the Output type AF or General
			  /* Set OUTPUT Type */
			  switch (Copy_u8OutputType)
			  {
			   case PUSH_PULL: CLR_BIT(GPIOH->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Push Pull
							   break;
			   case OPEN_DRAIN:SET_BIT(GPIOH->GPIOx_OTYPER,Copy_u8PinNumber);    //Set Bit to Open Drain
							   break;
			   default: break;
			  }
			  /* Out Speed Configure */
			  CLR_BIT(GPIOH->GPIOx_OSPEEDER,(Copy_u8PinNumber*2));    //Clear First Bit
			  CLR_BIT(GPIOH->GPIOx_OSPEEDER,(Copy_u8PinNumber*2+1));  //Clear Second Bit
			  GPIOH->GPIOx_OSPEEDER |= (Copy_u8OutputSpeed<<(Copy_u8PinNumber*2)); //Set the Output Spped
		  break;

			  default: break;
	}

}


void MGPIO_voidSetPinValue(u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber, u8 Copy_u8Value)
{
	switch (Copy_u8PortNumber)
	{
	 case PORTA:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOA->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOA->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	 case PORTB:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOB->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOB->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	 case PORTC:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOC->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOC->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	 case PORTD:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOD->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOD->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	 case PORTE:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOE->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOE->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	 case PORTF:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOF->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOF->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	 case PORTG:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOG->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOG->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	 case PORTH:
		 if (Copy_u8Value==High)
		 {
			 SET_BIT(GPIOH->GPIO_ODR,Copy_u8PinNumber); //Set the Pin Value to High
		 }
		 else
		 {
			 CLR_BIT(GPIOH->GPIO_ODR,Copy_u8PinNumber);//Set the Pin Value to Low
		 }
		 break;
	}
}

u8 MGPIO_u8GetPinValue (u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber)
{
	u8 Local_u8Value;
	Local_u8Value=0;
	switch (Copy_u8PortNumber)
	{
	 case PORTA:
		 Local_u8Value=GET_BIt(GPIOA->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 case PORTB:
		 Local_u8Value=GET_BIt(GPIOB->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 case PORTC:
		 Local_u8Value=GET_BIt(GPIOC->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 case PORTD:
		 Local_u8Value=GET_BIt(GPIOD->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 case PORTE:
		 Local_u8Value=GET_BIt(GPIOE->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 case PORTF:
		 Local_u8Value=GET_BIt(GPIOF->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 case PORTG:
		 Local_u8Value=GET_BIt(GPIOG->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 case PORTH:
		 Local_u8Value=GET_BIt(GPIOH->GPIO_IDR,Copy_u8PinNumber); //Read the Pin Value
		 break;
	 default: break;
	}
	return Local_u8Value;
}



/**********************************************************************************************/
/*Function: MGPIO_AtomicSet				                          						      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Set the GPIO pin output value using atomic access                        */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG       				      */
/**********************************************************************************************/
void MGPIO_AtomicSet (u8 copy_u8PortNumber,u8 copy_PinNumber)
{
	    copy_PinNumber=copy_PinNumber+15;
		/* Switching on the port number */
		switch (copy_u8PortNumber)
		{
			case PORTA:
				GPIOA->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			case PORTB:
				GPIOB->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			case PORTC:
				GPIOC->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			case PORTD:
				GPIOD->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			case PORTE:
				GPIOE->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			case PORTF:
				GPIOG->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			case PORTG:
				GPIOG->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			case PORTH:
				GPIOH->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
				break;
			default:

				break;
		}
		return ;
}


/**********************************************************************************************/
/*Function: MGPIO_AtomicReset				                          					      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function Reset the GPIO pin output value using atomic access                      */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG 					      */
/**********************************************************************************************/
void MGPIO_AtomicReset( u8 copy_u8PortNumber,u8 copy_PinNumber)
{

	/* Switching on the port number */
	switch (copy_u8PortNumber)
	{
		case PORTA:
			GPIOA->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		case PORTB:
			GPIOB->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		case PORTC:
			GPIOC->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		case PORTD:
			GPIOD->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		case PORTE:
			GPIOE->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		case PORTF:
			GPIOG->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		case PORTG:
			GPIOG->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		case PORTH:
			GPIOH->GPIO_BSRR = 1<<copy_PinNumber;   //set the required pin to be Set with 1
			break;
		default:

			break;
	}
	return ;
}


/**********************************************************************************************/
/*Function: MGPIO_vidLockPin  				                          					      */
/*I/P Parameters: copy_PinNumber copy_u8PortNumber											  */
/*Returns:it returns nothing			                            				          */
/*Desc:This Function lock or unlock the GPIO pin from being configured                        */
/**********************************************************************************************/
/*Input  Pins from PIN0 to PIN15					             						      */
/*		 Port Number GPIO_PORTA, GPIO_PORTB, GPIO_PORTAC      							      */
/*       Statues GPIO_Lock, GPIO_Unlock                                                       */
void MGPIO_vidLockPin (u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8Statue)
{
	/**************************************************************************************/
	/**************************************************************************************/
	/*									Inputs Validation								  */
	if ((copy_PinNumber < 0) || (copy_PinNumber > 15) )
	{
		return ;
	}

	/**************************************************************************************/
	/**************************************************************************************/
	/* Switching on the port number */
	switch (copy_u8PortNumber)
	{
		case PORTA:
			/* Sequence for the LCKK bit */
			SET_BIT(GPIOA->GPIO_LCKR,LCKK);
			CLR_BIT(GPIOA->GPIO_LCKR,LCKK);
			SET_BIT(GPIOA->GPIO_LCKR,LCKK);
			if( ~ GET_BIT(GPIOA->GPIO_LCKR,LCKK) )
			{
				/*Switching on lock or unlock*/
				switch (copy_u8Statue)
				{
					/*Lock Case*/
					case GPIO_Lock:
							SET_BIT(GPIOA->GPIO_LCKR,copy_PinNumber);
							break;
					/*Unlock Case*/
					case GPIO_Unlock:
							CLR_BIT(GPIOA->GPIO_LCKR,copy_PinNumber);
							break;
					default:
						break;
				}
				/* Sequence for the LCKK bit */
				SET_BIT(GPIOA->GPIO_LCKR,LCKK);
				CLR_BIT(GPIOA->GPIO_LCKR,LCKK);
				SET_BIT(GPIOA->GPIO_LCKR,LCKK);
			}
			break;
		case PORTB:
			/* Sequence for the LCKK bit */
			SET_BIT(GPIOB->GPIO_LCKR,LCKK);
			CLR_BIT(GPIOB->GPIO_LCKR,LCKK);
			SET_BIT(GPIOB->GPIO_LCKR,LCKK);
			if( ~ GET_BIT(GPIOB->GPIO_LCKR,LCKK) )
			{
				switch (copy_u8Statue)
				{
					case GPIO_Lock:
							SET_BIT(GPIOB->GPIO_LCKR,copy_PinNumber);
							break;
					case GPIO_Unlock:
							CLR_BIT(GPIOB->GPIO_LCKR,copy_PinNumber);
							break;
					default:
						break;
				}
				/* Sequence for the LCKK bit */
				SET_BIT(GPIOB->GPIO_LCKR,LCKK);
				CLR_BIT(GPIOB->GPIO_LCKR,LCKK);
				SET_BIT(GPIOB->GPIO_LCKR,LCKK);
			}
			break;
		case PORTC:
			/* Sequence for the LCKK bit */
			SET_BIT(GPIOC->GPIO_LCKR,LCKK);
			CLR_BIT(GPIOC->GPIO_LCKR,LCKK);
			SET_BIT(GPIOC->GPIO_LCKR,LCKK);
			if( ~ GET_BIT(GPIOC->GPIO_LCKR,LCKK) )
			{
				switch (copy_u8Statue)
				{
					case GPIO_Lock:
							SET_BIT(GPIOC->GPIO_LCKR,copy_PinNumber);
							break;
					case GPIO_Unlock:
							CLR_BIT(GPIOC->GPIO_LCKR,copy_PinNumber);
							break;
					default:
						break;
				}
				/* Sequence for the LCKK bit */
				SET_BIT(GPIOC->GPIO_LCKR,LCKK);
				CLR_BIT(GPIOC->GPIO_LCKR,LCKK);
				SET_BIT(GPIOC->GPIO_LCKR,LCKK);
			}
			break;
		default:
				break;
	}

}

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
void MGPIO_voidAF(u8 copy_PinNumber, u8 copy_u8PortNumber, u8 copy_u8AFNumber)
{
	switch (copy_u8PortNumber)
	{
	 case PORTA:
		 if (copy_PinNumber<8)
		 {
			 GPIOA->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOA->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOA->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOA->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	 case PORTB:
		 if (copy_PinNumber<8)
		 {
			 GPIOB->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOB->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOB->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOB->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	 case PORTC:
		 if (copy_PinNumber<8)
		 {
			 GPIOC->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOC->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOC->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOC->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	 case PORTD:
		 if (copy_PinNumber<8)
		 {
			 GPIOD->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOD->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOD->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOD->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	 case PORTE:
		 if (copy_PinNumber<8)
		 {
			 GPIOE->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOE->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOE->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOE->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	 case PORTF:
		 if (copy_PinNumber<8)
		 {
			 GPIOF->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOF->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOF->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOF->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	 case PORTG:
		 if (copy_PinNumber<8)
		 {
			 GPIOG->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOG->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOG->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOG->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	 case PORTH:
		 if (copy_PinNumber<8)
		 {
			 GPIOH->GPIOx_AFRL &=~(15<<(copy_PinNumber*4));
			 GPIOH->GPIOx_AFRL |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 else if (copy_PinNumber>7)
		 {
			 GPIOH->GPIOx_AFRH &=~(15<<(copy_PinNumber*4));
			 GPIOH->GPIOx_AFRH |= (copy_u8AFNumber<<(copy_PinNumber*4));
		 }
		 break;
	}
}



