/*
 * IR_prog.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Mohammed Ramadan
 */




#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "../../MCAL/SYSTIC/SYSTIC_init.h"
#include "../../MCAL/EXTI/EXTI_init.h"

#include "IR_conf.h"
#include "IR_private.h"
#include "IR_init.h"

/*declaration HIR_config_t*/
extern HIR_config_t IR_config ;

/*flag to differ between first falling edge and other edges*/
static u8  G_u8StartFlag   = 0 ;
/*array to store data recevered */
static u32 GR_u32FrameData  [50] ;
/*counter number of edges*/
static u8  G_u8EdgeCounter = 0 ;
/*final IR data recerved*/
u8  G_u8IrData      = 0 ;
static u8  G_ReturnTrueValue = 0 ;
static void HIR_voidPraseFrame (void)
{
	/*iterator for for loop*/
	u8 L_u8Counter ;
	for (L_u8Counter = 0 ; L_u8Counter < 8 ; L_u8Counter ++)
	{
		/*range of logic one*/
		if (GR_u32FrameData [L_u8Counter + 17] >= 4000 && GR_u32FrameData [L_u8Counter + 17] <= 4500)
		{
			SET_BIT (G_u8IrData , L_u8Counter) ;
		}
		/*range of logic zero*/
		else if (GR_u32FrameData [L_u8Counter + 17] >= 2000 && GR_u32FrameData [L_u8Counter + 17] <= 2500)
		{
			CLR_BIT (G_u8IrData , L_u8Counter) ;
		}
	}
	/*clear flag after storing data*/
	G_u8StartFlag   = 0 ;
	/*clear edge counter after storing data*/
	G_u8EdgeCounter = 0 ;
	G_ReturnTrueValue = 1 ;
}

static void HIR_voidGetFrame (void)
{
	if (G_u8StartFlag == 0)
	{
		/*call back fuction to prase frame with initialized value of time*/
		MSTK_voidSetIntervalSingle(80 , HIR_voidPraseFrame) ;
		G_u8StartFlag = 1 ;
	}
	else
	{
		/*store elapsed ticks at FrameData array*/
		GR_u32FrameData [G_u8EdgeCounter] = MSTK_u32GetElapsedTicks() ;
		/*call back fuction to prase frame with reinitialized value of time*/
		MSTK_voidSetIntervalSingle(80 , HIR_voidPraseFrame) ;
		G_u8EdgeCounter ++ ;
	}
}

void HIR_voidInit (void)
{
	/*initialize systic timer*/
	MSTK_voidInit() ;

	/*Initialize selected external interrupt*/
	MEXTI_voidInit (IR_config.PORT , IR_config.PIN , GPIO_INPUT_NO_PULL) ;

	/*enable selected external interrupt with falling edge triggering*/
	MEXTI_voidEnableLine(EXTI_FALING,IR_config.PIN) ;
}

u8 HIR_u8GetPushedPuttonOfRemote (void)
{
	/*call back function fo EXTI to get data of frame*/
	MEXTI_voidSetCallBack(IR_config.PIN , HIR_voidGetFrame) ;
	/*wait until data be sent*/
	while (G_ReturnTrueValue == 0) ;
	/*resume G_ReturnTrueValue to 0*/
	G_ReturnTrueValue = 0 ;
	return G_u8IrData ;
}
