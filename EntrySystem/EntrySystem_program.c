/*
 * EntrySystem_program.c
 *
 *  Created on: Sep 17, 2026
 *      Author: hatem
 */
#include "EntrySystem_interface.h"
#include "../../Hal/Led/Led_interface.h"
#include "../../Hal/LCD/LCD_interface.h"
#include "../../Hal/KPD/KPD_Interface.h"
#include "../../Hal/Buzzer/Buzzer_interface.h"
#include "../../Hal/SevSeg/SevSeg_interface.h"
#include <util/delay.h>
#include <String.h>

static SystemState_t CurrentState= State_Init;
static char InputPass[7]={0};
static u8 PassIndex=0;;
static u8 TriesLeft=Max_Tries;
static u8 ShowFlag=0;



void Dashboard_Init(void)
{
	LCD_Init();
	KPD_Init();
	Buzzer_Init();
    Led_InitFor2Pin();

}

void Dashboard_Run(void)
{
	u8 PressedBtn=KPD_BtnValueNotPressed;
	KPD_GetValue(&PressedBtn);
//***********************************************//
	switch (CurrentState)
	{
	case State_Init:
	LCD_SendCommand(LCD_ClearDisplay);
	_delay_ms(5);
	LCD_WriteMessage("System Ready");
	_delay_ms(1500);



	CurrentState=State_ResetInput;
	break;
	//****************************************//

	case State_ResetInput:

    LCD_SendCommand(LCD_ClearDisplay);
	_delay_ms(5);
	LCD_WriteMessage("Enter Password");

	LCD_MoveTo(Lcd_Line2,0);

	PassIndex= 0;
	ShowFlag = 0;

	for(u8 i=0;i<7;i++)
	{
		InputPass[i] = '\0';
	}

	CurrentState=State_EnterPass;

	break;



	//*************************************************//
	case State_EnterPass:

		if(PressedBtn !=KPD_BtnValueNotPressed)
		{
			if(PressedBtn>='0'&& PressedBtn<='9'&& PassIndex<6)
			{
				InputPass[PassIndex]=PressedBtn;
				PassIndex++;

				if(ShowFlag==1)
				{
					LCD_WriteCharacter(PressedBtn);
				}
				else
				{
					LCD_WriteCharacter('*');
				}

			}

		else if (PressedBtn=='A')
		{
			ShowFlag=!ShowFlag;
			LCD_MoveTo(Lcd_Line2,0);
			for(u8 i=0;i<PassIndex;i++)
			{
				if(ShowFlag==1)
				{
					LCD_WriteCharacter(InputPass[i]);
				}
				else
				{
					LCD_WriteCharacter('*');
				}
			}
		}
		else if(PressedBtn=='E')
		{
			InputPass[PassIndex]='\0';
			CurrentState=State_Checkpass;
		}

		}
		break;
		//*******************************************************//

	case State_Checkpass:
		if(strcmp(InputPass, Correct_Pass)==0)
		{
			LCD_SendCommand(LCD_ClearDisplay);
			_delay_ms(5);
			LCD_WriteMessage("System Unlocked");
			Led_OnForPin(LedGreen_Group,LedGreen_Pin);
			Led_OffPin(LedRed_Group,LedRed_Pin);
			_delay_ms(1500);
			TriesLeft=Max_Tries;
			CurrentState=State_DrawMainMenu;
		}
		else
		{
			TriesLeft--;
			LCD_SendCommand(LCD_ClearDisplay);
			_delay_ms(5);
			LCD_WriteMessage("Wrong Password");

			CurrentState=State_WrongPass;

		}
		break;

		//**********************************************************//

	case State_WrongPass:

		if(TriesLeft>0)
		{
		  LCD_MoveTo(Lcd_Line2,0);
		  LCD_WriteMessage("Tries Left:");
		  LCD_WriteCharacter(TriesLeft+'0');
		  _delay_ms(2000);
		  CurrentState=State_ResetInput;

		}
		else
		{
			LCD_SendCommand(LCD_ClearDisplay);
			_delay_ms(5);
		    LCD_WriteMessage("System Locked!");

			CurrentState=State_Locked;
		}

		break;
		//*******************************************************//

	case State_Locked:

		Led_OnForPin(LedRed_Group,LedRed_Pin);
		Led_OffPin(LedGreen_Group,LedGreen_Pin);
		Buzzer_On(Buzzer_Group,Buzzer_Pin);
		_delay_ms(50);
		Buzzer_Off(Buzzer_Group,Buzzer_Pin);
		_delay_ms(50);

		if (PressedBtn != KPD_BtnValueNotPressed)
		    {
		        if (PressedBtn == 'C')
		        {
					Led_OffPin(LedRed_Group,LedRed_Pin);
		            Buzzer_Off(Buzzer_Group,Buzzer_Pin);
		            TriesLeft = Max_Tries;
		            CurrentState = State_Init;
		        }
		    }
		    break;

		    //*****************************************************//

	case State_DrawMainMenu:
		LCD_SendCommand(LCD_ClearDisplay);
		_delay_ms(5);
		LCD_WriteMessage("1:Motor 2:7Seg");
        LCD_MoveTo(Lcd_Line2,0);
		LCD_WriteMessage("B:Log Out");

		CurrentState = State_MainMenu;
		break;












		    //**************************************************//

	case State_MainMenu:

		if (PressedBtn != KPD_BtnValueNotPressed)
		{
			if (PressedBtn == '1')
			{

			}
			else if (PressedBtn == '2')
			{

			}
			else if (PressedBtn == 'B')
			{
				Led_OffPin(LedGreen_Group, LedGreen_Pin);
				CurrentState = State_ResetInput;
			}


		}
		break;





















	}

}






















