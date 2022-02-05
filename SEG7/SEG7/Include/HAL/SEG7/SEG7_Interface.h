/*
 * SEG7_Interface.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_HAL_SEG7_SEG7_INTERFACE_H_
#define INCLUDE_HAL_SEG7_SEG7_INTERFACE_H_

#define SEG7_SELECT_U8_PORTA 0
#define SEG7_SELECT_U8_PORTB 1
#define SEG7_SELECT_U8_PORTC 2
#define SEG7_SELECT_U8_PORTD 3

#define ZERO 	 0
#define ONE 	 1
#define TWO      2
#define THREE    3
#define FOUR     4
#define FIVE     5
#define SIX      6
#define SEVEN    7
#define EIGHT    8
#define NINE     9

/*Move to private*/
#define SEG7_SELECT_VALUE_ZERO 	   0x3f
#define SEG7_SELECT_VALUE_ONE 	   0x06
#define SEG7_SELECT_VALUE_TWO      0x5b
#define SEG7_SELECT_VALUE_THREE    0x4f
#define SEG7_SELECT_VALUE_FOUR     0x66
#define SEG7_SELECT_VALUE_FIVE     0x6d
#define SEG7_SELECT_VALUE_SIX      0x7d
#define SEG7_SELECT_VALUE_SEVEN    0x07
#define SEG7_SELECT_VALUE_EIGHT    0x7f
#define SEG7_SELECT_VALUE_NINE     0x6f

/***************************************************************/

/***************************************************************/
void HSEG7_VoidInit(void);


/***************************************************************/

/***************************************************************/
void HSEG7_VoidDisplayNumber(u8 copy_u8Number);


/***************************************************************/

/***************************************************************/
void HSEG7_VoidAddSeg7(u8 copy_u8Seg7Port);



/***************************************************************/

/***************************************************************/

#endif /* INCLUDE_HAL_SEG7_SEG7_INTERFACE_H_ */
