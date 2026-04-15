#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// (If 0x27 doesn't work, try 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();         // Initialize the LCD
  lcd.backlight();    // Turn on the backlight (the blue light)
  
  // Rule of Zero: Column 0, Row 0 is the top left
  lcd.setCursor(0, 0); 
  lcd.print("Hello SparkHub!");
  
  lcd.setCursor(0, 1); // Move to the second row
  lcd.print("MRC Series 2026");
}

void loop() {
  // We can make things blink!
  // lcd.setCursor(14, 1);
  // lcd.print("OK");
  // delay(500);
  // lcd.setCursor(14, 1);
  // lcd.print("  ");
  // delay(500);
}