/*
 * SEG7_Program.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */
#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/SEG7/SEG7_Cfg.h"
#include "../Include/HAL/SEG7/SEG7_Interface.h"


void HSEG7_VoidInit(void)
{
	MDIO_VoidSetPortDirection(SEG7_U8_PORT,SEG7_U8_PORT_OUTPUT);
	if(SEG7_INIT_VALUE!=0)
	{
		MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_INIT_VALUE);
	}
}

/***************************************************************/

/***************************************************************/
void HSEG7_VoidDisplayNumber(u8 copy_u8Number)
{
    if(copy_u8Number <= NINE)
    {
    	switch(copy_u8Number)
    	{
    			case ZERO:
    				MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_ZERO);
    				break;
    			case ONE:
    	    		MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_ONE);
    	    		break;
    			case TWO:
    	    		MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_TWO);
    	    		break;
    			case THREE:
    	    		MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_THREE);
    	    		break;
    	        case FOUR:
    	    		MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_FOUR);
    	    		break;
    	    	case FIVE:
    	    	    MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_FIVE);
    	    	    break;
    	    	case SIX:
    	    	    MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_SIX);
    	    	    break;
    	    	case SEVEN:
    	    	    MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_SEVEN);
    	    	    break;
    	    	case EIGHT:
    	    	    MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_EIGHT);
    	    	    break;
    	    	 case NINE:
    	    	    MDIO_VoidSetPortValue(SEG7_U8_PORT,SEG7_SELECT_VALUE_NINE);
    	    	    break;
    	}
    }
}
/***************************************************************/

/***************************************************************/
void HSEG7_VoidAddSeg7(u8 copy_u8Seg7Port)
{
	if(copy_u8Seg7Port <= SEG7_SELECT_U8_PORTD )
	{
		switch(copy_u8Seg7Port)
		{
		case SEG7_SELECT_U8_PORTA:
			MDIO_VoidSetPortDirection(SEG7_SELECT_U8_PORTA,SEG7_U8_PORT_OUTPUT);
			break;
		case SEG7_SELECT_U8_PORTB:
			MDIO_VoidSetPortDirection(SEG7_SELECT_U8_PORTB,SEG7_U8_PORT_OUTPUT);
			break;
		case SEG7_SELECT_U8_PORTC:
			MDIO_VoidSetPortDirection(SEG7_SELECT_U8_PORTC,SEG7_U8_PORT_OUTPUT);
			break;
		case SEG7_SELECT_U8_PORTD:
			MDIO_VoidSetPortDirection(SEG7_SELECT_U8_PORTD,SEG7_U8_PORT_OUTPUT);
			break;
		}
	}
}

