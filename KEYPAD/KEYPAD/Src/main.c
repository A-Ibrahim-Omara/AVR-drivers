/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../Include/CALCULATOR/CALCULATOR_Interface.h"

u8 global_u8_CheckDivByZero = 0 ;


u8 APPCALCULATOR_u8_CheckNum(u8 copy_u8_keypad_OutputCharacter)
{
	u8 local_u8_CheckValue='o',local_u8_CharToInt = (copy_u8_keypad_OutputCharacter-48);

	if(local_u8_CharToInt >= 0  && local_u8_CharToInt < 10)
	{
		local_u8_CheckValue='n';
	}
	return local_u8_CheckValue ;
}

void APPCALCULATOR_u8_CreatNum(s32 *ptr,u8 key)
{
	*ptr= (*ptr) * 10 + (s32)(key-48);
}

s32 APPCALCULATOR_u8_Calculator(s32 copy_u8_keypad_num1 ,u8 copy_u8_keypad_operation,s32 copy_u8_keypad_num2,u8 copy_u8_num1_sign,u8 copy_u8_num2_sign)
{
	s32 local_u8_CalcResult=0;

	if(copy_u8_num1_sign)
	{
		copy_u8_keypad_num1=copy_u8_keypad_num1*(-1);
	}
	if(copy_u8_num2_sign)
	{
		copy_u8_keypad_num2=copy_u8_keypad_num2*(-1);
	}

	switch(copy_u8_keypad_operation)
	{
	case '+':
		local_u8_CalcResult= (s32)copy_u8_keypad_num1+ (s32)copy_u8_keypad_num2;
		break;
	case '-':
		local_u8_CalcResult= (s32)copy_u8_keypad_num1- (s32)copy_u8_keypad_num2;
		break;
	case '*':
		local_u8_CalcResult= (s32)copy_u8_keypad_num1* (s32)copy_u8_keypad_num2;
		break;
	case '/':
		if(copy_u8_keypad_num2!=0)
		{
		local_u8_CalcResult = (s32)copy_u8_keypad_num1/(s32)copy_u8_keypad_num2;
		}
		else
		{
			global_u8_CheckDivByZero=1;
		}
		break;
	}

	return local_u8_CalcResult;
}

