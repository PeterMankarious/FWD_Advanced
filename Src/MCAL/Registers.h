#ifndef REGISTERS_H 
#define REGISTERS_H
/*- INCLUDES -----------------------------------------------*/
#include "../Libraries/Types.h"
/*- CONSTANTS ----------------------------------------------*/
	
	/* System */
#define SYSCTRL_BASE 0x400FE000

#define GPIOHBCTL_OFFSET 0x06C
#define RCGCGPIO_OFFSET 0x608

#define GPIOHBCTL *((volatile uint32_t*)(SYSCTRL_BASE + GPIOHBCTL_OFFSET))
#define RCGCGPIO *((volatile uint32_t*)(SYSCTRL_BASE + RCGCGPIO_OFFSET))
	/* Ports */
#define PORTA_BASE_APB 0x40004000
#define PORTA_BASE_AHB 0x40058000

#define GPIODIR_OFFSET 0x400
#define GPIOAFSEL_OFFSET 0x420
#define GPIODR2R_OFFSET 0x500
#define GPIODR4R_OFFSET 0x504
#define GPIODR8R_OFFSET 0x508
#define GPIOODR_OFFSET 0x50C
#define GPIOPUR_OFFSET 0x510
#define GPIOPDR_OFFSET 0x514
#define GPIOSLR_OFFSET 0x518
#define GPIODEN_OFFSET 0x51C
#define GPIOAMSEL_OFFSET 0x528

#define PORTA_DIR *((volatile uint32_t*)(PORTA_BASE_AHB + GPIODIR_OFFSET))
#define PORTA_AFSEL *((volatile uint32_t*)(PORTA_BASE_AHB + GPIOAFSEL_OFFSET))
#define PORTA_DR2R *((volatile uint32_t*)(PORTA_BASE_AHB + GPIODR2R_OFFSET))
#define PORTA_DR4R *((volatile uint32_t*)(PORTA_BASE_AHB + GPIODR4R_OFFSET))
#define PORTA_DR8R *((volatile uint32_t*)(PORTA_BASE_AHB + GPIODR8R_OFFSET))
#define PORTA_ODR *((volatile uint32_t*)(PORTA_BASE_AHB + GPIOODR_OFFSET))
#define PORTA_PUR *((volatile uint32_t*)(PORTA_BASE_AHB + GPIOPUR_OFFSET))
#define PORTA_PDR *((volatile uint32_t*)(PORTA_BASE_AHB + GPIOPDR_OFFSET))
#define PORTA_SLR *((volatile uint32_t*)(PORTA_BASE_AHB + GPIOSLR_OFFSET))
#define PORTA_DEN *((volatile uint32_t*)(PORTA_BASE_AHB + GPIODEN_OFFSET))


#define PORTA *((volatile uint32_t*)0x00000000)
/*- PRIMITIVE TYPES ----------------------------------------*/
/*- ENUMS --------------------------------------------------*/
/*- STRUCTS AND UNIONS -------------------------------------*/
/*- FUNCTION-LIKE MACROS -----------------------------------*/
/*- FUNCTION DECLARATIONS ----------------------------------*/
#endif  /*Registers.h*/
