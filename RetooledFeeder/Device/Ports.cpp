/* 
* Ports.cpp
*
* Created: 05.06.2014 12:34:31
* Author: Mihalych
*/


//---------------------------------------------------------------------------

#include "Ports.h"
#include <avr/io.h>
//---------------------------------------------------------------------------

Port portC = Port(&DDRC, &PORTC, &PINC);
Pin pinC0 = Pin(&portC, DDC0, PINC0);
Pin pinC1 = Pin(&portC, DDC1, PINC1);
Pin pinC2 = Pin(&portC, DDC2, PINC2);
Pin pinC3 = Pin(&portC, DDC3, PINC3);
Pin pinC4 = Pin(&portC, DDC4, PINC4);
Pin pinC5 = Pin(&portC, DDC5, PINC5);
Pin pinC6 = Pin(&portC, DDC6, PINC6);
Pin pinC7 = Pin(&portC, DDC7, PINC7);

Port portD = Port(&DDRD, &PORTD, &PIND);
Pin pinD0 = Pin(&portD, DDD0, PIND0);
Pin pinD1 = Pin(&portD, DDD1, PIND1);
Pin pinD2 = Pin(&portD, DDD2, PIND2);
Pin pinD3 = Pin(&portD, DDD3, PIND3);
Pin pinD4 = Pin(&portD, DDD4, PIND4);
Pin pinD5 = Pin(&portD, DDD5, PIND5);
Pin pinD6 = Pin(&portD, DDD6, PIND6);
Pin pinD7 = Pin(&portD, DDD7, PIND7);

Port portA = Port(&DDRA, &PORTA, &PINA);
Pin pinA0 = Pin(&portA, DDA0, PINA0);
Pin pinA1 = Pin(&portA, DDA1, PINA1);
Pin pinA2 = Pin(&portA, DDA2, PINA2);
Pin pinA3 = Pin(&portA, DDA3, PINA3);
Pin pinA4 = Pin(&portA, DDA4, PINA4);
Pin pinA5 = Pin(&portA, DDA5, PINA5);
Pin pinA6 = Pin(&portA, DDA6, PINA6);
Pin pinA7 = Pin(&portA, DDA7, PINA7);

Port portB = Port(&DDRB, &PORTB, &PINB);
Pin pinB0 = Pin(&portB, DDB0, PINB0);
Pin pinB1 = Pin(&portB, DDB1, PINB1);
Pin pinB2 = Pin(&portB, DDB2, PINB2);
Pin pinB3 = Pin(&portB, DDB3, PINB3);
Pin pinB4 = Pin(&portB, DDB4, PINB4);
Pin pinB5 = Pin(&portB, DDB5, PINB5);
Pin pinB6 = Pin(&portB, DDB6, PINB6);
Pin pinB7 = Pin(&portB, DDB7, PINB7);
//---------------------------------------------------------------------------