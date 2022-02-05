/*
 * UART_Interface.h
 *
 *  Created on: Jan 28, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

/*-------------------Modes to be used--------------------*/
#define POLLING         1
#define INTERRUPT       2

#define ASYNCHRONOUS    1
#define SYNCHRONOUS     2

/*-------------------------------------------------------*/

/*----------------value of a specific bit----------------*/
#define OFF         0
#define ON          1
/*-------------------------------------------------------*/

/*------PIN of Double speed mode-------------------------*/
#define UART_U8_UCSRA_PIN1          1
/*------PIN of the multiprocessor Communication Mode-----*/
#define UART_U8_UCSRA_PIN0          0
/*-------------------------------------------------------*/
#define UART_U8_UCSRA_PIN5          5
#define UART_U8_UCSRA_PIN6          6
#define UART_U8_UCSRA_PIN7          7

/*-------------------------------------------------------*/

#define PARITY_DISABLED       0
#define PARITY_RESERVED		  1
#define PARITY_EVEN           2
#define PARITY_ODD            3

/*------PIN of RX Complete Interrupt Enable--------------*/
#define UART_U8_UCSRB_PIN7          7
/*------PIN of TX Complete Interrupt Enable--------------*/
#define UART_U8_UCSRB_PIN6          6
/*------PIN of enables interrupt on the UDRE Flag--------*/
#define UART_U8_UCSRB_PIN5          5
/*------PIN of RXEN enables the USART Receiver-----------*/
#define UART_U8_UCSRB_PIN4          4
/*------PIN of TXEN enables the USART Transmitter--------*/
#define UART_U8_UCSRB_PIN3          3
/*------PIN of UCSZ2 Character Size----------------------*/
#define UART_U8_UCSRB_PIN2          2
/*------PIN of Receive  Data Bit 8-----------------------*/
#define UART_U8_UCSRB_PIN1          1
/*------PIN of Transmit Data Bit 8-----------------------*/
#define UART_U8_UCSRB_PIN0          0
/*-------------------------------------------------------*/

/*------PIN of Select REG UCSRC or URSEL-----------------*/
#define UART_U8_UCSRC_PIN7          7
/*------PIN of Select Asynchronous and Synch mode--------*/
#define UART_U8_UCSRC_PIN6          6
/*------PIN of UPM1 Select Parity Mode-------------------*/
#define UART_U8_UCSRC_PIN5          5
/*------PIN of UPM0 Select Parity Mode-------------------*/
#define UART_U8_UCSRC_PIN4          4
/*------PIN of Stop Bit Select---------------------------*/
#define UART_U8_UCSRC_PIN3          3
/*------PIN of UCSZ2 Character Size----------------------*/
#define UART_U8_UCSRC_PIN2          2
/*------PIN of Receive  Data Bit 8-----------------------*/
#define UART_U8_UCSRC_PIN1          1
/*------PIN of Transmit Data Bit 8-----------------------*/
#define UART_U8_UCSRC_PIN0          0
/*-------------------------------------------------------*/





/*-----------------Functions Prototypes------------------*/
void UART_voidInit(void);
void UART_voidTransmitChar(u8 local_u8_data);
u8 UART_u8_RecieveChar(void);


/*-------------------------------------------------------*/

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
