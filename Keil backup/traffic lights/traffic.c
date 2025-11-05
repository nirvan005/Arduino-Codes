#include<reg51.h>
sbit red_led=P2^0;
sbit yellow_led=P2^1;
sbit green_led=P2^2;
void delay(unsigned int time){
	int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}		
}
int main(){
	while(1){
		red_led=1;
		yellow_led=0;
		green_led=0;
		delay(100);

		red_led=0;
		yellow_led=1;
		green_led=0;
		delay(100);
		
		red_led=0;
		yellow_led=0;
		green_led=1;
		delay(100);
	}
	return 0;
}