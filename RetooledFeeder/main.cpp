/*
 * RetooledFeeder.cpp
 *
 * Created: 28.10.2015 23:18:09
 * Author : Mihalych
 */ 
//---------------------------------------------------------------------------

#define F_CPU 1000000UL  // 1 MHz
//---------------------------------------------------------------------------

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
//---------------------------------------------------------------------------

#include "Device/Device.h"
#include "BaseTypes/DateTime.h"
#include "BaseTypes/rtc.h"
#include "Device/Ports.h"
#include "Buttons/KeyMatrixController.h"
#include "Modes/MainMode.h"
#include "BaseTypes/DateTimeTimerInit.h"
//---------------------------------------------------------------------------

LcdNamespace::Lcd lcd;
char buffer[33];

//---------------------------------------------------------------------------
int main(void)
{
    /* Replace with your application code */
	
	MCUCSR = 1 << JTD;
	MCUCSR = 1 << JTD;
	
	DDRD |= _BV(DDD2);
	PORTD |= _BV(PD2);
	
	sei();
	
	lcd.LCD_Init();
	Device::lcdPtr = &lcd;
	
	lcd.LCD_Clear();
	lcd.LCD_SendString("Hello Test!");
	
	_delay_ms(1000);
	
	dateTime receivedDayTime = get_date_time();
	//rtc_init();
	
	KeyMatrixController keyMatrixController = KeyMatrixController();
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
	
	MainMode mainMode = MainMode();	
	keyMatrixControllerPtr->AttachConsumer(&mainMode);
	
	
	
	//InitTimer();
	//Device::InitTimer0();
	//DateTime::Initialize(1, 5);	
	DateTime::Initialize(260, 4);
	Device::InitTimer2();
	
	
	if(receivedDayTime.hour == 0 && receivedDayTime.minute == 0 && receivedDayTime.second == 0 )
	{
		lcd.LCD_Clear();
		lcd.LCD_SendString("Start Clock init");
		_delay_ms(500);

		dateTime dt;
		
		dt.hour = 1;
		dt.minute = 31;
		dt.second = 00;
		
		dt.date = 31;
		dt.month = 10;
		dt.year = 15;
		dt.day = 5;
		
		rtc_init();
		set_date_time(dt);

		lcd.LCD_SendString("Clock init finish!");
		_delay_ms(2000);
	}


	lcd.LCD_Clear();
	lcd.LCD_SendString("Started!");
	_delay_ms(2000);
	
	dateTime lastDateTime = dateTime();
	
	lcd.LCD_WriteCom(0b00001111);
	//LCD_WriteCom(0x01);
	//_delay_ms(2);
	
	pinA4.SetAsOutput();
	
	//lcd.LCD_Clear();
	//lcd.LCD_SendString("Ready for launch");
	//_delay_ms(2000);
	//
	//
	//pinA4.SetHightLevel();
	//
	//lcd.LCD_Clear();
	//lcd.LCD_SendString("Launched!");
	//_delay_ms(5000);
	//
	//pinA4.SetLowLevel();
	//
	//lcd.LCD_Clear();
	//lcd.LCD_SendString("Finished!");
	//_delay_ms(2000);
	
	while(1)
	{
		mainMode.OnTick();
		keyMatrixControllerPtr->ButtonsControllerOnTick();		
	}
}
//---------------------------------------------------------------------------
