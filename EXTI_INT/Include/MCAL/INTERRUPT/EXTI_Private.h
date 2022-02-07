/*
 * EXTI_Private.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_INTERRUPT_EXTI_PRIVATE_H_
#define INCLUDE_MCAL_INTERRUPT_EXTI_PRIVATE_H_

#define EXTI_u8_MCUCR   *((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR  *((volatile u8 *)0x54)
#define EXTI_u8_GIFR    *((volatile u8 *)0x5A)
#define EXTI_u8_GICR    *((volatile u8 *)0x5B)


#define EXTI_u8_MCUCR_PIN0      0
#define EXTI_u8_MCUCR_PIN1      1
#define EXTI_u8_MCUCR_PIN2      2
#define EXTI_u8_MCUCR_PIN3      3

#define EXTI_u8_MCUCSR_PIN0     6


#endif /* INCLUDE_MCAL_INTERRUPT_EXTI_PRIVATE_H_ */
