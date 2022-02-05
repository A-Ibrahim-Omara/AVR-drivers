/*
 * TIMER1_Program.c
 *
 *  Created on: Jan 25, 2022
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

#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Interface.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Private.h"
#include "../Include/MCAL/GLOBAL_INTERRUPT/GI_Cfg.h"

#include "../Include/MCAL/TIMER1/TIMER1_Private.h"
#include "../Include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_Cfg.h"

void MTIMERS_voidTimer1Init(void)
{
	SET_BIT(TIMER1_u8_TCCR1A,7);
	CLR_BIT(TIMER1_u8_TCCR1A,6);

	CLR_BIT(TIMER1_u8_TCCR1A,0);
	SET_BIT(TIMER1_u8_TCCR1A,1);
	SET_BIT(TIMER1_u8_TCCR1B,3);
	SET_BIT(TIMER1_u8_TCCR1B,4);

	TIMER1_u8_OCR1A=1500;
	TIMER1_u8_ICR1=19999;

	CLR_BIT(TIMER1_u8_TCCR1B,0);
    SET_BIT(TIMER1_u8_TCCR1B,1);
	CLR_BIT(TIMER1_u8_TCCR1B,2);
}

