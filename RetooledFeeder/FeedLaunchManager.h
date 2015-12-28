/* 
* FeedLaunchManager.h
*
* Created: 02.11.2015 13:20:55
* Author: Mihalych
*/


#ifndef __FEEDLAUNCHMANAGER_H__
#define __FEEDLAUNCHMANAGER_H__
//---------------------------------------------------------------------------

#include "FeedLaunchSettings.h"
//---------------------------------------------------------------------------

class FeedLaunchManager
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		FeedLaunchManager(void);
		~FeedLaunchManager();
		
		void SetSettings(FeedLaunchSettings settings);
		void ProceedTick(void);
		
		FeedLaunchSettings settings;
	protected:
	private:		
		FeedLaunchManager( const FeedLaunchManager &c );
		FeedLaunchManager& operator=( const FeedLaunchManager &c );
		
		uint8_t wasLaunched;
		uint64_t turnOffTime;
}; //FeedLaunchManager
//---------------------------------------------------------------------------
#endif //__FEEDLAUNCHMANAGER_H__
