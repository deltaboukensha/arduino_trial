#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 6

CRGB leds[NUM_LEDS];
uint8_t hue = 0;
uint8_t index = 0;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  leds[0] = CHSV(0, 0, 0);
  leds[1] = CHSV(0, 0, 0);
  leds[2] = CHSV(0, 0, 0);
  leds[3] = CHSV(0, 0, 0);
  leds[4] = CHSV(0, 0, 0);
  leds[5] = CHSV(0, 0, 0);
  leds[index] = CHSV(hue, 255, 255);
  FastLED.show();
  delay(1000);

  hue = (hue + 1) % 256;
  index = (index + 1) % NUM_LEDS;
}
