#include <LiquidCrystal.h>
//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  //lcd.init();
  //lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World! Welcome to the SparkHub Series 2026. ");
}

void loop() {
  lcd.scrollDisplayLeft();
  //lcd.scrollDisplayRight();
  delay(400); // Controlling the "Speed" of the scroll
}