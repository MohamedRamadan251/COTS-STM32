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
 * This module contains the RCC APIs Definitions for all CLK Configurations Needed in any Other Peripheral
 * This file provides Four functions be called from user application
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
 * The Startup Code Sets the Clock to 72 MHz using HSI as a Source.
 * ******************************************************************************************************************
 * Sequence To initialize System CLock
 * - Set the CLK Source(ClkSource) in Configuration File
 * - In case You want to Use a Division Factor Set it in the Configuration File from the options
 * - In Case of PLL you must choose the PLL Source and division Factor From the Options
 * ******************************************************************************************************************
 * To change the CLK source you must enable the new CLK source before you disable the old one
 * use this Sequence
 * 1- MRCC_vidSetClkStatus (New Source, ON)
 * 2- MRCC_vidSetClkSource (New Source)
 * 3- MRCC_vidSetClkStatus (Old Source, OFF)
 * Note In Case of PLL two Sources must be ON
 * ******************************************************************************************************************
 * To SET the Clock State for a peripheral you must choose the BUS which the Peripheral is connected to.
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_RCC_INT_H
#define _MCAL_RCC_INT_H




/**************************************************/
/*Description: Definitions for Clock Source       */
/* For this Function:- MRCC_voidSetClkSource      */
/**************************************************/
#define HSI                 HSI_SOURCE
#define HSE                 HSE_SOURCE
#define PLL_P               PLL_P_SOURCE
#define PLL_R               PLL_R_SOURCE

/**************************************************/
/*Description: Definitions for Clock Source       */
/* For this Function:- MRCC_voidSetClkStatus      */
/**************************************************/
#define HSI_Enable          HSI_CLK_STATUS
#define HSE_Enable          HSE_CLK_STATUS
#define PLL_Enable          PLL_CLK_STATUS
#define PLLI2S_Enable       PLLI2S_CLK_STATUS
#define PLLSAI_Enable       PLLSAI_CLK_STATUS

/**************************************************/
/*Description: Definitions for Peripheral Buses   */
/**************************************************/
#define AHB1  AHB1_BUS
#define AHB2  AHB2_BUS
#define AHB3  AHB3_BUS
#define APB1  APB1_BUS
#define APB2  APB2_BUS

/**************************************************/
/*Description: Definitions for Peripheral         */
/**************************************************/
/**************************************************/
/********************AHB1**************************/
#define GPIOAEN        GPIOA_Enable        // GPIOA Enable
#define GPIOBEN        GPIOB_Enable        // GPIOB Enable
#define GPIOCEN        GPIOC_Enable        // GPIOC Enable
#define GPIODEN        GPIOD_Enable        // GPIOD Enable
#define GPIOEEN        GPIOE_Enable        // GPIOE Enable
#define GPIOFEN        GPIOF_Enable        // GPIOF Enable
#define GPIOGEN        GPIOG_Enable        // GPIOG Enable
#define GPIOHEN        GPIOH_Enable        // GPIOH Enable
#define CRCEN          CRC_Enable          // CRC Enable
#define BKPSRAMEN	   BKPSRAM_Enable      // BKPSRAM Enable
#define DMA1EN         DMA1_Enable         // DMA 1 Enable
#define DMA2EN         DMA2_Enable         // DMA 2 Enable
#define OTGHSEN        OTGHS_Enable        // OTGHS Enable
#define OTGHSULPIEN    OTGHSULPI_Enable    // OTGHSULPI Enable
/**************************************************/
/********************AHB2**************************/
#define DCMIEN         DCMI_Enable         // DCMI Enable
#define OTGFSEN        OTGFS_Enable		   // OTGFS Enable
/**************************************************/
/********************AHB3**************************/
#define FMCEN          FMC_Enable 		   // FMC Enable
#define QSPIEN         QSPI_Enable		   // QSPI Enable

