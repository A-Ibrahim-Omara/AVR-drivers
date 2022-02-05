/*
 * UART_Cfg.h
 *
 *  Created on: Jan 28, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_UART_UART_CFG_H_
#define INCLUDE_MCAL_UART_UART_CFG_H_

/*--------The Frequency (Crystal value) manually---------*/
#define FOCS                    8000000
/*-------------------------------------------------------*/

/*-----------------BaudRate to be used-------------------*/
#define BaudRate               9600
/*-------------------------------------------------------*/

/*-------------------Modes to be used---------------------*/
#define UART_INT_POLL_MODE               POLLING
#define UART_ASYNCH_SYNCH_MODE           ASYNCHRONOUS
/*-------------------------------------------------------*/
/*------------To Double The Speed Of The UART------------*/
#define UART_DOUBLE_SPEED       OFF
/*-------------------------------------------------------*/

/*-----To Enable the multiprocessor Communication Mode---*/
#define UART_MULTI_PROCESSOR    OFF
/*-------------------------------------------------------*/

#endif /* INCLUDE_MCAL_UART_UART_CFG_H_ */
