#include<LiquidCrystal.h>
const int sensorPin=A0;
float temp;
int sensorVal;

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd(13,12,8,9,10,11);


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  sensorVal=analogRead(sensorPin);
  float volt=sensorVal*(5.0/1023.0);
  temp=volt*100;
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");
  lcd.print("      ");
}