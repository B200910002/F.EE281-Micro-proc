/*
 * Lab_3.c
 *
 * Created: 10/4/2022 12:25:31 PM
 * Author : Ocean
 */ 

#include <avr/io.h>
#include <util/delay.h>

void test(){
	DDRC=0xff;
	DDRG=0x0f; 
	PORTC=0x07; 
	PORTG=0x01; 
}

void test2(){
	DDRC=0xff; 
	DDRG=0x0f; 
	while (1) 
	{ 
		PORTC=0x06;
		PORTG=0x08; 
		_delay_ms(5);
		PORTC=0x5B; 
		PORTG=0x04;
		_delay_ms(5);
		PORTC=0x4F; 
		PORTG=0x02; 
		_delay_ms(5);
		PORTC=0x66; 
		PORTG=0x01; 
		_delay_ms(5);
	}
}

void phoneNumber(){
	char tel_num[20] = {0x00, 0x00, 0x00, 0x00,
						0x6f, 0x6d, 0x6d, 0x06, 
						0x5b, 0x6f, 0x06, 0x06, 
						0x00, 0x00, 0x00, 0x00,   
						};
	DDRC=0xff; 
	DDRG=0x0f; 
	while (1) {
		for(int i=0; i<12; i++) { 
			for(int j=0; j<50; j++) {
				PORTC=tel_num[i]; PORTG=0x08; _delay_ms(50);
				PORTC=tel_num[i+1]; PORTG=0x04; _delay_ms(50);
				PORTC=tel_num[i+2]; PORTG=0x02; _delay_ms(50);
				PORTC=tel_num[i+3]; PORTG=0x01; _delay_ms(50);
			}
		}
	}
}

void helpMe(){
	char tel_num[20] = {0x00, 0x00, 0x00, 0x00,
						0x76, 0x79, 0x38, 0x73, 			//H - 01110110 - 76 
						0x00, 0x00,						    //M - 00110011 00100111  - 33 27  
 						0x33, 0x27,0x79,0x00};							//E - 01111001 - f9 
															//L - 00111000 - 38	
															//p - 01110011 - 73
	DDRC=0xff;
	DDRG=0x0f;
	while (1) {
		for(int i=0; i<12; i++) {
			for(int j=0; j<50; j++) {
				PORTC=tel_num[i]; PORTG=0x08; _delay_ms(50);
				PORTC=tel_num[i+1]; PORTG=0x04; _delay_ms(50);
				PORTC=tel_num[i+2]; PORTG=0x02; _delay_ms(50);
				PORTC=tel_num[i+3]; PORTG=0x01; _delay_ms(50);
			}
		}
	}
}
void blink(){
	char tel_num[26] = {0x00, 0x00, 0x00, 0x00,
						0x6f, 0x6d, 0x6d, 0x06,
						0x5b, 0x6f, 0x06,0x06,
						0x00, 0x00, 0x00, 0x00,
						0x76, 0x79, 0x38, 0x73, 		
						0x00,						    
						0x33, 0x27, 0x79, 0x00
	};
	DDRC=0xff;
	DDRG=0x0f;
	while (1) {
		for(int i=0; i<23; i++) {
			for(int j=0; j<1000; j++) {
				PORTC=tel_num[i]; PORTG=0x08; _delay_ms(1);
				PORTC=tel_num[i+1]; PORTG=0x04; _delay_ms(1);
				PORTC=tel_num[i+2]; PORTG=0x02; _delay_ms(1);
				PORTC=tel_num[i+3]; PORTG=0x01; _delay_ms(1);
			}
			
		}
	}
}

int main(void)
{
	//test();
	//test2();
	//phoneNumber();
	//helpMe();
	blink();
}
