#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 255 

CRGB leds[NUM_LEDS];
int stackedCount = 0;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {

  if (stackedCount < NUM_LEDS) {
    for (int i = NUM_LEDS - 1; i >= stackedCount; i--) {
      FastLED.clear();
      for (int s = 0; s < stackedCount; s++) {
        leds[s] = CRGB::Blue; 
      }
      leds[i] = CRGB::Blue; 
      FastLED.show();
      delay(90);
    }
    stackedCount++;
    delay(200);
  } 
  else {
    delay(1000);
    for(int blink = 0; blink < 3; blink++) {
      FastLED.clear();
      FastLED.show();
      delay(200);
      fill_solid(leds, NUM_LEDS, CRGB::Blue);
      FastLED.show();
      delay(200);
    }
    stackedCount = 0; 
    FastLED.clear();
    FastLED.show();
  }
}