/*******************************************************************************************
* ! Title : RCC_program
* ! File Name : RCC_program.c
* ! Description : This file has the definition of the RCC functions and
* the usage of the global variables.
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
 * ******************************************************************************************************************
 * This module contains the RCC APIs Implementation for all CLK Configurations Needed in any Other Peripheral
 * This file provoides Four functions to be called from user application
 * 1- MRCC_voidClkInit(void) :-  Setups the system clock (System clock source, PLL Multiplier
 *                    		   factors, AHB/APBx prescalers and Flash settings).
 *                     	   This function is called at start of code after reset and
 *                      	   before using any Functions in main program. This call is made inside
 *                            the "main.c" file.
 * 2- MRCC_voidSetClkSource (u32 Copy_u32Source):-  Set the Clock source for my Micro-Controller, must be used after
 * 												  enable the CLK source using the next Function  This call is made inside
 *                            					  the "main.c" file.
 * 3- MRCC_voidSetClkStatus (u32 Copy_u32Source, u8 Copy_u8State):- Enable or Disable the clock Source you Enter
 *  															  This call is made inside the "main.c" file.
 * 4- MRCC_voidSetPeripheralclock (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State):- Enable the CLK for a peripheral
 *     This call is made inside the "main.c" file.
 * 5- MRCC_voidResetPeripheralclock (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State):-
 *    Reset the clock Source you Enter This call is made inside the "main.c" file.
 * 6- MRCC_voidSetPeripheralclockLowPowerMode (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State):-
 *    Enable or Disable the clock Source you Enter in low power mode This call is made inside the "main.c" file.
 * ******************************************************************************************************************
 * 1- MRCC_voidSetPLLConfigurations: this is a private Function which Configures The PLL
 * ******************************************************************************************************************
 * The Startup Code Sets the Clock to 72 MHz using HSI as a Source.
 * ******************************************************************************************************************
 * Sequence To initialize System CLock
 * - Set the CLK Source(ClkSource) in Configuration File
 * - In case You want to Use a Division Factor Set it in the Configuration File from the options
 * - In Case of PLL you must choose the PLL Source and division Factor From the Options
 * ******************************************************************************************************************
 * To change the CLK source you must enable the new CLK source before you disable the old one
 * use this Sequence
 * 1- MRCC_voidSetClkStatus (New Source, ON)
 * 2- MRCC_voidSetClkSource (New Source)
 * 3- MRCC_voidSetClkStatus (Old Source, OFF)
 * Note In Case of PLL two Sources must be ON
 * ******************************************************************************************************************
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


/******************************************************************/
#define PLLM_BIT0  GET_BIT(PLLM_VALUE,0)
#define PLLM_BIT1  GET_BIT(PLLM_VALUE,1)
#define PLLM_BIT2  GET_BIT(PLLM_VALUE,2)
#define PLLM_BIT3  GET_BIT(PLLM_VALUE,3)
#define PLLM_BIT4  GET_BIT(PLLM_VALUE,4)
#define PLLM_BIT5  GET_BIT(PLLM_VALUE,5)
/******************************************************************/
#define PLLN_BIT0  GET_BIT(PLLN_VALUE,0)
#define PLLN_BIT1  GET_BIT(PLLN_VALUE,1)
#define PLLN_BIT2  GET_BIT(PLLN_VALUE,2)
#define PLLN_BIT3  GET_BIT(PLLN_VALUE,3)
#define PLLN_BIT4  GET_BIT(PLLN_VALUE,4)
#define PLLN_BIT5  GET_BIT(PLLN_VALUE,5)
#define PLLN_BIT6  GET_BIT(PLLN_VALUE,6)
#define PLLN_BIT7  GET_BIT(PLLN_VALUE,7)
#define PLLN_BIT8  GET_BIT(PLLN_VALUE,8)
/******************************************************************/
#define PLLP_BIT0  GET_BIT(PLLP_VALUE,0)
#define PLLP_BIT1  GET_BIT(PLLP_VALUE,1)
/******************************************************************/
#define PLLQ_BIT0  GET_BIT( PLLQ_VALUE,0)
#define PLLQ_BIT1  GET_BIT( PLLQ_VALUE,1)
#define PLLQ_BIT2  GET_BIT( PLLQ_VALUE,2)
#define PLLQ_BIT3  GET_BIT( PLLQ_VALUE,3)
/******************************************************************/
#define PLLR_BIT0  GET_BIT(PLLR_VALUE,0)
#define PLLR_BIT1  GET_BIT(PLLR_VALUE,1)
#define PLLR_BIT2  GET_BIT(PLLR_VALUE,2)
/******************************************************************/