/**************************************************/
/********************ABP1**************************/
#define TIM2EN     Timer2_Enable  			// Timer 2  Enable
#define TIM3EN     Timer3_Enable            // Timer 3  Enable
#define TIM4EN     Timer4_Enable            // Timer 4  Enable
#define TIM5EN     Timer5_Enable            // Timer 5  Enable
#define TIM6EN     Timer6_Enable            // Timer 6  Enable
#define TIM7EN     Timer7_Enable            // Timer 7  Enable
#define TIM12EN    Timer12_Enable           // Timer 12 Enable
#define TIM13EN    Timer13_Enable           // Timer 13 Enable
#define TIM14EN    Timer14_Enable           // Timer 14 Enable
#define WWDGEN     WatchDog_Enable		    // WatchDog Timer Enable
#define SPI2EN     SPI2_Enable    			// SPI2 Enable
#define SPI3EN     SPI3_Enable              // SPI3 Enable
#define SPDIFRXEN  SPDIFRX_Enable           // SPDIFRX Enable
#define USART2EN   USART2_Enable            // USART 2 Enable
#define USART3EN   USART3_Enable            // USART 3 Enable
#define UART4EN    UART4_Enable             // UART 4 Enable
#define UART5EN    UART5_Enable             // UART 5 Enable
#define I2C1EN     I2C1_Enable              // I2C 1 Enable
#define I2C2EN     I2C2_Enable              // I2C 2 Enable
#define I2C3EN     I2C3_Enable              // I2C 3 Enable
#define FMPI2C1EN  FMPI2C_Enable            // FMPI2C Enable
#define CAN1EN     CAN1_Enable              // CAN 1 Enable
#define CAN2EN     CAN2_Enable              // CAN 2 Enable
#define CECEN      CEC_Enable               // CEC Enable
#define PWREN      Power_Enable             // Power Enable
#define DACEN      DAC_Enable               // DAC Enable

/**************************************************/
/********************ABP2**************************/
#define TIM1EN     Timer1_Enable 			// Timer 1  Enable
#define TIM8EN     Timer8_Enable            // Timer 8  Enable
#define USART1EN   USART1_Enable            // USART 1 Enable
#define USART6EN   USART6_Enable            // USART 6 Enable
#define ADC1EN     ADC1_Enable              // ADC 1 Enable
#define ADC2EN     ADC2_Enable              // ADC 2 Enable
#define ADC3EN     ADC3_Enable              // ADC 3 Enable
#define SDIOEN     SDIO_Enable   			// SDIO Enable
#define SPI1EN     SPI2_Enable   			// SPI2 Enable
#define SPI4EN     SPI1_Enable              // SPI1 Enable
#define SYSCFGEN   SYSCFG_Enable 			// SYSCFG Enable
#define TIM9EN     Timer9_Enable 			// Timer 9   Enable
#define TIM10EN    Timer10_Enable           // Timer 10  Enable
#define TIM11EN    Timer11_Enable           // Timer 11  Enable
#define SAI1EN     SAI1_Enable              // SAI 1 Enable
#define SAI2EN     SAI2_Enable              // SAI 2 Enable
/***********************************************************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/**************************************************/
/*Description: Definitions for Peripheral         */
/**************************************************/
/**************************************************/
/********************AHB1**************************/
#define GPIOARST        GPIOA_Reset       // GPIOA Reset
#define GPIOBRST        GPIOB_Reset       // GPIOB Reset
#define GPIOCRST        GPIOC_Reset       // GPIOC Reset
#define GPIODRST        GPIOD_Reset       // GPIOD Reset
#define GPIOERST        GPIOE_Reset       // GPIOE Reset
#define GPIOFRST        GPIOF_Reset       // GPIOF Reset
#define GPIOGRST        GPIOG_Reset       // GPIOG Reset
#define GPIOHRST        GPIOH_Reset       // GPIOH Reset
#define CRCRST          CRC_Reset         // CRC Reset
#define DMA1RST         DMA1_Reset        // DMA 1 Reset
#define DMA2RST         DMA2_Reset        // DMA 2 Reset
#define OTGHSRST        OTGHS_Reset       // OTGHS Reset
/**************************************************/
/********************AHB2**************************/
#define DCMIRST         DCMI_Reset        // DCMI Reset
#define OTGFSRST        OTGFS_Reset	      // OTGFS Reset
/**************************************************/
/********************AHB3**************************/
#define FMCRST          FMC_Reset  	      // FMC Reset
#define QSPIRST         QSPI_Reset 	      // QSPI Reset

