/*
 * TIMER1_Private.h
 *
 *  Created on: Jan 25, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TIMER1_u8_TCCR1A_REG      *((volatile u8  *)0x4F)
#define TIMER1_u8_TCCR1B_REG      *((volatile u8  *)0x4E)

#define TIMER1_u8_TCNT1L_REG      *((volatile u8  *)0x4C)
#define TIMER1_u8_TCNT1H_REG      *((volatile u8  *)0x4D)
#define TIMER1_u8_TCNT1_REG       *((volatile u16 *)0x4C)

#define TIMER1_u8_OCR1AL_REG      *((volatile u8  *)0x4A)    /*comment*/
#define TIMER1_u8_OCR1AH_REG      *((volatile u8  *)0x4B)
#define TIMER1_u8_OCR1A_REG       *((volatile u16 *)0x4A)    /*comment*/

#define TIMER1_u8_OCR1BL_REG      *((volatile u8  *)0x48)    /*comment*/
#define TIMER1_u8_OCR1BH_REG      *((volatile u8  *)0x49)
#define TIMER1_u8_OCR1B_REG       *((volatile u16 *)0x48)    /*comment*/

#define TIMER1_u8_ICR1L_REG      *((volatile u8  *)0x46)    /*comment*/
#define TIMER1_u8_ICR1H_REG      *((volatile u8  *)0x47)
#define TIMER1_u8_ICR1_REG       *((volatile u16 *)0x46)    /*comment*/

#define TIMER1_u8_TIMSK_REG       *((volatile u8 *)0x59)
#define TIMER1_u8_TIFR_REG        *((volatile u8 *)0x58)


#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
