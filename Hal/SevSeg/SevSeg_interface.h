/*
 * SevSeg_interface.h
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include "SevSeg_config.h"
#include "SevSeg_private.h"

//SevSeg_Init
void SevSeg_Init(u8 GroupName);

//SevSeg_DisplayNum
void SevSeg_DisplayNum(u8 GroupName, u8 Number);

#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
