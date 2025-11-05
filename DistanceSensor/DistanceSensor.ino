#include<LiquidCrystal.h>
#define TRIG 2
#define ECHO 3

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd(13,12,8,9,10,11);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  delay(500);
}

void loop() {
  lcd.setCursor(0,0);
  digitalWrite(TRIG,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration=pulseIn(ECHO, HIGH,30000);
  float dist=duration/58.0;
  lcd.print("Dist: ");
  lcd.print(dist);
  lcd.print(" cm");
  lcd.print("           ");

}