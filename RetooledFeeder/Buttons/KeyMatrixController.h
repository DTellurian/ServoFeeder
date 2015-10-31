/*
 * KeyMatrixController.h
 *
 * Created: 26.01.2014 12:25:59
 *  Author: Mihalych
 */ 


#ifndef KEYMATRIXCONTROLLER_H_
#define KEYMATRIXCONTROLLER_H_
//---------------------------------------------------------------------------

#include "ButtonsControllerDefines.h"
#include "KeyMatrixButton.h"
#include "ButtonsControllerConsumer.h"
#include "ButtonsController.h"
#include "../BaseTypes/Pin.h"
//---------------------------------------------------------------------------


class KeyMatrixController : public ButtonsController
{
	public:
		KeyMatrixController(void);
		
		void Initialize(uint16_t defaultDelay);
		virtual void ButtonsControllerOnTick(void);
		
		Pin* horizontalPins[KeyMatrixHorizontalCount];
		Pin* verticalPins[KeyMatrixVerticalCount];
		
		KeyMatrixButton matrixButtons[KeyMatrixHorizontalCount][KeyMatrixVerticalCount];
	private:
		
		
};
//---------------------------------------------------------------------------
#endif /* KEYMATRIXCONTROLLER_H_ */