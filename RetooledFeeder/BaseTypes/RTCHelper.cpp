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

RTCDateTime RTCHelper::LoadDateTime(uint8_t forceLoad)
{
	uint64_t currentMilliseconds = DateTime::milliseconds;
	
	if(currentMilliseconds > nextTimeToLoadDateTime || forceLoad)
	{
		lastLoadedDateTime = RTC::GetDateTime();
		nextTimeToLoadDateTime = currentMilliseconds + DATETIME_UPDATE_PERIOD_MILLISECONDS;
	}
	
	return lastLoadedDateTime;
}
//---------------------------------------------------------------------------

uint8_t RTCHelper::DateTimeEquals(RTCDateTime &left, RTCDateTime &right)
{
	if(left.year == right.year && left.month == right.month && left.date == right.date && left.hour == right.hour && left.minute == right.minute && left.second == right.second )
		return 1;
	else
		return 0;
}
//---------------------------------------------------------------------------

uint8_t RTCHelper::TimeEquals(RTCDateTime &left, RTCDateTime &right)
{
	if(left.hour == right.hour && left.minute == right.minute && left.second == right.second )
		return 1;
	else
		return 0;
}
//---------------------------------------------------------------------------

void RTCHelper::TimeWithSecondsToString(char* stringPtr, RTCDateTime dateTime)
{	
	sprintf(stringPtr, "%.2d:%.2d:%.2d", dateTime.hour, dateTime.minute, dateTime.second);
}
//---------------------------------------------------------------------------

void RTCHelper::TimeWithoutSecondsToString(char* stringPtr, RTCDateTime dateTime)
{
	sprintf(stringPtr, "%.2d:%.2d", dateTime.hour, dateTime.minute);
}
//---------------------------------------------------------------------------

void RTCHelper::DateToString(char* stringPtr, RTCDateTime dateTime)
{
	sprintf(stringPtr, "%.2d:%.2d:%.2d", dateTime.date, dateTime.month, dateTime.year);
}
//---------------------------------------------------------------------------