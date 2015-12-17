/* 
* DateTimeEditHelper.cpp
*
* Created: 17.12.2015 10:57:48
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "DateTimeEditHelper.h"
//---------------------------------------------------------------------------

// default constructor
DateTimeEditHelper::DateTimeEditHelper()
{
} //DateTimeEditHelper
//---------------------------------------------------------------------------

// default destructor
DateTimeEditHelper::~DateTimeEditHelper()
{
} //~DateTimeEditHelper
//---------------------------------------------------------------------------

void DateTimeEditHelper::ProceedTimeEditButtonPress(Button* buttonPtr, uint8_t& handled, RTCDateTime& timeToEdit, EditableLcdControl* controlPtr, uint8_t editSeconds)
{
	if(!buttonPtr->IsIntValueButton())
		return;
		
	handled = 1;
	uint8_t buttonIntValue = buttonPtr->GetButtonIntValue();
	
	if(controlPtr->cursorXPosition == 0)
	{
		if(buttonIntValue > 2)
			return;
		
		timeToEdit.hour = buttonIntValue * 10 + timeToEdit.hour % 10;
		controlPtr->SetCursorCoordinates(1, controlPtr->cursorYPosition);
	}else if(controlPtr->cursorXPosition == 1)
	{
		if(timeToEdit.hour % 10 == 2 && buttonIntValue > 3)
			return;
		
		timeToEdit.hour = buttonIntValue + (timeToEdit.hour / 10) * 10;
		controlPtr->SetCursorCoordinates(3, controlPtr->cursorYPosition);
	}
	else if(controlPtr->cursorXPosition == 3)
	{
		if(buttonIntValue > 5)
			return;
		
		timeToEdit.minute = buttonIntValue * 10 + timeToEdit.minute % 10;
		controlPtr->SetCursorCoordinates(4, controlPtr->cursorYPosition);
	}
	else if(controlPtr->cursorXPosition == 4)
	{
		timeToEdit.minute = buttonIntValue + (timeToEdit.minute / 10) * 10;
		
		uint8_t nextCursorPosition = editSeconds == 1 ? 6 : 0;
		controlPtr->SetCursorCoordinates(nextCursorPosition, controlPtr->cursorYPosition);
	}
	else if(controlPtr->cursorXPosition == 6)
	{
		if(buttonIntValue > 5)
			return;
		
		timeToEdit.second = buttonIntValue * 10 + timeToEdit.second % 10;
		controlPtr->SetCursorCoordinates(7, controlPtr->cursorYPosition);
	}else if(controlPtr->cursorXPosition == 7)
	{
		timeToEdit.second = buttonIntValue + (timeToEdit.second / 10) * 10;
		controlPtr->SetCursorCoordinates(0, controlPtr->cursorYPosition);
	}
}
//---------------------------------------------------------------------------