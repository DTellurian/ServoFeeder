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
MainMode::MainMode(void)
//MainMode::MainMode(LcdController* lcdControllerPtr)
	:lastDateTime(), feedLaunchManager1(), feedLaunchManager2(), feedLaunchManager3(), feedLaunchManager4()
	//, dateTimeControl(lcdControllerPtr, 8, 0)
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
	DrawDate();
	
	feedLaunchManager1.ProceedTick();
	feedLaunchManager2.ProceedTick();
	feedLaunchManager3.ProceedTick();
	feedLaunchManager4.ProceedTick();
	
	//dateTimeControl.SetTime(receivedDayTime);
	//dateTimeControl.CopyToLcdController();
}
//---------------------------------------------------------------------------

void MainMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	//Device::lcd.LCD_Clear();
	
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
	//Device::lcd.LCD_Goto(30, 1);
/*
	if(buttonPtr == Device::ButtonPtr1)
	Device::lcd.LCD_SendString("1");
	else if(buttonPtr == Device::ButtonPtr2)
	Device::lcd.LCD_SendString("2");
	else if(buttonPtr == Device::ButtonPtr3)
	Device::lcd.LCD_SendString("3");
	else if(buttonPtr == Device::ButtonPtr4)
	Device::lcd.LCD_SendString("4");
	else if(buttonPtr == Device::ButtonPtr5)
	Device::lcd.LCD_SendString("5");
	else if(buttonPtr == Device::ButtonPtr6)
	Device::lcd.LCD_SendString("6");
	else if(buttonPtr == Device::ButtonPtr7)
	Device::lcd.LCD_SendString("7");
	else if(buttonPtr == Device::ButtonPtr8)
	Device::lcd.LCD_SendString("8");
	else if(buttonPtr == Device::ButtonPtr9)
	Device::lcd.LCD_SendString("9");
	else if(buttonPtr == Device::ButtonPtrStar)
	Device::lcd.LCD_SendString("*");
	else if(buttonPtr == Device::ButtonPtr0)
	Device::lcd.LCD_SendString("0");
	else if(buttonPtr == Device::ButtonPtrSharp)
	Device::lcd.LCD_SendString("#");
*/
	//set_date_time(receivedDayTime);
	
	//handled = 1;
	
	//_delay_ms(1000);
}
//---------------------------------------------------------------------------

void MainMode::EnterMode(FeedLaunchSettings& feed1, FeedLaunchSettings& feed2, FeedLaunchSettings& feed3, FeedLaunchSettings& feed4)
{
	Device::lcd.LCD_Clear();
	DrawDate();
	
	Device::lcd.LCD_Goto(9, 0);
	DrawFeedInfo(feed1);
	
	Device::lcd.LCD_Goto(9, 1);
	DrawFeedInfo(feed2);
	
	Device::lcd.LCD_Goto(25, 0);
	DrawFeedInfo(feed3);
	
	Device::lcd.LCD_Goto(25, 1);
	DrawFeedInfo(feed4);
	
	feedLaunchManager1.SetSettings(feed1);
	feedLaunchManager2.SetSettings(feed2);
	feedLaunchManager3.SetSettings(feed3);
	feedLaunchManager4.SetSettings(feed4);
}
//---------------------------------------------------------------------------

void MainMode::DrawDate(void)
{
	RTCDateTime receivedDayTime = RTCHelper::LoadDateTime(0);
	
	if(RTCHelper::DateTimeEquals(lastDateTime, receivedDayTime) == 0)
	{
		lastDateTime = receivedDayTime;
		
		Device::lcd.LCD_Goto(0, 0);
		sprintf(Device::lcdBuffer, "%.2d:%.2d:%.2d", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second);
		Device::lcd.LCD_SendString(Device::lcdBuffer);
		
		Device::lcd.LCD_Goto(0, 1);
		sprintf(Device::lcdBuffer, "%.2d:%.2d:%.2d", receivedDayTime.date, receivedDayTime.month, receivedDayTime.year);
		Device::lcd.LCD_SendString(Device::lcdBuffer);
	}
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