/**************************************************/
/********************ABP1**************************/
#define TIM2RST     Timer2_Reset  		 // Timer 2  Reset
#define TIM3RST     Timer3_Reset         // Timer 3  Reset
#define TIM4RST     Timer4_Reset         // Timer 4  Reset
#define TIM5RST     Timer5_Reset         // Timer 5  Reset
#define TIM6RST     Timer6_Reset         // Timer 6  Reset
#define TIM7RST     Timer7_Reset         // Timer 7  Reset
#define TIM12RST    Timer1_Reset         // Timer 12 Reset
#define TIM13RST    Timer13_Reset        // Timer 13 Reset
#define TIM14RST    Timer14_Reset        // Timer 14 Reset
#define WWDGRST     WatchDog_Timer	     // WatchDog Timer Reset
#define SPI2RST     SPI2_Reset    		 // SPI2 Reset
#define SPI3RST     SPI3_Reset           // SPI3 Reset
#define SPDIFRXRST  SPDIFRX_Reset        // SPDIFRX Reset
#define USART2RST   USART2_Reset         // USART 2 Reset
#define USART3RST   USART3_Reset         // USART 3 Reset
#define UART4RST    UART4_Reset          // UART 4 Reset
#define UART5RST    UART5_Reset          // UART 5 Reset
#define I2C1RST     I2C1_Reset           // I2C 1 Reset
#define I2C2RST     I2C2_Reset           // I2C 2 Reset
#define I2C3RST     I2C3_Reset           // I2C 3 Reset
#define FMPI2C1RST  FMPI2C_Reset         // FMPI2C Reset
#define CAN1RST     CAN1_Reset           // CAN 1 Reset
#define CAN2RST     CAN2_Reset           // CAN 2 Reset
#define CECRST      CEC_Reset            // CEC Reset
#define PWRRST      Power_Reset          // Power Reset
#define DACRST      DAC_Reset            // DAC Reset

/**************************************************/
/********************ABP2**************************/
#define TIM1RST     Timer1_Reset 			 // Timer 1  Reset
#define TIM8RST     Timer8_Reset             // Timer 8  Reset
#define USART1RST   USART1_Reset             // USART 1 Reset
#define USART6RST   USART6_Reset             // USART 6 Reset
#define ADC1RST     ADC1_Reset               // ADC 1 Reset
#define SDIORST     SDIO_Reset   			 // SDIO Reset
#define SPI1RST     SPI2_Reset   			 // SPI2 Reset
#define SPI4RST     SPI1_Reset               // SPI1 Reset
#define SYSCFGRST   SYSCFG_Reset 			 // SYSCFG Reset
#define TIM9RST     Timer9_Reset 			 // Timer 9   Reset
#define TIM10RST    Timer10_Reset            // Timer 10  Reset
#define TIM11RST    Timer11_Reset            // Timer 11  Reset
#define SAI1RST     SAI1_Reset               // SAI 1 Reset
#define SAI2RST     SAI2_Reset               // SAI 2 Reset
/***********************************************************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/**************************************************/
/*Description: Definitions for Peripheral         */
/**************************************************/
/**************************************************/
/********************AHB1**************************/
#define GPIOALPENR        GPIOA_Low            // GPIOA Low Power Mode Enable
#define GPIOBLPENR        GPIOB_Low            // GPIOB Low Power Mode Enable
#define GPIOCLPENR        GPIOC_Low            // GPIOC Low Power Mode Enable
#define GPIODLPENR        GPIOD_Low            // GPIOD Low Power Mode Enable
#define GPIOELPENR        GPIOE_Low            // GPIOE Low Power Mode Enable
#define GPIOFLPENR        GPIOF_Low            // GPIOF Low Power Mode Enable
#define GPIOGLPENR        GPIOG_Low            // GPIOG Low Power Mode Enable
#define GPIOHLPENR        GPIOH_Low            // GPIOH Low Power Mode Enable
#define CRCLPENR          CRC_Low              // CRC Low Power Mode Enable
#define FLITFLPEN		  FLITF_Low	           // FLITF Low Power Mode Enable
#define SRAM1LPEN		  FLITF_Low	           // FLITF Low Power Mode Enable
#define SRAM2LPEN		  FLITF_Low	           // FLITF Low Power Mode Enable
#define BKPSRAMLPENR	  BKPSRAM_Low	       // BKPSRAM Low Power Mode Enable
#define DMA1LPENR         DMA1_Low             // DMA 1 Low Power Mode Enable
#define DMA2LPENR         DMA2_Low             // DMA 2 Low Power Mode Enable
#define OTGHSLPENR        OTGHS_Low            // OTGHS Low Power Mode Enable
#define OTGHSULPILPENR    OTGHSULPI_Low        // OTGHSULPI Low Power Mode Enable
/**************************************************/
/********************AHB2**************************/
#define DCMILPENR         DCMI_Low             // DCMI Low Power Mode Enable
#define OTGFSLPENR        OTGFS_Low		       // OTGFS Low Power Mode Enable
/*****************************************************/
/********************AHB3*****************************/
#define FMCLPENR          FMC_Low  		       // FMC Low Power Mode Enable
#define QSPILPENR         QSPI_Low 		       // QSPI Low Power Mode Enable

