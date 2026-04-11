#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 100 

CRGB leds[NUM_LEDS];
int pos = 0;
int direction = 1; // 1 means forward, -1 means backward

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  //fadeToBlackBy(leds, NUM_LEDS, 150); // Leave a little trail
  FastLED.clear();
  leds[pos] = CRGB::Red;
  
  // Update position
  pos = pos + direction;

  // Logic: If we hit the end (9) or the start (0), reverse direction!
  if (pos == NUM_LEDS - 1 || pos == 0) {
    direction = direction * -1; 
  }

  FastLED.show();
  delay(100);
}