#include<LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd(13,12,8,9,10,11);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  dht.begin();

}

void loop() {
  lcd.setCursor(0,0);
  float humidity=dht.readHumidity();
  float temp=dht.readTemperature();

  if(isnan(humidity) || isnan(temp))
    lcd.print("Sensor Error");
  else{
    lcd.print("T: ");
    lcd.print(temp);
    lcd.print((char)223);
    lcd.print("C           ");
    lcd.setCursor(0,1);
    lcd.print("H: ");
    lcd.print(humidity);
    lcd.print("           ");
  }
}