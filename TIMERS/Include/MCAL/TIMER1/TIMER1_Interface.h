/*
 * TIMER1_Interface.h
 *
 *  Created on: Jan 25, 2022
 *      Author: Ahmed Ibrahim
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
/*-------------------------------------------------------------*/
#define Compare_Output_Mode_A          1
#define Compare_Output_Mode_B          2
/*-------------------------------------------------------------*/
#define TCCR1A_u8_COM1A1_PIN7		   7
#define TCCR1A_u8_COM1A0_PIN6		   6
#define TCCR1A_u8_COM1B1_PIN4          5
#define TCCR1A_u8_COM1B0_PIN4          4
#define TCCR1A_u8_FOC1A_PIN4           3
#define TCCR1A_u8_FOC1B_PIN4           2
#define TCCR1A_u8_WGM11_PIN1	   	   1
#define TCCR1A_u8_WGM10_PIN0		   0

#define TCCR1B_u8_CS10_PIN0            0
#define TCCR1B_u8_CS11_PIN1            1
#define TCCR1B_u8_CS12_PIN2            2
#define TCCR1B_u8_WGM12_PIN3           3
#define TCCR1B_u8_WGM13_PIN4           4

/*-------------------------------------------------------------*/
/***************************************************************/
/*Function Name    -->> MTIMERS_voidTimer1Init           *******/
/*Description      -->> To initiate Timer1               *******/
/*Arguments Input  -->> void                             *******/
/*Arguments Output -->> void                             *******/
/***************************************************************/
/*-------------------------------------------------------------*/
void MTIMERS_voidTimer1Init(void);
/*-------------------------------------------------------------*/
#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
