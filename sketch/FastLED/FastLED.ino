#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 6

CRGB leds[NUM_LEDS];
uint8_t hue = 0;
uint8_t offset = 256 / 6;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  hue = (hue + 1) % 256;
  leds[0] = CHSV((hue + offset * 0) % 256, 255, 255);
  leds[1] = CHSV((hue + offset * 1) % 256, 255, 255);
  leds[2] = CHSV((hue + offset * 2) % 256, 255, 255);
  leds[3] = CHSV((hue + offset * 3) % 256, 255, 255);
  leds[4] = CHSV((hue + offset * 4) % 256, 255, 255);
  leds[5] = CHSV((hue + offset * 5) % 256, 255, 255);
  FastLED.show();
  delay(100);
}
