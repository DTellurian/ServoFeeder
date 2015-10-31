
#include "Lcd.h"
using namespace LcdNamespace;

//namespace LcdNamespace
	
//������� ��� ������ � ������
#define ClearBit(reg, bit)       reg &= (~(1<<(bit)))
#define SetBit(reg, bit)         reg |= (1<<(bit))	

#define FLAG_BF 7
//---------------------------------------------------------------------------

Lcd::Lcd(void)
{
	
}
//---------------------------------------------------------------------------

unsigned char __swap_nibbles(unsigned char data)
{
  asm volatile("swap %0" : "=r" (data) : "0" (data));
  return data;
}
//---------------------------------------------------------------------------

void Lcd::LCD_WriteComInit(unsigned char data)
{
  _delay_us(40);
  ClearBit(PORT_SIG, RS);	
#ifdef BUS_4BIT
  unsigned char tmp; 
  tmp  = PORT_DATA & 0x0f;
  tmp |= (data & 0xf0);
  PORT_DATA = tmp;		 
#else
  PORT_DATA = data;		
#endif  
  SetBit(PORT_SIG, EN);	        
  _delay_us(2);
  ClearBit(PORT_SIG, EN);	
}
//---------------------------------------------------------------------------

void LCD_CommonFunc(unsigned char data)
{
#ifdef BUS_4BIT  
  unsigned char tmp; 
  tmp  = PORT_DATA & 0x0f;
  tmp |= (data & 0xf0);

  PORT_DATA = tmp;		//����� ������� ������� 
  SetBit(PORT_SIG, EN);	        
  _delay_us(2);
  ClearBit(PORT_SIG, EN);	

  data = __swap_nibbles(data);
  tmp  = PORT_DATA & 0x0f;
  tmp |= (data & 0xf0);
 
  PORT_DATA = tmp;		//����� ������� ������� 
  SetBit(PORT_SIG, EN);	        
  _delay_us(2);
  ClearBit(PORT_SIG, EN);	 
#else 
  PORT_DATA = data;		    //����� ������ �� ���� ���������� 
  SetBit(PORT_SIG, EN);	     //��������� E � 1
  _delay_us(2);
  ClearBit(PORT_SIG, EN);	//��������� E � 0 - ������������ �����
#endif
}
//---------------------------------------------------------------------------

void LCD_Wait(void)
{
#ifdef CHECK_FLAG_BF
  #ifdef BUS_4BIT
  
  unsigned char data;
  DDRX_DATA &= 0x0f;            //������������� ���� �� ����
  PORT_DATA |= 0xf0;	        //�������� pull-up ���������
  SetBit(PORT_SIG, RW);         //RW � 1 ������ �� lcd
  ClearBit(PORT_SIG, RS);	//RS � 0 �������
  do{
    SetBit(PORT_SIG, EN);	
    _delay_us(2);
    data = PIN_DATA & 0xf0;      //������ ������ � �����
    ClearBit(PORT_SIG, EN);
    data = __swap_nibbles(data);
    SetBit(PORT_SIG, EN);	
    _delay_us(2);
    data |= PIN_DATA & 0xf0;      //������ ������ � �����
    ClearBit(PORT_SIG, EN);
    data = __swap_nibbles(data);
  }while((data & (1<<FLAG_BF))!= 0 );
  ClearBit(PORT_SIG, RW);
  DDRX_DATA |= 0xf0; 
  
  #else
  unsigned char data;
  DDRX_DATA = 0;                //������������� ���� �� ����
  PORT_DATA = 0xff;	        //�������� pull-up ���������
  SetBit(PORT_SIG, RW);         //RW � 1 ������ �� lcd
  ClearBit(PORT_SIG, RS);	//RS � 0 �������
  do{
    SetBit(PORT_SIG, EN);	
    _delay_us(2);
    data = PIN_DATA;            //������ ������ � �����
    ClearBit(PORT_SIG, EN);	
  }while((data & (1<<FLAG_BF))!= 0 );
  ClearBit(PORT_SIG, RW);
  DDRX_DATA = 0xff; 
  #endif    
#else
  _delay_us(40);
#endif  
}
//---------------------------------------------------------------------------

//������� ������ ������� 
void Lcd::LCD_WriteCom(unsigned char data)
{
  LCD_Wait();
  ClearBit(PORT_SIG, RS);	//��������� RS � 0 - �������
  LCD_CommonFunc(data);
}
//---------------------------------------------------------------------------

//������� ������ ������
void Lcd::LCD_WriteData(unsigned char data)
{
  LCD_Wait();
  SetBit(PORT_SIG, RS);	    //��������� RS � 1 - ������
  LCD_CommonFunc(data);
}
//---------------------------------------------------------------------------

//ooieoey eieoeaeecaoee
void Lcd::LCD_Init(void)
{
#ifdef BUS_4BIT
  DDRX_DATA |= 0xf0;
  PORT_DATA |= 0xf0; 
#else  
  DDRX_DATA |= 0xff;
  PORT_DATA |= 0xff;
#endif
  
  DDRX_SIG |= (1<<RW)|(1<<RS)|(1<<EN);
  PORT_SIG |= (1<<RW)|(1<<RS)|(1<<EN);
  ClearBit(PORT_SIG, RW);
  _delay_ms(40);
  
#ifdef HD44780  
  LCD_WriteComInit(0x30); 
  _delay_ms(10);
  LCD_WriteComInit(0x30);
  _delay_ms(1);
  LCD_WriteComInit(0x30);
#endif
  
#ifdef BUS_4BIT  
  //LCD_WriteComInit(0x20); //4 ��������� ����
  //LCD_WriteCom(0x20); //4-��������� ����, 1 - ������
  
  LCD_WriteComInit(0x28); //4 ��������� ����
  LCD_WriteCom(0x28); //4-��������� ����, 2 - ������    
#else
  LCD_WriteCom(0x38); //8-��������� ����, 2 - ������
  //LCD_WriteCom(0x30); //8-��������� ����, 2 - ������
#endif
  LCD_WriteCom(0x08);
  LCD_WriteCom(0x0c);  //������� ���, ������ � �������� ���������
  LCD_WriteCom(0x01);  //0b00000001 - ������� �������
  _delay_ms(2);
  LCD_WriteCom(0x06);  //0b00000110 - ������ �������� ������, ������ ���
}
//---------------------------------------------------------------------------

//������� ������ ������ �� ���� ������
void Lcd::LCD_SendStringFlash(char *str)
{
  unsigned char data = pgm_read_byte(str);
  while (data)
  {
    LCD_Wait();
    SetBit(PORT_SIG, RS);			
    LCD_CommonFunc(data);
    str++;
    data = pgm_read_byte(str);
  }
}
//---------------------------------------------------------------------------

//������ ������ ������ �� RAM
void Lcd::LCD_SendString(char *str)
{
  unsigned char data;
  int counter = 0;
  SetBit(PORT_SIG, RS);			
  while (*str)
  {
	  /*
    //������� ��� ��� ��������������� ��������
	if(counter == 8)
		LCD_WriteCom(0xc0);
	//�� ����	

	 
    //������� ��� ��� ��������������� ��������
	if(counter == 32)
	LCD_WriteCom(0xc0);
	//�� ����
	*/
	  
	data = *str++;
    LCD_Wait();
    SetBit(PORT_SIG, RS);			
    LCD_CommonFunc(data);

	counter++;
  }
}
//---------------------------------------------------------------------------

void Lcd::LCD_Clear(void)
{
  LCD_WriteCom(0x01);
  _delay_ms(2);
}
//---------------------------------------------------------------------------