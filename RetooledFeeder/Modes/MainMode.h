/* 
* MainMode.h
*
* Created: 31.10.2015 15:39:40
* Author: Mihalych
*/


#ifndef __MAINMODE_H__
#define __MAINMODE_H__
//---------------------------------------------------------------------------

#include "../Buttons/ButtonsControllerConsumer.h"
#include "../Buttons/Button.h"
#include "../BaseTypes/rtc.h"
#include "../Lcd/DateTimeControl.h"
#include "../FeedLaunchSettings.h"
#include "../FeedLaunchManager.h"
#include "../ModesSupport/Mode.h"
//---------------------------------------------------------------------------

class MainMode : public ButtonsControllerConsumer, public Mode
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		//MainMode(void);
		MainMode(void);
		~MainMode();
										
		virtual void ProceedModeOnTick(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		
		virtual void EnterMode(void);
		void Initialize(FeedLaunchSettings& feed1, FeedLaunchSettings& feed2, FeedLaunchSettings& feed3, FeedLaunchSettings& feed4);
	protected:
	private:		
		MainMode( const MainMode &c );
		MainMode& operator=( const MainMode &c );
		
		RTCDateTime lastDateTime;				
		
		
		//void DrawDate(void);
		void DrawFeedInfo(FeedLaunchSettings& feed);
		
		FeedLaunchManager feedLaunchManager1;
		FeedLaunchManager feedLaunchManager2;
		FeedLaunchManager feedLaunchManager3;
		FeedLaunchManager feedLaunchManager4;
}; //MainMode
//---------------------------------------------------------------------------
#endif //__MAINMODE_H__
