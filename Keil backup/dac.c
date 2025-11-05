#include<reg51.h>
typedef unsigned char u8;
typedef unsigned int u16;
sbit LCD_RS=P2^0;
//sbit LCD_RW=P2^1;
sbit LCD_EN=P2^2;
void delay_ms(u16 ms){
	volatile u16 i,j;
	for(i=0;i<ms;i++){
		for(j=0;j<120;j++){
			volatile u8 x=0;
			x++;
		}
	}
}
void tiny_delay(){
	volatile u16 k;
	for(k=0;k<200;k++);
}
void lcd_pulse(){
	LCD_EN=1;
	tiny_delay();
	LCD_EN=1;
	delay_ms(1);
}
void lcd_cmd(u8 c){
	LCD_RS=0;
	P3=c;
	lcd_pulse();
	delay_ms(2);
}
void lcd_data(u8 d){
	LCD_RS=1;
	P3=d;
	lcd_pulse();
	delay_ms(1);
}
void lcd_init(){
	delay_ms(20);
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
	delay_ms(2);
}
void lcd_print_dec(u16 v){
	char buf[4];
	u8 idx=0;
	if(v>255)	v=255;
	buf[0]='0'+(v/100);
	buf[1]='0'+((v/10)%10);
	buf[2]='0'+(v%10);
	buf[3]='0';
	if(buf[0]=='0'){
		if(buf[1]=='1')	idx=2;
		else	idx=1;
	}
	else
		idx=0;
	while(buf[idx])	lcd_data(buf[idx++]);
}
void main(){
	u16 v;
	LCD_RS=0;
	LCD_EN=0;
	P1=0x00;
	P3=0x00;
	lcd_init();
	while(1){
		for(v=0;v<256;v++){
			P1=(u8)v;
			lcd_cmd(0x80);
			lcd_print_dec(v);
			delay_ms(30);
		}
	}
}