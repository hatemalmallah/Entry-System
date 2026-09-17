/*
 * Buzzer_program.c

 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */
#include "../../Mcal/DIO/DIO_interface.h"
#include "Buzzer_interface.h"



//Buzzer_Init
void Buzzer_Init()
{
	DIO_DirectionSetForPin(Buzzer_Group, Buzzer_Pin, DIO_Output);
}

//Buzzer_On
void Buzzer_On(u8 GroupName,u8 PinNo)
{
#if Buzzer_Connection==Buzzer_NPNConnection
	DIO_WriteValueForPin(GroupName,PinNo,DIO_High);

#elif Buzzer_Connection==Buzzer_PNPConnection
	DIO_WriteValueForPin(GroupName,PinNo,DIO_Low);
#error "Invalid Buzzer Connection"
#endif

}

//Buzzer_OFF
void Buzzer_Off(u8 GroupName,u8 PinNo)
{
#if Buzzer_Connection==Buzzer_NPNConnection
	DIO_WriteValueForPin(GroupName,PinNo,DIO_Low);

#elif Buzzer_Connection==Buzzer_PNPConnection
	DIO_WriteValueForPin(GroupName,PinNo,DIO_High);
#error "Invalid Buzzer Connection"
#endif
}

//Buzzer_Tone
void Buzzer_Tone(u8 GroupName,u8 PinNo)
{
	DIO_ToggleControlForPin(GroupName,PinNo);
}

