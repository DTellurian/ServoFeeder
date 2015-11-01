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

#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
//---------------------------------------------------------------------------

#include "Device.h"
#include "BaseTypes/DateTime.h"
#include "BaseTypes/rtc.h"

#include "Buttons/KeyMatrixController.h"
#include "Modes/MainMode.h"
#include "BaseTypes/DateTimeTimerInit.h"
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
int main(void)
{
    /* Replace with your application code */		
	Device::Initialize();
				
	while(1)
	{
		Device::mainModePtr->OnTick();
		Device::keyMatrixControllerPtr->ButtonsControllerOnTick();		
	}
}
//---------------------------------------------------------------------------
