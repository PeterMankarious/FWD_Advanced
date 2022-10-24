#include "../MCAL/GPIO/GPIO.h"

int main(void)
{
	initGPIO(PORT_A,0,OUTPUT);
	while(1)
	{
		writeGPIO(PORT_A,0,1);
	}
	return 0;
}
