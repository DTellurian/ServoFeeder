/* 
* EditableLcdControl.cpp
*
* Created: 16.12.2015 12:13:57
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "EditableLcdControl.h"
//---------------------------------------------------------------------------

// default constructor
EditableLcdControl::EditableLcdControl(LcdController* lcdControllerPtr, uint8_t x, uint8_t y, uint8_t width, uint8_t height)
	:BaseLcdControl(lcdControllerPtr, x, y, width, height), isInEditMode(0), cursorXPosition(0), cursorYPosition(0)
{
} //EditableLcdControl
//---------------------------------------------------------------------------
// default destructor
EditableLcdControl::~EditableLcdControl()
{
} //~EditableLcdControl
//---------------------------------------------------------------------------

uint8_t EditableLcdControl::IsInEditMode(void)
{
	return isInEditMode;
}
//---------------------------------------------------------------------------

void EditableLcdControl::SetCursor(void)
{
	GetLcdPtr()->LCD_Goto(x + cursorXPosition, y + cursorYPosition);
}
//---------------------------------------------------------------------------

void EditableLcdControl::EnterEditMode(void)
{
	isInEditMode = 1;
	GetLcdPtr()->LCD_WriteCom(0b00001111);//Отображение курсора, мигание курсора!
}
//---------------------------------------------------------------------------

void EditableLcdControl::ExitEditMode(void)
{
	isInEditMode = 0;
	GetLcdPtr()->LCD_WriteCom(0b00001100);//Отображение курсора, мигание курсора!
}
//---------------------------------------------------------------------------

void EditableLcdControl::SetCursorCoordinates(uint8_t newX, uint8_t newY)
{
	cursorXPosition = newX;
	cursorYPosition = newY;
}
//---------------------------------------------------------------------------