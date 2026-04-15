#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 1. Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 2. Define the Sensor Pins
const int trigPin = 2;
const int echoPin = 3;

// Variables for math
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Communication Started...");

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Set Pin Modes
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  
  lcd.setCursor(0, 0);
  lcd.print("Digital Ruler");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // 3. Trigger the "Shout"
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 4. Measure the "Echo"
  duration = pulseIn(echoPin, HIGH);

  // 5. Calculate Distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 6. Display the result on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:      "); 
  lcd.setCursor(10, 0);
  lcd.print(distance);
  lcd.print("cm");

  delay(200); 
}