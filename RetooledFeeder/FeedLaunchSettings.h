/* 
* FeedLaunchSettings.h
*
* Created: 02.11.2015 12:40:32
* Author: Mihalych
*/


#ifndef __FEEDLAUNCHSETTINGS_H__
#define __FEEDLAUNCHSETTINGS_H__
//---------------------------------------------------------------------------

#include "BaseTypes/rtc.h"
//---------------------------------------------------------------------------

class FeedLaunchSettings
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		FeedLaunchSettings();
		~FeedLaunchSettings();
		
		RTCDateTime feedTime;
		uint8_t isEnabled;
		uint8_t outputPortIndex;
		uint8_t lengthInSeconds;
	protected:
	private:
		//FeedLaunchSettings( const FeedLaunchSettings &c );
		//FeedLaunchSettings& operator=( const FeedLaunchSettings &c );

}; //FeedLaunchSettings
//---------------------------------------------------------------------------
#endif //__FEEDLAUNCHSETTINGS_H__
