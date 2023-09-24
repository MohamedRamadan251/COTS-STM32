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
#ifndef __GPIO_CONFIGURATION_H
#define __GPIO_CONFIGURATION_H



/*options :- NORMAL_MODE , LOW_POWER_MODE */
#define POWER_MODE     NORMAL_MODE

/* Options:- ON   OFF */
#define GPIO_PORTA_STATUS   ON
#define GPIO_PORTB_STATUS   ON
#define GPIO_PORTC_STATUS   ON
#define GPIO_PORTD_STATUS   ON
#define GPIO_PORTE_STATUS   ON
#define GPIO_PORTF_STATUS   ON
#define GPIO_PORTG_STATUS   ON
#define GPIO_PORTH_STATUS   ON


#endif /* __GPIO_CONFIGURATION_H */
