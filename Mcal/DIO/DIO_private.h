/*
 * DIO_private.h
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_
//**Group Name**//
#define DIO_GroupA  0
#define DIO_GroupB  1
#define DIO_GroupC  2
#define DIO_GroupD  3

//**Pin No**//
#define DIO_Pin0  0
#define DIO_Pin1  1
#define DIO_Pin2  2
#define DIO_Pin3  3
#define DIO_Pin4  4
#define DIO_Pin5  5
#define DIO_Pin6  6
#define DIO_Pin7  7

//**Direction State**//
#define DIO_Input   0
#define DIO_Output  1
#define DIO_GroupInput   0x00
#define DIO_GroupOutput  0xFF


//**Output State**//
#define DIO_High 1
#define DIO_Low 0
#define DIO_GroupHigh 0xFF
#define DIO_GroupLow 0x00

//**Internal Pull-Up **//
#define DIO_Enable 1
#define DIO_Disable 0
#define DIO_AllEnable 0xFF
#define DIO_AllDisable 0x00




#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
