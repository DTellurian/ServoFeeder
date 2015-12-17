/*
 * KeyMatrixButton.cpp
 *
 * Created: 26.01.2014 12:58:21
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "KeyMatrixButton.h"
#include "ButtonsController.h"
//---------------------------------------------------------------------------

KeyMatrixButton::KeyMatrixButton(void)
	:buttonIntValue(255)
{
	
}
//---------------------------------------------------------------------------

void KeyMatrixButton::InitializeMatrixButton(ButtonsController* buttonsControllerPtr, uint16_t delayMs)	
{
	Initialize(buttonsControllerPtr, delayMs);
}
//---------------------------------------------------------------------------

uint8_t KeyMatrixButton::IsPressed(void)
{
	return isVerticalPressed && isHorizontalPressed;
}
//---------------------------------------------------------------------------

uint8_t KeyMatrixButton::IsIntValueButton(void)
{
	return buttonIntValue != 255;
}
//---------------------------------------------------------------------------

uint8_t KeyMatrixButton::GetButtonIntValue(void)
{
	return buttonIntValue;
}
//---------------------------------------------------------------------------