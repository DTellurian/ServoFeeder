/* 
* RTCHelper.cpp
*
* Created: 01.11.2015 22:14:31
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include <stdio.h>
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

void RTCHelper::TimeWithSecondsToString(char* stringPtr, RTCDateTime dateTime)
{	
	sprintf(stringPtr, "%.2d:%.2d:%.2d", dateTime.hour, dateTime.minute, dateTime.second);
}
//---------------------------------------------------------------------------

void RTCHelper::DateToString(char* stringPtr, RTCDateTime dateTime)
{
	sprintf(stringPtr, "%.2d:%.2d:%.2d", dateTime.date, dateTime.month, dateTime.year);
}
//---------------------------------------------------------------------------