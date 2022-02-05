/*
 * SPI_Interface.h
 *
 *  Created on: Jan 30, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_SPI_SPI_INTERFACE_H_
#define INCLUDE_MCAL_SPI_SPI_INTERFACE_H_

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);

u8 SPI_voidTransive(u8 local_u8_data);


#endif /* INCLUDE_MCAL_SPI_SPI_INTERFACE_H_ */
