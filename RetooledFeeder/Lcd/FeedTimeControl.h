/* 
* FeedTimeControl.h
*
* Created: 19.12.2015 15:39:52
* Author: Mihalych
*/


#ifndef __FEEDTIMECONTROL_H__
#define __FEEDTIMECONTROL_H__
//---------------------------------------------------------------------------

#include "BaseLcdControl.h"
#include "../BaseTypes/RTC.h"
#include "EditableLcdControl.h"
#include "../FeedLaunchSettings.h"
//---------------------------------------------------------------------------

class FeedTimeControl : public EditableLcdControl
{
	//variables
	public:
		FeedTimeControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y);
		
		void SetFeedTime(FeedLaunchSettings& feedTime);
	protected:
	private:

	//functions
	public:
		
		~FeedTimeControl();
	protected:
	private:
		FeedTimeControl();
		FeedTimeControl( const FeedTimeControl &c );
		FeedTimeControl& operator=( const FeedTimeControl &c );

}; //FeedTimeControl
//---------------------------------------------------------------------------
#endif //__FEEDTIMECONTROL_H__
