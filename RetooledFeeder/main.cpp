/*
 * RetooledFeeder.cpp
 *
 * Created: 28.10.2015 23:18:09
 * Author : Mihalych
 */ 
//---------------------------------------------------------------------------

#define F_CPU 1000000UL  // 1 MHz
//---------------------------------------------------------------------------

#include <avr/io.h>

#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
//---------------------------------------------------------------------------

#include "Device.h"
#include "BaseTypes/DateTime.h"
#include "BaseTypes/rtc.h"

#include "Buttons/KeyMatrixController.h"
#include "Modes/MainMode.h"
#include "BaseTypes/DateTimeTimerInit.h"
#include "BaseTypes/RTCHelper.h"
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
int main(void)
{
    /* Replace with your application code */		
		
	Device::Initialize();
			
	RTCDateTime receivedDayTime = RTCHelper::LoadDateTime(1);
	
	FeedLaunchSettings feed1;
	//feed1.feedTime.hour = receivedDayTime.hour;
	//feed1.feedTime.minute = receivedDayTime.minute + 1;
	feed1.feedTime.hour = 4;	
		
	FeedLaunchSettings feed2;
	//feed2.feedTime.hour = receivedDayTime.hour;
	//feed2.feedTime.minute = receivedDayTime.minute + 2;
	feed2.feedTime.hour = 8;
		
	FeedLaunchSettings feed3;
	//feed3.feedTime.hour = receivedDayTime.hour;
	//feed3.feedTime.minute = receivedDayTime.minute + 3;
	//feed3.isEnabled = 0;
	feed3.feedTime.hour = 14;
		
	FeedLaunchSettings feed4;
	//feed4.feedTime.hour = receivedDayTime.hour;
	//feed4.feedTime.minute = receivedDayTime.minute + 4;
	//feed4.lengthInSeconds = 3;
	feed4.feedTime.hour = 18;
	
	FeedLaunchSettings feed5;
	feed5.feedTime.hour = 22;
	
	Device::mainMode.EnterMode(feed1, feed2, feed3, feed4, feed5);
				
	uint8_t wasOut3LaunchedByButton = 0;
	
	uint8_t wasOut3LaunchedByRadio = 0;
	uint64_t radioTurnOffTime = 0;
	
	uint8_t wasOut1LaunchedByRadio = 0;
	
	uint8_t isRadioEnabled = 0;
								
	while(1)
	{
		Device::mainMode.OnTick();
		Device::keyMatrixController.ButtonsControllerOnTick();
		//Device::lcdControllerPtr->Redraw(0);
		
		if(Device::ButtonPtr0->IsPressed())
		{
			Device::outputPin3Ptr->SetHightLevel();
			wasOut3LaunchedByButton = 1;
		}
		else if(wasOut3LaunchedByButton)
		{
			wasOut3LaunchedByButton = 0;
			Device::outputPin3Ptr->SetLowLevel();
		}
		
		if(Device::ButtonPtrStar->IsPressed())
		{
			Device::lcd.LCD_Goto(16, 0);
			
			if(isRadioEnabled == 0)
			{
				isRadioEnabled  = 1;
				Device::lcd.LCD_SendString("*");
			}
			else
			{
				isRadioEnabled = 0;
				Device::lcd.LCD_SendString(" ");
			}
			
			_delay_ms(100);
		}
		
		if(Device::radionCPinPtr->IsPinSet() && isRadioEnabled)
		{
			Device::outputPin3Ptr->SetHightLevel();
			wasOut3LaunchedByRadio = 1;
			radioTurnOffTime = DateTime::milliseconds + 2000;
		}
		else if(wasOut3LaunchedByRadio && DateTime::milliseconds > radioTurnOffTime)
		{
			Device::outputPin3Ptr->SetLowLevel();
			wasOut3LaunchedByRadio = 0;
		}
		
		if(Device::radionAPinPtr->IsPinSet())
		{
			Device::outputPin1Ptr->SetHightLevel();
			wasOut1LaunchedByRadio = 1;
			radioTurnOffTime = DateTime::milliseconds + 2000;
		}
		else if(wasOut1LaunchedByRadio && DateTime::milliseconds > radioTurnOffTime)
		{
			wasOut1LaunchedByRadio = 0;
			Device::outputPin1Ptr->SetLowLevel();
		}
	}
}
//---------------------------------------------------------------------------
