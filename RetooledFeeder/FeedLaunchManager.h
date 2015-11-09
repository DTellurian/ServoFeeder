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
	protected:
	private:		
		FeedLaunchManager( const FeedLaunchManager &c );
		FeedLaunchManager& operator=( const FeedLaunchManager &c );


		FeedLaunchSettings settings;
		static uint8_t wasLaunched;
		static uint64_t turnOffTime;
		
		static uint8_t vibrationLaunched;
		static uint64_t vibrationOffTime;
}; //FeedLaunchManager
//---------------------------------------------------------------------------
#endif //__FEEDLAUNCHMANAGER_H__
