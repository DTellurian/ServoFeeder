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
//---------------------------------------------------------------------------

class MainMode : public ButtonsControllerConsumer
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		MainMode(void);
		~MainMode();
										
		void OnTick(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
	protected:
	private:
		//MainMode( const MainMode &c );
		MainMode& operator=( const MainMode &c );
		
		RTCDateTime lastDateTime;

}; //MainMode
//---------------------------------------------------------------------------
#endif //__MAINMODE_H__