/******************************************************************************/
/*Function: MRCC_voidClkInit		                     					  */
/*I/P Parameters: nothing						 							  */
/*Returns:it returns Error Status                              				  */
/*Desc:This Function to enable The Clock due to pre-configurations	   	      */
/******************************************************************************/
void MRCC_voidClkInit(void)
{
  #if ClkSource == HSE
	/*HSI ON*/
	MRCC_voidSetClkStatus(HSE_Enable,ON);
	/*pull on Flag to check on the HSE if ready or not*/
	while(GET_BIT(RCC ->RCC_CR,CR_HSE_RDY_BIT)==0);
	MRCC_voidSetClkSource(HSE);
	/*PLL OFF*/
	MRCC_voidSetClkStatus(PLL_Enable,OFF);
	/*HSI OFF*/
	MRCC_voidSetClkStatus(HSI_Enable,OFF);

  #endif

  #if ClkSource == HSI
	/*HSI ON*/
	MRCC_voidSetClkStatus(HSI_Enable,ON);
	/*pull on Flag to check on the HSE if ready or not*/
	while(GET_BIT(RCC ->RCC_CR,CR_HSI_RDY_BIT)==0);
	MRCC_voidSetClkSource(HSI);
	/*PLL OFF*/
	MRCC_voidSetClkStatus(PLL_Enable,OFF);
	/*HSE OFF*/
	MRCC_voidSetClkStatus(HSE_Enable,OFF);
  #endif

  #if ClkSource == PLL_P

	switch (PLL_Source) {
		case HSE_Src:
			/*HSI ON*/
			MRCC_voidSetClkStatus(HSE_Enable,ON);
			/*pull on Flag to check on the HSE if ready or not*/
			while(GET_BIT(RCC ->RCC_CR,CR_HSE_RDY_BIT)==0);
		   /*Switch to HSI*/
		   MRCC_voidSetClkSource(HSE);
		   /*PLL OFF*/
		   MRCC_voidSetClkStatus(PLL_Enable,OFF);
		   /*HSI OFF*/
			MRCC_voidSetClkStatus(HSI_Enable,OFF);
		   /* Set All PLL Configurations */
			RCC_voidSetPLLConfigurations();
		   /*PLL ON*/
		   MRCC_voidSetClkStatus(PLL_Enable,ON);
		   /*pull on Flag to check on the HSE if ready or not*/
		   while(GET_BIT(RCC ->RCC_CR,CR_PLL_RDY_BIT)==0);
		   /*Switch to PLL*/
		   MRCC_voidSetClkSource(PLL_P);
			break;
		case HSI_Src:
			/*HSI ON*/
			MRCC_voidSetClkStatus(HSI_Enable,ON);
			/*pull on Flag to check on the HSE if ready or not*/
			while(GET_BIT(RCC ->RCC_CR,CR_HSI_RDY_BIT)==0);
			/*Switch to HSI*/
			MRCC_voidSetClkSource(HSI);
			/*PLL OFF*/
			MRCC_voidSetClkStatus(PLL_Enable,OFF);
			/*HSE OFF*/
			MRCC_voidSetClkStatus(HSE_Enable,OFF);
			/* Set All PLL Configurations */
			MRCC_voidSetPLLConfigurations();
			/*PLL ON*/
			MRCC_voidSetClkStatus(PLL_Enable,ON);
			/*pull on Flag to check on the HSE if ready or not*/
			while(GET_BIT(RCC ->RCC_CR,CR_PLL_RDY_BIT)==0);
			/*Switch to PLL*/
			MRCC_voidSetClkSource(PLL_P);
			break;
		default:
			break;
	}
  #endif
	CLR_BIT(RCC->RCC_CFGR,7);  //AHB Prescaler 1
	/**********************************************/
	//APB 1 Prescaler 4
	SET_BIT(RCC->RCC_CFGR,10);
	SET_BIT(RCC->RCC_CFGR,12);
	/**********************************************/
	SET_BIT(RCC->RCC_CFGR,15); //APB 2 Prescaler 2


	CLR_BIT(RCC->RCC_CR,7);
}

