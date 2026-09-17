/*
 * LCD_private.h
 *
 *  Created on: Sep 4, 2026
 *      Author: hatem
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define LCD_8BitMode    1
#define LCD_4BitMode    2

//Display Command
#define LCD_ClearDisplay      0x01
#define LCD_ReturnHome        0x02

/*
  I/D=1, Increment AC (Cursor moves right)
    I/D=0, Decrement AC (Cursor moves left)
    S=1, screen shifting on
    S=0, screen shifting off
    0 0 0 0 0 1 I/D S
    0 0 0 0 0 1  0  0
    0 0 0 0 0 1  1  0
 */
#define LCD_LeftNoShift       0x04
#define LCD_LeftShift         0x05
#define LCD_RightNoShift      0x06
#define LCD_RightShift        0x07

/*
   DisplayOnOFF
    D=1, display on; D=0, display off
    C=1, cursor on; C=0, cursor off
    B=1, cursor blinking on; B=0, cursor blinking off
    0 0 0 0 1 D C B
    0 0 0 0 1 0 0 0
    0 0 0 0 1 1 0 0
    0 0 0 0 1 1 1 0
    0 0 0 0 1 1 1 1
 */
#define LCD_DisplayOff         0x08
#define LCD_DisplayOn          0x0C
#define LCD_CursorOn           0x0E
#define LCD_CursorBlinking     0x0F


/*
 * Function Set
 *  DL=1, 8-bit interface; DL=0, 4-bit interface
    N=1, 2-line display; N=0, 1-line display
    F=1, 5x11 dots font; F=0, 5x8 dots font
  */
#define LCD_8Bit2Line5x11F     0x3C
#define LCD_8Bit2Line5x8F      0x38
#define LCD_8Bit1Line5x11F     0x34
#define LCD_8Bit1Line5x8F      0x30

#define LCD_4Bit2Line5x11F     0x2C
#define LCD_4Bit2Line5x8F      0x28
#define LCD_4Bit1Line5x11F     0x24
#define LCD_4Bit1Line5x8F      0x20

/*Set CGRAM*/
#define LCD_SetCGRAMCommand    0x40

/*Set DDRAM*/
#define LCD_SetDDRAMCommand    0x80



#define Lcd_Line1     0
#define Lcd_Line2     1



#define Lcd_AddressLine1       0x00
#define Lcd_AddressLine2       0x40



#endif /* HAL_LCD_LCD_PRIVATE_H_ */
