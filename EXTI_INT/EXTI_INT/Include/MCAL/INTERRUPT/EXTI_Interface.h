/*
 * EXTI_Interface.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Ibrahim
 */


#ifndef INCLUDE_MCAL_INTERRUPT_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_INTERRUPT_EXTI_INTERFACE_H_

#include "../../LIB/bit_math.h"
#include "../../LIB/std_type.h"

#define EXTI_u8_RISING_MODE           3
#define EXTI_u8_FALLING_MODE          2
#define EXTI_u8_LOW_LEVEL_MODE        0
#define EXTI_u8_IOC_MODE              1

#define EXTI_u8_EXTI0              0
#define EXTI_u8_EXTI1              1
#define EXTI_u8_EXTI2              2

#define EXTI_u8_EXTI0_ENABLE_BIT    6
#define EXTI_u8_EXTI1_ENABLE_BIT    7
#define EXTI_u8_EXTI2_ENABLE_BIT    5

void MEXTI_voidEXTIEnable(u8 copy_u8EXTI_num,u8 copy_u8EXTI_Sense);
void MEXTI_voidEXTIDisable(u8 copy_u8EXTI_num);
void MEXTI_voidSetCallBack(void(*copyPointerToFunction)(void),u8 copy_u8_index);




#endif /* INCLUDE_MCAL_INTERRUPT_EXTI_INTERFACE_H_ */
