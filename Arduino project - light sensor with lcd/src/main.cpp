//this project is a simple light sensor with an LCD display,
//the display is connected to the arduino via I2C, its a simple 16x2 display
//make sure to change the parameters of the display, or even change the architecture of the display
//further instructions and explanations are in the readme file(if one even exists, i hope i wasnt lazy and made one)
//i also wish you goodluck if you want to upgrade, update or otpimize this code
//what did you eat for lunch? me personally i ate a sandwich, drank some water, white monster, ultra zero
//and basically nothing for the rest of the day, but i hope you had a great lunch
//at the same time, i think realizing youre nobodies tru best or closest friend is one
//of the most painful things to realize, me personally i feel ignored or neglected
//and hope that C++ will relieve me from it
//i also feel like i mean basically nothing to anyone, and theres noone i can relate to
//good luck, even if this code is simple
  

#include <Arduino.h>

 #include <LiquidCrystal_I2C.h>

 const uint8_t lightSensorPin = A1;
 LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
	 lcd.init();
	 lcd.backlight();
	 lcd.print("Light sensor");
	 delay(1000);
	 lcd.clear();
}

void loop() {
	 const int lightLevel = analogRead(lightSensorPin);
	 const int lightPercent = map(lightLevel, 0, 1023, 0, 100);

	 lcd.setCursor(0, 0);
	 lcd.print("Raw: ");
	 lcd.print(lightLevel);
	 lcd.print("    ");

	 lcd.setCursor(0, 1);
	 lcd.print("Level: ");
	 lcd.print(lightPercent);
	 lcd.print("%     ");

	 delay(250);
}
