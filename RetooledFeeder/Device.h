/* 
* Device.h
*
* Created: 31.10.2015 15:31:48
* Author: Mihalych
*/


#ifndef __DEVICE_H__
#define __DEVICE_H__
//---------------------------------------------------------------------------

#include "Buttons/SimpleButton.h"
#include "Lcd/Lcd.h"
#include "Buttons/KeyMatrixController.h"
#include "Modes/MainMode.h"
#include "Lcd/LcdController.h"
//---------------------------------------------------------------------------

using namespace LcdNamespace;
//---------------------------------------------------------------------------

class Device
{
	//variables
	public:
	protected:
	private:

	//functions
	public:	
		~Device();
	
		//static Button* ButtonPtr1;
		//static Button* ButtonPtr2;
		//static Button* ButtonPtr3;
		//static Button* ButtonPtr4;
		//static Button* ButtonPtr5;
		//static Button* ButtonPtr6;
		//static Button* ButtonPtr7;
		//static Button* ButtonPtr8;
		//static Button* ButtonPtr9;
		//static Button* ButtonPtrStar;
		static Button* ButtonPtr0;
		//static Button* ButtonPtrSharp;
	
		static void Initialize();
						
		static Lcd lcd;
		static KeyMatrixController keyMatrixController;
		static MainMode mainMode;
		//static LcdController lcdController;
		
		static char lcdBuffer[18];
		
		static Pin* outputPin3Ptr;
	protected:
	private:
		Device();
		Device( const Device &c );
		Device& operator=( const Device &c );
		
		static void InitTimer2(void);

}; //Device
//---------------------------------------------------------------------------
#endif //__DEVICE_H__
