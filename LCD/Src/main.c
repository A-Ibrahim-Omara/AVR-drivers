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
#include "../Include/HAL/LCD_Interface.h"
extern u8 CharRunArr[8];
extern u8 CharRun2Arr[8];
extern u8 CharStandArr[8];
extern u8 CharGunArr[8];
extern u8 CharDiedArr[8];
extern u8 CharEnemyArr[8];
extern u8 CharBulletArr[8];

extern u8 Char1BallArr[8];
extern u8 Char3Ball2Arr[8];


extern u8 Char4ChildArr[8];
extern u8 Char7ChildrunArr[8];
extern u8 Char5MothArr[8];

extern u8 Char5Childrun2Arr[8];
extern u8 Char5ChildbigArr[8];
/***************************************/
/*************FLAG**********************/
extern u8 Char0FCorner1Arr[8];
extern u8 Char1FCorner2Arr[8];
extern u8 Char2FTopArr[8];
extern u8 Char3FBotArr[8];
extern u8 Char4FDiagonal1Arr[8];
extern u8 Char5FDiagonal2Arr[8];
extern u8 Char6Fend1Arr[8];
extern u8 Char7Fend2Arr[8];

int main(void)
{
	MDIO_VoidInit();
    MDIO_VoidSetPortDirection(DIO_U8_PORTA,DIO_U8_PORT_OUTPUT);
	MDIO_VoidSetPortDirection(DIO_U8_PORTC,DIO_U8_PORT_OUTPUT);

	HLCD_VoidInit();
	HLCD_VoidClearDisplay();
	_delay_ms(10);

	/************************************************/
	/*******************Chapter1*****************************/

	HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL6);
	HLCD_VoidSendString("1947");
	_delay_ms(1000);
	HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL0);
	HLCD_VoidSendString("Playing football");
	_delay_ms(1000);

	HLCD_VoidSendSpecialCharacter(CharRunArr,0,LCD_U8_ROW0,LCD_U8_COL0);
	HLCD_VoidSendSpecialCharacter(Char3Ball2Arr,3,LCD_U8_ROW0,LCD_U8_COL1);

	u8 i=0;
		while(i!=12)
		{
			i=i+2;
			HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i-1);
	        HLCD_VoidSendData(0x20);
	        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i-2);
	        HLCD_VoidSendData(0x20);
	        _delay_ms(150);
			HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i);
			HLCD_VoidSendData(0);
			HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i+1);
			HLCD_VoidSendData(3);
			_delay_ms(150);

		}
		i=i+2;
					HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i-1);
			        HLCD_VoidSendData(0x20);
			        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i-2);
			        HLCD_VoidSendData(0x20);
			        _delay_ms(150);

		HLCD_VoidSendSpecialCharacter(CharRun2Arr,2,LCD_U8_ROW0,LCD_U8_COL0+10);
		HLCD_VoidSendSpecialCharacter(Char1BallArr,1,LCD_U8_ROW0,LCD_U8_COL0+9);

		_delay_ms(150);
		i=10;
		while(i!=2)
				{
					i=i-2;
					HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i+1);
			        HLCD_VoidSendData(0x20);
			        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i+2);
			        HLCD_VoidSendData(0x20);
			        _delay_ms(150);
					HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i);
					HLCD_VoidSendData(2);
					HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i-1);
					HLCD_VoidSendData(1);
					_delay_ms(150);
				}
    _delay_ms(1000);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i);
    HLCD_VoidSendData(0x20);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0+i-1);
    HLCD_VoidSendData(0x20);
    _delay_ms(500);

    HLCD_VoidClearDisplay();

	/************************************************/
	/*******************Chapter2*****************************/
    HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL0);
    HLCD_VoidSendString("In 1948");
    _delay_ms(1000);
    HLCD_VoidClearDisplay();
    HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL0);
	HLCD_VoidSendString("A FAMILY'S TRIP");
    _delay_ms(1000);

	HLCD_VoidSendSpecialCharacter(Char4ChildArr,4,LCD_U8_ROW0,LCD_U8_COL1);
	HLCD_VoidSendData(4);
	HLCD_VoidSendData(4);
	HLCD_VoidSendSpecialCharacter(Char5MothArr,5,LCD_U8_ROW0,LCD_U8_COL4);
	HLCD_VoidSendSpecialCharacter(CharStandArr,1,LCD_U8_ROW0,LCD_U8_COL5);
    _delay_ms(1000);

	HLCD_VoidSendSpecialCharacter(CharEnemyArr,3,LCD_U8_ROW0,LCD_U8_COL14);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL15);
	HLCD_VoidSendData(3);
	HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL13);
	HLCD_VoidSendData(3);

    HLCD_VoidClearDisplay();
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL1);
	HLCD_VoidSendData(4);
	HLCD_VoidSendData(4);
	HLCD_VoidSendData(4);
	HLCD_VoidSendData(5);
	HLCD_VoidSendData(1);

    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL13);
	HLCD_VoidSendData(3);
	HLCD_VoidSendData(3);
	HLCD_VoidSendData(3);
    _delay_ms(500);

