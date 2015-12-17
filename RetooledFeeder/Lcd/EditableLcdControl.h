/* 
* EditableLcdControl.h
*
* Created: 16.12.2015 12:13:57
* Author: Mihalych
*/


#ifndef __EDITABLELCDCONTROL_H__
#define __EDITABLELCDCONTROL_H__
//---------------------------------------------------------------------------

#include "BaseLcdControl.h"
//---------------------------------------------------------------------------

class EditableLcdControl : public BaseLcdControl
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		EditableLcdControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
		
		~EditableLcdControl();
		
		uint8_t IsInEditMode(void);
		void SetCursor(void);
		void EnterEditMode(void);
		void ExitEditMode(void);
		
		void SetCursorCoordinates(uint8_t newX, uint8_t newY);

		uint8_t cursorXPosition;
		uint8_t cursorYPosition;	
	protected:

		
	private:
		EditableLcdControl();
		EditableLcdControl( const EditableLcdControl &c );
		EditableLcdControl& operator=( const EditableLcdControl &c );
		
		uint8_t isInEditMode;

}; //EditableLcdControl
//---------------------------------------------------------------------------

#endif //__EDITABLELCDCONTROL_H__
