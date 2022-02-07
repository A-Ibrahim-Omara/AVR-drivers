/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>

#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/INTERRUPT/EXTI_Interface.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
//#include "../Include/HAL/LCD/LCD_Interface.h"
//#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"

/*
void TOGGLE(void)
{
	static u8 flag =0;
	flag^=1;
	MDIO_VoidSetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,flag);
}

void Seg7_Incre(void)
{
	static u8 count=0;
    count++;
	if(count==10)
	{
		count=0;
	}
		HSEG7_VoidDisplayNumber(count);
}
*/
int main(void)
{

	MDIO_VoidInit();
	//HSEG7_VoidInit();
	//MEXTI_voidSetCallBack(Seg7_Incre,EXTI_u8_EXTI2);
	MEXTI_voidEXTIEnable(2,EXTI_u8_FALLING_MODE);
	MGI_voidEnable();

	while(1)
	{

	}
	return 1;
}