int main(void)
{
	MDIO_VoidInit();
    MDIO_VoidSetPortDirection(DIO_U8_PORTA,DIO_U8_PORT_OUTPUT);
	MDIO_VoidSetPortDirection(DIO_U8_PORTC,DIO_U8_PORT_OUTPUT);
	MDIO_VoidSetPortDirection(DIO_U8_PORTB,0x0f);

	HLCD_VoidInit();
	HLCD_VoidClearDisplay();
    u8 key1,operation,key3,num1_negative_sign_flag=0,num2_negative_sign_flag=0,loop_flag=1;
    u8 clear_screen_char_Flag=0;
    s32 num1=0,num2=0;
    s32 result;


	while(1)
	{

	key1 = HKEYPAD_u8_GetPressedKey(); /* get the pressed button from keypad */


/**************************************************************************************************************************/
/****** MAKE SURE THAT KEY1= sign '-' or '+' for first number or a Number between (0 and 9) *******************************/
/**************************************************************************************************************************/

	if(key1!=KEYPAD_u8_KEY_NOT_PRESSED && (key1!= '+' || key1!= '-') )
	 {
			if(key1=='-')
			{
			num1_negative_sign_flag = 1;
			HLCD_VoidSendData(key1); 					  /*Display sign '-' for first number on LCD*/
			key1 = HKEYPAD_u8_GetPressedKey();            /* get the pressed button from keypad (expect and must be a number)*/
			while( (key1<'0' ||  key1>'9') && key1!='C' ) /* CHECK IF IT WAS NOT A NUMBER GET THE KEY AGAIN TILL BE A NUMBER OR 'C'*/
			{
				key1 = HKEYPAD_u8_GetPressedKey();        /* get the pressed button from keypad (expect and must be a number)*/
			}
			}
			else if(key1=='+')
			{
			HLCD_VoidSendData(key1);                      /*Display sign '+' for first number on LCD*/
			key1 = HKEYPAD_u8_GetPressedKey();            /* get the pressed button from keypad (EXPEXT AND MUST BE A NUMBER)*/
			while( (key1<'0' ||  key1>'9') && key1!='C' ) /* CHECK IF IT WAS NOT A NUMBER GET THE KEY AGAIN TILL BE A NUMBER OR 'C'*/
			{
				key1 = HKEYPAD_u8_GetPressedKey();        /* get the pressed button from keypad (expect and must be a number)*/
			}
			}
			if(key1 =='C')                                /* IF USER CHOOSE TO CLEAR DISPLAY AND START A NEW OPERATION*/
			{
				clear_screen_char_Flag=1;                 /* FLAG TO CLEAR DISPLAY AND START NEW OPERATION*/
			}
	 }

/****** SIGN '-' or '+' FOR FIRST NUMBER OR A NUMBER BETWEEN (0 AND 9) WAS TOOK**********************************************/
/****************************************************************************************************************************/




/****************************************************************************************************************************/
/******************************CONTINUE TO ENTER THE DIGITES OF THE FIRST NUMBER*********************************************/
/*********************GO OUT THE WHILE LOOP WHEN USER INPUT AN OPERATION '+'or '-'or '/'or '*' ******************************/
/*********************	RESTART THE PROGRAM WHEN USER ASK TO DELET THE DISPLY BY INPUT 'C' **********************************/
/*************IF THE INPUT A CHARACTER NOT 'C' NOR AN OPERATION DONOT TAKE ANY ACTIO AND INPUT A CHARACTER AGAIN*************/
/****************************************************************************************************************************/
	 if(key1!=KEYPAD_u8_KEY_NOT_PRESSED  && APPCALCULATOR_u8_CheckNum(key1)=='n')
	 {
		 HLCD_VoidSendData(key1);
		 _delay_ms(10);
		 APPCALCULATOR_u8_CreatNum(&num1,key1);                            /*FUNCTION TO ADD A NEW DIGIT TO THE FIRST NUMBER*/
		 key1 = HKEYPAD_u8_GetPressedKey();                                /* get the pressed button from keypad */

	 while( (loop_flag==1) && (clear_screen_char_Flag!=1) )                /*GO OUT WHILE WHEN INPUT =='C' or AN OPERATION*/
	 {
	     if(key1!=KEYPAD_u8_KEY_NOT_PRESSED && (key1>='0' &&  key1<='9'))
	     {
		 HLCD_VoidSendData(key1);
		 APPCALCULATOR_u8_CreatNum(&num1,key1);          				  /*FUNCTION TO ADD A NEW DIGIT TO THE FIRST NUMBER*/
		 key1 = HKEYPAD_u8_GetPressedKey();								  /* get the pressed button from keypad */
	     }
		 else if( key1!=KEYPAD_u8_KEY_NOT_PRESSED && (key1=='+' ||  key1=='-' ||  key1=='*' ||  key1=='/'))
		 {
		 	loop_flag=0;                                                  /*GO OUT USER INPUT == AN OPERATION*/
		 }
		 else if(key1!=KEYPAD_u8_KEY_NOT_PRESSED && (key1=='C') )
		 {
		 	clear_screen_char_Flag=1;                                     /*GO OUT USER INPUT =='C' */
		 }
		 else
		 {                                                                /*IF THE INPUT CHARACTER NOT 'C' NOR AN OPERATION*/
		 	key1 = HKEYPAD_u8_GetPressedKey();                            /* get the pressed button from keypad again */
		 }
	 }
     loop_flag=1;                                                        /*RESET THE FLAG INDICATE OF THE OPERATION INPUT*/
     if(clear_screen_char_Flag!=1)
     {
		 operation=key1;                                                 /* OPERATION = THE LATEST VALUE OF KEY1*/
		 HLCD_VoidSendData(operation);

/******************** IF MY CODE GO OUT THE WHILE LOOP SO THE USER INPUT WAS THE OPERATION***********************************/
/***********************************SO OPERATION = THE LATEST VALUE OF KEY1**************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/

		 key3 = HKEYPAD_u8_GetPressedKey(); /* get the pressed button from keypad */
         while((key3==KEYPAD_u8_KEY_NOT_PRESSED || key3== '=' || key3== 'C' ) && clear_screen_char_Flag!=1)
         {
            if(key3!= 'C')
            {
            	key3 = HKEYPAD_u8_GetPressedKey(); /* get the pressed button from keypad */
            }
            else
            {
            	clear_screen_char_Flag=1;
            }
          }
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/**********************START TO INPUT THE SECOND NUMBER SIGN AND VALUE OR VALUE DIRECTLY*************************************/
/*******************IF USER WANT TO ENTER THE SIGN AND THE FIRST DIGIT OF THE SECOND NUMBER**********************************/

           if( (key3=='+' || key3=='-')  && clear_screen_char_Flag!=1)
           {
        	   if(key3=='-')
			   {
				   num2_negative_sign_flag = 1;
				   HLCD_VoidSendData(key3);                     /*Display sign '-' for first number on LCD*/
				   key3 = HKEYPAD_u8_GetPressedKey();           /* get the pressed button from keypad (expect and must be a number)*/
			   while( (key3<'0' ||  key3>'9') && key3!='C' )    /* CHECK IF IT WAS NOT A NUMBER GET THE KEY AGAIN TILL BE A NUMBER OR 'C'*/
			   {
				   key3 = HKEYPAD_u8_GetPressedKey();           /* get the pressed button from keypad (expect and must be a number)*/
			   }
			   }
			   else if(key3=='+')
			   {
				   HLCD_VoidSendData(key1);                     /*Display sign '+' for first number on LCD*/
				   key1 = HKEYPAD_u8_GetPressedKey();           /* get the pressed button from keypad (EXPEXT AND MUST BE A NUMBER)*/
			       while((key3<'0' ||  key3>'9') && key3!='C' ) /* CHECK IF IT WAS NOT A NUMBER GET THE KEY AGAIN TILL BE A NUMBER OR 'C'*/
			    	    {
			    	    	key3 = HKEYPAD_u8_GetPressedKey();  /* get the pressed button from keypad (expect and must be a number)*/
			    	    }
			   }
			   if(key3 =='C')                                   /* IF USER CHOOSE TO CLEAR DISPLAY AND START A NEW OPERATION*/
			   {
				   clear_screen_char_Flag=1;                    /* FLAG TO CLEAR DISPLAY AND START NEW OPERATION*/
			   }
            }
            else if(clear_screen_char_Flag==1)                  /* IF USER CHOOSE TO CLEAR DISPLAY AND START A NEW OPERATION*/
            {
            	 HLCD_VoidClearDisplay();                       /* CLEAR DISPLAY AND START A NEW OPERATION */
            }

/******************USER ENTERED THE SIGN AND THE FIRST DIGIT OF THE SECOND NUMBER********************************************/
/****************************************************************************************************************************/

/****************************************************************************************************************************/
/*********IF USER WANT TO ENTER THE FIRST DIGIT OF THE SECOND NUMBER DIRECTLY OR WANT TO CONTINUE ENTER DIGITS OF NUMBER2****/

            if(key3!=KEYPAD_u8_KEY_NOT_PRESSED && key3!= 'C' && APPCALCULATOR_u8_CheckNum(key3)=='n')
            {
				HLCD_VoidSendData(key3);
				APPCALCULATOR_u8_CreatNum(&num2,key3);                                  /*FUNCTION TO ADD A NEW DIGIT TO THE SECOND NUMBER*/
				key3 = HKEYPAD_u8_GetPressedKey();                                      /* get the pressed button from keypad */
                while( loop_flag==1 && (clear_screen_char_Flag!=1) )
                {                                                                       /*GO OUT WHILE WHEN INPUT =='C' or THE END OF OPERATION == '=' */
                	if(key3!=KEYPAD_u8_KEY_NOT_PRESSED && (key3>='0' &&  key3<='9'))
                	{
						HLCD_VoidSendData(key3);
						APPCALCULATOR_u8_CreatNum(&num2,key3);                          /*FUNCTION TO ADD A NEW DIGIT TO THE SECOND NUMBER*/
						key3 = HKEYPAD_u8_GetPressedKey();                              /* get the pressed button from keypad */
                	}
                    else if(key3==KEYPAD_u8_KEY_NOT_PRESSED)                            /*IF THE INPUT CHARACTER NOT 'C' NOR '=' */
                    {                                                                   /* get the pressed button from keypad again */
                        key3 = HKEYPAD_u8_GetPressedKey();
                    }
                	else if(key3!=KEYPAD_u8_KEY_NOT_PRESSED && (key3=='C') )              /* IF USER CHOOSE TO CLEAR DISPLAY AND START A NEW OPERATION*/
                	{                                                                     /* CLEAR DISPLAY AND START A NEW OPERATION */
                		clear_screen_char_Flag=1;
                	}
                	else if(key3!=KEYPAD_u8_KEY_NOT_PRESSED && key3=='=')                /*IF THE INPUT CHARACTER WAS '=' */
                	{                                                                    /* GO OUT THE WHILE LOOP AND DISPLAY THE RESULT */
                		loop_flag=0;
                	}
                }
                loop_flag=1;                                                             /*RESET THE FLAG INDICATE OF '=' INPUT*/
                if(key3!='C')
                {
					if(key3=='=')                                                        /*THE INPUT CHARACTER WAS '=' */
					{
						HLCD_VoidSendData('=');
						result = APPCALCULATOR_u8_Calculator(num1,operation,num2,num1_negative_sign_flag,num2_negative_sign_flag);
					}
				    if(global_u8_CheckDivByZero==1)                                      /*IF OPERATION WAS '/' AND DIV NUM1/0 */
				    {
						global_u8_CheckDivByZero=0;
						HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL0);
						HLCD_VoidSendString("enter num2 > 0");
						_delay_ms(1000);
						HLCD_VoidClearDisplay();
					}
					else
					{
					    HLCD_VoidDisplayNumber(result);                     /*THE USER INPUT '=' SO ASKING TO DISPLAY RESULT*/
					}
				}
                else
                {
                	 HLCD_VoidClearDisplay();                                /*THE USER INPUT 'C' SO ASKING TO CLEAR THE DISPLAY*/
                }
			}
		    else if(key3 =='C')
		    {
		    	 HLCD_VoidClearDisplay();                                    /*THE USER INPUT 'C' SO ASKING TO CLEAR THE DISPLAY*/
		    }
		    }
     	 	else
     	 	{
     	 		HLCD_VoidClearDisplay();                                     /*THE USER INPUT 'C' SO ASKING TO CLEAR THE DISPLAY*/
     	 	}
	 }
	 else if(key1!=KEYPAD_u8_KEY_NOT_PRESSED && key1!= 'C' && APPCALCULATOR_u8_CheckNum(key1)!='n')
	 {                                                                       /*IF USER FIRST CHAR WASNOT '+' nor'-' nor a NUMBER*/
		 HLCD_VoidSendData(key1);
		 HLCD_VoidSendString(" enter num1");
		 _delay_ms(2000);
		 HLCD_VoidClearDisplay();
	 }
	 else if(key1!=KEYPAD_u8_KEY_NOT_PRESSED && key1== 'C')
		 {                                                                    /*THE USER INPUT 'C' SO ASKING TO CLEAR THE DISPLAY*/
			 HLCD_VoidClearDisplay();
		 }

/**************************************************************************************************************************/
/*********REINITIATE_VALUES_TO_BE_READY_FOR_NEXT_OPERATION******************************************************************/

	     clear_screen_char_Flag=0;
		 num1_negative_sign_flag=0;
		 num2_negative_sign_flag=0;
		 num1=0;
		 num2=0;
		 key1=255;

/**************************************************************************************************************************/
/**************************************************************************************************************************/
	} /***********_WHILE(1)_CURLE_***************/
	return 1;
}  /***********_MAIN_CURLE_***************/

