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

#include "Lcd/Lcd.h"
#include "BaseTypes/rtc.h"
#include "Device/Ports.h"
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
	
	//pinD7.SetAsOutput();
	//pinD6.SetAsOutput();
	//pinD5.SetAsOutput();
	
	sei();
	
	lcd.LCD_Init();
	lcd.LCD_Clear();
	lcd.LCD_SendString("Hello Test!");
	
	_delay_ms(1000);
	
	dateTime receivedDayTime = get_date_time();
	//rtc_init();
	
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
	
	
    while (1) 
    {
		//PORTD |= _BV(PD2);
		//_delay_ms(2000);
		//
		//PORTD &= ~_BV(PD2);
		//_delay_ms(2000);
		
		dateTime receivedDayTime = get_date_time();
		
		if(DateTimeEquals(lastDateTime, receivedDayTime) == 0)
		{
			lastDateTime = receivedDayTime;

			lcd.LCD_Clear();
			
			sprintf(buffer, "%i:%i:%i", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second);
			lcd.LCD_SendString(buffer);
			
			//lcd.LCD_SendString("ABCDEFGHI");
			
			//lcd.LCD_Goto(15, 0);
			//lcd.LCD_SendString(" ");
			//lcd.LCD_SendString("Day number:");
			//sprintf(buffer, "%.1d", lastDateTime.day);
			//lcd.LCD_SendString(buffer);
			
			//lcd.LCD_Goto(17, 0);
			//lcd.LCD_SendString("T");
			
			lcd.LCD_Goto(17, 0);
			lcd.LCD_SendString("Day number:");
			sprintf(buffer, "%.1d", lastDateTime.day);
			lcd.LCD_SendString(buffer);
			
			lcd.LCD_WriteCom(0xc0);
			
			//char* bfrPtr = buffer + 1;
			//sprintf(bfrPtr, "%.2d:%.2d:%.2d        %i.%i.%.2d", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second, receivedDayTime.date, receivedDayTime.month, receivedDayTime.year);
			
			sprintf(buffer, "%.2d:%.2d:%.2d        %i.%i.%.2d", receivedDayTime.hour, receivedDayTime.minute, receivedDayTime.second, receivedDayTime.date, receivedDayTime.month, receivedDayTime.year);
			lcd.LCD_SendString(buffer);
			
			lcd.LCD_Goto(19, 1);
			
			_delay_ms(100);
		}
    }
}
//---------------------------------------------------------------------------
