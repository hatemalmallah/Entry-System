/*
 * EntrySystem_private.h
 *
 *  Created on: Sep 17, 2026
 *      Author: hatem
 */

#ifndef APP_ENTRYSYSTEM_ENTRYSYSTEM_PRIVATE_H_
#define APP_ENTRYSYSTEM_ENTRYSYSTEM_PRIVATE_H_

typedef enum
{
	State_Init,
	State_ResetInput,
	State_EnterPass,
	State_Checkpass,
	State_WrongPass,
	State_Locked,
	State_DrawMainMenu,
	State_MainMenu
}SystemState_t;

#endif /* APP_ENTRYSYSTEM_ENTRYSYSTEM_PRIVATE_H_ */
