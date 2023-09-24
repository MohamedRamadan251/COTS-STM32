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
 *  * 1- MRCC_voidSetPLLConfigurations: this is a private Function which Configures The PLL
 * ******************************************************************************************************************
 * This File contains the RCC Privates for all CLK Private Configurations Needed in any Other Peripheral
 * ******************************************************************************************************************
 */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MCAL_RCC_PRIV_H
#define _MCAL_RCC_PRIV_H

/**************************************************/
/* Description : Definitions for On & Off States  */
/**************************************************/
#define ON  		1
#define OFF 		0
#define Reset 		1
#define NotToReset	0
/**************************************************/
/* Description : Definitions for RCC Base Address */
/**************************************************/
#define RCC ((volatile RCC_t*) 0x40023800)

/**************************************************/
/* Description : Definitions for Sources of clock */
/**************************************************/
#define HSI_SOURCE   0
#define HSE_SOURCE   1
#define PLL_P_SOURCE 2
#define PLL_R_SOURCE 3

/**************************************************/
/* Description : Definitions for System Buses	  */
/**************************************************/
#define AHB1_BUS     0
#define AHB2_BUS     2
#define AHB3_BUS     5
#define APB1_BUS     7
#define APB2_BUS     9



/**************************************************/
/* Description : Definitions for Sources of clock */
/**************************************************/
#define HSI_CLK_STATUS    (0)
#define HSE_CLK_STATUS    (16)
#define PLL_CLK_STATUS    (24)
#define PLLI2S_CLK_STATUS (26)
#define PLLSAI_CLK_STATUS (28)

/**************************************************/
/*Description: Definitions for Sources bits reset */
/**************************************************/
#define SW_Resetmask (~0x3)


/********************************************************/
/* Description : RCC Registers mapping using structure  */
/********************************************************/
typedef struct
{
  /*Clock control register (RCC_CR)*/
  volatile u32 RCC_CR;
  /*Clock configuration register (RCC_PLLCFGR)*/
  volatile u32 RCC_PLLCFGR;
  /*Clock configuration register (RCC_CFGR)*/
  volatile u32 RCC_CFGR;
  /*Clock interrupt register (RCC_CIR)*/
  volatile u32 RCC_CIR;
  /*RCC APB1 peripheral reset register (RCC_APB1RSTR)*/
  volatile u32 RCC_AHB1RSTR;
  /*RCC APB2 peripheral reset register (RCC_APB2RSTR)*/
  volatile u32 RCC_AHB2RSTR;
  /*RCC APB3 peripheral reset register (RCC_APB3RSTR)*/
  volatile u32 RCC_AHB3RSTR;
  /* Reserved Address */
  u32 Reserved1;
  /*APB1 peripheral reset register (RCC_APB1RSTR)*/
  volatile u32 RCC_APB1RSTR;
  /*APB2 peripheral reset register (RCC_APB2RSTR)*/
  volatile u32 RCC_APB2RSTR;
  /* Reserved Address */
  u32 Reserved2;
  /* Reserved Address */
  u32 Reserved3;
  /*AHB Peripheral Clock enable register (RCC_AHBENR)*/
  volatile u32 RCC_AHB1ENR;
    /*AHB Peripheral Clock enable register (RCC_AHBENR)*/
  volatile u32 RCC_AHB2ENR;
    /*AHB Peripheral Clock enable register (RCC_AHBENR)*/
  volatile u32 RCC_AHB3ENR;
  u32 Reserved4;
  /*APB1 peripheral clock enable register (RCC_APB1ENR)*/
  volatile u32 RCC_APB1ENR;
  /*APB2 peripheral clock enable register (RCC_APB2ENR)*/
  volatile u32 RCC_APB2ENR;
  /* Reserved Address */
  u32 Reserved5;
  /* Reserved Address */
  u32 Reserved6;
  /*RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)*/
  volatile u32 RCC_AHB1LPENR;
  /*RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)*/
  volatile u32 RCC_AHB2LPENR;
  /*RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)*/
  volatile u32 RCC_AHB3LPENR;
  /* Reserved Address */
  u32 Reserved7;
  /* RCC APB1 peripheral clock enabled in low power mode register (RCC_APB1LPENR) */
  volatile u32 RCC_APB1LPENR;
  /* RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR) */
  volatile u32 RCC_APB2LPENR;
  /* Reserved Address */
  u32 Reserved8;
  /* Reserved Address */
  u32 Reserved9;
  /*Backup domain control register (RCC_BDCR)*/
  volatile u32 RCC_BDCR;
  /*Control/status register (RCC_CSR)*/
  volatile u32 RCC_CSR;
  /* Reserved Address */
  u32 Reserved10;
  /* Reserved Address */
  u32 Reserved11;
  /*RCC spread spectrum clock generation register (RCC_SSCGR)*/
  volatile u32 RCC_SSCGR;
  /*RCC PLLI2S configuration register (RCC_PLLI2SCFGR)*/
  volatile u32 RCC_PLLI2SCFGR;
  /*RCC PLL configuration register (RCC_PLLSAICFGR)*/
  volatile u32 RCC_PLL_SAICFGR;
  /*RCC dedicated clock configuration register (RCC_DCKCFGR)*/
  volatile u32 RCC_DCKCFGR;
  /*RCC clocks gated enable register (CKGATENR)*/
  volatile u32 RCC_CKGATENR;
  /*RCC dedicated clocks configuration register 2 (DCKCFGR2)*/
  volatile u32 RCC_DCKCFGR2;
}RCC_t;


