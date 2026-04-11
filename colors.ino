#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 8
#define MAX_VOLTS 5
#define MAX_AMPS 500
#define BRIGHTNESS 30

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Method 1: Predefined FastLED Names
  leds[0] = CRGB::Amethyst;
  leds[1] = CRGB::HotPink;

  // Method 2: RGB Mixing (Red, Green, Blue)
  leds[2] = CRGB(0, 255, 0);       // Pure Green (0 Red, Max Green, 0 Blue)
  leds[3] = CRGB(255, 255, 0);     // Red + Green makes Yellow!

  // Method 3: Hex Codes (Great for matching logos/branding)
  leds[4] = 0x00FFFF;              // Cyan

  // Method 4: HSV (Hue, Saturation, Value)
  // Hue 160 is Blue. Max Saturation (255), Max Brightness (255)
  leds[5] = CHSV(160, 255, 255);   
  
  // Same blue, but dropping the brightness down to 50
  leds[6] = CHSV(160, 255, 50);    

  leds[7] = CRGB(0, 0, 0); // Black/Off

  leds[8] = CRGB(100, 67, 200); 

  leds[9] = CRGB(255, 255, 255); // R + G + B = W

  FastLED.show();
}