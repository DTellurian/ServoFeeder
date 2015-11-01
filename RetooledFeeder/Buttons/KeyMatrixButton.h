/*
 * KeyMatrixButton.h
 *
 * Created: 26.01.2014 12:58:07
 *  Author: Mihalych
 */ 


#ifndef KEYMATRIXBUTTON_H_
#define KEYMATRIXBUTTON_H_
//---------------------------------------------------------------------------

#include "Button.h"
//---------------------------------------------------------------------------

class KeyMatrixButton : public Button
{
	public:	
		KeyMatrixButton(void);					
		void InitializeMatrixButton(ButtonsController* buttonsControllerPtr, uint16_t delayMs);		
		
		friend class KeyMatrixController;
	protected:
		virtual uint8_t IsPressed(void);
		
	private:		
		KeyMatrixButton(const KeyMatrixButton& c);
		KeyMatrixButton& operator=(const KeyMatrixButton& c);
				
		volatile uint8_t isHorizontalPressed;
		volatile uint8_t isVerticalPressed;
};
//---------------------------------------------------------------------------
#endif /* KEYMATRIXBUTTON_H_ */