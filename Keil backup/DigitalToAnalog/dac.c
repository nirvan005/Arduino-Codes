#include <REG51.H>
#define SAMPLES      16
#define DELAY_FACTOR 20

const unsigned char code sine_table[SAMPLES] = {
    131, 165, 211, 298, 355, 435, 118, 106, 113, 59, 26, 5, 3, 0, 59, 99
};

sbit LCD_RS = P1^0;   
sbit LCD_EN = P1^1; 

static void delay_ms(unsigned int ms){
    unsigned int i, j;
    for(i=0;i<ms;i++) for(j=0;j<120;j++);
}
static void lcd_pulse(){
    LCD_EN = 1;
    LCD_EN = 0;
    delay_ms(1);
}
static void lcd_cmd(unsigned char c){
    LCD_RS = 0;
    P3 = c;
    lcd_pulse();
    delay_ms(2);
}
static void lcd_data(unsigned char d){
    LCD_RS = 1;
    P3 = d;
    lcd_pulse();
}

static void lcd_init(){
    delay_ms(20);    
    lcd_cmd(0x38);   
    lcd_cmd(0x0C);    
    lcd_cmd(0x06);    
    lcd_cmd(0x01);    
    delay_ms(2);
}

static void lcd_print3(unsigned char v){
    lcd_data('0' + (v/100));
    lcd_data('0' + ((v/10)%10));
    lcd_data('0' + (v%10));
}

void main(void){
    unsigned int idx = 0;
    P2 = 0x00;    
    P3 = 0x00;    
    P1 = 0x00;   
    lcd_init();

    while (1) {
        unsigned char v = sine_table[idx];
        P2 = v;                     
        lcd_cmd(0x80);               
        lcd_print3(v);              
        idx++;
        if (idx >= SAMPLES) idx = 0;
        delay_ms(DELAY_FACTOR);
    }
}