/**************************************************/
/********************ABP1**************************/
#define TIM2LPENR     Timer2_Low  			  // Timer 2  Low Power Mode Enable
#define TIM3LPENR     Timer3_Low              // Timer 3  Low Power Mode Enable
#define TIM4LPENR     Timer4_Low              // Timer 4  Low Power Mode Enable
#define TIM5LPENR     Timer5_Low              // Timer 5  Low Power Mode Enable
#define TIM6LPENR     Timer6_Low              // Timer 6  Low Power Mode Enable
#define TIM7LPENR     Timer7_Low              // Timer 7  Low Power Mode Enable
#define TIM12LPENR    Timer12_Low             // Timer 12 Low Power Mode Enable
#define TIM13LPENR    Timer13_Low             // Timer 13 Low Power Mode Enable
#define TIM14LPENR    Timer14_Low             // Timer 14 Low Power Mode Enable
#define WWDGLPENR     WatchDog_Low		      // WatchDog Timer Low Power Mode Enable
#define SPI2LPENR     SPI2_Low    			  // SPI2 Low Power Mode Enable
#define SPI3LPENR     SPI3_Low                // SPI3 Low Power Mode Enable
#define SPDIFRXLPENR  SPDIFRX_Low             // SPDIFRX Low Power Mode Enable
#define USART2LPENR   USART2_Low              // USART 2 Low Power Mode Enable
#define USART3LPENR   USART3_Low              // USART 3 Low Power Mode Enable
#define UART4LPENR    UART4_Low               // UART 4 Low Power Mode Enable
#define UART5LPENR    UART5_Low               // UART 5 Low Power Mode Enable
#define I2C1LPENR     I2C1_Low                // I2C 1 Low Power Mode Enable
#define I2C2LPENR     I2C2_Low                // I2C 2 Low Power Mode Enable
#define I2C3LPENR     I2C3_Low                // I2C 3 Low Power Mode Enable
#define FMPI2C1LPENR  FMPI2C_Low              // FMPI2C Low Power Mode Enable
#define CAN1LPENR     CAN1_Low                // CAN 1 Low Power Mode Enable
#define CAN2LPENR     CAN2_Low                // CAN 2 Low Power Mode Enable
#define CECLPENR      CEC_Low                 // CEC Low Power Mode Enable
#define PWRLPENR      Power_Low               // Power Low Power Mode Enable
#define DACLPENR      DAC_Low                 // DAC Low Power Mode Enable

/**************************************************/
/********************ABP2**************************/
#define TIM1LPENR     Timer1_Low  		      // Timer 1  Low Power Mode Enable
#define TIM8LPENR     Timer8_Low              // Timer 8  Low Power Mode Enable
#define USART1LPENR   USART1_Low              // USART 1 Low Power Mode Enable
#define USART6LPENR   USART6_Low              // USART 6 Low Power Mode Enable
#define ADC1LPENR     ADC1_Low                // ADC 1 Low Power Mode Enable
#define ADC2LPENR     ADC2_Low                // ADC 2 Low Power Mode Enable
#define ADC3LPENR     ADC3_Low                // ADC 3 Low Power Mode Enable
#define SDIOLPENR     SDIO_Low    		      // SDIO Low Power Mode Enable
#define SPI1LPENR     SPI2_Low    		      // SPI2 Low Power Mode Enable
#define SPI4LPENR     SPI1_Low                // SPI1 Low Power Mode Enable
#define SYSCFGLPENR   SYSCFG_Low  		      // SYSCFG Low Power Mode Enable
#define TIM9LPENR     Timer9_Low  		      // Timer 9   Low Power Mode Enable
#define TIM10LPENR    Timer10_Low             // Timer 10  Low Power Mode Enable
#define TIM11LPENR    Timer11_Low             // Timer 11  Low Power Mode Enable
#define SAI1LPENR     SAI1_Low                // SAI 1 Low Power Mode Enable
#define SAI2LPENR     SAI2_Low                // SAI 2 Low Power Mode Enable

