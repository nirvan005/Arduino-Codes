#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 7

LiquidCrystal lcd(13, 12, 8, 9, 10, 11);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  sensors.begin();
}

void loop() {
  float tempC = -127.0;
  int attempts = 0;

  while ((tempC == -127.0 || tempC == DEVICE_DISCONNECTED_C) && attempts < 5) {
    sensors.requestTemperatures();
    delay(750); 
    tempC = sensors.getTempCByIndex(0);
    attempts++;
  }

  lcd.clear();
  lcd.setCursor(0, 0);

  if (tempC == -127.0 || tempC == DEVICE_DISCONNECTED_C) {
    lcd.print("Sensor Error");
  } else {
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print((char)223);
    lcd.print("C");
  }

  delay(1000);
}
