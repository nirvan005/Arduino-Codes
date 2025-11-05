#include<LiquidCrystal.h>
const int analogPin = A0;

const float thresholdV = 2.5;
const int refVoltage = 5;
const float range = 1023.0;
float prevAnalogVal = -1.0;

LiquidCrystal lcd(13,12,8,9,10,11);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  int rawVal = analogRead(analogPin);
  float curAnalogVal = (rawVal / range) * refVoltage;

  if (curAnalogVal != prevAnalogVal) {
    lcd.setCursor(0,0);
    lcd.clear();
    if (curAnalogVal < 2.45) {
      lcd.print("South Pole");
      lcd.setCursor(0,1);
      lcd.print("value: ");
      lcd.print(curAnalogVal);
      lcd.print(" V");
    } else if (curAnalogVal > 2.55) {
      lcd.print("North Pole");
      lcd.setCursor(0,1);
      lcd.print("value: ");
      lcd.print(curAnalogVal);
      lcd.print(" V");
    } else {
      lcd.print("No Magnet");
      lcd.setCursor(0,1);
      lcd.print("value: ");
      lcd.print(curAnalogVal);
      lcd.print(" V");
    }
    prevAnalogVal = curAnalogVal;
  }
  delay(100);
}