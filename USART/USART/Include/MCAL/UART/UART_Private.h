/*
 * UART_Private.h
 *
 *  Created on: Jan 28, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

/*----------------------REG Mapping------------------------*/
#define UART_U8_UDR_REG           *((volatile u8 *)0x2C)

#define UART_U8_UCSRA_REG         *((volatile u8 *)0x2B)
#define UART_U8_UCSRB_REG         *((volatile u8 *)0x2A)
#define UART_U8_UCSRC_REG         *((volatile u8 *)0x40)

#define UART_U8_UBRRL_REG         *((volatile u8 *)0x29)
#define UART_U8_UBRRH_REG         *((volatile u8 *)0x40)
/*---------------------------------------------------------*/

/*--------------equation to calculate UBRR value-----------*/
#define UART_UBRR (FOCS/16/BaudRate-1)
/*---------------------------------------------------------*/

#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
