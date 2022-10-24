#ifndef GPIO_H
#define GPIO_H
/*- INCLUDES -----------------------------------------------*/
#include "../Registers.h"
/*- CONSTANTS ----------------------------------------------*/
	/* Ports */
	#define PORT_A 0

	/* Directions */
	#define INPUT 0
	#define OUTPUT 1
	
	/* Values */
	#define LOW 0
	#define HIGH 1
	
/*- PRIMITIVE TYPES ----------------------------------------*/
/*- ENUMS --------------------------------------------------*/
/*- STRUCTS AND UNIONS -------------------------------------*/
/*- FUNCTION-LIKE MACROS -----------------------------------*/

#define GPIODATA_WRITE(BASE,MASK,DATA) *((volatile uint32_t*)((BASE) + ((MASK)<<2))) = (DATA) 
	
/*- FUNCTION DECLARATIONS ----------------------------------*/
int initGPIO(int portNumber, int pinNumber, int direction);
int writeGPIO(int portNumber, int pinNumber, uint32_t value);
#endif  /*GPIO.h*/





