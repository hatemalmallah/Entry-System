/*
 * LCD_interface.h
 *
 *  Created on: Sep 4, 2026
 *      Author: hatem
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "LCD_config.h"
#include "../../Common/StdTypes.h"

void LCD_Init ();
void LCD_SendCommand(u8 Command);
void LCD_WriteCharacter(u8 Character);
void LCD_WriteMessage (s8 *String);
void LCD_WriteNumber  (s32 Number);
void LCD_MoveTo (u8 LineNo,u8 DigitNo);
void LCD_StoreSpecialCharacter(u8*SpecialChar,u8 LocationNo);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
