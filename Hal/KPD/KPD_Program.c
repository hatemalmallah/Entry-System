/*
 * KPD_Program.c
 *
 *  Created on: Sep 10, 2026
 *      Author: hatem
 */

#include "KPD_Interface.h"
#include <util/delay.h>


static u8 KPDValues[KPD_RowNo][KPD_ColNo]= KPD_ValuesConfigured;
static u8 KPD_RGroups[KPD_RowNo]= KPD_RGroupConfigured;
static u8 KPD_RPins[KPD_RowNo]= KPD_RPinConfigured;
static u8 KPD_CGroups[KPD_ColNo]= KPD_CGroupConfigured;
static u8 KPD_CPins[KPD_ColNo]= KPD_CPinConfigured;


void KPD_Init()
{
for(u8 RowIndex=0;RowIndex<KPD_RowNo;RowIndex++)
{
	DIO_DirectionSetForPin(KPD_RGroups[RowIndex],KPD_RPins[RowIndex],DIO_Input);
    DIO_InternalPullUpControlForPin(KPD_RGroups[RowIndex],KPD_RPins[RowIndex],DIO_Enable);
}
for(u8 ColIndex=0;ColIndex<KPD_ColNo;ColIndex++)
{
	DIO_DirectionSetForPin(KPD_CGroups[ColIndex],KPD_CPins[ColIndex],DIO_Output);
	DIO_WriteValueForPin(KPD_CGroups[ColIndex],KPD_CPins[ColIndex],DIO_High);
}

}

void KPD_GetValue(u8 *KPD_Value)
{
  *KPD_Value=KPD_BtnValueNotPressed;
  u8 IsBtnPressed=KPD_BtnStateNotPressed;

  for(u8 Col=0;Col<KPD_ColNo;Col++)
  {
	  DIO_WriteValueForPin(KPD_CGroups[Col],KPD_CPins[Col],DIO_Low);

	  for(u8 Row=0;Row<KPD_RowNo;Row++)
	  {
		  IsBtnPressed= DIO_ReadStateInputForPin(KPD_RGroups[Row],KPD_RPins[Row]);

		  if(IsBtnPressed==KPD_BtnStatePressed)
		  {
			  _delay_ms(35);
			  IsBtnPressed= DIO_ReadStateInputForPin(KPD_RGroups[Row],KPD_RPins[Row]);
			  if(IsBtnPressed==KPD_BtnStatePressed)
			  {
				  *KPD_Value=KPDValues[Row][Col];
				  while(DIO_ReadStateInputForPin(KPD_RGroups[Row], KPD_RPins[Row]) == KPD_BtnStatePressed);
				  DIO_WriteValueForPin(KPD_CGroups[Col],KPD_CPins[Col],DIO_High);
				  return;

			  }

		  }
	  }

	  DIO_WriteValueForPin(KPD_CGroups[Col],KPD_CPins[Col],DIO_High);
  }
}

