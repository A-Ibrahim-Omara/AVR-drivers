/*
 * EXTI_Program.c
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Ibrahim
 */


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
#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"


#include "../Include/MCAL/INTERRUPT/EXTI_Interface.h"
#include "../Include/MCAL/INTERRUPT/EXTI_Private.h"
#include "../Include/MCAL/INTERRUPT/EXTI_Cfg.h"

static void (*pf[3]) (void)={NULL,NULL,NULL};


static u8 flag=0;
void __vector_1(void)	__attribute__((signal));
void __vector_1(void)
{
	if(pf[EXTI_u8_EXTI0]!=NULL)
	{
		pf[EXTI_u8_EXTI0]();
	}
}

void __vector_2(void)	__attribute__((signal));
void __vector_2(void)
{
	if(pf[EXTI_u8_EXTI1]!=NULL)
		{
			pf[EXTI_u8_EXTI1]();
		}
}

void __vector_3(void)	__attribute__((signal));
void __vector_3(void)
{
	if(pf[EXTI_u8_EXTI2]!=NULL)
		{
			pf[EXTI_u8_EXTI2]();
		}
}

void MEXTI_voidSetCallBack(void(*copyPointerToFunction)(void),u8 copy_u8_index)
{
	pf[copy_u8_index]=copyPointerToFunction;
}

void MEXTI_voidEXTIEnable(u8 copy_u8EXTI_num,u8 copy_u8EXTI_Sense)
{
	if(copy_u8EXTI_num<0 || copy_u8EXTI_num>2 || copy_u8EXTI_Sense<0 || copy_u8EXTI_Sense>3)
	{

	}
	else if (copy_u8EXTI_num==EXTI_u8_EXTI2 && copy_u8EXTI_Sense<2)
	{

	}
	switch(copy_u8EXTI_num)
	{
	case EXTI_u8_EXTI0:
					   SET_BIT(EXTI_u8_GICR,EXTI_u8_EXTI0_ENABLE_BIT);
                       switch(copy_u8EXTI_Sense)
                       {
                       case EXTI_u8_LOW_LEVEL_MODE:
                                                   CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN0);
                                                   CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN1);
                                                   break;
                       case EXTI_u8_IOC_MODE:
                                                   SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN0);
                                                   CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN1);
                                                   break;
                       case EXTI_u8_FALLING_MODE:
                                                   CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN0);
                                                   SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN1);
                                                   break;
                       case EXTI_u8_RISING_MODE:
                                                   SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN0);
                                                   SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN1);
                                                   break;
                       }
                       break;
     case EXTI_u8_EXTI1:
                       SET_BIT(EXTI_u8_GICR,EXTI_u8_EXTI1_ENABLE_BIT);
                           switch(copy_u8EXTI_Sense)
                           {
                           case EXTI_u8_LOW_LEVEL_MODE:
                                                       CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN2);
                                                       CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN3);
                                                       break;
                           case EXTI_u8_IOC_MODE:
                                                       SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN2);
                                                       CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN3);
                                                       break;
                           case EXTI_u8_FALLING_MODE:
                                                       CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN2);
                                                       SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN3);
                                                       break;
                           case EXTI_u8_RISING_MODE:
                                                       SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN2);
                                                       SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_PIN3);
                                                       break;
                           }
                           break;

              case EXTI_u8_EXTI2:
              					   SET_BIT(EXTI_u8_GICR,EXTI_u8_EXTI2_ENABLE_BIT);
                                     switch(copy_u8EXTI_Sense)
                                     {
                                     case EXTI_u8_FALLING_MODE:
                                                       CLR_BIT(EXTI_u8_MCUCSR,EXTI_u8_MCUCSR_PIN0);
                                                       break;
                                     case EXTI_u8_RISING_MODE:
                                                       SET_BIT(EXTI_u8_MCUCSR,EXTI_u8_MCUCSR_PIN0);
                                                       break;

                                     }
	                                break;
	}
}


void MEXTI_voidEXTIDisable(u8 copy_u8EXTI_num)
{
	if(copy_u8EXTI_num<0 || copy_u8EXTI_num>2 )
		{

		}
	else
	{

		switch(copy_u8EXTI_num)
					{
					case EXTI_u8_EXTI0:
						CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI0_ENABLE_BIT);
					            	break;
					case EXTI_u8_EXTI1:
						CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI1_ENABLE_BIT);
									break;
					case EXTI_u8_EXTI2:
						CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI2_ENABLE_BIT);
									break;
	}
}

}
