/* 
* Device.cpp
*
* Created: 31.10.2015 15:31:48
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include <avr/interrupt.h>
#include <util/delay.h>
//---------------------------------------------------------------------------

#include "Device.h"
#include "BaseTypes/DateTime.h"
#include "Device/Ports.h"
//---------------------------------------------------------------------------

Lcd Device::lcd;
char buffer[33];
KeyMatrixController Device::keyMatrixController;
MainMode Device::mainMode;
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

KeyMatrixController* Device::keyMatrixControllerPtr;
MainMode* Device::mainModePtr;
//---------------------------------------------------------------------------

void Device::Initialize()
{
	Device::mainModePtr = &mainMode;
	Device::keyMatrixControllerPtr = &keyMatrixController;

	MCUCSR = 1 << JTD;
	MCUCSR = 1 << JTD;
	
	sei();
	
	lcd.LCD_Init();
	Device::lcdPtr = &lcd;
	
	lcd.LCD_Clear();
	lcd.LCD_SendString("Launching!");
	_delay_ms(2000);

	KeyMatrixController* keyMatrixControllerPtr = &keyMatrixController;
	keyMatrixControllerPtr->Initialize(100);

	keyMatrixControllerPtr->horizontalPins[0] = &pinD3;
	keyMatrixControllerPtr->horizontalPins[1] = &pinC0;
	keyMatrixControllerPtr->horizontalPins[2] = &pinC1;
	keyMatrixControllerPtr->horizontalPins[3] = &pinC3;
	
	keyMatrixControllerPtr->verticalPins[0] = &pinC4;
	keyMatrixControllerPtr->verticalPins[1] = &pinB0;
	keyMatrixControllerPtr->verticalPins[2] = &pinC2;
	
	
	Device::ButtonPtr1= &keyMatrixControllerPtr->matrixButtons[0][0];
	Device::ButtonPtr2= &keyMatrixControllerPtr->matrixButtons[0][1];
	Device::ButtonPtr3= &keyMatrixControllerPtr->matrixButtons[0][2];
	Device::ButtonPtr4= &keyMatrixControllerPtr->matrixButtons[1][0];
	Device::ButtonPtr5= &keyMatrixControllerPtr->matrixButtons[1][1];
	Device::ButtonPtr6= &keyMatrixControllerPtr->matrixButtons[1][2];
	Device::ButtonPtr7= &keyMatrixControllerPtr->matrixButtons[2][0];
	Device::ButtonPtr8= &keyMatrixControllerPtr->matrixButtons[2][1];
	Device::ButtonPtr9= &keyMatrixControllerPtr->matrixButtons[2][2];
	Device::ButtonPtrStar= &keyMatrixControllerPtr->matrixButtons[3][0];
	Device::ButtonPtr0= &keyMatrixControllerPtr->matrixButtons[3][1];
	Device::ButtonPtrSharp= &keyMatrixControllerPtr->matrixButtons[3][2];
	
	keyMatrixControllerPtr->AttachConsumer(mainModePtr);
	
	
	RTCDateTime receivedDayTime = RTC::GetDateTime();
		
	if(receivedDayTime.hour == 0 && receivedDayTime.minute == 0 && receivedDayTime.second == 0 )
	{
		lcd.LCD_Clear();
		lcd.LCD_SendString("Start Clock init");
		_delay_ms(500);

		RTCDateTime dt;
			
		dt.hour = 1;
		dt.minute = 31;
		dt.second = 00;
			
		dt.date = 31;
		dt.month = 10;
		dt.year = 15;
		dt.day = 5;
			
		RTC::Init();
		RTC::SetDateTime(dt);

		lcd.LCD_SendString("Clock init finish!");
		_delay_ms(2000);
	}


	lcd.LCD_Clear();
	lcd.LCD_SendString("Started!");
	_delay_ms(2000);
		
	RTCDateTime lastDateTime = RTCDateTime();
		
	lcd.LCD_WriteCom(0b00001111);
	//LCD_WriteCom(0x01);
	//_delay_ms(2);
	
	pinA4.SetAsOutput();	
	
	//DateTime::Initialize(260, 4);
	DateTime::Initialize(4);
	Device::InitTimer2();
}
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
	//DateTime::OnSecondsTick();
}
//---------------------------------------------------------------------------