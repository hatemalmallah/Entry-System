/*
 * DIO_program.c
 *
 *  Created on: Aug 24, 2026
 *      Author: hatem
 */

#include "DIO_interface.h"



// DDR
// Direction -> Input  -> 0 -> ClearBit
// Direction -> Output -> 1 -> SetBit
void DIO_DirectionSetForPin(u8 GroupName,u8 PinNo,u8 DirectionState)
{
	if(PinNo<=DIO_Pin7)
	{
		if(DirectionState==DIO_Input)
		{
			switch(GroupName)
			{
			case DIO_GroupA: ClearBit(DDRA_Reg,PinNo);break;
			case DIO_GroupB: ClearBit(DDRB_Reg,PinNo);break;
			case DIO_GroupC: ClearBit(DDRC_Reg,PinNo);break;
			case DIO_GroupD: ClearBit(DDRD_Reg,PinNo);break;
			default : break;
			}
		}
		else if (DirectionState==DIO_Output)
		{
			switch(GroupName)
			{
			 case DIO_GroupA: SetBit(DDRA_Reg,PinNo);break;
			 case DIO_GroupB: SetBit(DDRB_Reg,PinNo);break;
			 case DIO_GroupC: SetBit(DDRC_Reg,PinNo);break;
			 case DIO_GroupD: SetBit(DDRD_Reg,PinNo);break;
			 default : break;
			}
		}
	}
}
void DIO_DirectionSetForGroup(u8 GroupName,u8 DirectionState)
{
	switch(GroupName)
	{
	case DIO_GroupA: DDRA_Reg=DirectionState; break;
	case DIO_GroupB: DDRB_Reg=DirectionState; break;
	case DIO_GroupC: DDRC_Reg=DirectionState; break;
	case DIO_GroupD: DDRD_Reg=DirectionState; break;
	default: break;
	}
}

// PORT
// OuputValue-> High -> 1 -> SetBit
// OuputValue-> Low  -> 0 -> ClearBit
void DIO_WriteValueForPin(u8 GroupName,u8 PinNo,u8 OutputState)
{
	if(PinNo<=DIO_Pin7)
	{
		if(OutputState==DIO_Low)
		{
			switch(GroupName)
			{
			   case DIO_GroupA: ClearBit(PORTA_Reg,PinNo);break;
			   case DIO_GroupB: ClearBit(PORTB_Reg,PinNo);break;
		       case DIO_GroupC: ClearBit(PORTC_Reg,PinNo);break;
			   case DIO_GroupD: ClearBit(PORTD_Reg,PinNo);break;
			   default : break;
			}
		}
		else if(OutputState==DIO_High)
		{
			switch(GroupName)
			{
			  case DIO_GroupA: SetBit(PORTA_Reg,PinNo);break;
			  case DIO_GroupB: SetBit(PORTB_Reg,PinNo);break;
			  case DIO_GroupC: SetBit(PORTC_Reg,PinNo);break;
		      case DIO_GroupD: SetBit(PORTD_Reg,PinNo);break;
			  default : break;
			}
		}
	}
}
void DIO_WriteValueForGroup(u8 GroupName,u8 OutputState)
{
	switch(GroupName)
		{
		case DIO_GroupA: PORTA_Reg=OutputState; break;
		case DIO_GroupB: PORTB_Reg=OutputState; break;
		case DIO_GroupC: PORTC_Reg=OutputState; break;
		case DIO_GroupD: PORTD_Reg=OutputState; break;
		default: break;
		}
}u8 DIO_ReadStateInputForPin(u8 GroupName,u8 PinNo);

//Read input state
u8 DIO_ReadStateInputForPin(u8 GroupName,u8 PinNo)
{
	u8 InputState = 0xFF;
	if(PinNo<=DIO_Pin7)
	{
		switch(GroupName)
		{
		   case DIO_GroupA: InputState=ReadBit(PINA_Reg,PinNo);break;
		   case DIO_GroupB: InputState=ReadBit(PINB_Reg,PinNo);break;
		   case DIO_GroupC: InputState=ReadBit(PINC_Reg,PinNo);break;
		   case DIO_GroupD: InputState=ReadBit(PIND_Reg,PinNo);break;
		   default : break;
		}
	}
	return InputState;
}
u8 DIO_ReadStateInputForGroup(u8 GroupName)
{
	u8 InputState = 0xFF;
	    switch(GroupName)
	    {
	        case DIO_GroupA: InputState = PINA_Reg; break;
	        case DIO_GroupB: InputState = PINB_Reg; break;
	        case DIO_GroupC: InputState = PINC_Reg; break;
	        case DIO_GroupD: InputState = PIND_Reg; break;
	        default: break;
	    }

	    return InputState;
}

//internal pull up
void DIO_InternalPullUpControlForPin(u8 GroupName,u8 PinNo,u8 PullUpState)
{
	if(PinNo<=DIO_Pin7)
	{
		if(PullUpState==DIO_Enable)
		{
			switch(GroupName)
	 	{
  	    	case DIO_GroupA: SetBit(PORTA_Reg,PinNo);break;
			case DIO_GroupB: SetBit(PORTB_Reg,PinNo);break;
			case DIO_GroupC: SetBit(PORTC_Reg,PinNo);break;
			case DIO_GroupD: SetBit(PORTD_Reg,PinNo);break;
			default : break;
		}
		}
		else if(PullUpState==DIO_Disable)
		{
			switch(GroupName)
			{
	        case DIO_GroupA: ClearBit(PORTA_Reg, PinNo); break;
	        case DIO_GroupB: ClearBit(PORTB_Reg, PinNo); break;
	        case DIO_GroupC: ClearBit(PORTC_Reg, PinNo); break;
	        case DIO_GroupD: ClearBit(PORTD_Reg, PinNo); break;
	        default : break;
			}
		}
	}
}
void DIO_InternalPullUpControlForGroup(u8 GroupName,u8 PullUpState)
{
	switch(GroupName)
	{
	       case DIO_GroupA: PORTA_Reg=PullUpState;break;
		   case DIO_GroupB: PORTB_Reg=PullUpState;break;
		   case DIO_GroupC: PORTC_Reg=PullUpState;break;
		   case DIO_GroupD: PORTD_Reg=PullUpState;break;
		   default : break;
	}
}

//toggle
void DIO_ToggleControlForPin(u8 GroupName, u8 PinNo)
{
	if(PinNo <= DIO_Pin7)
	    {
	        switch(GroupName)
	        {
	            case DIO_GroupA: ToggleBit(PORTA_Reg, PinNo); break;
	            case DIO_GroupB: ToggleBit(PORTB_Reg, PinNo); break;
	            case DIO_GroupC: ToggleBit(PORTC_Reg, PinNo); break;
	            case DIO_GroupD: ToggleBit(PORTD_Reg, PinNo); break;
	            default: break;
	        }
	    }
}
void DIO_ToggleControlForGroup(u8 GroupName)
{
	switch(GroupName)
	    {
	        case DIO_GroupA: PORTA_Reg ^= 0xFF; break;
	        case DIO_GroupB: PORTB_Reg ^= 0xFF; break;
	        case DIO_GroupC: PORTC_Reg ^= 0xFF; break;
	        case DIO_GroupD: PORTD_Reg ^= 0xFF; break;
	        default: break;
	    }
}
