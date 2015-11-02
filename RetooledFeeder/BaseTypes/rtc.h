/* 
* rtc.h
*
* Created: 27.06.2014 15:14:46
* Author: Mihalych
*/


#ifndef __RTC_H__
#define __RTC_H__
//---------------------------------------------------------------------------

#include <stdint.h>
//---------------------------------------------------------------------------

//Data type to hold calendar/clock data
typedef struct
{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t date;
    uint8_t month;
    uint8_t day;
    uint8_t year;
} RTCDateTime;
//---------------------------------------------------------------------------
 
/*******************************************************************
  Interface function to initialize RTC: 1. Disable Clock Halt
                                        2. Set to 24 hour mode
                                        3. Disable Write Protection
  No Calendar/Clock will be changed
********************************************************************/
//---------------------------------------------------------------------------

class RTC
{
	public:
		static void Init(void);
 
		//Interface function to read Calendar/Clock value
		static RTCDateTime GetDateTime(void);
 
		//Interface function to set Calendar/Clock value
		static void SetDateTime(RTCDateTime dt);

		static uint8_t DateTimeEquals(RTCDateTime &left, RTCDateTime &right);
		static uint8_t TimeEquals(RTCDateTime &left, RTCDateTime &right);

	private:
		RTC();
		RTC( const RTC &c );
		RTC& operator=( const RTC &c );
};
//---------------------------------------------------------------------------
#endif //__RTC_H__
