/*
 * LCD_Cfg.h
 *
 *  Created on: Jan 4, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_HAL_LCD_CFG_H_
#define INCLUDE_HAL_LCD_CFG_H_

#define LCD_DATA_MODE    LCD_DATA_MODE_4
#define LCD_DATA_PORT    DIO_U8_PORTA
#define LCD_CONTROL_PORT DIO_U8_PORTB

/*-----GPIO Cfg----*/
#define LCD_RS_PIN  DIO_U8_PIN1
#define LCD_RW_PIN  DIO_U8_PIN2
#define LCD_E_PIN   DIO_U8_PIN3
/*---------------------------*/
#if DATA_MODE == DATA_MODE_8
#define DB0_PIN 0
#define DB1_PIN 1
#define DB2_PIN 2
#define DB3_PIN 3
#endif
#define DB4_PIN 4
#define DB5_PIN 5
#define DB6_PIN 6
#define DB7_PIN 7




#endif /* INCLUDE_HAL_LCD_CFG_H_ */
