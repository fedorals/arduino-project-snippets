#include "pins_arduino.h"
#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

DHT dht(4, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.print("Booting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  const float dhtTemperature = dht.readTemperature();
  const float humidity = dht.readHumidity();
  const float lm35Voltage = analogRead(A1) * 5.0f / 1023.0f;
  const float lm35Temperature = lm35Voltage * 100.0f;

  lcd.setCursor(0, 0);
  if (isnan(dhtTemperature) || isnan(humidity)) {
    lcd.print("DHT error");
  } else {
    lcd.print("DHT:");
    lcd.print(dhtTemperature, 1);
    lcd.print((char)223);
    lcd.print("C ");
    lcd.print(humidity, 0);
    lcd.print("%");
  }

  lcd.setCursor(0, 1);
  lcd.print("LM35:");
  lcd.print(lm35Temperature, 1);
  lcd.print((char)223);
  lcd.print("C");

  delay(2000);
}