/******************************************************************************/
/*Function: MRCC_voidSetPLLConfigurations                          			  */
/*I/P Parameters: void			            								  */
/*Returns:it returns void		                              				  */
/*Desc:This Function Configure the PLL CFGR							          */
/******************************************************************************/
void MRCC_voidSetPLLConfigurations(void)
{
	RCC->RCC_PLLCFGR=0x0000;
	u32 Local_u32value=0;
		Local_u32value=((PLLM_BIT0<<0) |(PLLM_BIT1<<1)  |(PLLM_BIT2<<2) |(PLLM_BIT3<<3) |(PLLM_BIT4<<4) |(PLLM_BIT5<<5) |
				   (PLLN_BIT0<<6) |(PLLN_BIT1<<7)  |(PLLN_BIT2<<8) |(PLLN_BIT3<<9) |(PLLN_BIT4<<10)|(PLLN_BIT5<<11)|
				   (PLLN_BIT6<<12)|(PLLN_BIT7<<13) |(PLLN_BIT8<<14)|(0<<15)        |(PLLP_BIT0<<16)|(PLLP_BIT1<<17)|(0<<18)|(0<<19)|
				   (0<<20)|(0<<21)|(PLL_Source<<22)|(0<<23)        |(PLLQ_BIT0<<24)|(PLLQ_BIT1<<25)|(PLLQ_BIT2<<26)|
				   (PLLQ_BIT3<<27)|(PLLR_BIT0<<28) |(PLLR_BIT0<<29)|(PLLR_BIT0<<30)|(0<<31));
	/* Configure the PLL CFGR  */
	RCC->RCC_PLLCFGR=Local_u32value;
}

/******************************************************************************/
/*Function: MRCC_voidSetClkSource                          					  */
/*I/P Parameters: Copy_u32Source            								  */
/*Returns:it returns void	                                 				  */
/*Desc:This Function Set the Clock source for my micro-controller	          */
/******************************************************************************/
/*Options:-   - HSI 	  - HSE		   - PLL_P		   - PLL_R 				  */
/******************************************************************************/
void MRCC_voidSetClkSource (u32 Copy_u32Source)
{
	/* Switching on the clock sources */
  switch (Copy_u32Source)
  {
	/*IF the clock source is HSI the bits 0,1 are cleared */
	/* then updated with the corresponding value of HSI   */
    case HSI:
				CLR_BIT(RCC ->RCC_CFGR,CFGR_SW0_Bit);
				CLR_BIT(RCC ->RCC_CFGR,CFGR_SW1_Bit);
				break;
	/*IF the clock source is HSE the bits 0,1 are cleared */
	/* then updated with the corresponding value of HSE   */
	case HSE:
				SET_BIT(RCC ->RCC_CFGR,CFGR_SW0_Bit);
				CLR_BIT(RCC ->RCC_CFGR,CFGR_SW1_Bit);
				break;
	/*IF the clock source is PLL the bits 0,1 are cleared */
	/* then updated with the corresponding value of PLL   */
	case PLL_P:
				CLR_BIT(RCC ->RCC_CFGR,CFGR_SW0_Bit);
				SET_BIT(RCC ->RCC_CFGR,CFGR_SW1_Bit);
				break;
	/*IF the clock source is PLL the bits 0,1 are cleared */
	/* then updated with the corresponding value of PLL   */
	case PLL_R:
				SET_BIT(RCC ->RCC_CFGR,CFGR_SW0_Bit);
				SET_BIT(RCC ->RCC_CFGR,CFGR_SW1_Bit);
				break;
	default:
		break;
}
	}


