#include<reg51.h>							// header file
sbit LED = P2^0;					// p2^0 is the port number of led

void delay(unsigned int time) {
	int i,j;
	for(i=0; i<time; i++) {    	// outloop for time interval between blink
			for(j=0; j<1275; j++); 	// approx 1ms delay for 11.0592Mhz  1275 blinking speed larger the value more blinking frequency
	}
}

void main() {
	while(1) {
		LED = 0;
		delay(100);
		LED = 1;
		delay(100);
	}
}