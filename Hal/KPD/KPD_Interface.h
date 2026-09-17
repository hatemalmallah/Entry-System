/*
 * KPD_Interface.h
 *
 *  Created on: Sep 10, 2026
 *      Author: hatem
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#include "KPD_Config.h"
#include "../../Mcal/DIO/DIO_interface.h"
#include "KPD_Private.h"



void KPD_Init();
void KPD_GetValue(u8 *KPD_Value);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
