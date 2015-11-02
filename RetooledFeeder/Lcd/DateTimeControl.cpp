/* 
* DateTimeControl.cpp
*
* Created: 01.11.2015 23:10:57
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "DateTimeControl.h"
#include "../BaseTypes/RTCHelper.h"
//---------------------------------------------------------------------------

// default constructor
DateTimeControl::DateTimeControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y)
	:BaseLcdControl(lcdControllerPtr, x, y, 8, 2)
{
} //DateTimeControl
//---------------------------------------------------------------------------

// default destructor
DateTimeControl::~DateTimeControl()
{
} //~DateTimeControl
//---------------------------------------------------------------------------

#include <stdio.h>
//---------------------------------------------------------------------------

void DateTimeControl::SetTime(RTCDateTime time)
{
	char* buffer = GetBufferPointerToWrite();
	//sprintf(buffer, "Hello!");
	//sprintf(buffer, "%.2d:%.2d:%.2d", time.hour, time.minute, time.second);
	RTCHelper::TimeWithSecondsToString(buffer, time);
	
	buffer = GetBufferPointerToWrite(1);
	RTCHelper::DateToString(buffer, time);
}
//---------------------------------------------------------------------------