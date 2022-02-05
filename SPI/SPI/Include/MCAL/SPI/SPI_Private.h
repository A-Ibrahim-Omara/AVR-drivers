/*
 * SPI_Private.h
 *
 *  Created on: Jan 30, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_SPI_SPI_PRIVATE_H_
#define INCLUDE_MCAL_SPI_SPI_PRIVATE_H_

/*----------------------REG Mapping------------------------*/
#define SPI_U8_SPCR_REG           *((volatile u8 *)0x2D)
#define SPI_U8_SPSR_REG           *((volatile u8 *)0x2E)
#define SPI_U8_SPDR_REG           *((volatile u8 *)0x2F)
/*---------------------------------------------------------*/

#endif /* INCLUDE_MCAL_SPI_SPI_PRIVATE_H_ */
