/*
 * Button_interface.h
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

#include "Button_config.h"
#include "Button_private.h"

// Btn_Init
void Btn_InitForPin(u8 GroupName,u8 PinNo);
void Btn_InitForGroup(u8 GroupName);

// Btn_GetState
u8 Btn_GetStateForPin(u8 GroupName,u8 PinNo);
u8 Btn_GetStateForGroup(u8 GroupName);
#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
