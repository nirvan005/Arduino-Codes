#include<reg51.h>
#define LCD P3
#define DAC P1
#define SAMPLES 256

sbit RS=P2^0;
sbit E=P2^1;

unsigned char code sine[SAMPLES]={128, 131, 134, 137, 140, 144, 147, 150, 153, 156, 159, 162, 165, 168, 171, 174,
177, 180, 183, 186, 188, 191, 194, 197, 199, 202, 204, 207, 209, 212, 214, 216,
219, 221, 223, 225, 227, 229, 231, 233, 234, 236, 238, 239, 241, 242, 244, 245,
246, 248, 249, 250, 250, 251, 252, 253, 253, 254, 254, 254, 255, 255, 255, 255,
255, 255, 255, 254, 254, 254, 253, 253, 252, 251, 250, 250, 249, 248, 246, 245,
244, 242, 241, 239, 238, 236, 234, 233, 231, 229, 227, 225, 223, 221, 219, 216,
214, 212, 209, 207, 204, 202, 199, 197, 194, 191, 188, 186, 183, 180, 177, 174,
171, 168, 165, 162, 159, 156, 153, 150, 147, 144, 140, 137, 134, 131, 128, 125,
122, 119, 116, 113, 110, 107, 104, 101, 99, 96, 93, 91, 88, 86, 83, 81,
79, 77, 74, 72, 70, 68, 66, 64, 63, 61, 59, 58, 56, 55, 53, 52,
51, 49, 48, 47, 47, 46, 45, 44, 44, 43, 43, 43, 42, 42, 42, 42,
42, 42, 42, 43, 43, 43, 44, 44, 45, 46, 47, 47, 48, 49, 51, 52,
53, 55, 56, 58, 59, 61, 63, 64, 66, 68, 70, 72, 74, 77, 79, 81,
83, 86, 88, 91, 93, 96, 99,100,103,106,109,112,116,119,122,125};

void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char cmd){
	RS=0;
	LCD=cmd;
	E=1;
	delay(1);
	E=0;
	delay(2);
}

void lcd_init(){
	delay(20);
	
	lcd_cmd(0x38);
	delay(2);
	
	lcd_cmd(0x0C);
	delay(2);
	
	lcd_cmd(0x06);
	delay(2);
	
	lcd_cmd(0x01);
	delay(10);
	
	lcd_cmd(0x80);
	delay(20);
}

void lcd_data(unsigned char dat){
	RS=1;
	LCD=dat;
	E=1;
	delay(1);
	E=0;
	delay(2);
}

void lcd_string(unsigned char* str){
	unsigned int i;
	for(i=0;str[i]!='\0';i++){
		lcd_data(str[i]);
	}
}

void lcd_print(unsigned char val){
	lcd_data((val/100)+'0');
	lcd_data(((val/10)%10)+'0');
	lcd_data((val%10)+'0');
}

void main(){
	unsigned int idx=0;
	P3=0X00;
	P1=0X00;
	P2=0X00;
	lcd_init();
	lcd_string("DAC Converter");
	delay(200);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	while(1){
		unsigned char v=sine[idx];
		DAC=v;
		lcd_cmd(0x80);
		lcd_print(v);
		idx++;
		delay(20);
		if(idx>=SAMPLES)	idx=0;
	}
}