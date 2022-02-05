/*
 * SPI_Program.c
 *
 *  Created on: Jan 30, 2022
 *      Author: Ahmed Ibrahim
 */


#include "../Include/LIB/bit_math.h"
#include "../Include/LIB/std_type.h"

#include "../Include/MCAL/SPI/SPI_Cfg.h"
#include "../Include/MCAL/SPI/SPI_Interface.h"
#include "../Include/MCAL/SPI/SPI_Private.h"
#include "../Include/MCAL/DIO/DIO_Cfg.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"

void SPI_voidMasterInit(void)
{
	MDIO_VoidSetPinDirection(DIO_U8_PORTB,5,1);
	MDIO_VoidSetPinDirection(DIO_U8_PORTB,6,0);
	MDIO_VoidSetPinDirection(DIO_U8_PORTB,7,1);
	MDIO_VoidSetPinDirection(DIO_U8_PORTB,4,1);
	/*Double Speed*/
	CLR_BIT(SPI_U8_SPSR_REG,0);
	/*CLK Rate*/
	SET_BIT(SPI_U8_SPCR_REG,0);
	/*CLK Rate*/
	CLR_BIT(SPI_U8_SPCR_REG,1);
	/*CLK Phase 0*/
	SET_BIT(SPI_U8_SPCR_REG,2);
	/*CLK polarity 0*/
	SET_BIT(SPI_U8_SPCR_REG,3);
	/*MAster mode*/
	SET_BIT(SPI_U8_SPCR_REG,4);
	/*LSB first*/
	SET_BIT(SPI_U8_SPCR_REG,5);
	/*SPI enable*/
	SET_BIT(SPI_U8_SPCR_REG,6);

}
void SPI_voidSlaveInit(void)
{
	    MDIO_VoidSetPinDirection(DIO_U8_PORTB,5,0);
		MDIO_VoidSetPinDirection(DIO_U8_PORTB,6,1);
		MDIO_VoidSetPinDirection(DIO_U8_PORTB,7,0);
		MDIO_VoidSetPinDirection(DIO_U8_PORTB,4,0);
	    /*Double Speed*/
		CLR_BIT(SPI_U8_SPSR_REG,0);
		/*CLK Rate*/
		SET_BIT(SPI_U8_SPCR_REG,0);
		/*CLK Rate*/
		CLR_BIT(SPI_U8_SPCR_REG,1);
		/*CLK Phase 1*/
		SET_BIT(SPI_U8_SPCR_REG,2);
		/*CLK polarity 1*/
		SET_BIT(SPI_U8_SPCR_REG,3);
		/*Slave mode*/
		CLR_BIT(SPI_U8_SPCR_REG,4);
		/*LSB first*/
		SET_BIT(SPI_U8_SPCR_REG,5);
		/*SPI enable*/
		SET_BIT(SPI_U8_SPCR_REG,6);
}

u8 SPI_voidTransive(u8 local_u8_data)
{
	SPI_U8_SPDR_REG=local_u8_data;
	while(!GET_BIT(SPI_U8_SPSR_REG,7))
	{
	}
	return SPI_U8_SPDR_REG;
}

