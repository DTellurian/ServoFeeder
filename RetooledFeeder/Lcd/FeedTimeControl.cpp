/* 
* FeedTimeControl.cpp
*
* Created: 19.12.2015 15:39:51
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include <stdio.h>
//---------------------------------------------------------------------------

#include "FeedTimeControl.h"
#include "../BaseTypes/RTCHelper.h"
#include "../Device.h"
//---------------------------------------------------------------------------

// default destructor
FeedTimeControl::~FeedTimeControl()
{
} //~FeedTimeControl
//---------------------------------------------------------------------------

FeedTimeControl::FeedTimeControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y)
	:EditableLcdControl(lcdControllerPtr, x, y, 7, 1)
{
	
}
//---------------------------------------------------------------------------

void FeedTimeControl::SetFeedTime(FeedLaunchSettings& feedTime)
{
	char* buffer = GetBufferPointerToWrite();
	
	RTCHelper::TimeWithoutSecondsToString(buffer, feedTime.feedTime);
	
	if(feedTime.isEnabled)
		sprintf(buffer + 5, "T%.i", feedTime.lengthInSeconds);		
	else
		sprintf(buffer + 5, "--");
}
//---------------------------------------------------------------------------