/* 
* Device.cpp
*
* Created: 31.10.2015 15:31:48
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "Device.h"
#include "../BaseTypes/DateTime.h"
#include <avr/interrupt.h>
//---------------------------------------------------------------------------

// default destructor
Device::~Device()
{
} //~Device

//---------------------------------------------------------------------------

Button* Device::ButtonPtr1;
Button* Device::ButtonPtr2;
Button* Device::ButtonPtr3;
Button* Device::ButtonPtr4;
Button* Device::ButtonPtr5;
Button* Device::ButtonPtr6;
Button* Device::ButtonPtr7;
Button* Device::ButtonPtr8;
Button* Device::ButtonPtr9;
Button* Device::ButtonPtrStar;
Button* Device::ButtonPtr0;
Button* Device::ButtonPtrSharp;
LcdNamespace::Lcd* Device::lcdPtr;
//---------------------------------------------------------------------------

void Device::InitTimer2(void)
{
	OCR2 = 60;
	//TCCR2 = _BV(WGM21) | _BV(CS22) | _BV(CS21);// | _BV(CS20);
	TCCR2 = _BV(WGM21) | _BV(CS22);// | _BV(CS21); | _BV(CS20);
	TIMSK |= _BV(OCIE2);  //”станавливаем дл€ него прерывание совпадени€
}

//---------------------------------------------------------------------------
ISR(TIMER2_COMP_vect)
{
	DateTime::OnMillisecondsTick();
	DateTime::OnSecondsTick();
}
//---------------------------------------------------------------------------