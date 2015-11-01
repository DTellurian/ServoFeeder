/*
 * KeyMatrixController.cpp
 *
 * Created: 26.01.2014 12:37:06
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "KeyMatrixController.h"
#include <stdlib.h>
//---------------------------------------------------------------------------

KeyMatrixController::KeyMatrixController(void)
{			
	/*
	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)	
		for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
		{
			KeyMatrixButton* buttonToAttachPtr = &KeyMatrixButton(this, defaultDelay);
			AttachButton(buttonToAttachPtr);
			matrixButtons[horizontal][vertical] = buttonToAttachPtr;
		}			
		*/
}
//---------------------------------------------------------------------------

void KeyMatrixController::Initialize(uint16_t defaultDelay)
{	
	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)	
		for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
		{			
			matrixButtons[horizontal][vertical].InitializeMatrixButton(this, defaultDelay);
			AttachButton(&matrixButtons[horizontal][vertical]);						
		}					
		
}
//---------------------------------------------------------------------------

void KeyMatrixController::ButtonsControllerOnTick(void)
{		
	/*
	for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
		verticalPins[vertical]->SetAsInputWithPullUp();
		
	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)
	{
		horizontalPins[horizontal]->SetAsOutput();
		horizontalPins[horizontal]->SetHightLevel();
	}
	
	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)
	{						
		horizontalPins[horizontal]->SetLowLevel();
		
		for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
			(&matrixButtons[horizontal][vertical])->isHorizontalPressed = !verticalPins[vertical]->IsPinSet();
			
		horizontalPins[horizontal-1]->SetHightLevel();
	}		
		*/
	for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
		verticalPins[vertical]->SetAsInputWithPullUp();
		
	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)
	{
		horizontalPins[horizontal]->SetAsOutput();
		horizontalPins[horizontal]->SetHightLevel();
	}
	
	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)
	{		
		horizontalPins[horizontal]->SetLowLevel();
		
		for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
			matrixButtons[horizontal][vertical].isHorizontalPressed = !verticalPins[vertical]->IsPinSet();
			
		horizontalPins[horizontal]->SetHightLevel();
	}
	
	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)		
		horizontalPins[horizontal]->SetAsInputWithPullUp();
		
	for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
	{
		verticalPins[vertical]->SetAsOutput();
		verticalPins[vertical]->SetHightLevel();
	}
	
	for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
	{			
		verticalPins[vertical]->SetLowLevel();
		
		for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)
			matrixButtons[horizontal][vertical].isVerticalPressed = !horizontalPins[horizontal]->IsPinSet();
			
		verticalPins[vertical]->SetHightLevel();
	}
	
	/*
	//Непонятно зачем это тут было
	for(uint8_t vertical = 0; vertical < KeyMatrixVerticalCount; vertical++)
		verticalPins[vertical]->SetLowLevel();

	for(uint8_t horizontal = 0; horizontal < KeyMatrixHorizontalCount; horizontal++)
	{
		horizontalPins[horizontal]->SetAsOutput();
		horizontalPins[horizontal]->SetLowLevel();
	}
	*/
	
	ButtonsController::ButtonsControllerOnTick();
	//for(uint8_t i = 0; i < attachedButtonsCount; i++)
		//buttons[i]->OnTick();
}
//---------------------------------------------------------------------------