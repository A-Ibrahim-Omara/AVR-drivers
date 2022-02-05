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
#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/HAL/SERVO_MOTOR/SERVO_Interface.h"


int main(void)
{
	MDIO_VoidInit();
    //MDIO_VoidSetPortDirection(DIO_U8_PORTA,DIO_U8_PORT_OUTPUT);
	MDIO_VoidSetPortDirection(DIO_U8_PORTD,DIO_U8_PORT_OUTPUT);
	//MDIO_VoidSetPortDirection(DIO_U8_PORTB,0x0f);
	//MTIMERS_voidTimer0Init(230);
	 MTIMERS_voidTimer1Init();
	 SERVO_voidSetAngel(-70);
	 //HLCD_VoidInit();
	// ADC_voidInit();
	// ADC_u16GetDigitlValue(ADC_u8_CHANNEL_3);
	//MTIMERS_voidTimer0OVFSetCallBack(TOGGLE);
	//MTIMERS_voidTimer0CTCSetCallBack(TOGGLE);
	//MGI_voidEnable();
	 u16 Dig_read,Ana_read;
	while(1)
	{
		//Dig_read=ADC_u16GetDigitlValue(ADC_u8_CHANNEL_3);
	//	Ana_read=Dig_read/1000.0;
	} /***********_WHILE(1)_CURLE_***************/
	return 1;
}  /***********_MAIN_CURLE_***************/

