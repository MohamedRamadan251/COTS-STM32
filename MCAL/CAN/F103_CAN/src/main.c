/*
 * main.c
 *
 *  Created on: Jul 3, 2021
 *      Author: Ali_Mahrez
 */

#include "../include/MCAL/CAN/CAN_interface.h"
#include "../include/MCAL/CAN/CAN_private.h"
#include "../include/MCAL/GPIO/GPIO_interface.h"
#include "../include/MCAL/GPIO/GPIO_private.h"
#include "../include/MCAL/RCC/RCC_interface.h"
#include "../include/MCAL/RCC/RCC_private.h"
#include "../include/MCAL/SYSTICK/SYSTICK_interface.h"
#include "../include/MCAL/SYSTICK/SYSTICK_private.h"
#include "../include/MCAL/SYSTICK/SYSTICK_configuration.h"



void main()
{
	MRCC_voidClkInit();
	MSYSTICk_voidEnable();
	   /* Enable the Rcc for the GPIOA */
	MGPIO_voidIntialization(IOPA);//
	MGPIO_voidSetPinMode(PIN0,GPIO_PORTA,Output10_PushPull);
	MGPIO_voidSetPinValue(PIN0, GPIO_PORTA, 1);
	MCAN_voidInit();
	CAN_Msg x,y;
	MCAN_voidCreateMessage(55,0,0,2,CAN_MSG_Standard_Format,CAN_MSG_DataFrame,CAN_TSR_TME0,&x);
	x.Data[0]='O';
	x.Data[1]='K';
	u8 counter=0;
	while(1)
	{
		MCAN_voidSendMessage(&x);
//		MCAN_voidReadMessage(&y, 0);
//		MSYSTICK_voidSetBusyWait(1,SEC);
	}


}
//void main()
//{
//	MRCC_voidClkInit();
//	MSYSTICk_voidEnable();
//	   /* Enable the Rcc for the GPIOA */
//	MGPIO_voidIntialization(IOPA);//
//	MGPIO_voidSetPinMode(PIN0,GPIO_PORTA,Output10_PushPull);
//	MGPIO_voidSetPinValue(PIN0, GPIO_PORTA, 1);
//	MCAN_voidInit();
//	CAN_Msg x,y;
//	MCAN_voidCreateMessage(55,0,0,2,CAN_MSG_Standard_Format,CAN_MSG_DataFrame,CAN_TSR_TME0,&x);
//	u8 counter=0;
//	while(1)
//	{
//		MCAN_voidReadMessage(&y,0);
//	}
//
//
//}
