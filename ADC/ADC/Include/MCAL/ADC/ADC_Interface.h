/*
 * ADC_Interface.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

#define ADC_u8_CHANNEL_0          0
#define ADC_u8_CHANNEL_1          1
#define ADC_u8_CHANNEL_2          2
#define ADC_u8_CHANNEL_3          3
#define ADC_u8_CHANNEL_4          4
#define ADC_u8_CHANNEL_5          5
#define ADC_u8_CHANNEL_6          6
#define ADC_u8_CHANNEL_7          7

void ADC_voidInit(void);
u16 ADC_u16GetDigitlValue(u8 copy_u8_ChannelNumber);


#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