/******************************************************************************/
/*Function: MRCC_vidClkInit		                     						  */
/*I/P Parameters: nothing						 							  */
/*Returns:it returns void                             				          */
/*Desc:This Function to enable The Clock due to Pre-configurations	   	      */
/******************************************************************************/
void MRCC_voidClkInit(void);

/******************************************************************************/
/*Function: MRCC_voidSetClkSource                          					  */
/*I/P Parameters: Copy_u32Source            								  */
/*Returns:it returns void                              				          */
/*Desc:This Function Set the Clock source for my micro-controller	          */
/******************************************************************************/
/*Options:-   - HSI 	  - HSE		   - PLL_P		   - PLL_R 				  */
/******************************************************************************/
void MRCC_voidSetClkSource (u32 copy_u32Source);


/******************************************************************************/
/*Function: RCC_vidSetClkStatus                     						  */
/*I/P Parameters: copy_u32Source , copy_u8State  							  */
/*Returns:it returns void                                			          */
/*Desc:This Function to enable or disable the clock Source	        	      */
/******************************************************************************/
/* copy_u32Source :-  - HSI_Enable    - HSE_Enable    - PLL_Enable		      */
/* copy_u8State   :-  - ON            - OFF									  */
/******************************************************************************/
void RCC_voidSetClkStatus (u32 copy_u32Source, u8 copy_u8State);

/******************************************************************************/
/*Function: MRCC_vidSetPeripheralclock                     					  */
/*I/P Parameters: copy_u8Bus , copy_u32peripheral , copy_u8State  			  */
/*Returns:it returns void                              				          */
/*Desc:This Function to enable or disable the clock for a peripheral 	      */
/******************************************************************************/
/* copy_u8Bus         :-    - AHB   - APB1   - APB2							  */
/* copy_u32peripheral :-    Choose peripheral From Configuration File		  */
/* copy_u8State       :-    - ON    - OFF									  */
/******************************************************************************/
void MRCC_voidSetPeripheralclock (u8 copy_u8Bus, u32 copy_u32peripheral, u8 copy_u8State);

/**************************************************************************************************/
/*Function: MRCC_voidSetPeripheralclockLowPowerMode            				  					  */
/*I/P Parameters: Copy_u8Bus , Copy_u32peripheral , Copy_u8State  			  					  */
/*Returns:it returns void                              				  					 		  */
/*Desc:This Function to enable or disable the clock for a peripheral in low power mode  	      */
/**************************************************************************************************/
/* Copy_u8Bus         :-    - AHB1   - AHB2   - AHB3   - APB1   - APB2		  					  */
/* Copy_u32peripheral :-    Choose peripheral From Interface File	    	  					  */
/* Copy_u8State       :-    - ON    - OFF									  					  */
/**************************************************************************************************/
void MRCC_voidSetPeripheralclockLowPowerMode (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State);


/******************************************************************************/
/*Function: MRCC_voidResetPeripheralclock                     				  */
/*I/P Parameters: Copy_u8Bus , Copy_u32peripheral , Copy_u8State  			  */
/*Returns:it returns void                              				          */
/*Desc:This Function to Reset the clock for a peripheral 				      */
/******************************************************************************/
/* Copy_u8Bus         :-    - AHB1   - AHB2   - AHB3   - APB1   - APB2		  */
/* Copy_u32peripheral :-    Choose peripheral From Interface File	    	  */
/* Copy_u8State       :-    - Reset    - NotToReset							  */
/******************************************************************************/
void MRCC_voidResetPeripheralclock (u8 Copy_u8Bus, u32 Copy_u32peripheral, u8 Copy_u8State);




#endif /* __RCC_INT_H */
