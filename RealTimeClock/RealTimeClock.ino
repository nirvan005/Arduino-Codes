#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
RTC_DS1307 rtc;

void setup() {
  lcd.begin(16, 2);
  Wire.begin();
  rtc.begin();
  lcd.print("DS1307 Clock");
  delay(2000);
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  if (now.hour() < 10) lcd.print('0');
  lcd.print(now.hour());
  lcd.print(':');
  if (now.minute() < 10) lcd.print('0');
  lcd.print(now.minute());
  lcd.print(':');
  if (now.second() < 10) lcd.print('0');
  lcd.print(now.second());

  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  if (now.day() < 10) lcd.print('0');
  lcd.print(now.day());
  lcd.print('/');
  if (now.month() < 10) lcd.print('0');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());

  delay(1000);
}