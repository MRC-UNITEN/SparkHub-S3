// #include <Wire.h> 
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // lcd.init();
  // lcd.backlight();
  lcd.print("Blinking Cursor:");
  
  // Turn on the blinking block cursor
  lcd.setCursor(0, 1);
  lcd.blink(); 
}

void loop() {
  // Nothing needed here for a static blink
}