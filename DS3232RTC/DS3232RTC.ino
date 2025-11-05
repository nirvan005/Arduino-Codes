#include<LiquidCrystal.h>
#include<RTClib.h>

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd(13,12,8,9,10,11);
RTC_DS3231 rtc;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  if (! rtc.begin()) {
    lcd.print("RTC not found!");
    while (1);
  }

  rtc.adjust(DateTime(2025,11,04,22,41,0));
}

void loop() {
  lcd.setCursor(0,0);
  DateTime now=rtc.now();

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
  
  lcd.print(":");
  
  if(now.month()<10)
    lcd.print("0");
  lcd.print(now.month());
  
  lcd.print(":");
  
  if(now.year()<10)
    lcd.print("0");
  lcd.print(now.year());
}