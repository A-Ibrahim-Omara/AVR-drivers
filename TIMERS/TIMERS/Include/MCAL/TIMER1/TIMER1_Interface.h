/*
 * TIMER1_Interface.h
 *
 *  Created on: Jan 25, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_

#define ENABLE                    1
#define DISABLE                   0

#define TIMER1_u8_NORMAL_MODE         1
#define TIMER1_u8_CTC_MODE            2
#define TIMER1_u8_FPWM_MODE           3

#define TIMER1_u8_FPWM_INVERTING      1
#define TIMER1_u8_FPWM_NONINVERTING   2

#define TCCR1A_u8_COM1A1_PIN7      7
#define TCCR1A_u8_COM1A0_PIN6      6
#define TCCR1A_u8_WGM11_PIN1       1
#define TCCR1A_u8_WGM10_PIN0       0
#define TCCR1A_u8_COM00_PIN4      4
#define TCCR0_u8_COM01_PIN5      5
#define TCCR0_u8_COM00_PIN4      4
#define TCCR0_u8_COM01_PIN5      5


void MTIMERS_voidTimer1Init(void);

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
