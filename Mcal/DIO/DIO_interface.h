/*
 * DIO_interface.h
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../../Common/StdTypes.h"
#include "../Atmega32Registers.h"
#include "DIO_config.h"
#include "DIO_private.h"
//**API**//

//API TO Select Direction(input-output)
void DIO_DirectionSetForPin(u8 GroupName,u8 PinNo,u8 DirectionState);
void DIO_DirectionSetForGroup(u8 GroupName,u8 DirectionState);

//API To Provide Output value(High-Low)
void DIO_WriteValueForPin(u8 GroupName,u8 PinNo,u8 OutputState);
void DIO_WriteValueForGroup(u8 GroupName,u8 OutputState);

//API To Read input state
u8 DIO_ReadStateInputForPin(u8 GroupName,u8 PinNo);
u8 DIO_ReadStateInputForGroup(u8 GroupName);

//API To Enable Internal Pull-Up
void DIO_InternalPullUpControlForPin(u8 GroupName,u8 PinNo,u8 PullUpState);
void DIO_InternalPullUpControlForGroup(u8 GroupName,u8 PullUpState);

//API To Toggle
void DIO_ToggleControlForPin(u8 GroupName, u8 PinNo);
void DIO_ToggleControlForGroup(u8 GroupName);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
