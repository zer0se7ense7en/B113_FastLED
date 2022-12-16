#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN_1     7
#define LED_PIN_2     8
#define NUM_LEDS    300
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds_l[NUM_LEDS];
CRGB leds_r[NUM_LEDS];

//#define UPDATES_PER_SECOND 100

void setup() {
  delay(3000); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN_1, COLOR_ORDER>(leds_l, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, LED_PIN_2, COLOR_ORDER>(leds_r, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(12,16000);

  Serial.begin(115200);
}

void flowing_rainbow(String mode) {
  if (mode == "forward") {

  }
  else if (mode == "around") {
    
  }
}

void uniform_rainbow() {
  for (int c = 0; c < 255; c++) {
    for (int l = 0; l < NUM_LEDS; l++) {
      leds_r[l].setHue(c);
      leds_l[l].setHue(c);
    }
    FastLED.show();
  }
}

void loop() {
  flowing_rainbow("forward");

  FastLED.show();
}