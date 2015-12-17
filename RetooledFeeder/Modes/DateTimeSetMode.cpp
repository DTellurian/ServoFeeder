/* 
* DateTimeSetMode.cpp
*
* Created: 15.12.2015 17:43:12
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "DateTimeSetMode.h"
#include "../Device.h"
#include "../BaseTypes/RTCHelper.h"
#include "../Lcd/DateTimeEditHelper.h"
//---------------------------------------------------------------------------

// default constructor
DateTimeSetMode::DateTimeSetMode()
	:isDateEdited(0)
{
} //DateTimeSetMode
//---------------------------------------------------------------------------

// default destructor
DateTimeSetMode::~DateTimeSetMode()
{
} //~DateTimeSetMode
//---------------------------------------------------------------------------

void DateTimeSetMode::EnterMode(void)
{
	isDateEdited = 0;
	
	Device::lcdController.Clear();
	
	Device::dateTimeControl.SetXY(4, 0);
	Device::dateTimeControl.SetCursorCoordinates(0, 0);
	Device::dateTimeControl.CopyToLcdController();
	
	Device::dateTimeControl.EnterEditMode();
	Device::lcdController.Redraw(1);
}
//---------------------------------------------------------------------------

void DateTimeSetMode::ExitMode(void)
{
	Device::dateTimeControl.ExitEditMode();
}
//---------------------------------------------------------------------------

void DateTimeSetMode::ProceedModeOnTick(void)
{
	RTCDateTime receivedDayTime = RTCHelper::LoadDateTime(0);
	
	Device::dateTimeControl.SetTime(receivedDayTime);
	Device::dateTimeControl.CopyToLcdController();
	Device::lcdController.Redraw(0);
	Device::dateTimeControl.SetCursor();
}
//---------------------------------------------------------------------------

void DateTimeSetMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	if(!isActive || handled)
		return;
			
	handled = 1;
	
	if(buttonPtr->IsIntValueButton())
	{
		RTCDateTime receivedDayTime = RTC::GetDateTime();
	
		if(!isDateEdited)
			DateTimeEditHelper::ProceedTimeEditButtonPress(buttonPtr, handled, receivedDayTime, &Device::dateTimeControl, 1);
		else		
			DateTimeEditHelper::ProceedDateEditButtonPress(buttonPtr, handled, receivedDayTime, &Device::dateTimeControl, 1);
		
		RTC::SetDateTime(receivedDayTime);
	}
	else if(buttonPtr == Device::ButtonPtrStar)
	{
		if(isDateEdited)
		{
			isDateEdited = 0;
			Device::dateTimeControl.SetCursorCoordinates(0, 0);
		}
		else
		{
			isDateEdited = 1;
			Device::dateTimeControl.SetCursorCoordinates(0, 1);
		}
	}
	
	if(buttonPtr == Device::ButtonPtrSharp)
		Device::modesController.SetCurrentMode(&Device::mainMode);
		
	
	_delay_ms(100);
}
//---------------------------------------------------------------------------