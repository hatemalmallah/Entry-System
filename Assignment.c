/*

 * Assignment.c
 *
 *  Created on: Aug 26, 2026
 *      Author: hatem
 */
#include "EntrySystem/EntrySystem_interface.h"
#include "../Hal/DCMotor/DC_interface.h"
#include <util/delay.h>


//************************************//

void main()
{
  Dashboard_Init();

  while(1)
  {
	  Dashboard_Run();
  }
}
