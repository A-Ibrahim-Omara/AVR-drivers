/*
 * SERVO_Program.c
 *
 *  Created on: Jan 30, 2022
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

void SERVO_voidSetAngel(s8 local_s8_angel)
{
	u16 RegValue=1500;
	if( local_s8_angel>=-90 && local_s8_angel<=90 )
	{
		if(local_s8_angel>0)
		{
			RegValue+=((1000.0/180.0)*local_s8_angel);
		}
		else if(local_s8_angel<0)
		{
			RegValue=1000+((1000.0/180.0)*(90+local_s8_angel));
		}
		else
		{

		}
		TIMER1_u8_OCR1A_REG=RegValue;
	}
}
