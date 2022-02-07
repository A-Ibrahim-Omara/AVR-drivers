/*
 * TIMER1_Program.c
 *
 *  Created on: Jan 25, 2022
 *      Author: Ahmed Ibrahim
 */

#include <stdio.h>
#include <stdlib.h>

#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"

#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Interface.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Private.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Cfg.h"

#include "../Include/MCAL/TIMER1/TIMER1_Private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_Cfg.h"

/*-------------------------------------------------------------*/

void MTIMERS_voidTimer1Init(void)
{
	SET_BIT(TIMER1_u8_TCCR1A_REG,TCCR1A_u8_COM1A1_PIN7);
	CLR_BIT(TIMER1_u8_TCCR1A_REG,TCCR1A_u8_COM1A0_PIN6);

	CLR_BIT(TIMER1_u8_TCCR1A_REG,TCCR1A_u8_WGM10_PIN0);
	SET_BIT(TIMER1_u8_TCCR1A_REG,TCCR1A_u8_WGM11_PIN1);
	
	SET_BIT(TIMER1_u8_TCCR1B_REG,TCCR1B_u8_WGM12_PIN3);
	SET_BIT(TIMER1_u8_TCCR1B_REG,TCCR1B_u8_WGM13_PIN4);

	TIMER1_u8_OCR1A_REG=1500;
	TIMER1_u8_ICR1_REG=19999;

	CLR_BIT(TIMER1_u8_TCCR1B_REG,TCCR1B_u8_CS10_PIN0);
    SET_BIT(TIMER1_u8_TCCR1B_REG,TCCR1B_u8_CS11_PIN1);
	CLR_BIT(TIMER1_u8_TCCR1B_REG,TCCR1B_u8_CS12_PIN2);
}
/*-------------------------------------------------------------*/

