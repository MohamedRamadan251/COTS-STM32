/*
 * main.c
 *
 *  Created on: Jul 3, 2021
 *      Author: Ali_Mahrez
 */

#include "MCAL/CAN/CAN_interface.h"
#include "MCAL/CAN/CAN_private.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/GPIO/GPIO_private.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/RCC/RCC_private.h"


void main()
{
	MRCC_voidClkInit();

	MSYSTICk_voidEnable();
	   /* Enable the Rcc for the GPIOA */
	MGPIO_voidIntialization(IOPA);//

	MGPIO_voidSetPinMode(PIN0,GPIO_PORTA,Output10_PushPull);
//	MGPIO_ErrorStatusSetPinMode(PIN9,GPIO_PORTA,Output2_AFPushPull);
//	MGPIO_ErrorStatusSetPinMode(PIN10,GPIO_PORTA,Input_Floating);

	MCAN_voidInit();
	CAN_Msg x,y;
	MCAN_voidCreateMessage(100,99,0,1,CAN_MSG_Standard_Format,CAN_MSG_DataFrame,CAN_TSR_TME0,&x);
	MSYSTICK_voidSetBusyWait(1000000);

	volatile u32 recmsg = 0;

	while(1)
	{
		MCAN_voidSendMessage(&x);
		MSYSTICK_voidSetBusyWait(1000000);
		MCAN_voidReadMessage(&y, 0);
		if(y.Data[0] == 99)
		{
			MGPIO_voidSetPinValue(PIN0, GPIO_PORTA, 1);
		}
	}


}
