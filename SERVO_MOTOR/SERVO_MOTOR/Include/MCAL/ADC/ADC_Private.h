/*
 * ADC_Private.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADC_u8_ADMUX_REG   *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG  *((volatile u8 *)0x26)
#define ADC_u8_ADCL  	   *((volatile u8 *)0x24)
#define ADC_u8_ADCH  	   *((volatile u8 *)0x25)
#define ADC_u8_SFIOR       *((volatile u8 *)0x50)

#define ADC_u8_ADC_REG     *((volatile u16 *)0x24)


#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
