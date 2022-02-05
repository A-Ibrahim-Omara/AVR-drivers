/*
 * TIMER1_Private.h
 *
 *  Created on: Jan 25, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TIMER1_u8_TCCR1A      *((volatile u8  *)0x4F)
#define TIMER1_u8_TCCR1B      *((volatile u8  *)0x4E)

#define TIMER1_u8_TCNT1L      *((volatile u8  *)0x4C)
#define TIMER1_u8_TCNT1H      *((volatile u8  *)0x4D)
#define TIMER1_u8_TCNT1       *((volatile u16 *)0x4C)

#define TIMER1_u8_OCR1AL      *((volatile u8  *)0x4A)    /*comment*/
#define TIMER1_u8_OCR1AH      *((volatile u8  *)0x4B)
#define TIMER1_u8_OCR1A       *((volatile u16 *)0x4A)    /*comment*/

#define TIMER1_u8_OCR1BL      *((volatile u8  *)0x48)    /*comment*/
#define TIMER1_u8_OCR1BH      *((volatile u8  *)0x49)
#define TIMER1_u8_OCR1B       *((volatile u16 *)0x48)    /*comment*/

#define TIMER1_u8_ICR1L      *((volatile u8  *)0x46)    /*comment*/
#define TIMER1_u8_ICR1H      *((volatile u8  *)0x47)
#define TIMER1_u8_ICR1       *((volatile u16 *)0x46)    /*comment*/

#define TIMER1_u8_TIMSK       *((volatile u8 *)0x59)
#define TIMER1_u8_TIFR        *((volatile u8 *)0x58)


#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
