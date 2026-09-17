/*

 * LCD_program.c
 *
 *  Created on: Sep 7, 2026
 *      Author: hatem
 */

#include "LCD_interface.h"
#include "../../Mcal/DIO/DIO_interface.h"
#include <util/delay.h>
void LCD_Init ()
{
#if LCD_Mode==LCD_8BitMode
DIO_DirectionSetForPin(LCD_RSGroup,LCD_RSPin,DIO_Output);
DIO_DirectionSetForPin(LCD_RWGroup,LCD_RWPin,DIO_Output);
DIO_DirectionSetForPin(LCD_EGroup,LCD_EPin,DIO_Output);
DIO_DirectionSetForGroup(LCD_DataGroup,DIO_GroupOutput);
_delay_ms(35);

LCD_SendCommand(LCD_FunctionSet);
_delay_ms(1);

LCD_SendCommand(LCD_DisplayOnOff);
_delay_ms(1);

LCD_SendCommand(LCD_ClearDisplay);
_delay_ms(2);

LCD_SendCommand(LCD_EntryMode);

#elif Lcd_Mode==Lcd_4BitMode
#else
#error "Invaild LCD Mode"
#endif

}

void LCD_SendCommand(u8 Command)
{
#if LCD_Mode==LCD_8BitMode
	DIO_WriteValueForPin(LCD_RSGroup,LCD_RSPin,DIO_Low);
	DIO_WriteValueForPin(LCD_RWGroup,LCD_RWPin,DIO_Low);
    DIO_WriteValueForGroup(LCD_DataGroup,Command);

    DIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_High);
    _delay_ms(1);
    DIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_Low);

#elif LCD_Mode==LCD_4BitMode
#else
#error "Invalid LCD Mode"

#endif
}

void LCD_WriteCharacter(u8 Character)
{
#if LCD_Mode==LCD_8BitMode
	DIO_WriteValueForPin(LCD_RSGroup,LCD_RSPin,DIO_High);
	DIO_WriteValueForPin(LCD_RWGroup,LCD_RWPin,DIO_Low);
	DIO_WriteValueForGroup(LCD_DataGroup,Character);

	 DIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_High);
	    _delay_ms(1);
	 DIO_WriteValueForPin(LCD_EGroup,LCD_EPin,DIO_Low);

	#elif LCD_Mode==LCD_4BitMode
	#else
	#error "Invalid LCD Mode"
	#endif
}

void LCD_WriteMessage (s8 *String)
{
	u8 counter=0;
	while(String[counter]!='\0')
	{
		LCD_WriteCharacter(String[counter]);
		counter++;
	}
}

void LCD_WriteNumber  (s32 Number)
{
u8 NumberDigits[10]={0};
u8 Index=0;
s8 Counter=0;


if(Number==0)
{
	LCD_WriteCharacter('0');
	return;
}

if(Number<0)
{
	LCD_WriteCharacter('-');
	Number=Number * -1;
}
while(Number>0)
{
	NumberDigits[Index]= (Number%10)+'0';
	Number= Number/10;
	Index++;
}
for(Counter=Index-1;Counter>=0;Counter--)
{
	LCD_WriteCharacter(NumberDigits[Counter]);
}
}

void LCD_MoveTo (u8 LineNo,u8 DigitNo)
{
	u8 DDRAMAddress=0;
	switch(LineNo)
	{
	case Lcd_Line1 : DDRAMAddress=Lcd_AddressLine1+DigitNo;break;
	case Lcd_Line2 : DDRAMAddress=Lcd_AddressLine2+DigitNo;break;
	default : break;
	}
	LCD_SendCommand(LCD_SetDDRAMCommand|DDRAMAddress);
}

void LCD_StoreSpecialCharacter(u8*SpecialChar,u8 LocationNo)
{
	u8 LocationCGRAMAddress=LocationNo*8;
	LCD_SendCommand(LCD_SetCGRAMCommand|LocationCGRAMAddress);

	for(u8 index=0;index<8;index++)
	{
		LCD_WriteCharacter(SpecialChar[index]);
	}

	LCD_MoveTo(Lcd_Line1,0);
}
