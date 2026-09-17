/*
 * SevSeg_program.c


 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#include "../../Mcal/DIO/DIO_interface.h"
#include "SevSeg_interface.h"


  static u8 SevSeg_Num[10] =
{
    0xC0, //->0
    0xF9, //->1
    0xA4, //->2
    0xB0, //->3
    0x99, //->4
    0x92, //->5
    0x82, //->6
    0xF8, //->7
    0x80, //->8
    0x90  //->9
};

//SevSeg_Init
void SevSeg_Init(u8 GroupName)
{
	DIO_DirectionSetForGroup(GroupName,0xFF);
}

//SevSeg_DisplayNum
void SevSeg_DisplayNum(u8 GroupName, u8 Number)
{
	if(Number<=9)
	    {
	         DIO_WriteValueForGroup(GroupName, SevSeg_Num[Number]);
	    }
	    else
	    {

	        DIO_WriteValueForGroup(GroupName, 0xBF);
	    }
}


