/*
 * DIO_Interface.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#include "../../LIB/bit_math.h"
#include "../../LIB/std_type.h"

/*--------------------------------------------------------------------------------------------*/
#define DIO_U8_PORTA 	    0
#define DIO_U8_PORTB	    1
#define DIO_U8_PORTC 	    2
#define DIO_U8_PORTD 		3
/*--------------------------------------------------------------------------------------------*/
#define DIO_U8_PIN0 		0
#define DIO_U8_PIN1 		1
#define DIO_U8_PIN2         2
#define DIO_U8_PIN3         3
#define DIO_U8_PIN4         4
#define DIO_U8_PIN5         5
#define DIO_U8_PIN6         6
#define DIO_U8_PIN7         7
/*--------------------------------------------------------------------------------------------*/
#define DIO_U8_HIGH         1
#define DIO_U8_LOW          0
/*--------------------------------------------------------------------------------------------*/
#define DIO_U8_OUTPUT       1
#define DIO_U8_INPUT        0
/*--------------------------------------------------------------------------------------------*/
#define DIO_U8_PORT_OUTPUT 0xFF
#define DIO_U8_PORT_INPUT  0x00
/*--------------------------------------------------------------------------------------------*/
void MDIO_VoidInit(void);
/*--------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPinDirection(u8 copy_u8portid , u8 copy_u8pinid ,u8 copy_u8pindirection);
/*--------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPinValue(u8 copy_u8portid,u8 copy_u8pinid,u8 copy_u8pinValue);
/*--------------------------------------------------------------------------------------------*/
u8 MDIO_U8GetPinValue(u8 copy_u8portid,u8 copy_u8pinid);
/*--------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPortDirection(u8 copy_u8portid,u8 copy_u8portdirection);
/*--------------------------------------------------------------------------------------------*/
void MDIO_VoidSetPortValue(u8 copy_u8portid,u8 copy_u8portValue);
/*--------------------------------------------------------------------------------------------*/


#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
