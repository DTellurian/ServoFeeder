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
#include "Modes/DateTimeSetMode.h"
#include "Lcd/LcdController.h"
#include "ModesSupport/ModesController.h"
#include "Modes/FeedTimeSetMode.h"
#include "Lcd/FeedTimeControl.h"
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
	
		static KeyMatrixButton* ButtonPtr1;
		static KeyMatrixButton* ButtonPtr2;
		static KeyMatrixButton* ButtonPtr3;
		static KeyMatrixButton* ButtonPtr4;
		static KeyMatrixButton* ButtonPtr5;
		static KeyMatrixButton* ButtonPtr6;
		static KeyMatrixButton* ButtonPtr7;
		static KeyMatrixButton* ButtonPtr8;
		static KeyMatrixButton* ButtonPtr9;
		static Button* ButtonPtrStar;
		static KeyMatrixButton* ButtonPtr0;
		static Button* ButtonPtrSharp;
	
		static void Initialize();
						
		static Lcd lcd;
		static KeyMatrixController keyMatrixController;
		static MainMode mainMode;
		static DateTimeSetMode dateTimeSetMode;
		static FeedTimeSetMode feedTimeSetMode;
		static LcdController lcdController;
		
		static char lcdBuffer[18];
		
		static Pin* outputPin1Ptr;
		static Pin* outputPin3Ptr;
		
		static Pin* radionAPinPtr;
		static Pin* radionBPinPtr;
		static Pin* radionCPinPtr;
		
		static ModesController modesController;
		
		static DateTimeControl dateTimeControl;
		static FeedTimeControl feed1Control;
		static FeedTimeControl feed2Control;
		static FeedTimeControl feed3Control;
		static FeedTimeControl feed4Control;
		static FeedTimeControl feed5Control;
	protected:
	private:
		Device();
		Device( const Device &c );
		Device& operator=( const Device &c );
		
		static void InitTimer2(void);

}; //Device
//---------------------------------------------------------------------------
#endif //__DEVICE_H__
