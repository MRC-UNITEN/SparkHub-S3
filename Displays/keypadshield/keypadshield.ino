#include <LiquidCrystal.h>

// These are the pins used by the shield's hard-wired design
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello SparkHub!");
  lcd.setCursor(0, 1); // Move to the second row
  lcd.print("MRC Series 2026");
}

void loop() {
  // int x = analogRead(A0); // Read the value from the buttons
  
  // lcd.setCursor(0, 1); // Move to the bottom row

  // // Button logic based on voltage ranges
  // if (x < 60) {
  //   lcd.print("Right     ");
  // } else if (x < 200) {
  //   lcd.print("Up        ");
  // } else if (x < 400) {
  //   lcd.print("Down      ");
  // } else if (x < 600) {
  //   lcd.print("Left      ");
  // } else if (x < 800) {
  //   lcd.print("Select    ");
  // }
}