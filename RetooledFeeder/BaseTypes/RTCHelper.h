/* 
* RTCHelper.h
*
* Created: 01.11.2015 22:14:31
* Author: Mihalych
*/


#ifndef __RTCHELPER_H__
#define __RTCHELPER_H__
//---------------------------------------------------------------------------

#include "RTC.h"
//---------------------------------------------------------------------------

#define DATETIME_UPDATE_PERIOD_MILLISECONDS 100
//---------------------------------------------------------------------------

class RTCHelper
{
	//variables
	public:
		static RTCDateTime LoadDateTime(void);
		static void TimeWithSecondsToString(char* stringPtr, RTCDateTime dateTime);		
		static void DateToString(char* stringPtr, RTCDateTime dateTime);
	
	protected:
	private:

	//functions
	public:
		
		~RTCHelper();
	protected:
	private:
		RTCHelper();
		RTCHelper( const RTCHelper &c );
		RTCHelper& operator=( const RTCHelper &c );
		
		static uint64_t nextTimeToLoadDateTime;
		static RTCDateTime lastLoadedDateTime;

}; //RTCHelper
//---------------------------------------------------------------------------
#endif //__RTCHELPER_H__
