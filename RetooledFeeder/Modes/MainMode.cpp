/* 
* MainMode.cpp
*
* Created: 31.10.2015 15:39:40
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "MainMode.h"
#include "../BaseTypes/DateTime.h"
#include "../Device.h"
#include "../Buttons/Button.h"
#include "../BaseTypes/RTCHelper.h"
//---------------------------------------------------------------------------

char mainBuffer[33];

// default constructor
//MainMode::MainMode(void)
MainMode::MainMode(LcdController* lcdControllerPtr)
	:lastDateTime()
	, dateTimeControl(lcdControllerPtr, 8, 0)
{
} //MainMode
//---------------------------------------------------------------------------

// default destructor
MainMode::~MainMode()
{
} //~MainMode
//---------------------------------------------------------------------------

void MainMode::OnTick()
{
	cli();
	RTCDateTime receivedDayTime = RTCHelper::LoadDateTime();
	//RTC::GetDateTime();
	
	//Device::lcdPtr->LCD_Clear();
	//Device::lcdPtr->LCD_Goto(0, 0);
	//Device::lcdPtr->LCD_SendString("Hello!");
	//_delay_ms(100);

	//sprintf(mainBuffer, "%.2d:%.2d:%.2d        %i.%i.%.2d", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second, receivedDayTime.date, receivedDayTime.month, receivedDayTime.year);
	//Device::lcdPtr->LCD_SendString(mainBuffer);
	
	dateTimeControl.SetTime(receivedDayTime);
	dateTimeControl.CopyToLcdController();
	sei();
	
	_delay_ms(100);
	
	
	return;
		/*
	if(RTC::DateTimeEquals(lastDateTime, receivedDayTime) == 0)
	{
		cli();
		lastDateTime = receivedDayTime;

		Device::lcdPtr->LCD_Clear();
				
		//sprintf(mainBuffer, "%i:%i:%i", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second);
		//Device::lcdPtr->LCD_SendString(mainBuffer);
				
		Device::lcdPtr->LCD_Goto(0, 0);
		//sprintf(mainBuffer, "MS:%.8d", DateTime::milliseconds / 1000);
		//sprintf(mainBuffer, "Loc:%.2d:%.2d:%.2d", DateTime::CurrentTime.GetHours(), DateTime::CurrentTime.GetMinutes(), DateTime::CurrentTime.GetSeconds());
		//Device::lcdPtr->LCD_SendString(mainBuffer);
				
		Device::lcdPtr->LCD_Goto(17, 0);
		Device::lcdPtr->LCD_SendString("Day number:");
		sprintf(mainBuffer, "%.1d", lastDateTime.day);
		Device::lcdPtr->LCD_SendString(mainBuffer);
				
		Device::lcdPtr->LCD_WriteCom(0xc0);
				
		//char* bfrPtr = buffer + 1;
		//sprintf(bfrPtr, "%.2d:%.2d:%.2d        %i.%i.%.2d", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second, receivedDayTime.date, receivedDayTime.month, receivedDayTime.year);
				
		sprintf(mainBuffer, "%.2d:%.2d:%.2d        %i.%i.%.2d", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second, receivedDayTime.date, receivedDayTime.month, receivedDayTime.year);
		Device::lcdPtr->LCD_SendString(mainBuffer);
				
		Device::lcdPtr->LCD_Goto(19, 1);
				
		_delay_ms(100);
		sei();
	}
	*/
}
//---------------------------------------------------------------------------

void MainMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	Device::lcdPtr->LCD_Clear();
	
	//RTCDateTime receivedDayTime = get_date_time();
//
	//if(buttonPtr == Device::ButtonPtr1)
	//receivedDayTime.hour++;
	//else if(buttonPtr == Device::ButtonPtr4)
	//receivedDayTime.hour--;
	//else if(buttonPtr == Device::ButtonPtr2)
	//receivedDayTime.minute++;
	//else if(buttonPtr == Device::ButtonPtr5)
	//receivedDayTime.minute--;
	//else if(buttonPtr == Device::ButtonPtr3)
	//receivedDayTime.second++;
	//else if(buttonPtr == Device::ButtonPtr6)
	//receivedDayTime.second--;
//
	//Device::lcdPtr->LCD_Goto(30, 1);

	//if(buttonPtr == Device::ButtonPtr1)
	//Device::lcdPtr->LCD_SendString("1");
	//else if(buttonPtr == Device::ButtonPtr2)
	//Device::lcdPtr->LCD_SendString("2");
	//else if(buttonPtr == Device::ButtonPtr3)
	//Device::lcdPtr->LCD_SendString("3");
	//else if(buttonPtr == Device::ButtonPtr4)
	//Device::lcdPtr->LCD_SendString("4");
	//else if(buttonPtr == Device::ButtonPtr5)
	//Device::lcdPtr->LCD_SendString("5");
	//else if(buttonPtr == Device::ButtonPtr6)
	//Device::lcdPtr->LCD_SendString("6");
	//else if(buttonPtr == Device::ButtonPtr7)
	//Device::lcdPtr->LCD_SendString("7");
	//else if(buttonPtr == Device::ButtonPtr8)
	//Device::lcdPtr->LCD_SendString("8");
	//else if(buttonPtr == Device::ButtonPtr9)
	//Device::lcdPtr->LCD_SendString("9");
	//else if(buttonPtr == Device::ButtonPtrStar)
	//Device::lcdPtr->LCD_SendString("*");
	//else if(buttonPtr == Device::ButtonPtr0)
	//Device::lcdPtr->LCD_SendString("0");
	//else if(buttonPtr == Device::ButtonPtrSharp)
	//Device::lcdPtr->LCD_SendString("#");

	//set_date_time(receivedDayTime);
	
	handled = 1;
	
	_delay_ms(1000);
}
//---------------------------------------------------------------------------
