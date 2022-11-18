/*
 * Lab_4.c
 *
 * Created: 10/21/2022 12:01:33 PM
 * Author : Ocean
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void selectRL();
void selectLR();
void selectlr();
void selectrl();
void check();

void test(){
	DDRA=0xff;
	DDRE=0x00;
	while (1)
	{
		if((PINE & 0x10)==0x00)
		PORTA=0x80;
		else if((PINE & 0x20)==0x00)
		PORTA=0x01;
		else
		PORTA=0x00;
	}
}

void selectlr(){
	while(1){
		PORTA=0x80;
		_delay_ms(5000);
		PORTA=0x40;
		_delay_ms(5000);
		PORTA=0x20;
		_delay_ms(5000);
		PORTA=0x10;
		_delay_ms(5000);
		PORTA=0x08;
		_delay_ms(5000);
		PORTA=0x04;
		_delay_ms(5000);
		PORTA=0x02;
		_delay_ms(5000);
		PORTA=0x01;
		_delay_ms(5000);
	}
}

void selectrl(){
	while(1){
		PORTA=0x01;
		_delay_ms(5000);
		PORTA=0x02;
		_delay_ms(5000);
		PORTA=0x04;
		_delay_ms(5000);
		PORTA=0x08;
		_delay_ms(5000);
		PORTA=0x10;
		_delay_ms(5000);
		PORTA=0x20;
		_delay_ms(5000);
		PORTA=0x40;
		_delay_ms(5000);
		PORTA=0x80;
		_delay_ms(5000);
	}
}

void selectLR(){
	while(1){
		PORTA=0x80;
		check();
		_delay_ms(5000);
		PORTA=0x40;
		check();
		_delay_ms(5000);
		PORTA=0x20;
		check();
		_delay_ms(5000);
		PORTA=0x10;
		check();
		_delay_ms(5000);
		PORTA=0x08;
		check();
		_delay_ms(5000);
		PORTA=0x04;
		check();
		_delay_ms(5000);
		PORTA=0x02;
		check();
		_delay_ms(5000);
		PORTA=0x01;
		check();
		_delay_ms(5000);
	}
}

void selectRL(){
	while(1){
		PORTA=0x01;
		check();
		_delay_ms(5000);
		PORTA=0x02;
		check();
		_delay_ms(5000);
		PORTA=0x04;
		check();
		_delay_ms(5000);
		PORTA=0x08;
		check();
		_delay_ms(5000);
		PORTA=0x10;
		check();
		_delay_ms(5000);
		PORTA=0x20;
		check();
		_delay_ms(5000);
		PORTA=0x40;
		check();
		_delay_ms(5000);
		PORTA=0x80;
		check();
		_delay_ms(5000);
	}
}

void check(){
	if((PINE & 0x10)==0x00){
		selectrl();
	}
	else if((PINE & 0x20)==0x00){
		selectlr();
	}
}

void daalgawar(){
	DDRA=0xff;
	DDRE=0x00;
	int turn = 0;
	while (1)
	{
		if((PINE & 0x10)==0x00){
			
		}
		else if((PINE & 0x20)==0x00){
			while(1){
				PORTA=0x03;
				_delay_ms(500);
				PORTA=0x07;
				_delay_ms(500);
			}
		}
		else
			PORTA=0x00;
	}
}

const int P[9] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
int eff = 0;

void delay_ms(int ms)
{
	volatile int i,j;
	for (i=0; i<ms; i++)
	for (j=0; j<1000; j++)
	if((PINE & 0x10)==0x00) {
		eff = 1;
	}
	else if((PINE & 0x20)==0x00) {
		eff = 2;
	}
}

void da1()
{
	DDRA=0xff;
	DDRE=0x00;
	int n = 0;
	while (1) {
		// Tulhuur
		if((PINE & 0x10)==0x00)
		eff = 1;
		else if((PINE & 0x20)==0x00)
		eff = 2;
		switch (eff) {
			case 1:
			// Snake
			PORTA = P[0];
			for (int j=1; j<=8; j++) {
				int a = j;
				int b = j+1;
				int c = j+2;
				if (b > 8)
				b -= 8;
				if (c >8)
				c -= 8;
				PORTA = P[a] + P[b] + P[c];
				delay_ms(300);
				if(eff != 1)
				break;
			}
			break;
			case 2:
			// Blink
			PORTA = P[0];
			for (int i=1; i<=8; i++) {
				if (n%2 == i%2)
				PORTA += P[i];
			}
			delay_ms(300);
			n++;
			break;
		}
	}
}
int tas=0;
void delay_sec(int sec)
{
	volatile int i,j,k;
	for (k=0; k<sec; k++)
	for (i=0; i<2000; i++)
	for (j=0; j<90; j++);
}

ISR(INT4_vect)
{
	tas=1;
}
ISR(INT5_vect)
{
	tas=2;
}
void tasal(){
	DDRA=0xff;
	DDRE=0x00;
	SREG =0x80;
	EIMSK=0x30;
	EICRB=0x00;
	for(;;){
		if(tas==1){
			if(PORTA>=128){
				PORTA = 0x0f;
				}else{
				PORTA = 0xf0;
			}
		}
		if(tas==2){
			if(PORTA<=1){
				PORTA = 3;
				}else{
				PORTA *=4;
			}
		}
		delay_sec(1);
	}
}

int main()
{
	//test();
	//tasaldal();
	//daalgawar();
	//tasaldal();
	//da1();
	tasal();
}

