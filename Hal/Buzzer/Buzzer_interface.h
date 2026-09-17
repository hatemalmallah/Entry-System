/*
 * Buzzer_interface.h
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

#include "Buzzer_config.h"
#include "Buzzer_private.h"


//Buzzer_Init
void Buzzer_Init();

//Buzzer_On
void Buzzer_On(u8 GroupName,u8 PinNo);

//Buzzer_OFF
void Buzzer_Off(u8 GroupName,u8 PinNo);

//Buzzer_Tone
void Buzzer_Tone(u8 GroupName,u8 PinNo);


#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
