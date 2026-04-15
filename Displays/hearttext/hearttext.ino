#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Custom Heart Icon (1 = pixel on, 0 = pixel off)
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup() {
  lcd.init();
  lcd.backlight();

  // Create the character and store it in "Slot 0"
  lcd.createChar(0, heart);
  lcd.setCursor(0, 0);
  lcd.print("I ");
  
  // Write the custom character from Slot 0
  lcd.write(0); 
  
  lcd.print(" MRC Robots!");
}

void loop() {}