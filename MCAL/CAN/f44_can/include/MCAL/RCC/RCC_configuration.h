/*******************************************************************************************
* ! Title : RCC_interface
* ! File Name : RCC_interface.h
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
 * ******************************************************************************************************************
 * This File contains the RCC Configurations for all CLK Configurations Needed in any Other Peripheral
 * ******************************************************************************************************************
 * To SET the Clock State for a peripheral you must choose the BUS which the Peripheral is connected to.
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_RCC_conf_H
#define _MCAL_RCC_conf_H

/* This refers to the current clock required to work on       */
/* Options Available for the system clock ( HSE , HSI , PLL ) */
#define ClkSource PLL_P


/*********************************************************************************/
/*  Definition of the PLL Sources */											 //
#define HSE_Src   1																 //
#define HSI_Src   0																 //
/*This will refer to the PLL input clock source*/                                //
/* Options Available for the system clock ( HSE_Src , HSI_Src , HSI2_Src ) */	 //
#define PLL_Source HSI_Src														 //
/*********************************************************************************/



/*
000000: PLLM = 0, wrong configuration
000001: PLLM = 1, wrong configuration
000010: PLLM = 2
000011: PLLM = 3
000100: PLLM = 4
...
111110: PLLM = 62
111111: PLLM = 63
*/
#define PLLM_VALUE 16

/*
000000000: PLLN = 0, wrong configuration
000000001: PLLN = 1, wrong configuration ...
000110010: PLLN = 50
...
001100011: PLLN = 99
001100100: PLLN = 100
...
110110000: PLLN = 432
110110001: PLLN = 433, wrong configuration ...
111111111: PLLN = 511, wrong configuration

*/
#define PLLN_VALUE 336

/*
binary       Decimal
00:		     0       PLLP = 2
01:		     1       PLLP = 4
10:		     2       PLLP = 6
11:		     3       PLLP = 8
*/
#define PLLP_VALUE 0


/*
0000: PLLQ = 0, wrong configuration
0001: PLLQ = 1, wrong configuration
0010: PLLQ = 2
0011: PLLQ = 3
0100: PLLQ = 4
...
1111: PLLQ = 15
*/
#define PLLQ_VALUE 4

/*
000: PLLR = 0, wrong configuration
001: PLLR = 1, wrong configuration
010: PLLR = 2
011: PLLR = 3
...
111: PLLR = 7
*/
#define PLLR_VALUE 7

#endif /* __RCC_conf_H */
