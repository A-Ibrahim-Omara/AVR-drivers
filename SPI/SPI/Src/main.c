

#define  F_CPU 8000000UL
#include "../INCLUDE/MCAL/DIO/DIO_Interface.h"
#include "../INCLUDE/MCAL/SPI/SPI_Interface.h"
#include "util/delay.h"

void main(void)
{
	u8 i;
	MDIO_VoidInit();
	//HLCD_VoidInit();
	//SPI_voidMasterInit();
	/**/
	while(1)
	{
		for( i=0;i<100;i++)
		{
			SPI_voidTransive(i);
			//HLCD_VoidDisplayNumber(i);
			_delay_ms(500);
			//HLCD_VoidClearDisplay();
		}
	}
}



