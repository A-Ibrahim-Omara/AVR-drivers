/*
 * LCD_Program.c
 *
 *  Created on: Jan 4, 2022
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

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Private.h"

#include "../Include/HAL/LCD_Cfg.h"
#include "../Include/HAL/LCD_Interface.h"
#include "../Include/HAL/LCD_Private.h"
/*--------------------------------------------------------------------*/
#if(LCD_DATA_MODE == LCD_DATA_MODE_8)
static const u8 DataPinsIdx[8] = {DB0_PIN, DB1_PIN, DB2_PIN, DB3_PIN,
								  DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN};
#else
static const u8 DataPinsIdx[4] = {DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN};
#endif
/*--------------------------------------------------------------------*/
static int InitState = 0;
/*-------------------------------------------------------------------------------*/
void HLCD_SendCommand(u8 copy_u8_command)
{
	u8 local_u8Command,local_u8LcdPinData;
	u32 i ;
	/*---set RS & SW values---*/
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_U8_LOW);
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_U8_LOW);
	 /*---send Cmd to LCD---*/
#if (LCD_DATA_MODE == LCD_DATA_MODE_8)
	 for(i = 0; i < 8; i++)
	 	{
		   local_u8LcdPinData = copy_u8_command & 0x01;
	       if(local_u8LcdPinData ==1)//GpioData = (~GpioData)+ 1;
	        {
	    	   MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_HIGH);
	        }
	       else
	       {
	    	   MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_LOW);
	       }
	       copy_u8_command = copy_u8_command >> 1;
	 	}
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_HIGH);
	 _delay_ms(2);
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_LOW);
#else
	 /*----Send the most 4 bits of the cmd-------*/
	 local_u8Command =( (copy_u8_command & 0xF0) >> 4);
	 for(i = 0; i < 4; i++)
	 	 {
	 		 local_u8LcdPinData = local_u8Command & 0x01;
	 	     if(local_u8LcdPinData ==1)//GpioData = (~GpioData)+ 1;
	 	       {
	 	    	 MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_HIGH);
	 	       }
	 	     else
	 	       {
	 	    	 MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_LOW);
	 	       }
	 	     local_u8Command = local_u8Command >> 1;
	 	 }
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_HIGH);
	 _delay_ms(2);
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_LOW);
	 /*----Send the least 4 bits of the cmd-------*/
	 local_u8Command = (copy_u8_command & 0x0F);
	 for(i = 0; i < 4; i++)
		{
			local_u8LcdPinData = local_u8Command & 0x01;
			if(local_u8LcdPinData ==1)//GpioData = (~GpioData)+ 1;
			 {
			    MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_HIGH);
			 }
			else
			 {
			   	MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_LOW);
			 }
			local_u8Command = local_u8Command >> 1;
		}
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_HIGH);
	 _delay_ms(2);
	 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_LOW);
#endif
}
/*-------------------------------------------------------------------------------*/
void HLCD_VoidInit(void)
{
	u8 local_u8FuncSet;
    _delay_ms(50);
#if(LCD_DATA_MODE==LCD_DATA_MODE_8)
    HLCD_SendCommand(LCD_U8_FUNCTION_SET);
#else
    local_u8FuncSet = (u8)(LCD_U8_FUNCTION_SET>>4);
   // HLCD_SendCommand(local_u8FuncSet);
    local_u8FuncSet = (u8)(LCD_U8_FUNCTION_SET & 0x0F);
   //  HLCD_SendCommand(local_u8FuncSet);
    HLCD_SendCommand(0x33);
    HLCD_SendCommand(0x32);

#endif
    _delay_ms(10);
    HLCD_SendCommand(LCD_U8_DISPLAY_CONTROL);
    _delay_ms(10);
    HLCD_SendCommand(LCD_U8_CLEAR_DISPLAY);
    _delay_ms(10);
    HLCD_SendCommand(LCD_U8_ENTRY_SET);
    InitState = 1;
}

void HLCD_VoidSendData(u8 copy_8uChar)
{
	u32 i;
	u8 local_u8Data,local_u8LcdPinData;
	//rs=1
	MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_U8_HIGH);
	//rw=0
	MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_U8_LOW);
#if(LCD_DATA_MODE==LCD_DATA_MODE_8)
	for(i = 0; i < 8; i++)
	{
		local_u8LcdPinData = copy_8uChar & 0x01;
		if(local_u8LcdPinData ==1)//GpioData = (~GpioData)+ 1;
		{
		    MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_HIGH);
		}
		else
		{
		    MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_LOW);
		}
		copy_8uChar = copy_8uChar >> 1;
	}
	MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_HIGH);
    _delay_ms(3);
	MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_LOW);