/**************************************************/
/*Description: Definitions for Error Status   */
/**************************************************/
#define NotOk  0
#define OK 1
#define OutOfRange 2

#define CFGR_SW0_Bit      0
#define CFGR_SW1_Bit      1
#define CR_HSI_RDY_BIT    1
#define CR_HSE_RDY_BIT    17
#define CR_PLL_RDY_BIT    25
#define CR_PLLI2S_RDY_BIT 27
#define CR_PLLSAI_RDY_BIT 29
#define PLLCFGR_PLLSRC    22

#define Prescaler_ResetMask (~0x780000)

/**************************************************/
/*Description: Definitions for Peripheral         */
/**************************************************/
/**************************************************/
/********************AHB1**************************/
#define GPIOA_Enable     1 << 0         // GPIOA Enable
#define GPIOB_Enable     1 << 1         // GPIOB Enable
#define GPIOC_Enable     1 << 2         // GPIOC Enable
#define GPIOD_Enable     1 << 3         // GPIOD Enable
#define GPIOE_Enable     1 << 4         // GPIOE Enable
#define GPIOF_Enable     1 << 5         // GPIOF Enable
#define GPIOG_Enable     1 << 6         // GPIOG Enable
#define GPIOH_Enable     1 << 7         // GPIOH Enable
#define CRC_Enable       1 << 12        // CRC Enable
#define BKPSRAM_Enable   1 << 18        // BKPSRAM Enable
#define DMA1_Enable      1 << 21        // DMA 1 Enable
#define DMA2_Enable      1 << 22        // DMA 2 Enable
#define OTGHS_Enable     1 << 29        // OTGHS Enable
#define OTGHSULPI_Enable 1 << 30        // OTGHSULPI Enable
/**************************************************/
/********************AHB2**************************/
#define DCMI_Enable         1 << 0      // DCMI Enable
#define OTGFS_Enable        1 << 7	    // OTGFS Enable
/**************************************************/
/********************AHB3**************************/
#define FMC_Enable         1 << 0	    // FMC Enable
#define QSPI_Enable        1 << 1	    // QSPI Enable

