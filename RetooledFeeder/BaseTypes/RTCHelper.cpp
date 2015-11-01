/* 
* RTCHelper.cpp
*
* Created: 01.11.2015 22:14:31
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "RTCHelper.h"
#include "DateTime.h"
//---------------------------------------------------------------------------

uint64_t RTCHelper::nextTimeToLoadDateTime = 0;
RTCDateTime RTCHelper::lastLoadedDateTime = RTCDateTime();
//---------------------------------------------------------------------------

RTCDateTime RTCHelper::LoadDateTime(void)
{
	uint64_t currentMilliseconds = DateTime::milliseconds;
	if(currentMilliseconds > nextTimeToLoadDateTime)
	{
		lastLoadedDateTime = RTC::GetDateTime();
		nextTimeToLoadDateTime = currentMilliseconds + DATETIME_UPDATE_PERIOD_MILLISECONDS;
	}
	
	return lastLoadedDateTime;
}
//---------------------------------------------------------------------------