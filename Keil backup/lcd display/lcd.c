#include<reg51.h>
#define LCD_PORT P3
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;
void delay(unsigned int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}
void lcd_cmd(unsigned char cmd){
	LCD_PORT=cmd;
	RS=0;
	RW=0;
	E=1;
	delay(1);
	E=0;
	delay(2);
}
void lcd_init(){
	delay(20);
	lcd_cmd(0x38);
	delay(5);
	lcd_cmd(0x38);
	delay(1);
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
	delay(2);
}
void lcd_data(unsigned char dat){
	LCD_PORT=dat;
	RS=1;
	RW=0;
	E=1;
	delay(1);
	E=0;
	delay(2);
}

void lcd_string(unsigned char *str){
	unsigned int i;
	for(i=0;str[i]!='\0';i++){
		lcd_data(str[i]);
	}
}
int main(){
	lcd_init();
	lcd_string("Hello World");
	lcd_cmd(0xC0);
	lcd_string("Bye World");
	while(1);
	return 0;
}