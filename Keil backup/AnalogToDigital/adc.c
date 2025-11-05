#include<reg51.h>
sfr mydata=0x90;
sbit rd=P2^5;
sbit wr=P2^6;
sbit intr=P2^7;
sbit RS=P2^0;
sbit EN=P2^2;
void delay(unsigned int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}
void lcd_cmd(unsigned char cmd){
	P3=cmd;
	RS=0;
	EN=1;
	delay(10);
	EN=0;
}
void lcd_data(unsigned char dat){
	P3=dat;
	RS=1;
	EN=1;
	delay(10);
	EN=0;
}
void display(char *ptr){
	while(*ptr!='\0'){
		lcd_data(*ptr);
		ptr++;
	}
}
void main(){
	unsigned char value;
	char temp[4];
	unsigned int i=0;
	lcd_cmd(0x01);
	lcd_cmd(0x0E);
	lcd_cmd(0x38);
	lcd_cmd(0x80);
	display("ADC = ");
	lcd_cmd(0xC0);
	intr=1;
	rd=1;
	wr=1;
	while(1){
		lcd_cmd(0xC0);
		wr=0;
		wr=1;
		while(intr==1);
		rd=0;
		value=mydata;
		rd=1;
		i=0;
		while(i<3){
			temp[i]= (value%10) + '0';
			value=value/10;
			i++;
		}
		for(i=2;i>=0;i--){
			lcd_cmd(0x06);
			lcd_data(temp[i]);
		}
		i=0;
		delay(1000);
		rd=1;
	}
}