/******************************************************************************/
/*Function: RCC_voidSetClkStatus                     						  */
/*I/P Parameters: Copy_u32Source , Copy_u8State  							  */
/*Returns:it returns void		                                			  */
/*Desc:This Function to enable or disable the clock Source	        	      */
/******************************************************************************/
/* Copy_u32Source :-  - HSI_Enable    - HSE_Enable    - PLL_Enable		      */
/*					  - PLLI2S_Enable - PLLSAI_Enable                         */
/* Copy_u8State   :-  - ON            - OFF									  */
/******************************************************************************/
void MRCC_voidSetClkStatus (u32 Copy_u32Source, u8 Copy_u8State)
{
	/* Switching on the clock sources (HSI, HSE, PLL) */
	switch (Copy_u32Source) {
		case HSI_Enable:
			             /* checking on the state of the peripheral */
						 if (Copy_u8State==ON)
					     {
						  /* Setting the HSI on bit with one to enable it */
						  SET_BIT(RCC ->RCC_CR,HSI_CLK_STATUS);
						 }
						 else
						 {
						  /* Setting the HSI bit with zero to disable it */
						  CLR_BIT(RCC ->RCC_CR,HSI_CLK_STATUS);
						 }
						 break;
		case HSE_Enable:
			             /* checking on the state of the peripheral */
						 if (Copy_u8State==ON)
					     {
						  /* Setting the HSE on bit with one to enable it */
						  SET_BIT(RCC ->RCC_CR,HSE_CLK_STATUS);
						 }
						 else
						 {
						  /* Setting the HSE bit with zero to disable it */
						  CLR_BIT(RCC ->RCC_CR,HSE_CLK_STATUS);
						 }
						 break;
		case PLL_Enable:
			             /* checking on the state of the peripheral */
						 if (Copy_u8State==ON)
					     {
						  /* Setting the PLL on bit with one to enable it */
						   SET_BIT(RCC ->RCC_CR,PLL_CLK_STATUS);
						 }
						 else
						 {
						  /* Setting the PLL bit with zero to disable it */
						  CLR_BIT(RCC ->RCC_CR,PLL_CLK_STATUS);
						 }
						 break;
		case PLLI2S_Enable:
			             /* checking on the state of the peripheral */
						 if (Copy_u8State==ON)
					     {
						  /* Setting the PLL on bit with one to enable it */
						   SET_BIT(RCC ->RCC_CR,PLLI2S_CLK_STATUS);
						 }
						 else
						 {
						  /* Setting the PLL bit with zero to disable it */
						  CLR_BIT(RCC ->RCC_CR,PLLI2S_CLK_STATUS);
						 }
						 break;
		case PLLSAI_Enable:
			             /* checking on the state of the peripheral */
						 if (Copy_u8State==ON)
					     {
						  /* Setting the PLL on bit with one to enable it */
						  SET_BIT(RCC ->RCC_CR,PLLSAI_CLK_STATUS);
						 }
						 else
						 {
						  /* Setting the PLL bit with zero to disable it */
						  CLR_BIT(RCC ->RCC_CR,PLLSAI_CLK_STATUS);
						 }
						 break;
		default:
			break;
	}
}


/******************************************************************************/
/*Function: MRCC_voidSetPeripheralclock                     				  */
/*I/P Parameters: Copy_u8Bus , Copy_u32peripheral , Copy_u8State  			  */
/*Returns:it returns void	                                				  */
/*Desc:This Function to enable or disable the clock for a peripheral 	      */
/******************************************************************************/
/* Copy_u8Bus         :-    - AHB1   - AHB2   - AHB3   - APB1   - APB2		  */
/* Copy_u32peripheral :-    Choose peripheral From Interface File	    	  */
/* Copy_u8State       :-    - ON    - OFF									  */
/******************************************************************************/
void MRCC_voidSetPeripheralclock (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State)
{
	/* Switching on buses of peripherals (AHB1, AHB2, AHB3, APB1, APB2) */
	switch (Copy_u8Bus)
	{
	    /* The AHB Bus is Chosen */
		case AHB1:
			      /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_AHB1ENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_AHB1ENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The AHB Bus is Chosen */
		case AHB2:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_AHB2ENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_AHB2ENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The AHB Bus is Chosen */
		case AHB3:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_AHB1ENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_AHB1ENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The APB1 Bus is Chosen */
		case APB1:
			      /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_APB1ENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_APB1ENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The APB2 Bus is Chosen */
		case APB2:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_APB2ENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_APB2ENR &= ~Copy_u32peripheral;
				  }
				  break;
		default:
			break;
	}
}

