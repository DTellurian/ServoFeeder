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
//LcdController Device::lcdController(&Device::lcd);

KeyMatrixController Device::keyMatrixController;
//MainMode Device::mainMode(&Device::lcdController);
MainMode Device::mainMode;

char Device::lcdBuffer[18];

Pin* Device::outputPin1Ptr;
Pin* Device::outputPin3Ptr;
Pin* Device::outputPin4Ptr;

Pin* Device::radionAPinPtr;
//Pin* Device::radionBPinPtr;
Pin* Device::radionCPinPtr;
//---------------------------------------------------------------------------

// default destructor
Device::~Device()
{
} //~Device
//---------------------------------------------------------------------------


//Button* Device::ButtonPtr1;
//Button* Device::ButtonPtr2;
//Button* Device::ButtonPtr3;
//Button* Device::ButtonPtr4;
//Button* Device::ButtonPtr5;
//Button* Device::ButtonPtr6;
//Button* Device::ButtonPtr7;
//Button* Device::ButtonPtr8;
//Button* Device::ButtonPtr9;
Button* Device::ButtonPtrStar;
Button* Device::ButtonPtr0;
//Button* Device::ButtonPtrSharp;
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
	
	
	//Device::ButtonPtr1= &keyMatrixController.matrixButtons[0][0];
	//Device::ButtonPtr2= &keyMatrixController.matrixButtons[0][1];
	//Device::ButtonPtr3= &keyMatrixController.matrixButtons[0][2];
	//Device::ButtonPtr4= &keyMatrixController.matrixButtons[1][0];
	//Device::ButtonPtr5= &keyMatrixController.matrixButtons[1][1];
	//Device::ButtonPtr6= &keyMatrixController.matrixButtons[1][2];
	//Device::ButtonPtr7= &keyMatrixController.matrixButtons[2][0];
	//Device::ButtonPtr8= &keyMatrixController.matrixButtons[2][1];
	//Device::ButtonPtr9= &keyMatrixController.matrixButtons[2][2];
	Device::ButtonPtrStar= &keyMatrixController.matrixButtons[3][0];
	Device::ButtonPtr0= &keyMatrixController.matrixButtons[3][1];
	//Device::ButtonPtrSharp= &keyMatrixController.matrixButtons[3][2];
	
	keyMatrixController.AttachConsumer(&mainMode);	
	
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
	_delay_ms(5000);
		
	RTCDateTime lastDateTime = RTCDateTime();
		
	//lcd.LCD_WriteCom(0b00001111);Отображение курсора, мигание курсора!	

	pinA1.SetAsOutput();
	outputPin1Ptr = &pinA1;
			
	pinA4.SetAsOutput();
	outputPin3Ptr = &pinA4;
	
	pinA3.SetAsOutput();	
	outputPin4Ptr = &pinA3;
	
	pinB5.SetAsInputWithPullUp();
	Device::radionAPinPtr = &pinB5;

	//pinB7.SetAsInputWithPullUp();
	//Device::radionBPinPtr = &pinB7;
	
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