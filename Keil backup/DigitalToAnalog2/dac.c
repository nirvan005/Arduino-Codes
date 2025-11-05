#include <REG51.H>
typedef unsigned char u8;
typedef unsigned int  u16;

/* LCD control on P1 */
sbit LCD_RS = P1^0;
sbit LCD_EN = P1^1;

/* LCD data bus on P3 (8-bit) */
static void delay_ms(u16 ms){
    volatile u16 i,j; for(i=0;i<ms;i++) for(j=0;j<120;j++);
}
static void pulse_en(){ LCD_EN = 1; LCD_EN = 0; delay_ms(1); }
static void lcd_cmd(u8 c){ LCD_RS = 0; P3 = c; pulse_en(); delay_ms(2); }
static void lcd_data(u8 d){ LCD_RS = 1; P3 = d; pulse_en(); }

static void lcd_init(){
    delay_ms(20);
    lcd_cmd(0x38);   
    lcd_cmd(0x0C);   
    lcd_cmd(0x06);  
    lcd_cmd(0x01);  
    delay_ms(2);
}

#define SAMPLES 16
#define DELAY_FACTOR 20
const u8 code sine_table[SAMPLES] = {
    128,176,218,245,255,245,218,176,128,79,37,10,0,10,37,79
};

static void lcd_print3(u8 v){
    lcd_data('0' + (v/100));
    lcd_data('0' + ((v/10)%10));
    lcd_data('0' + (v%10));
}

void main(void){
    u8 i = 0;
    P1 = 0x00;   
    P3 = 0x00;  
    P2 = 0x00;  
    lcd_init();

    while(1){
        P2 = sine_table[i];   
        lcd_cmd(0x80);          
        lcd_print3(sine_table[i]);
        i++; if(i>=SAMPLES) i=0;
        delay_ms(DELAY_FACTOR);
    }
}
