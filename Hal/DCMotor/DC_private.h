/*
 * DC_private.h
 *
 *  Created on: Sep 16, 2026
 *      Author: hatem
 */

#ifndef HAL_DCMOTOR_DC_PRIVATE_H_
#define HAL_DCMOTOR_DC_PRIVATE_H_
#include "../../Common/StdTypes.h"

typedef enum
{
	DC_OnOffOnly,
	DC_directionControl,

}DC_ControlType_t;


typedef enum
{
	DC_NPN,
	DC_PNP,
	DC_Hybrid,

}DC_ConnectionType_t;



typedef struct
{
	u8 ControlType;
	u8 ConnectionType;
	u8 DC_M1Group;
	u8 DC_M1Pin;
	u8 DC_M2Group;
	u8 DC_M2Pin;

}DC_config_t;

#endif /* HAL_DCMOTOR_DC_PRIVATE_H_ */
