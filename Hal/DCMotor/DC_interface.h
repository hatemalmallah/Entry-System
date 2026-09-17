/*
 * DC_interface.h
 *
 *  Created on: Sep 16, 2026
 *      Author: hatem
 */

#ifndef HAL_DCMOTOR_DC_INTERFACE_H_
#define HAL_DCMOTOR_DC_INTERFACE_H_
#include "DC_config.h"
#include "DC_private.h"
#include "../../Mcal/DIO/DIO_interface.h"
#include "../../Common/BitMath.h"
#include "../../Common/StdTypes.h"

void DC_Init(DC_config_t * MyConfig);

void DC_Off(DC_config_t *MyConfig);

ErrorState_t DC_On(DC_config_t *MyConfig);

void DC_OnCW(DC_config_t *MyConfig);

void DC_OnCCW(DC_config_t *MyConfig);

#endif /* HAL_DCMOTOR_DC_INTERFACE_H_ */
