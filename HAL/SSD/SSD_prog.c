/*
 * SSD_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_init.h"
#include "SSD_int.h"
#include "SSD_private.h"
#include "SSD_conf.h"

extern MGPIO_Config_t config_output_pin_push_pull ;
extern HSSD_Config_t  config_SSD_1 [] ;
extern HSSD_Config_t  config_SSD_2 [] ;
static u8 R_u8SsdData [] = {
	0x3f,    /**0*/
	0x06,    /**1*/
	0x5b,    /**2*/
	0x4f,    /**3*/
	0x66,    /**4*/
	0x6d,    /**5*/
	0x7d,    /**6*/
	0x07,    /**7*/
	0x7f,    /**8*/
	0x6f     /**9*/
} ;
void HSSD_voidSsdInitial (u8 A_u8SsdId)
{
	/*iterator counter for for loop*/
	u8 L_u8Iterator =  0 ;
	switch (A_u8SsdId)
	{
		               /** set direction of common pin of ssd1 as output */
		case SSD1_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
				                       SSD1EN_PORT                 ,
									   SSD1EN_PIN                ) ;

		               /** set direction of data pins of ssd1 as output */
		               for (L_u8Iterator = 0 ; L_u8Iterator < 7 ; L_u8Iterator ++)
		               {
		            	   MGPIO_voidInit(&config_output_pin_push_pull       ,
		            			           config_SSD_1[L_u8Iterator].PORT   ,
										   config_SSD_1[L_u8Iterator].PIN  ) ;
		               }
		    break ;

					   /** set direction of common pin of ssd2 as output */
		case SSD2_ID : MGPIO_voidInit(&config_output_pin_push_pull ,
                                       SSD2EN_PORT                 ,
				                       SSD2EN_PIN                ) ;

		               /** set direction of data pins of ssd2 as output */
		               for (L_u8Iterator = 0 ; L_u8Iterator < 7 ; L_u8Iterator ++)
				       {
				         	MGPIO_voidInit(&config_output_pin_push_pull        ,
				            	   		    config_SSD_2[L_u8Iterator].PORT    ,
										    config_SSD_2[L_u8Iterator].PIN   ) ;
				        }
			break ;

		default      : /** Error */
			break ;
	}
}

void HSSD_voidSsdWrite (u8 A_u8SsdId , u8 A_u8Num)
{
	/*iterator counter for for loop*/
	u8 L_u8Iterator =  0 ;

	#if SSD_TYPE == COMM_CATHODE	 /// if type of ssd is common cathod
		if (A_u8Num <= DISPLAY_9)
		{
			switch (A_u8SsdId)
			{
				               /**make the common pin of ssd1 is low (turn on ssd1) */
				case SSD1_ID : MGPIO_voidSetPinValue(SSD1EN_PORT , SSD1EN_PIN, GPIO_LOW) ;

				               /**Display number*/
				               for (L_u8Iterator = 0 ; L_u8Iterator < 7 ; L_u8Iterator ++)
				               {
				            	   MGPIO_voidSetPinValue(config_SSD_1[L_u8Iterator].PORT ,
				            			                 config_SSD_1[L_u8Iterator].PIN  ,
														 READ_BIT (R_u8SsdData [A_u8Num] , L_u8Iterator)
														                               ) ;
				               }
			        break ;

							   /**make the common pin of ssd2 is low (turn on ssd2) */
				case SSD2_ID : MGPIO_voidSetPinValue(SSD2EN_PORT , SSD2EN_PIN, GPIO_LOW) ;

				               /**Display number*/
				               for (L_u8Iterator = 0 ; L_u8Iterator < 7 ; L_u8Iterator ++)
				               {
				                  MGPIO_voidSetPinValue(config_SSD_2[L_u8Iterator].PORT ,
				               		                    config_SSD_2[L_u8Iterator].PIN  ,
				               						    READ_BIT (R_u8SsdData [A_u8Num] , L_u8Iterator)
				               						                                  ) ;
				               }
				    break ;

				default      : /** Error */
					break ;
			}
		}
	#elif SSD_TYPE == COMM_ANODE      /// if type of ssd is common andoe
		if (A_u8Num <= DISPLAY_9)
		{
			switch (A_u8SsdId)
			{                  /**make the common pin of ssd1 is high (turn on ssd1) */
				case SSD1_ID : MGPIO_voidSetPinValue(SSD1EN_PORT , SSD1EN_PIN, GPIO_HIGH) ;

				               /**Display number*/
				               for (L_u8Iterator = 0 ; L_u8Iterator < 7 ; L_u8Iterator ++)
				               {
				                  MGPIO_voidSetPinValue(config_SSD_1[L_u8Iterator].PORT ,
				               		                    config_SSD_1[L_u8Iterator].PIN  ,
				               						    READ_BIT ((~R_u8SsdData [A_u8Num]) , L_u8Iterator)
				               						                                  ) ;
				               }
						       break ;

							   /**make the common pin of ssd2 is high (turn on ssd2) */
				case SSD2_ID : MGPIO_voidSetPinValue(SSD2EN_PORT , SSD1EN_PIN, GPIO_HIGH) ;

				               /**Display number*/
				               for (L_u8Iterator = 0 ; L_u8Iterator < 7 ; L_u8Iterator ++)
				               {
				                  MGPIO_voidSetPinValue(config_SSD_2[L_u8Iterator].PORT ,
				               		                    config_SSD_2[L_u8Iterator].PIN  ,
				               						    READ_BIT ((~R_u8SsdData [A_u8Num]) , L_u8Iterator)
				               						                                  ) ;
						       }
				default      : /** Error */
				               break ;
			}
		}
	#else
		#error "select correct type of ssd"
	#endif
}

void HSSD_voidSsdOff (u8 A_u8SsdId)
{
	#if SSD_TYPE == COMM_CATHODE	 /// if type of ssd is common cathod
	    switch (A_u8SsdId)
	    {                   /**make the common pin of ssd1 is high (turn off ssd1) */
			 case SSD1_ID : MGPIO_voidSetPinValue(SSD1EN_PORT , SSD1EN_PIN, GPIO_HIGH) ;
			      break ;

							/**make the common pin of ssd2 is high (turn off ssd2) */
	    	 case SSD2_ID : MGPIO_voidSetPinValue(SSD2EN_PORT , SSD2EN_PIN, GPIO_HIGH) ;
	    	      break ;

	    	 default      : /** Error */
	    		  break ;
	    }
	#elif SSD_TYPE == COMM_ANODE   /// if type of ssd is common anode
	    switch (A_u8SsdId)
	    {                   /**make the common pin of ssd1 is high (turn off ssd1) */
			 case SSD1_ID : MGPIO_voidSetPinValue(SSD1EN_PORT , SSD1EN_PIN, GPIO_LOW) ;
	    	      break ;

							/**make the common pin of ssd2 is high (turn off ssd2) */
	    	 case SSD2_ID : MGPIO_voidSetPinValue(SSD2EN_PORT , SSD2EN_PIN, GPIO_LOW) ;
	    	      break ;

	    	 default      : /** Error */
	    		  break ;
	    }
	#else
		#error "select correct type of ssd"
	#endif
}
