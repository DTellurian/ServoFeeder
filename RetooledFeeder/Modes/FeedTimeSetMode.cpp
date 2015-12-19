/* 
* FeedTimeSetMode.cpp
*
* Created: 19.12.2015 16:43:16
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "FeedTimeSetMode.h"
#include "../Device.h"
#include "../Lcd/DateTimeEditHelper.h"
//---------------------------------------------------------------------------

// default constructor
FeedTimeSetMode::FeedTimeSetMode()
	:isDurationEdited(0), feedControlPtr(0), feedLaunchManagerPtr(0), feedSettingsIndex(0)
{
} //FeedTimeSetMode
//---------------------------------------------------------------------------

// default destructor
FeedTimeSetMode::~FeedTimeSetMode()
{
} //~FeedTimeSetMode
//---------------------------------------------------------------------------

void FeedTimeSetMode::EnterMode(FeedTimeControl* controlToEditPtr, FeedLaunchManager* feedLaunchManagerPtr, uint8_t settingsIndex)
{
	this->feedControlPtr = controlToEditPtr;
	this->feedLaunchManagerPtr = feedLaunchManagerPtr;
	this->feedSettingsIndex = settingsIndex;
	
	Device::modesController.SetCurrentMode(this);
}
//---------------------------------------------------------------------------

void FeedTimeSetMode::EnterMode(void)
{
	isDurationEdited = 0;
	
	Device::lcdController.Clear();
	
	feedControlPtr->SetXY(4, 0);
	feedControlPtr->SetCursorCoordinates(0, 0);	
	feedControlPtr->CopyToLcdController();
	
	feedControlPtr->EnterEditMode();
	Device::lcdController.Redraw(1);
	feedControlPtr->SetCursor();
}
//---------------------------------------------------------------------------

void FeedTimeSetMode::ExitMode(void)
{
	feedControlPtr->ExitEditMode();
}
//---------------------------------------------------------------------------

void FeedTimeSetMode::ProceedModeOnTick(void)
{
	Device::lcdController.Redraw(0);
	feedControlPtr->SetCursor();
}
//---------------------------------------------------------------------------

void FeedTimeSetMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	if(!isActive || handled)
		return;
	
	handled = 1;
	
	if(buttonPtr->IsIntValueButton())
	{
		RTCDateTime receivedDayTime = RTC::GetDateTime();
		
		if(!isDurationEdited)
			DateTimeEditHelper::ProceedTimeEditButtonPress(buttonPtr, handled, feedLaunchManagerPtr->settings.feedTime, feedControlPtr, 0);
		else
		{
			uint8_t buttonValue = buttonPtr->GetButtonIntValue();
			feedLaunchManagerPtr->settings.isEnabled = buttonValue != 0;			
			feedLaunchManagerPtr->settings.lengthInSeconds = buttonValue;
		}
		
		feedControlPtr->SetFeedTime(feedLaunchManagerPtr->settings);
		feedControlPtr->CopyToLcdController();
				
		//TODO: Save feed settings to EEPROM!
	}
	else if(buttonPtr == Device::ButtonPtrStar)
	{
		if(isDurationEdited)
		{
			isDurationEdited = 0;
			feedControlPtr->SetCursorCoordinates(0, 0);
		}
		else
		{
			isDurationEdited = 1;
			feedControlPtr->SetCursorCoordinates(6, 0);
		}
	}
	
	if(buttonPtr == Device::ButtonPtrSharp)
		Device::modesController.SetCurrentMode(&Device::mainMode);
}
//---------------------------------------------------------------------------