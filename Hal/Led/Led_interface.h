/*
 * Led_interface.h
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "Led_config.h"
#include "Led_private.h"
//Led_Init
void Led_InitFor2Pin();
void Led_InitForGroup(u8 GroupName);

//Led_On
void Led_OnForPin(u8 GroupName, u8 PinNo);
void Led_OnForGroup(u8 GroupName);

//Led_Off
void Led_OffPin(u8 GroupName, u8 PinNo);
void Led_OffGroup(u8 GroupName);

//Led_Toggle
void Led_ToggleForPin(u8 GroupName, u8 PinNo);
void Led_ToggleForGroup(u8 GroupName);
#endif /* HAL_LED_LED_INTERFACE_H_ */
