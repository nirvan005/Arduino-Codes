#include<LiquidCrystal.h>
#define LDR A0

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd(13,12,8,9,10,11);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  // Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0,0);
  int val=analogRead(LDR);
  lcd.print(val);
  lcd.print("             ");
  Serial.println(val);
  // delay(1000);
}