/**************************************************/
/********************ABP1**************************/
#define Timer2_Enable         1<<0			   // Timer 2  Enable
#define Timer3_Enable         1<<1             // Timer 3  Enable
#define Timer4_Enable         1<<2             // Timer 4  Enable
#define Timer5_Enable         1<<3             // Timer 5  Enable
#define Timer6_Enable         1<<4             // Timer 6  Enable
#define Timer7_Enable         1<<5             // Timer 7  Enable
#define Timer12_Enable        1<<6             // Timer 12 Enable
#define Timer13_Enable        1<<7             // Timer 13 Enable
#define Timer14_Enable        1<<8             // Timer 14 Enable
#define WatchDog_Enable       1<<11		       // WatchDog Timer Enable
#define SPI2_Enable           1<<14			   // SPI2 Enable
#define SPI3_Enable           1<<15            // SPI3 Enable
#define SPDIFRX_Enable        1<<16            // SPDIFRX Enable
#define USART2_Enable         1<<17            // USART 2 Enable
#define USART3_Enable         1<<18            // USART 3 Enable
#define UART4_Enable          1<<19            // UART 4 Enable
#define UART5_Enable          1<<20            // UART 5 Enable
#define I2C1_Enable           1<<21            // I2C 1 Enable
#define I2C2_Enable           1<<22            // I2C 2 Enable
#define I2C3_Enable           1<<23            // I2C 3 Enable
#define FMPI2C_Enable         1<<24            // FMPI2C Enable
#define CAN1_Enable           1<<25            // CAN 1 Enable
#define CAN2_Enable           1<<26            // CAN 2 Enable
#define CEC_Enable            1<<27            // CEC Enable
#define Power_Enable          1<<28            // Power Enable
#define DAC_Enable            1<<29            // DAC Enable

/**************************************************/
/********************ABP2**************************/
#define Timer1_Enable         1<<0			   // Timer 1  Enable
#define Timer8_Enable         1<<1             // Timer 8  Enable
#define USART1_Enable         1<<4             // USART 1 Enable
#define USART6_Enable         1<<5             // USART 6 Enable
#define ADC1_Enable           1<<8             // ADC 1 Enable
#define ADC2_Enable           1<<9             // ADC 2 Enable
#define ADC3_Enable           1<<10            // ADC 3 Enable
#define SDIO_Enable           1<<11			   // SDIO Enable
#define SPI2_Enable           1<<12			   // SPI2 Enable
#define SPI1_Enable           1<<13            // SPI1 Enable
#define SYSCFG_Enable         1<<14			   // SYSCFG Enable
#define Timer9_Enable         1<<16      	   // Timer 9   Enable
#define Timer10_Enable        1<<17            // Timer 10  Enable
#define Timer11_Enable        1<<18            // Timer 11  Enable
#define SAI1_Enable           1<<22            // SAI 1 Enable
#define SAI2_Enable           1<<23            // SAI 2 Enable


/********************************************************
/********************************************************
/********************************************************
/********************************************************
/********************************************************
/**************************************************/
/*Description: Definitions for Peripheral         */
/**************************************************/
/**************************************************/
/********************AHB1**************************/
#define GPIOA_Reset        1 << 0         // GPIOA Reset
#define GPIOB_Reset        1 << 1         // GPIOB Reset
#define GPIOC_Reset        1 << 2         // GPIOC Reset
#define GPIOD_Reset        1 << 3         // GPIOD Reset
#define GPIOE_Reset        1 << 4         // GPIOE Reset
#define GPIOF_Reset        1 << 5         // GPIOF Reset
#define GPIOG_Reset        1 << 6         // GPIOG Reset
#define GPIOH_Reset        1 << 7         // GPIOH Reset
#define CRC_Reset          1 << 12        // CRC Reset
#define DMA1_Reset         1 << 21        // DMA 1 Reset
#define DMA2_Reset         1 << 22        // DMA 2 Reset
#define OTGHS_Reset        1 << 29        // OTGHS Reset
/**************************************************/
/********************AHB2**************************/
#define DCMI_Reset         1 << 0         // DCMI Reset
#define OTGFS_Reset        1 << 7   	  // OTGFS Reset
/**************************************************/
/********************AHB3**************************/
#define FMC_Reset          1 << 0		   // FMC Reset
#define QSPI_Reset         1 << 1		   // QSPI Reset

