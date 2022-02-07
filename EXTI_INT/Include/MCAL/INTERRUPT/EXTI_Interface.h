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
/*-------------------------------------------------------------*/
#define EXTI_u8_RISING_MODE           3
#define EXTI_u8_FALLING_MODE          2
#define EXTI_u8_LOW_LEVEL_MODE        0
#define EXTI_u8_IOC_MODE              1
/*-------------------------------------------------------------*/
#define EXTI_u8_EXTI0                 0
#define EXTI_u8_EXTI1                 1
#define EXTI_u8_EXTI2                 2
/*-------------------------------------------------------------*/
#define EXTI_u8_EXTI0_ENABLE_BIT      6
#define EXTI_u8_EXTI1_ENABLE_BIT      7
#define EXTI_u8_EXTI2_ENABLE_BIT      5
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MEXTI_voidEXTIEnable             *******/
/*Description      -->> External Interrupt Enable        *******/
/*Arguments Input  -->>                                         *
 * EX_INT number-->EXTI_u8_EXTI0                                *
 * 				  ,EXTI_u8_EXTI1,                               *
 * 				   EXTI_u8_EXTI2.                               *
 * Sense_mode-->EXTI_u8_RISING_MODE                             *
 * 			   ,EXTI_u8_FALLING_MODE                            *
 *             ,EXTI_u8_LOW_LEVEL_MODE                          *
 *             ,EXTI_u8_IOC_MODE.                               *
 *                                                             */
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MEXTI_voidEXTIEnable(u8 copy_u8EXTI_num,u8 copy_u8EXTI_Sense);
/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MEXTI_voidEXTIDisable            *******/
/*Description      -->> External Interrupt Disable       *******/
/*Arguments Input  -->>                                         *
 * EX_INT number-->EXTI_u8_EXTI0                                *
 * 				  ,EXTI_u8_EXTI1,                               *
 * 				   EXTI_u8_EXTI2.                               *
 *                                                             */
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MEXTI_voidEXTIDisable(u8 copy_u8EXTI_num);
/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MEXTI_voidSetCallBack            *******/
/*Description      -->> callback func                    *******/
/*Arguments Input  -->>                                         *
 * Function address & index of EXT_INT pointer                  *
 *                 EXTI_u8_EXTI0  --> index 0                   *
 * 				  ,EXTI_u8_EXTI1, --> index 1                   *
 * 				   EXTI_u8_EXTI2. --> index 2                   *
 *                                                             */
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MEXTI_voidSetCallBack(void(*copyPointerToFunction)(void),u8 copy_u8_index);
/*-------------------------------------------------------------*/




#endif /* INCLUDE_MCAL_INTERRUPT_EXTI_INTERFACE_H_ */
