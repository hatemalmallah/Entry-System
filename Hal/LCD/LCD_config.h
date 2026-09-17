/*
 * LCD_config.h
 *
 *  Created on: Sep 4, 2026
 *      Author: hatem
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include "LCD_private.h"

#define LCD_Mode          LCD_8BitMode

#define LCD_RSPin         DIO_Pin0
#define LCD_RSGroup       DIO_GroupC

#define LCD_RWPin         DIO_Pin1
#define LCD_RWGroup       DIO_GroupC

#define LCD_EPin          DIO_Pin2
#define LCD_EGroup        DIO_GroupC

#if LCD_Mode==LCD_8BitMode
    #define LCD_DataGroup  DIO_GroupD

#elif LCD_Mode==LCD_4BitMode
    #define Lcd_D4Pin      DIO_Pin4
	#define Lcd_D4Group    DIO_GroupC
	#define Lcd_D5Pin      DIO_Pin5
	#define Lcd_D5Group    DIO_GroupC
	#define Lcd_D6Pin      DIO_Pin6
	#define Lcd_D6Group    DIO_GroupC
	#define Lcd_D7Pin      DIO_Pin7
	#define Lcd_D7Group    DIO_GroupC
#else
#error "Invalid LCD Mode"
#endif

#define  LCD_FunctionSet   LCD_8Bit2Line5x8F
#define  LCD_DisplayOnOff  LCD_CursorBlinking
#define  LCD_EntryMode     LCD_RightNoShift

#endif /* HAL_LCD_LCD_CONFIG_H_ */
