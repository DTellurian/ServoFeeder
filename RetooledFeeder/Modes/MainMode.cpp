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

//char mainBuffer[33];

// default constructor
//MainMode::MainMode(void)
MainMode::MainMode()
	:lastDateTime(), feedLaunchManager1(), feedLaunchManager2(), feedLaunchManager3(), feedLaunchManager4()	
{
} //MainMode
//---------------------------------------------------------------------------

// default destructor
MainMode::~MainMode()
{
} //~MainMode
//---------------------------------------------------------------------------

void MainMode::Initialize(FeedLaunchSettings& feed1, FeedLaunchSettings& feed2, FeedLaunchSettings& feed3, FeedLaunchSettings& feed4)
{
	feedLaunchManager1.SetSettings(feed1);
	feedLaunchManager2.SetSettings(feed2);
	feedLaunchManager3.SetSettings(feed3);
	feedLaunchManager4.SetSettings(feed4);
}
//---------------------------------------------------------------------------

void MainMode::EnterMode(void)
{
	Device::lcdController.Clear();
	
	Device::dateTimeControl.SetXY(0, 0);
	Device::dateTimeControl.CopyToLcdController();	
	
	Device::lcdController.Redraw(1);
	
	Device::lcd.LCD_Goto(9, 0);
	DrawFeedInfo(feedLaunchManager1.settings);
	
	Device::lcd.LCD_Goto(9, 1);
	DrawFeedInfo(feedLaunchManager2.settings);
	
	Device::lcd.LCD_Goto(25, 0);
	DrawFeedInfo(feedLaunchManager3.settings);
	
	Device::lcd.LCD_Goto(25, 1);
	DrawFeedInfo(feedLaunchManager4.settings);
}
//---------------------------------------------------------------------------

void MainMode::ProceedModeOnTick()
{	
	feedLaunchManager1.ProceedTick();
	feedLaunchManager2.ProceedTick();
	feedLaunchManager3.ProceedTick();
	feedLaunchManager4.ProceedTick();
	
	RTCDateTime receivedDayTime = RTCHelper::LoadDateTime(0);
	
	Device::dateTimeControl.SetTime(receivedDayTime);
	Device::dateTimeControl.CopyToLcdController();
	Device::lcdController.Redraw(0);	
}
//---------------------------------------------------------------------------

void MainMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{	
	if(!isActive || handled)
		return;
	
	handled = 1;
	
	RTCDateTime receivedDayTime = RTC::GetDateTime();

	if(buttonPtr == Device::ButtonPtr1)
		receivedDayTime.hour++;
	else if(buttonPtr == Device::ButtonPtr4)
		receivedDayTime.hour--;
	else if(buttonPtr == Device::ButtonPtr2)
		receivedDayTime.minute++;
	else if(buttonPtr == Device::ButtonPtr5)
		receivedDayTime.minute--;
	else if(buttonPtr == Device::ButtonPtr3)
		receivedDayTime.second++;
	else if(buttonPtr == Device::ButtonPtr6)
		receivedDayTime.hour = 16;
	else if(buttonPtr == Device::ButtonPtrStar)
	{
		Device::modesController.SetCurrentMode(&Device::dateTimeSetMode);
		_delay_ms(100);
		return;
	}
		
	RTC::SetDateTime(receivedDayTime);
	
	_delay_ms(100);
}
//---------------------------------------------------------------------------

void MainMode::DrawFeedInfo(FeedLaunchSettings& feed)
{
	sprintf(Device::lcdBuffer, "%.2d:%.2d", feed.feedTime.hour, feed.feedTime.minute);
	Device::lcd.LCD_SendString(Device::lcdBuffer);
	
	if(feed.isEnabled)
	{
		sprintf(Device::lcdBuffer, "T%.i", feed.lengthInSeconds);
		Device::lcd.LCD_SendString(Device::lcdBuffer);
	}
	else
		Device::lcd.LCD_SendString("--");
}
//---------------------------------------------------------------------------
