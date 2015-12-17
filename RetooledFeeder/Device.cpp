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
LcdController Device::lcdController(&Device::lcd);

KeyMatrixController Device::keyMatrixController;
MainMode Device::mainMode;
DateTimeSetMode Device::dateTimeSetMode;

char Device::lcdBuffer[18];

Pin* Device::outputPin1Ptr;
Pin* Device::outputPin3Ptr;

Pin* Device::radionAPinPtr;
Pin* Device::radionBPinPtr;
Pin* Device::radionCPinPtr;

DateTimeControl Device::dateTimeControl(&Device::lcdController, 0, 0);
//---------------------------------------------------------------------------

// default destructor
Device::~Device()
{
} //~Device
//---------------------------------------------------------------------------


KeyMatrixButton* Device::ButtonPtr1;
KeyMatrixButton* Device::ButtonPtr2;
KeyMatrixButton* Device::ButtonPtr3;
KeyMatrixButton* Device::ButtonPtr4;
KeyMatrixButton* Device::ButtonPtr5;
KeyMatrixButton* Device::ButtonPtr6;
KeyMatrixButton* Device::ButtonPtr7;
KeyMatrixButton* Device::ButtonPtr8;
KeyMatrixButton* Device::ButtonPtr9;
Button* Device::ButtonPtrStar;
KeyMatrixButton* Device::ButtonPtr0;
Button* Device::ButtonPtrSharp;
//---------------------------------------------------------------------------

ModesController Device::modesController;
//---------------------------------------------------------------------------

void Device::Initialize()
{
	MCUCSR = 1 << JTD;
	MCUCSR = 1 << JTD;
	
	sei();
	
	lcd.LCD_Init();	
	lcd.LCD_Clear();
	
	//lcd.LCD_SendString("Launching!");
	//_delay_ms(1000);

		
	keyMatrixController.Initialize(100);

	keyMatrixController.horizontalPins[0] = &pinD3;
	keyMatrixController.horizontalPins[1] = &pinC0;
	keyMatrixController.horizontalPins[2] = &pinC1;
	keyMatrixController.horizontalPins[3] = &pinC3;
	
	keyMatrixController.verticalPins[0] = &pinC4;
	keyMatrixController.verticalPins[1] = &pinB0;
	keyMatrixController.verticalPins[2] = &pinC2;
	
	
	Device::ButtonPtr1 = &keyMatrixController.matrixButtons[0][0];		
	Device::ButtonPtr2 = &keyMatrixController.matrixButtons[0][1];
	Device::ButtonPtr3 = &keyMatrixController.matrixButtons[0][2];
	Device::ButtonPtr4 = &keyMatrixController.matrixButtons[1][0];
	Device::ButtonPtr5 = &keyMatrixController.matrixButtons[1][1];
	Device::ButtonPtr6 = &keyMatrixController.matrixButtons[1][2];
	Device::ButtonPtr7 = &keyMatrixController.matrixButtons[2][0];
	Device::ButtonPtr8 = &keyMatrixController.matrixButtons[2][1];
	Device::ButtonPtr9 = &keyMatrixController.matrixButtons[2][2];
	Device::ButtonPtrStar = &keyMatrixController.matrixButtons[3][0];
	Device::ButtonPtr0 = &keyMatrixController.matrixButtons[3][1];
	Device::ButtonPtrSharp = &keyMatrixController.matrixButtons[3][2];
	
	Device::ButtonPtr1->buttonIntValue = 1;
	Device::ButtonPtr2->buttonIntValue = 2;
	Device::ButtonPtr3->buttonIntValue = 3;
	Device::ButtonPtr4->buttonIntValue = 4;
	Device::ButtonPtr5->buttonIntValue = 5;
	Device::ButtonPtr6->buttonIntValue = 6;
	Device::ButtonPtr7->buttonIntValue = 7;
	Device::ButtonPtr8->buttonIntValue = 8;
	Device::ButtonPtr9->buttonIntValue = 9;
	Device::ButtonPtr0->buttonIntValue = 0;
	
	keyMatrixController.AttachConsumer(&mainMode);
	keyMatrixController.AttachConsumer(&dateTimeSetMode);
	
	RTCDateTime receivedDayTime = RTC::GetDateTime();
		
	if(receivedDayTime.hour == 0 && receivedDayTime.minute == 0 && receivedDayTime.second == 0 )
	{
		//lcd.LCD_Clear();
		//lcd.LCD_SendString("Start Clock init");
		//_delay_ms(500);

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
		_delay_ms(500);
	}


	//lcd.LCD_Clear();
	lcd.LCD_SendString("Started!");
	_delay_ms(10000);
		
	RTCDateTime lastDateTime = RTCDateTime();
		
	//lcd.LCD_WriteCom(0b00001111);//Отображение курсора, мигание курсора!	
			
	pinA4.SetAsOutput();
	outputPin3Ptr = &pinA4;
	
	pinA1.SetAsOutput();
	outputPin1Ptr = &pinA1;
	
	pinB5.SetAsInputWithPullUp();
	Device::radionAPinPtr = &pinB5;

	pinB7.SetAsInputWithPullUp();
	Device::radionBPinPtr = &pinB7;
	
	pinB6.SetAsInputWithPullUp();
	Device::radionCPinPtr = &pinB6;
	
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
	TIMSK |= _BV(OCIE2);  //Устанавливаем для него прерывание совпадения
}

//---------------------------------------------------------------------------
ISR(TIMER2_COMP_vect)
{
	DateTime::OnMillisecondsTick();
	//DateTime::OnSecondsTick();
}
//---------------------------------------------------------------------------