/**************************************************/
/********************ABP1**************************/
#define Timer2_Reset       1 << 0		   // Timer 2  Reset
#define Timer3_Reset       1 << 1          // Timer 3  Reset
#define Timer4_Reset       1 << 2          // Timer 4  Reset
#define Timer5_Reset       1 << 3          // Timer 5  Reset
#define Timer6_Reset       1 << 4          // Timer 6  Reset
#define Timer7_Reset       1 << 5          // Timer 7  Reset
#define Timer1_Reset       1 << 6          // Timer 12 Reset
#define Timer13_Reset      1 << 7          // Timer 13 Reset
#define Timer14_Reset      1 << 8          // Timer 14 Reset
#define WatchDog_Timer     1 << 11		   // WatchDog Timer
#define SPI2_Reset         1 << 14		   // SPI2 Reset
#define SPI3_Reset         1 << 15         // SPI3 Reset
#define SPDIFRX_Reset      1 << 16         // SPDIFRX Reset
#define USART2_Reset       1 << 17         // USART 2 Reset
#define USART3_Reset       1 << 18         // USART 3 Reset
#define UART4_Reset        1 << 19         // UART 4 Reset
#define UART5_Reset        1 << 20         // UART 5 Reset
#define I2C1_Reset         1 << 21         // I2C 1 Reset
#define I2C2_Reset         1 << 22         // I2C 2 Reset
#define I2C3_Reset         1 << 23         // I2C 3 Reset
#define FMPI2C_Reset       1 << 24         // FMPI2C Reset
#define CAN1_Reset         1 << 25         // CAN 1 Reset
#define CAN2_Reset         1 << 26         // CAN 2 Reset
#define CEC_Reset          1 << 27         // CEC Reset
#define Power_Reset        1 << 28         // Power Reset
#define DAC_Reset          1 << 29         // DAC Reset

/**************************************************/
/********************ABP2**************************/
#define Timer1_Reset       1 << 0		   // Timer 1  Reset
#define Timer8_Reset       1 << 1          // Timer 8  Reset
#define USART1_Reset       1 << 4          // USART 1 Reset
#define USART6_Reset       1 << 5          // USART 6 Reset
#define ADC1_Reset         1 << 8          // ADC 1 Reset
#define SDIO_Reset         1 << 11		   // SDIO Reset
#define SPI2_Reset         1 << 12		   // SPI2 Reset
#define SPI1_Reset         1 << 13         // SPI1 Reset
#define SYSCFG_Reset       1 << 14		   // SYSCFG Reset
#define Timer9_Reset       1 << 16		   // Timer 9   Reset
#define Timer10_Reset      1 << 17         // Timer 10  Reset
#define Timer11_Reset      1 << 18         // Timer 11  Reset
#define SAI1_Reset         1 << 22         // SAI 1 Reset
#define SAI2_Reset         1 << 23         // SAI 2 Reset

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
#define GPIOA_Low       1 << 0         // GPIOA Low Power Mode Enable
#define GPIOB_Low       1 << 1         // GPIOB Low Power Mode Enable
#define GPIOC_Low       1 << 2         // GPIOC Low Power Mode Enable
#define GPIOD_Low       1 << 3         // GPIOD Low Power Mode Enable
#define GPIOE_Low       1 << 4         // GPIOE Low Power Mode Enable
#define GPIOF_Low       1 << 5         // GPIOF Low Power Mode Enable
#define GPIOG_Low       1 << 6         // GPIOG Low Power Mode Enable
#define GPIOH_Low       1 << 7         // GPIOH Low Power Mode Enable
#define CRC_Low         1 << 12        // CRC Low Power Mode Enable
#define FLITF_Low	    1 << 15        // FLITF Low Power Mode Enable
#define FLITF_Low	    1 << 16        // FLITF Low Power Mode Enable
#define FLITF_Low	    1 << 17        // FLITF Low Power Mode Enable
#define BKPSRAM_Low	    1 << 18        // BKPSRAM Low Power Mode Enable
#define DMA1_Low        1 << 21        // DMA 1 Low Power Mode Enable
#define DMA2_Low        1 << 22        // DMA 2 Low Power Mode Enable
#define OTGHS_Low       1 << 29        // OTGHS Low Power Mode Enable
#define OTGHSULPI_Low   1 << 30        // OTGHSULPI Low Power Mode Enable
/**************************************************/
/********************AHB2**************************/
#define DCMI_Low         1 << 0        // DCMI Low Power Mode Enable
#define OTGFS_Low        1 << 7		   // OTGFS Low Power Mode Enable
/**************************************************/
/********************AHB3**************************/
#define FMC_Low          1 << 0		   // FMC Low Power Mode Enable
#define QSPI_Low         1 << 1		   // QSPI Low Power Mode Enable

