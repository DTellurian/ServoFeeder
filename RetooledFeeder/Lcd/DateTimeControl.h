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
#include "EditableLcdControl.h"
//---------------------------------------------------------------------------

class DateTimeControl : public EditableLcdControl
{
	//variables
	public:
			DateTimeControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y);
			
			void SetTime(RTCDateTime time);					
	protected:
	private:
		

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
