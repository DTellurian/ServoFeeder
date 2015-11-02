/* 
* FeedLaunchManager.cpp
*
* Created: 02.11.2015 13:20:55
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "FeedLaunchManager.h"
#include "BaseTypes/RTCHelper.h"
#include "Device.h"
#include "BaseTypes/DateTime.h"
//---------------------------------------------------------------------------

// default constructor
FeedLaunchManager::FeedLaunchManager(void)
	:settings(), wasLaunched(0), turnOffTime(0)
{
	
} //FeedLaunchManager
//---------------------------------------------------------------------------
// default destructor
FeedLaunchManager::~FeedLaunchManager()
{
} //~FeedLaunchManager
//---------------------------------------------------------------------------

void FeedLaunchManager::SetSettings(FeedLaunchSettings settings)
{
	this->settings = settings;
}
//---------------------------------------------------------------------------

void FeedLaunchManager::ProceedTick(void)
{
	RTCDateTime receivedDayTime = RTCHelper::LoadDateTime(0);
	
	if(settings.isEnabled && RTCHelper::TimeEquals(receivedDayTime, settings.feedTime) && wasLaunched == 0)
	{
		Device::outputPin3Ptr->SetHightLevel();
		wasLaunched = 1;
		turnOffTime = DateTime::milliseconds + settings.lengthInSeconds * 1000;
	}
	
	if(wasLaunched && DateTime::milliseconds > turnOffTime)
	{
		Device::outputPin3Ptr->SetLowLevel();
		wasLaunched = 0;
	}
}
//---------------------------------------------------------------------------