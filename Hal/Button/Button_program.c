/*
 * Button_program.c
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#include "../../Mcal/DIO/DIO_interface.h"
#include "Button_interface.h"


// Btn_Init
void Btn_InitForPin(u8 GroupName,u8 PinNo)
{
	DIO_DirectionSetForPin(GroupName,PinNo,DIO_Input);
	DIO_InternalPullUpControlForPin(GroupName,PinNo,DIO_Enable);
}

void Btn_InitForGroup(u8 GroupName)
{
	DIO_DirectionSetForGroup(GroupName,DIO_GroupInput);
	DIO_InternalPullUpControlForGroup(GroupName,DIO_AllEnable);
}

// Btn_GetState
u8 Btn_GetStateForPin(u8 GroupName,u8 PinNo)
{
	u8 InputValue=0xFF;
	InputValue= DIO_ReadStateInputForPin(GroupName, PinNo);
	return InputValue;
}

u8 Btn_GetStateForGroup(u8 GroupName)
{
	u8 InputValue=0xFF;
		InputValue= DIO_ReadStateInputForGroup(GroupName);
		return InputValue;
}