/***************************************************/
/*****************BULLET MOVMENT**********************************/

	HLCD_VoidSendSpecialCharacter(CharBulletArr,2,LCD_U8_ROW0,LCD_U8_COL12);
    _delay_ms(150);

    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL11);
    HLCD_VoidSendData(2);
    _delay_ms(150);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL10);
    HLCD_VoidSendData(2);
    _delay_ms(150);


	HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL12);
    HLCD_VoidSendData(0x20);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL9);
     HLCD_VoidSendData(2);
    _delay_ms(150);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL11);
   HLCD_VoidSendData(0x20);
   HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL8);
    HLCD_VoidSendData(2);
   _delay_ms(150);
   HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL10);
   HLCD_VoidSendData(0x20);
   HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL7);
    HLCD_VoidSendData(2);
   _delay_ms(150);
   HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL10);
   HLCD_VoidSendData(0x20);
   HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL7);
    HLCD_VoidSendData(2);
   _delay_ms(150);
   HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL9);
    HLCD_VoidSendData(0x20);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL6);
     HLCD_VoidSendData(2);
    _delay_ms(150);

    /***************************************************/
    /*****************BULLET MOVMENT**********************************/


    /************************************************/
    /*******************Chapter3*****************************/

    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL8);
    HLCD_VoidSendData(0x20);
	HLCD_VoidSendSpecialCharacter(CharDiedArr,1,LCD_U8_ROW0,LCD_U8_COL5);
    _delay_ms(150);

	HLCD_VoidSendSpecialCharacter(Char7ChildrunArr,6,LCD_U8_ROW0,LCD_U8_COL1);
	HLCD_VoidSendData(6);
	 _delay_ms(150);

	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL2); //clearchild2
	 HLCD_VoidSendData(0x20);
	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0);
	 HLCD_VoidSendData(6);

	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL7); //clearbullet2
	 HLCD_VoidSendData(0x20);
	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL4);
	 HLCD_VoidSendData(1);
	 _delay_ms(150);

	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL1); //clearchild2
	  HLCD_VoidSendData(0x20);
	 _delay_ms(150);
	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL3);
	 HLCD_VoidSendData(1);

	HLCD_VoidSendSpecialCharacter(Char5Childrun2Arr,5,LCD_U8_ROW1,LCD_U8_COL0);

	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL0); //clearchild1
	 HLCD_VoidSendData(0x20);
	_delay_ms(150);
	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL6); //clearchild1
	 HLCD_VoidSendData(0x20);
	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL4); //clearchild1
	 HLCD_VoidSendData(0x20);
	 HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL4);
	 HLCD_VoidSendData(1);
	 _delay_ms(150);
	 HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL1);
	 HLCD_VoidSendData(5);
	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL5); //clearchild1
	 HLCD_VoidSendData(0x20);
	 HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL5);
	 HLCD_VoidSendData(1);
	 _delay_ms(150);

	 HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL3); //clearchild1
	 HLCD_VoidSendData(0x20);
	 HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL3);
	 HLCD_VoidSendData(1);
	 _delay_ms(150);
	 HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL0); //clearchild1
	 HLCD_VoidSendData(0x20);
	 HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL2);
	 HLCD_VoidSendData(5);
	 _delay_ms(2000);

	 HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL3); //clearchild1
	 HLCD_VoidSendData(0x20);
	  HLCD_VoidSendData(0x20);
	  HLCD_VoidSendData(0x20);
	/************************************************/
	/*******************Chapter4*****************************/
	_delay_ms(1500);
	HLCD_VoidSendSpecialCharacter(Char5ChildbigArr,5,LCD_U8_ROW1,LCD_U8_COL1);
    HLCD_VoidSendData(5);
	_delay_ms(1500);
	HLCD_VoidSendSpecialCharacter(CharStandArr,5,LCD_U8_ROW1,LCD_U8_COL1);
    HLCD_VoidSendData(5);
	 _delay_ms(150);
	HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL0);
    HLCD_VoidSendData(5);
	 _delay_ms(250);

	HLCD_VoidSendSpecialCharacter(CharRun2Arr,1,LCD_U8_ROW1,LCD_U8_COL0);
    HLCD_VoidSendData(1);
    HLCD_VoidSendData(1);
	 _delay_ms(200);

    HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL2);
   	HLCD_VoidSendData(0x20);
 	HLCD_VoidSendSpecialCharacter(CharRunArr,2,LCD_U8_ROW0,LCD_U8_COL0);
 	 _delay_ms(200);
    HLCD_VoidSendData(2);

    HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL1);
    HLCD_VoidSendData(0x20);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL1);
    HLCD_VoidSendData(2);

    _delay_ms(200);
    HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL0);
    HLCD_VoidSendData(0x20);
    HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL2);
    HLCD_VoidSendData(2);
    _delay_ms(200);

 	HLCD_VoidSendSpecialCharacter(CharGunArr,2,LCD_U8_ROW0,LCD_U8_COL0);
    HLCD_VoidSendData(2);
    HLCD_VoidSendData(2);
    _delay_ms(1000);

    /***************************************************/
    /*****************BULLET MOVMENT**********************************/

    	HLCD_VoidSendSpecialCharacter(CharBulletArr,1,LCD_U8_ROW0,LCD_U8_COL3);
        _delay_ms(200);
        HLCD_VoidSendData(1);
        _delay_ms(200);
        HLCD_VoidSendData(1);
        _delay_ms(200);
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL3);
        HLCD_VoidSendData(0x20);
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL6);
        HLCD_VoidSendData(1);
        _delay_ms(200);

        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL4);
        HLCD_VoidSendData(0x20);
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL7);
        HLCD_VoidSendData(1);
        _delay_ms(200);
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL5);
       HLCD_VoidSendData(0x20);
       HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL8);
       HLCD_VoidSendData(1);
       _delay_ms(200);
       HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL6);
       	HLCD_VoidSendData(0x20);
       	HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL9);
       	HLCD_VoidSendData(1);
       	_delay_ms(200);
       	HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL7);
     HLCD_VoidSendData(0x20);
     HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL10);
     HLCD_VoidSendData(1);
     _delay_ms(200);
            HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL8);
        HLCD_VoidSendData(0x20);
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL11);
        HLCD_VoidSendData(1);
        _delay_ms(200);
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL9);
        HLCD_VoidSendData(0x20);
        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL12);
        HLCD_VoidSendData(1);
        _delay_ms(1000);

        /***************************************************/
        /*****************BULLET MOVMENT**********************************/

        HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL10);
        HLCD_VoidSendData(0x20);
    	HLCD_VoidSendSpecialCharacter(CharDiedArr,7,LCD_U8_ROW0,LCD_U8_COL13);
         _delay_ms(200);

         HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL11);
         HLCD_VoidSendData(0x20);
         HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL14);
         HLCD_VoidSendData(7);
          _delay_ms(200);

          HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL12);
          HLCD_VoidSendData(0x20);
          HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL15);
          HLCD_VoidSendData(7);
          _delay_ms(2000);
        /************************************************/

	/************************************************/
	/*******************FLAG*****************************/

	HLCD_VoidSendSpecialCharacter(Char0FCorner1Arr,0,LCD_U8_ROW0,LCD_U8_COL0);
	HLCD_VoidSendSpecialCharacter(Char4FDiagonal1Arr,4,LCD_U8_ROW0,LCD_U8_COL1);
	HLCD_VoidSendSpecialCharacter(Char2FTopArr,2,LCD_U8_ROW0,LCD_U8_COL2);
	HLCD_VoidSendData(2);
	HLCD_VoidSendData(2);
	HLCD_VoidSendData(2);
	HLCD_VoidSendData(2);
	HLCD_VoidSendSpecialCharacter(Char6Fend1Arr,6,LCD_U8_ROW0,LCD_U8_COL7);
	HLCD_VoidSendSpecialCharacter(Char7Fend2Arr,7,LCD_U8_ROW1,LCD_U8_COL7);
	HLCD_VoidSendSpecialCharacter(Char1FCorner2Arr,1,LCD_U8_ROW1,LCD_U8_COL0);
	HLCD_VoidSendSpecialCharacter(Char5FDiagonal2Arr,5,LCD_U8_ROW1,LCD_U8_COL1);
	HLCD_VoidSendSpecialCharacter(Char3FBotArr,3,LCD_U8_ROW1,LCD_U8_COL2);
	HLCD_VoidSendData(3);
	HLCD_VoidSendData(3);
	HLCD_VoidSendData(3);
	HLCD_VoidSendData(3);

	/************************************************/
	/*******************FLAG**************************/

	HLCD_VoidGoToPos(LCD_U8_ROW0,LCD_U8_COL10);
	HLCD_VoidSendString("FREE   ");
	HLCD_VoidGoToPos(LCD_U8_ROW1,LCD_U8_COL8);
	HLCD_VoidSendString("PALASTINE");


	while(1)
	{

	}

	return 1;
}
