/* 
* FeedSettingsLoader.h
*
* Created: 28.12.2015 22:50:17
* Author: Mihalych
*/


#ifndef __FEEDSETTINGSLOADER_H__
#define __FEEDSETTINGSLOADER_H__
//---------------------------------------------------------------------------

#include "FeedLaunchSettings.h"
//---------------------------------------------------------------------------
class FeedSettingsLoader
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		static void SaveSettings(FeedLaunchSettings settings, int index);
		static void LoadSettings(FeedLaunchSettings& settings, int index);
		
		~FeedSettingsLoader();
	protected:
	private:
		FeedSettingsLoader();
		FeedSettingsLoader( const FeedSettingsLoader &c );
		FeedSettingsLoader& operator=( const FeedSettingsLoader &c );

}; //FeedSettingsLoader
//---------------------------------------------------------------------------
#endif //__FEEDSETTINGSLOADER_H__
