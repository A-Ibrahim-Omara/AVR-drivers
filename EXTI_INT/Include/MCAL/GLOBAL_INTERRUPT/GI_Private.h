/*
 * GI_Private.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_GLOBAL_INTERRUPT_GI_PRIVATE_H_
#define INCLUDE_MCAL_GLOBAL_INTERRUPT_GI_PRIVATE_H_

#define GI *((volatile u8 *)0x5f)
#define MGI_u8_ENABLE  1
#define MGI_u8_DISABLE 0


#define MGI_u8_INTERRUPT_ENABLE_BIT 7

#endif /* INCLUDE_MCAL_GLOBAL_INTERRUPT_GI_PRIVATE_H_ */
