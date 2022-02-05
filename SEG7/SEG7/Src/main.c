/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */
#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/SEG7/SEG7_Interface.h"


int main(void)
{
    u8 i=0;

	MDIO_VoidInit();
    HSEG7_VoidInit();
    _delay_ms(500);
	while(1)
	{
		for(i=0;i<10;i++)
		{
			HSEG7_VoidDisplayNumber(i);
			_delay_ms(500);
		}
	}

	return 1;
}
