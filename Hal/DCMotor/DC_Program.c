/*
 * DC_Program.c
 *
 *  Created on: Sep 16, 2026
 *      Author: hatem
 */
#include "DC_interface.h"

void DC_Init(DC_config_t * MyConfig)
{
	if(MyConfig!=NULL)
	{
		if(MyConfig->ControlType==DC_OnOffOnly)
		{
			DIO_DirectionSetForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_Output);
		}
		else if(MyConfig->ControlType==DC_directionControl)
		{
			DIO_DirectionSetForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_Output);
			DIO_DirectionSetForPin(MyConfig->DC_M2Group,MyConfig->DC_M2Pin,DIO_Output);
		}
	}
}

ErrorState_t DC_On(DC_config_t *MyConfig)
{
	ErrorState_t Local_Error=E_OK;
	if(MyConfig!=NULL)
	{
		if(MyConfig->ControlType==DC_OnOffOnly)
		{
			if(MyConfig->ConnectionType==DC_NPN)
			{
				DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_High);
			}
			else if (MyConfig->ConnectionType==DC_PNP)
			{
				DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_Low);
			}
			else
			{
				Local_Error=E_WRONG_CONFIG;
			}
		}
	}
	return Local_Error;
}

void DC_OnCW(DC_config_t *MyConfig)
{
	if(MyConfig!=NULL)
	{
		if(MyConfig->ConnectionType==DC_NPN)
		{
			DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_High);
			DIO_WriteValueForPin(MyConfig->DC_M2Group,MyConfig->DC_M2Pin,DIO_Low);
		}
		else if(MyConfig->ConnectionType==DC_PNP
				||MyConfig->ConnectionType==DC_Hybrid )
		{
			DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_Low);
			DIO_WriteValueForPin(MyConfig->DC_M2Group,MyConfig->DC_M2Pin,DIO_High);
		}


	}
	else
	{

	}
}

void DC_OnCCW(DC_config_t *MyConfig)
{
	if (MyConfig!=NULL)
	{
		if(MyConfig->ConnectionType==DC_NPN)
		{
			DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_Low);
			DIO_WriteValueForPin(MyConfig->DC_M2Group,MyConfig->DC_M2Pin,DIO_High);
		}
		else if (MyConfig->ConnectionType==DC_PNP||MyConfig->ConnectionType==DC_Hybrid)
		{
			DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_High);
			DIO_WriteValueForPin(MyConfig->DC_M2Group,MyConfig->DC_M2Pin,DIO_Low);
		}
		else
		{

		}
	}
	else
	{

	}
}

void DC_Off(DC_config_t *MyConfig)
{
	if(MyConfig!=NULL)
	{
		if (MyConfig->ControlType==DC_OnOffOnly)
		{
			if(MyConfig->ConnectionType==DC_NPN)
			{
				DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_Low);
			}
			else if (MyConfig-> ConnectionType==DC_PNP)
			{
				DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_High);
			}
			else
			{

			}
		}
		else if (MyConfig-> ControlType== DC_directionControl)
		{
			if(MyConfig->ConnectionType==DC_NPN)
			{
				DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_Low);
				DIO_WriteValueForPin(MyConfig->DC_M2Group,MyConfig->DC_M2Pin,DIO_Low);

			}
			else if (MyConfig-> ConnectionType==DC_PNP)
			{
				DIO_WriteValueForPin(MyConfig->DC_M1Group,MyConfig->DC_M1Pin,DIO_High);
				DIO_WriteValueForPin(MyConfig->DC_M2Group,MyConfig->DC_M2Pin,DIO_High);
			}
			else if(MyConfig->ConnectionType==DC_Hybrid)
			{
				/**< @bug  the Hybrid Connection we have corner case  we can't Stop Motor*/
				/**< M1 -> Q1-> PNP    Q4 -> NPN*/
				/**< M2 -> Q2-> PNP    Q3 -> NPN*/
			}
		}
	}
	else
	{

	}
}
