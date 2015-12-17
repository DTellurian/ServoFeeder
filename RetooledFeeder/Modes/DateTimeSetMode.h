/* 
* DateTimeSetMode.h
*
* Created: 15.12.2015 17:43:12
* Author: Mihalych
*/


#ifndef __DATETIMESETMODE_H__
#define __DATETIMESETMODE_H__
//---------------------------------------------------------------------------

#include "../Buttons/ButtonsControllerConsumer.h"
#include "../ModesSupport/Mode.h"
//---------------------------------------------------------------------------

class DateTimeSetMode : public ButtonsControllerConsumer, public Mode
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		DateTimeSetMode();
		~DateTimeSetMode();
		
		virtual void EnterMode(void);
		virtual void ExitMode(void);
			
		virtual void ProceedModeOnTick(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);		
		
	protected:
	private:
		DateTimeSetMode( const DateTimeSetMode &c );
		DateTimeSetMode& operator=( const DateTimeSetMode &c );
		
		uint8_t isDateEdited;

}; //DateTimeSetMode
//---------------------------------------------------------------------------
#endif //__DATETIMESETMODE_H__
