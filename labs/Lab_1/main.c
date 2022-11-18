/*
 * Lab_1.c
 *
 * Created: 9/9/2022 12:23:58 PM
 * Author : Ocean
 */ 

#include <avr/io.h>
#include <math.h>
void second_delay(int sec) 
{ 
	volatile int i,j,k; 
	for (k=0; k<sec; k++) 
	for (i=0; i<500; i++) 
	for (j=0; j<900; j++)
	; 
}

void allLightsOn(){
	 DDRA=0xff;
	 PORTA=0xff;
}

void allLightsBlink(){
	DDRA=0xff;
	PORTA=0xff;
	int i = 0;
	while(i<5){
		if(PORTA == 0x00){
			PORTA = 0xff;
		}

		else if(PORTA == 0xff){
			PORTA = 0x00;
		}
		second_delay(1);
		i++;
	}
}

void select(){
	DDRA=0xff;
	PORTA=0x80;
	second_delay(1); 
	PORTA=0x40; 
	second_delay(1); 
	PORTA=0x20; 
	second_delay(1); 
	PORTA=0x10; 
	second_delay(1); 
	PORTA=0x08; 
	second_delay(1); 
	PORTA=0x04; 
	second_delay(1);
	PORTA=0x02; 
	second_delay(1); 
	PORTA=0x01; 
	second_delay(1);
}

void uneeRandom(int sec){
	DDRA = 0xff;

	volatile int i,j,k;
	
	for (j=0; j<sec; j++)
	{
		PORTA = 0x01 + rand() % 255;
		//char test[4];
		//test[0]='0';test[1]='x';test[2]='f';test[3]='e';test[4]='\0';
		//PORTA= test;
		second_delay(1);
		second_delay(1);
		i ++;
	}
}

void jakRandom(){
	DDRA=0xff;
	int list1[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80} ;
	while(1){
		for(int i = 0 ; i<rand() % 8; i++){
			//list1[i] = 
			PORTA=list1[rand() % 8];
		}

	second_delay(1);
	}
	
}

void onlyRightLeft(){
	DDRA=0xff;
	//while(1){
		PORTA=0x80;
		second_delay(1);
		PORTA=0x40;
		second_delay(1);
		PORTA=0x20;
		second_delay(1);
		PORTA=0x10;
		second_delay(1);
		PORTA=0x08;
		second_delay(1);
		PORTA=0x04;
		second_delay(1);
		PORTA=0x02;
		second_delay(1);
		PORTA=0x01;
		second_delay(1);	
		PORTA=0x02;
		second_delay(1);
		PORTA=0x04;
		second_delay(1);
		PORTA=0x08;
		second_delay(1);
		PORTA=0x10;
		second_delay(1);
		PORTA=0x20;
		second_delay(1);
		PORTA=0x40;	
		second_delay(1);
		PORTA=0x80;
		second_delay(1);
//	}
}

void zma(){
	DDRA=0xff;
	PORTA=0X3B;
}

void random(){
	DDRA=0xff;
	
	PORTA=0x01;
	second_delay(1);
	PORTA=0x03;
	second_delay(1);
	PORTA=0x07;
	second_delay(1);
	PORTA=0x0f;
	second_delay(1);
	PORTA=0x1f;
	second_delay(1);
	PORTA=0x3f;
	second_delay(1);
	PORTA=0x7f;
	second_delay(1);
	PORTA=0xff;
	second_delay(1);
	PORTA=0x7F;
	second_delay(1);
	PORTA=0x3F;
	second_delay(1);
	PORTA=0x1f;
	second_delay(1);
	PORTA=0x0f;
	second_delay(1);
	PORTA=0x07;
	second_delay(1);
	PORTA=0x03;
	second_delay(1);
	PORTA=0x01;
	second_delay(1);
	PORTA=0x00;
	second_delay(1);
	PORTA=0x01;
	second_delay(1);
	PORTA = 0x00;
}

void level1(){
	DDRA=0xff;
	int i;
	for(i=0;i<3;i++){
		
	PORTA=0x01;
	second_delay(1);
	PORTA=0x06;
	second_delay(1);
	PORTA=0x38;
	second_delay(1);
	PORTA=0xc0;
	second_delay(1);
}
}
void level2(){
	DDRA=0xff;
	int i=0;
	for(i;i<3;i++){
	PORTA=0x0b;
	second_delay(1);
	PORTA=0x54;
	second_delay(1);
	PORTA=0xa0	;
	second_delay(1);
	PORTA=0xff;

	}
	
	}
void christmass(){
	DDRA=0xff;
	while(1){
		onlyRightLeft();
		PORTA=0x00;
		second_delay(4);
		level1();
		PORTA=0x00;
		second_delay(4);	
		random();
		PORTA=0x00;
		second_delay(4);
		level2();
		PORTA=0x00;
		second_delay(4);
		uneeRandom(3);
		PORTA=0x00;
		second_delay(4);
		allLightsBlink();
		PORTA=0x00;
		second_delay(4);	
	}
}

int main(void)
{
	/* Replace with your application code */
	//allLightsBlink();
	//allLightsOn();
	//select();
	//random();
	
	//onlyRightLeft();
	//uneeRandom();
	christmass();
	//zma();//
	
}

