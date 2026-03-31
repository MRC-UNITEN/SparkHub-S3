int btnPin = 2;
int ledPin = 9;
bool ledState = LOW;

unsigned long lastDebounceTime = 0;  // The last time the pin was toggled
unsigned long debounceDelay = 200;    // The "wait" time in ms

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(btnPin);

  if (reading == LOW) {
    // Check if enough time has passed since the last press
    if ((millis() - lastDebounceTime) > debounceDelay) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      
      // Update the timer
      lastDebounceTime = millis();
    }
  }
}