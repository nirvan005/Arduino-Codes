#include<reg51.h>
sbit red_led1=P2^0;
sbit yellow_led1=P2^1;
sbit green_led1=P2^2;

sbit red_led2=P2^3;
sbit yellow_led2=P2^4;
sbit green_led2=P2^5;

sbit red_led3=P3^0;
sbit yellow_led3=P3^1;
sbit green_led3=P3^2;

void delay(unsigned int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}		
}
int main(){
	while(1){
		red_led1=0;
		yellow_led1=0;
		green_led1=1;
		red_led2=1;
		yellow_led2=0;
		green_led2=0;
		red_led3=1;
		yellow_led3=0;
		green_led3=0;
		delay(200);
		
		red_led2=0;
		yellow_led2=1;
		green_led2=0;
		delay(200);
		
		red_led1=1;
		yellow_led1=0;
		green_led1=0;
		red_led2=0;
		yellow_led2=0;
		green_led2=1;
		delay(200);
		
		red_led3=0;
		yellow_led3=1;
		green_led3=0;
		delay(200);
		
		red_led3=0;
		yellow_led3=0;
		green_led3=1;
		red_led2=1;
		yellow_led2=0;
		green_led2=0;
		red_led1=0;
		yellow_led1=1;
		green_led1=0;
		delay(200);
	}
	return 0;
}