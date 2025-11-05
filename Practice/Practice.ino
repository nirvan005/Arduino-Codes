#include<LiquidCrystal.h>
#include<RTClib.h>

RTC_DS1307 rtc;

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd(13,12,8,9,10,11);



void setup() {
  rtc.begin();
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  DateTime now=rtc.now();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  if(now.hour()<10)
    lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");
  if(now.minute()<10)
    lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");
  if(now.second()<10)
    lcd.print("0");
  lcd.print(now.second());
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  if(now.day()<10)
    lcd.print("0");
  lcd.print(now.day());
  lcd.print("/");
  if(now.month()<10)
    lcd.print("0");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());
}