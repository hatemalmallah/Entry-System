/*
 * Led_program.c
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */
#include "../../Mcal/DIO/DIO_interface.h"
#include "Led_interface.h"



//Led_Init
void Led_InitFor2Pin()
{
	DIO_DirectionSetForPin(LedRed_Group, LedRed_Pin, DIO_Output);
	DIO_DirectionSetForPin(LedGreen_Group, LedGreen_Pin, DIO_Output);
}

void Led_InitForGroup(u8 GroupName)
{
	DIO_DirectionSetForGroup(GroupName,DIO_GroupOutput);
}

//Led_on
void Led_OnForPin(u8 GroupName, u8 PinNo)
{
	DIO_WriteValueForPin(GroupName,PinNo,DIO_High);
}

void Led_OnForGroup(u8 GroupName)
{
	DIO_WriteValueForGroup(GroupName,DIO_GroupHigh);
}

//Led_Off
void Led_OffPin(u8 GroupName, u8 PinNo)
{
	DIO_WriteValueForPin(GroupName,PinNo,DIO_Low);
}

void Led_OffGroup(u8 GroupName)
{
	DIO_WriteValueForGroup(GroupName,DIO_GroupLow);
}

//Led_Toggle
void Led_ToggleForPin(u8 GroupName, u8 PinNo)
{
	DIO_ToggleControlForPin(GroupName,PinNo);
}

void Led_ToggleForGroup(u8 GroupName)
{
	DIO_ToggleControlForGroup(GroupName);
}

