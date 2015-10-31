/*
 * LcdDefines.h
 *
 * Created: 05.06.2014 12:56:34
 *  Author: Mihalych
 */ 


#ifndef LCDDEFINES_H_
#define LCDDEFINES_H_
//---------------------------------------------------------------------------


//���� � �������� ���������� ���� ������ ���
#define PORT_DATA PORTD
#define PIN_DATA  PIND
#define DDRX_DATA DDRD

//���� � �������� ���������� ����������� ������ ���
#define PORT_SIG PORTB
#define PIN_SIG  PINB
#define DDRX_SIG DDRB

//������ ������� � ������� ���������� ����������� ������ ���
#define RS 1
#define RW 2
#define EN 3

//#define CHECK_FLAG_BF
#define BUS_4BIT
//#define HD44780
//******************************************************************************

//---------------------------------------------------------------------------
#endif /* LCDDEFINES_H_ */