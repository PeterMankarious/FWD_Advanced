/*- INCLUDES ----------------------------------------------*/
#include "GPIO.h"
/*- LOCAL MACROS ------------------------------------------*/
/*- LOCAL Dataypes ----------------------------------------*/
/*- LOCAL FUNCTIONS PROTOTYPES ----------------------------*/
/*- GLOBAL STATIC VARIABLES -------------------------------*/
/*- GLOBAL EXTERN VARIABLES -------------------------------*/
/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
int initGPIO(int portNumber, int pinNumber,int direction)
{
	if(pinNumber <0 || pinNumber > 7)
	{
		return 1; /* invalid pinNumber */
	}
	
	switch (portNumber)
	{
		case PORT_A:
		/* enable clock using RCGCGPIO register */
		RCGCGPIO |= 1;
		/* Activate AHB */
		GPIOHBCTL |= 1;
		/* Set direction using GPIODIR register */
		if(direction == INPUT) {PORTA_DIR &= ~(1<<pinNumber);}
		else if(direction == OUTPUT) {PORTA_DIR |= (1<<pinNumber); }
		else {return 3; /* invalid direction */}
		
		/* Configure GPIOAFSEL to set it to GPIO*/
		PORTA_AFSEL &= ~(1<<pinNumber);
		
		/* Set drive strength using GPIODR2R, GPIODR4R and GPIO DR8R*/
		PORTA_DR2R |= (1<<pinNumber); /* The other 2 will be reset by hardware */
		
		/* Configure Pull-up/down or open drain  using GPIOPUR GPIOPDR and GPIOODR */
		PORTA_PUR &= ~(1<<pinNumber);
		PORTA_PDR &= ~(1<<pinNumber);
		PORTA_ODR &= ~(1<<pinNumber);
		/* Enable GPIO as digital I/O using GPIODEN */
		PORTA_DEN |= 1<<pinNumber;
		break;
		default: return 2; /* invalid portNumber*/
	}
	
	return 0; /* no errors */
}

int writeGPIO(int portNumber, int pinNumber, uint32_t value)
{
	if(pinNumber <0 || pinNumber > 7)
	{
		return 1; /* invalid pinNumber */
	}
	
	switch(portNumber)
	{
		case PORT_A:
		GPIODATA_WRITE(PORTA_BASE_AHB,(1<<pinNumber),(value<<pinNumber));
	}
	return 0; /* no errors */
}
/*- APIs IMPLEMENTATION -----------------------------------*/