/**************************************************/
/********************ABP1**************************/
#define Timer2_Low       1 << 0		   // Timer 2  Low Power Mode Enable
#define Timer3_Low       1 << 1        // Timer 3  Low Power Mode Enable
#define Timer4_Low       1 << 2        // Timer 4  Low Power Mode Enable
#define Timer5_Low       1 << 3        // Timer 5  Low Power Mode Enable
#define Timer6_Low       1 << 4        // Timer 6  Low Power Mode Enable
#define Timer7_Low       1 << 5        // Timer 7  Low Power Mode Enable
#define Timer12_Low      1 << 6        // Timer 12 Low Power Mode Enable
#define Timer13_Low      1 << 7        // Timer 13 Low Power Mode Enable
#define Timer14_Low      1 << 8        // Timer 14 Low Power Mode Enable
#define WatchDog_Low     1 << 11	   // WatchDog Timer Low Power Mode Enable
#define SPI2_Low         1 << 14	   // SPI2 Low Power Mode Enable
#define SPI3_Low         1 << 15       // SPI3 Low Power Mode Enable
#define SPDIFRX_Low      1 << 16       // SPDIFRX Low Power Mode Enable
#define USART2_Low       1 << 17       // USART 2 Low Power Mode Enable
#define USART3_Low       1 << 18       // USART 3 Low Power Mode Enable
#define UART4_Low        1 << 19       // UART 4 Low Power Mode Enable
#define UART5_Low        1 << 20       // UART 5 Low Power Mode Enable
#define I2C1_Low         1 << 21       // I2C 1 Low Power Mode Enable
#define I2C2_Low         1 << 22       // I2C 2 Low Power Mode Enable
#define I2C3_Low         1 << 23       // I2C 3 Low Power Mode Enable
#define FMPI2C_Low       1 << 24       // FMPI2C Low Power Mode Enable
#define CAN1_Low         1 << 25       // CAN 1 Low Power Mode Enable
#define CAN2_Low         1 << 26       // CAN 2 Low Power Mode Enable
#define CEC_Low          1 << 27       // CEC Low Power Mode Enable
#define Power_Low        1 << 28       // Power Low Power Mode Enable
#define DAC_Low          1 << 29       // DAC Low Power Mode Enable

/**************************************************/
/********************ABP2**************************/
#define Timer1_Low       1 << 0	       // Timer 1  Low Power Mode Enable
#define Timer8_Low       1 << 1        // Timer 8  Low Power Mode Enable
#define USART1_Low       1 << 4        // USART 1 Low Power Mode Enable
#define USART6_Low       1 << 5        // USART 6 Low Power Mode Enable
#define ADC1_Low         1 << 8        // ADC 1 Low Power Mode Enable
#define ADC2_Low         1 << 9        // ADC 2 Low Power Mode Enable
#define ADC3_Low         1 << 10       // ADC 3 Low Power Mode Enable
#define SDIO_Low         1 << 11	   // SDIO Low Power Mode Enable
#define SPI2_Low         1 << 12	   // SPI2 Low Power Mode Enable
#define SPI1_Low         1 << 13       // SPI1 Low Power Mode Enable
#define SYSCFG_Low       1 << 14	   // SYSCFG Low Power Mode Enable
#define Timer9_Low       1 << 16	   // Timer 9   Low Power Mode Enable
#define Timer10_Low      1 << 17       // Timer 10  Low Power Mode Enable
#define Timer11_Low      1 << 18       // Timer 11  Low Power Mode Enable
#define SAI1_Low         1 << 22       // SAI 1 Low Power Mode Enable
#define SAI2_Low         1 << 23       // SAI 2 Low Power Mode Enable


/******************************************************************************/
/*Function: MRCC_voidSetPLLConfigurations                          			  */
/*I/P Parameters: void			            								  */
/*Returns:it returns void		                              				  */
/*Desc:This Function Configure the PLL CFGR							          */
/******************************************************************************/
void MRCC_voidSetPLLConfigurations(void);




#endif /* __RCC_PRIV_H */
