/* 
* DateTimeControl.cpp
*
* Created: 01.11.2015 23:10:57
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "DateTimeControl.h"
#include "../BaseTypes/RTCHelper.h"
//---------------------------------------------------------------------------

// default constructor
DateTimeControl::DateTimeControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y)
	:BaseLcdControl(lcdControllerPtr, x, y, 8, 2), isInEditMode(0)
{
} //DateTimeControl
//---------------------------------------------------------------------------

// default destructor
DateTimeControl::~DateTimeControl()
{
} //~DateTimeControl
//---------------------------------------------------------------------------

#include <stdio.h>
//---------------------------------------------------------------------------

void DateTimeControl::SetTime(RTCDateTime time)
{
	char* buffer = GetBufferPointerToWrite();
	//sprintf(buffer, "Hello!");
	//sprintf(buffer, "%.2d:%.2d:%.2d", time.hour, time.minute, time.second);
	RTCHelper::TimeWithSecondsToString(buffer, time);
	
	buffer = GetBufferPointerToWrite(1);
	RTCHelper::DateToString(buffer, time);
}
//---------------------------------------------------------------------------

void DateTimeControl::AfterLcdRedraw(void)
{
	if(isInEditMode)
		GetLcdPtr()->LCD_Goto(x + 1, y);
}
//---------------------------------------------------------------------------

void DateTimeControl::EnterEditMode(void)
{
	isInEditMode = 1;
	GetLcdPtr()->LCD_WriteCom(0b00001111);//Отображение курсора, мигание курсора!		
}
//---------------------------------------------------------------------------

void DateTimeControl::ExitEditMode(void)
{
	isInEditMode = 0;
	GetLcdPtr()->LCD_WriteCom(0b00001100);//Отображение курсора, мигание курсора!
}
//---------------------------------------------------------------------------

uint8_t DateTimeControl::IsInEditMode(void)
{
	return isInEditMode;
}
//---------------------------------------------------------------------------

void DateTimeControl::SetXY(uint8_t x, uint8_t y)
{	
	BaseLcdControl::x = x;
	BaseLcdControl::y = y;
}
//---------------------------------------------------------------------------