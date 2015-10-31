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

Port portC(&DDRC, &PORTC, &PINC);
Pin pinC0(&portC, DDC0, PINC0);
Pin pinC1(&portC, DDC1, PINC1);
Pin pinC2(&portC, DDC2, PINC2);
Pin pinC3(&portC, DDC3, PINC3);
Pin pinC4(&portC, DDC4, PINC4);
Pin pinC5(&portC, DDC5, PINC5);
Pin pinC6(&portC, DDC6, PINC6);
Pin pinC7(&portC, DDC7, PINC7);

Port portD(&DDRD, &PORTD, &PIND);
Pin pinD0(&portD, DDD0, PIND0);
Pin pinD1(&portD, DDD1, PIND1);
Pin pinD2(&portD, DDD2, PIND2);
Pin pinD3(&portD, DDD3, PIND3);
Pin pinD4(&portD, DDD4, PIND4);
Pin pinD5(&portD, DDD5, PIND5);
Pin pinD6(&portD, DDD6, PIND6);
Pin pinD7(&portD, DDD7, PIND7);

Port portB(&DDRB, &PORTB, &PINB);
Pin pinB0(&portB, DDB0, PINB0);
Pin pinB1(&portB, DDB1, PINB1);
Pin pinB2(&portB, DDB2, PINB2);
Pin pinB3(&portB, DDB3, PINB3);
Pin pinB4(&portB, DDB4, PINB4);
Pin pinB5(&portB, DDB5, PINB5);
Pin pinB6(&portB, DDB6, PINB6);
Pin pinB7(&portB, DDB7, PINB7);


Port portA(&DDRA, &PORTA, &PINA);
Pin pinA0(&portA, DDA0, PINA0);
Pin pinA1(&portA, DDA1, PINA1);
Pin pinA2(&portA, DDA2, PINA2);
Pin pinA3(&portA, DDA3, PINA3);
Pin pinA4(&portA, DDA4, PINA4);
Pin pinA5(&portA, DDA5, PINA5);
Pin pinA6(&portA, DDA6, PINA6);
Pin pinA7(&portA, DDA7, PINA7);

//---------------------------------------------------------------------------