/******************************************************************************/
/*Function: MRCC_voidResetPeripheralclock                     				  */
/*I/P Parameters: Copy_u8Bus , Copy_u32peripheral , Copy_u8State  			  */
/*Returns:it returns void                                   				  */
/*Desc:This Function to Reset the clock for a peripheral 				      */
/******************************************************************************/
/* Copy_u8Bus         :-    - AHB1   - AHB2   - AHB3   - APB1   - APB2		  */
/* Copy_u32peripheral :-    Choose peripheral From Interface File	    	  */
/* Copy_u8State       :-    - Reset    - NotToReset							  */
/******************************************************************************/
void MRCC_voidResetPeripheralclock (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State)
{
	/* Switching on buses of peripherals (AHB1, AHB2, AHB3, APB1, APB2) */
	switch (Copy_u8Bus)
	{
	    /* The AHB Bus is Chosen */
		case AHB1:
			      /* checking on the state of the peripheral */
				  if (Copy_u8State==Reset)
				  {
					  /* Setting the peripheral bit with one to reset the peripheral */
					  RCC ->RCC_AHB1RSTR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero not to reset the peripheral */
					  RCC ->RCC_AHB1RSTR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The AHB Bus is Chosen */
		case AHB2:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==Reset)
				  {
					  /* Setting the peripheral bit with one to reset the peripheral */
					  RCC ->RCC_AHB2RSTR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero not to reset the peripheral */
					  RCC ->RCC_AHB2RSTR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The AHB Bus is Chosen */
		case AHB3:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==Reset)
				  {
					  /* Setting the peripheral bit with one to reset the peripheral */
					  RCC ->RCC_AHB3RSTR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero not to reset the peripheral */
					  RCC ->RCC_AHB3RSTR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The APB1 Bus is Chosen */
		case APB1:
			      /* checking on the state of the peripheral */
				  if (Copy_u8State==Reset)
				  {
					  /* Setting the peripheral bit with one to reset the peripheral */
					  RCC ->RCC_APB1RSTR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero not to reset the peripheral */
					  RCC ->RCC_APB1RSTR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The APB2 Bus is Chosen */
		case APB2:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==Reset)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_APB2RSTR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero not to reset the peripheral */
					  RCC ->RCC_APB2RSTR &= ~Copy_u32peripheral;
				  }
				  break;
		default:
			break;
	}
}

/**************************************************************************************************/
/*Function: MRCC_voidSetPeripheralclockLowPowerMode            				  					  */
/*I/P Parameters: Copy_u8Bus , Copy_u32peripheral , Copy_u8State  			  					  */
/*Returns:it returns void	                                				  					  */
/*Desc:This Function to enable or disable the clock for a peripheral in low power mode  	      */
/**************************************************************************************************/
/* Copy_u8Bus         :-    - AHB1   - AHB2   - AHB3   - APB1   - APB2		  					  */
/* Copy_u32peripheral :-    Choose peripheral From Interface File	    	  					  */
/* Copy_u8State       :-    - ON    - OFF									  					  */
/**************************************************************************************************/
void MRCC_voidSetPeripheralclockLowPowerMode (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State)
{
	/* Switching on buses of peripherals (AHB1, AHB2, AHB3, APB1, APB2) */
	switch (Copy_u8Bus)
	{
	    /* The AHB1 Bus is Chosen */
		case AHB1:
			      /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_AHB1LPENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_AHB1LPENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The AHB2 Bus is Chosen */
		case AHB2:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_AHB2LPENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_AHB2LPENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The AHB3 Bus is Chosen */
		case AHB3:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_AHB3LPENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_AHB3LPENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The APB1 Bus is Chosen */
		case APB1:
			      /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_APB1LPENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_APB1LPENR &= ~Copy_u32peripheral;
				  }
				  break;
		/* The APB2 Bus is Chosen */
		case APB2:
				  /* checking on the state of the peripheral */
				  if (Copy_u8State==ON)
				  {
					  /* Setting the peripheral bit with one to enable the peripheral */
					  RCC ->RCC_APB2LPENR |= Copy_u32peripheral;
				  }
				  else
				  {
					  /* Setting the peripheral bit with zero to disable the peripheral */
					  RCC ->RCC_APB2LPENR &= ~Copy_u32peripheral;
				  }
				  break;
		default:
			break;
	}
}

// ----------------------------------------------------------------------------