#else
	/*----Send the most 4 bits of the cmd-------*/
	local_u8Data =( (copy_8uChar & 0xF0) >> 4);
		 for(i = 0; i < 4; i++)
		 	 {
			 local_u8LcdPinData = local_u8Data & 0x01;
		 	     if(local_u8LcdPinData ==1)//GpioData = (~GpioData)+ 1;
		 	       {
		 	    	 MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_HIGH);
		 	       }
		 	     else
		 	       {
		 	    	 MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_LOW);
		 	       }
		 	    local_u8Data = local_u8Data >> 1;
		 	 }
		 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_HIGH);
		 _delay_ms(2);
		 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_LOW);
		 /*----Send the least 4 bits of the cmd-------*/
		 local_u8Data = (copy_8uChar & 0x0F);
		 for(i = 0; i < 4; i++)
			{
				local_u8LcdPinData = local_u8Data & 0x01;
				if(local_u8LcdPinData ==1)//GpioData = (~GpioData)+ 1;
				 {
				    MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_HIGH);
				 }
				else
				 {
				   	MDIO_VoidSetPinValue(LCD_DATA_PORT,DataPinsIdx[i],DIO_U8_LOW);
				 }
				local_u8Data = local_u8Data >> 1;
			}
		 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_HIGH);
		 _delay_ms(3);
		 MDIO_VoidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_U8_LOW);
#endif
}
void HLCD_VoidSendString(u8 *copy_P8uString)
{
	while(*copy_P8uString>0)
	{
		HLCD_VoidSendData(*copy_P8uString++);
	}
}

void HLCD_VoidClearDisplay(void)
{
	HLCD_SendCommand(0x01);
	_delay_ms(2);
}

void HLCD_VoidDisplayNumber(s32 copy_u32Number)
{
	u8 U8data,count=0;
	u32 U32data=0,reverse_n=0,remainder_n;
	    	if (copy_u32Number == 0)
	    	{
	    		HLCD_VoidSendData('0');
	    	}
	    	if (copy_u32Number < 0)
	    	{
	    		HLCD_VoidSendData('-');
	    		copy_u32Number *= -1;
	    	}
	    	U32data = copy_u32Number;
			while(U32data!=0)
			{
				    remainder_n=(U32data % 10);
					reverse_n = remainder_n + reverse_n * 10;
					U32data = U32data/10;
                    count++;
			}
			while(count!=0)
			{
				remainder_n=(reverse_n % 10);
				reverse_n = reverse_n/10;
		     	U8data = (u8)(remainder_n+48);
			    HLCD_VoidSendData(U8data);
			    count--;
			}
}


void HLCD_VoidGoToPos(u8 copy_u8RowNum,u8 copy_u8ColumnNo)
{
   if( (copy_u8RowNum <= LCD_U8_ROW1) && (copy_u8ColumnNo <= LCD_U8_COL15) )
   {
     switch(copy_u8RowNum)
     {
     case LCD_U8_ROW0 :
    	 HLCD_SendCommand(LCD_U8_ROW0_ADDRESS+copy_u8ColumnNo);
    	 break;
     case LCD_U8_ROW1 :
         HLCD_SendCommand(LCD_U8_ROW1_ADDRESS+copy_u8ColumnNo);
         break;
     }
   }
   /* wait for more 39 usec */
   	_delay_ms(1);
}


void HLCD_VoidSendSpecialCharacter(u8 *copy_pu8CharArr,u8 copy_u8PatternNum,
								   u8 copy_u8RowNum, u8 copy_ColNum)
{
	u8 local_u8CGRAMAddress, local_u8Counter;
	/* Calculate CGRAM Address = Pattern Number * 8 */
	local_u8CGRAMAddress = copy_u8PatternNum * 8;
	SET_BIT(local_u8CGRAMAddress,6);
	/* Send Command to set CGRAM Address */
	HLCD_SendCommand(local_u8CGRAMAddress);

	for (local_u8Counter=0; local_u8Counter < 8; local_u8Counter++)
	{
		/* Send byte from character array */
		HLCD_VoidSendData(copy_pu8CharArr[local_u8Counter]);
	}
	/* Send Command to set DDRAM Address */
	HLCD_VoidGoToPos(copy_u8RowNum,copy_ColNum);
	/* Display pattern from CGRAM */
	HLCD_VoidSendData(copy_u8PatternNum);
}


