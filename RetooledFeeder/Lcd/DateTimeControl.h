/* 
* DateTimeControl.h
*
* Created: 01.11.2015 23:10:57
* Author: Mihalych
*/


#ifndef __DATETIMECONTROL_H__
#define __DATETIMECONTROL_H__
//---------------------------------------------------------------------------

#include "BaseLcdControl.h"
#include "../BaseTypes/RTC.h"
//---------------------------------------------------------------------------

class DateTimeControl : public BaseLcdControl
{
	//variables
	public:
			DateTimeControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y);
			
			void SetTime(RTCDateTime time);			
			void AfterLcdRedraw(void);
			
			void EnterEditMode(void);
			void ExitEditMode(void);
			uint8_t IsInEditMode(void);
			
			void SetXY(uint8_t x, uint8_t y);
	protected:
	private:
		uint8_t isInEditMode;

	//functions
	public:		
		~DateTimeControl();
	protected:
	private:
		DateTimeControl();
		DateTimeControl( const DateTimeControl &c );
		DateTimeControl& operator=( const DateTimeControl &c );

}; //DateTimeControl
//---------------------------------------------------------------------------
#endif //__DATETIMECONTROL_H__
