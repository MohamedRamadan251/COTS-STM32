#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/LIB.h"
#include "../include/MCAL/RCC/RCC_interface.h"
#include "../include/MCAL/RCC/RCC_configuration.h"
#include "../include/MCAL/RCC/RCC_private.h"
#include "../include/MCAL/GPIO/GPIO_interface.h"
#include "../include/MCAL/GPIO/GPIO_configuration.h"
#include "../include/MCAL/GPIO/GPIO_private.h"
#include "../include/MCAL/SYSTICK/SYSTICK_interface.h"
#include "../include/MCAL/SYSTICK/SYSTICK_configuration.h"
#include "../include/MCAL/SYSTICK/SYSTICK_private.h"
#include "../include/MCAL/CAN/CAN_interface.h"
#include "../include/MCAL/CAN/CAN_configuration.h"
#include "../include/MCAL/CAN/CAN_private.h"


void main(void)
{
	MRCC_voidClkInit();
	MGPIO_voidIntialization();
	MCAN_voidInit();
	MGPIO_voidSetPinOutputOrAF(PORTA,PIN0,OUTPUT,PUSH_PULL,FAST_SPEED);
	MSYSTICk_voidConfig();
	CAN_Msg x,y;
	MCAN_voidCreateMessage(100,7,0,1,CAN_MSG_Standard_Format,CAN_MSG_DataFrame,CAN_TSR_TME0,&x);
	volatile u32 recmsg = 0;
	while(1)
		{
			MCAN_voidSendMessage(&x);
			MSYSTICK_voidSetBusyWait(1,SEC);
			MCAN_voidReadMessage(&y,0);
			MSYSTICK_voidSetBusyWait(1,SEC);
			recmsg=y.Data[0];
			if(recmsg == 99)
			{
				MGPIO_voidSetPinValue(PORTA,PIN0,High);
			}
		}
}
