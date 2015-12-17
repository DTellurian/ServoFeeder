/* 
* DateTimeEditHelper.h
*
* Created: 17.12.2015 10:57:49
* Author: Mihalych
*/


#ifndef __DATETIMEEDITHELPER_H__
#define __DATETIMEEDITHELPER_H__
//---------------------------------------------------------------------------

#include "../Buttons/Button.h"
#include "../BaseTypes/rtc.h"
#include "EditableLcdControl.h"
//---------------------------------------------------------------------------

class DateTimeEditHelper
{
//variables
public:
protected:
private:

//functions
public:
	static void ProceedTimeEditButtonPress(Button* buttonPtr, uint8_t& handled, RTCDateTime& timeToEdit, EditableLcdControl* controlPtr, uint8_t editSeconds);
	static void ProceedDateEditButtonPress(Button* buttonPtr, uint8_t& handled, RTCDateTime& timeToEdit, EditableLcdControl* controlPtr, uint8_t editSeconds);
	
	~DateTimeEditHelper();
protected:
private:
	DateTimeEditHelper();
	DateTimeEditHelper( const DateTimeEditHelper &c );
	DateTimeEditHelper& operator=( const DateTimeEditHelper &c );

}; //DateTimeEditHelper
//---------------------------------------------------------------------------
#endif //__DATETIMEEDITHELPER_H__
