/*
 * ADC_Program.c
 *
 *  Created on: Jan 17, 2022
 *      Author: Ahmed Ibrahim
 */

#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/HAL/LCD/LCD_Cfg.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/LCD/LCD_Private.h"
#include "../Include/MCAL/ADC/ADC_Private.h"
#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/MCAL/ADC/ADC_Cfg.h"

void ADC_voidInit(void)
{
	/*Vref = AVCC*/
	CLR_BIT(ADC_u8_ADMUX_REG,6);
	CLR_BIT(ADC_u8_ADMUX_REG,7);

	/*right adj*/
	CLR_BIT(ADC_u8_ADMUX_REG,5);

	/*disable auto trigger*/
	CLR_BIT(ADC_u8_ADCSRA_REG,5);

	/*Prescaler 64*/
	CLR_BIT(ADC_u8_ADCSRA_REG,0);
	SET_BIT(ADC_u8_ADCSRA_REG,1);
	SET_BIT(ADC_u8_ADCSRA_REG,2);

	/*Enable ADC*/
	SET_BIT(ADC_u8_ADCSRA_REG,7);

}

u16 ADC_u16GetDigitlValue(u8 copy_u8_ChannelNumber)
{
	u16 local_u16DigitalValue;
	if(copy_u8_ChannelNumber<32)
	{
		/*Clear MUX4...0*/
		ADC_u8_ADMUX_REG &= 0xE0;

		/*SELECT CHANNEL*/
		ADC_u8_ADMUX_REG|= copy_u8_ChannelNumber;
		/*START CONVERSION*/
		SET_BIT(ADC_u8_ADCSRA_REG,6);

		while((GET_BIT(ADC_u8_ADCSRA_REG,4)==0))
		{
			/**/
		}

		if(GET_BIT(ADC_u8_ADCSRA_REG,4)!=0)
		{
			/*Clear flag*/
			SET_BIT(ADC_u8_ADCSRA_REG,4);

			/*Get Digital Value From REGISTER*/
			local_u16DigitalValue=ADC_u8_ADC_REG;
		}
	}

	return local_u16DigitalValue;
}
