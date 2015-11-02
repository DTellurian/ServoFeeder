/*
 * DateTime.cpp
 *
 * Created: 10.08.2012 10:17:14
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "DateTime.h"
//#include "DateTimeTimerInit.h"
//---------------------------------------------------------------------------

volatile uint64_t DateTime::milliseconds = 0;
volatile uint16_t DateTime::ticksCount = 0;
//uint16_t DateTime::ticksInSecond = 0;
uint16_t DateTime::millisecondsInTick = 0;
//CFTime DateTime::CurrentTime = CFTime();
//CFDate DateTime::CurrentDate = CFDate();

void DateTime::Initialize(uint16_t millisecondsInTick)
{	
	DateTime::millisecondsInTick = millisecondsInTick;
	
	//InitTimer();
}
//---------------------------------------------------------------------------

void DateTime::OnMillisecondsTick(void)
{
	DateTime::milliseconds += millisecondsInTick;	
}
//---------------------------------------------------------------------------