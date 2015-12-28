/* 
* FeedTimeSetMode.h
*
* Created: 19.12.2015 16:43:16
* Author: Mihalych
*/


#ifndef __FEEDTIMESETMODE_H__
#define __FEEDTIMESETMODE_H__

//---------------------------------------------------------------------------

#include "../Buttons/ButtonsControllerConsumer.h"
#include "../ModesSupport/Mode.h"
#include "../Lcd/FeedTimeControl.h"
#include "../FeedLaunchManager.h"
//---------------------------------------------------------------------------

class FeedTimeSetMode : public ButtonsControllerConsumer, public Mode
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		FeedTimeSetMode();
		~FeedTimeSetMode();
		
		void EnterMode(FeedTimeControl* controlToEditPtr, FeedLaunchManager* feedLaunchManagerPtr, uint8_t settingsIndex);
		
		virtual void EnterMode(void);
		virtual void ExitMode(void);
				
		virtual void ProceedModeOnTick(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);		
	protected:
	private:
		FeedTimeSetMode( const FeedTimeSetMode &c );
		FeedTimeSetMode& operator=( const FeedTimeSetMode &c );
		
		uint8_t isDurationEdited;
		FeedTimeControl* feedControlPtr;
		FeedLaunchManager* feedLaunchManagerPtr;
		uint8_t feedSettingsIndex;
				
}; //FeedTimeSetMode
//---------------------------------------------------------------------------
#endif //__FEEDTIMESETMODE_H__
