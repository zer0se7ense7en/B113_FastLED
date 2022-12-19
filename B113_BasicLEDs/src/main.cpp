#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN_1     7
#define LED_PIN_2     8
#define NUM_LEDS_PER_STRIPE_LEFT    230
#define NUM_LEDS_PER_STRIPE_RIGHT    280
#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
CRGB leds_l[NUM_LEDS_PER_STRIPE_LEFT];
CRGB leds_r[NUM_LEDS_PER_STRIPE_RIGHT];

int del_val = 100;
byte delaytime = 250;
int wave;

CRGBPalette16 currentPalette;
TBlendType    currentBlending;
#define UPDATES_PER_SECOND 100

void setup() {
  delay(3000); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN_1, COLOR_ORDER>(leds_l, NUM_LEDS_PER_STRIPE_LEFT).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, LED_PIN_2, COLOR_ORDER>(leds_r, NUM_LEDS_PER_STRIPE_RIGHT).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(12,16000);
  FastLED.clear();
  FastLED.show();

  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
  Serial.begin(115200);
}
/*
void wait(float factor) {
  FastLED.delay(delaytime*factor);
}

void cleanBL(bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_l[i].setRGB(0,0,0);
  }
  if(shouw) {
    FastLED.show();
  }
}

void cleanFL(bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_l[i].setRGB(0,0,0);
  }
  if(shouw) {
    FastLED.show();
  }
}

void cleanFR(bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_r[i].setRGB(0,0,0);
  }
  if(shouw) {
    FastLED.show();
  }
}

void cleanBR(bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_r[i].setRGB(0,0,0);
  }
  if(shouw) {
    FastLED.show();
  }
}

void cleanall() {
  FastLED.clear();
  FastLED.show();
}

void colorBL(byte hue, bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_l[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}

void colorFL(byte hue, bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_l[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}

void colorFR(byte hue, bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_r[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}

void colorBR(byte hue, bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_r[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}
*/
/*
void colspBL(byte hue, byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsBL[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}

void colspFL(byte hue, byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsFL[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}

void colspFR(byte hue, byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsFR[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}

void colspBR(byte hue, byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsBR[i].setHue(hue);
  }
  if(shouw) {
    FastLED.show();
  }
}
*/
/*
void whiteBL(bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_l[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}

void whiteFL(bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_l[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}

void whiteFR(bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_r[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}

void whiteBR(bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_r[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}
*/
/*
void whispBL(byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsBL[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}

void whispFL(byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsFL[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}

void whispFR(byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsFR[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}

void whispBR(byte startled, byte endled, bool shouw) {
  for(byte i = startled-1; i <= endled-1; i++) {
    ledsBR[i].setRGB(255,255,255);
  }
  if(shouw) {
    FastLED.show();
  }
}
*/
/*
void rgbBL(byte r, byte g, byte b, bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_l[i].setRGB(r,g,b);
  }
  if(shouw) {
    FastLED.show();
  }
}

void rgbFL(byte r, byte g, byte b, bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_l[i].setRGB(r,g,b);
  }
  if(shouw) {
    FastLED.show();
  }
}

void rgbFR(byte r, byte g, byte b, bool shouw) {
  for(int i = NUM_LEDS_PER_STRIPE/2; i < NUM_LEDS_PER_STRIPE; i++) {
    leds_r[i].setRGB(r,g,b);
  }
  if(shouw) {
    FastLED.show();
  }
}

void rgbBR(byte r, byte g, byte b, bool shouw) {
  for(int i = 0; i < NUM_LEDS_PER_STRIPE/2; i++) {
    leds_r[i].setRGB(r,g,b);
  }
  if(shouw) {
    FastLED.show();
  }
}

void Cruise1() {
      colorBL(0,0);
      colorBR(160,0);
      colorFR(160,0);
      colorFL(0,1);
}

void Emergency1() {
 
      colorBL(0,0);
      colorFL(160,0);
      colorFR(0,0);
      colorBR(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep1
      colorBL(0,0);
      colorFL(160,0);
      colorFR(0,0);
      colorBR(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep2

      colorBL(0,0);
      colorFL(160,0);
      colorFR(0,0);
      colorBR(160,0);
       wait(0.57);
      cleanall();
       wait(0.57);

      colorBR(0,0);
      colorFR(160,0);
      colorFL(0,0);
      colorBL(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep1
      colorBR(0,0);
      colorFR(160,0);
      colorFL(0,0);
      colorBL(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep2

      colorBR(0,0);
      colorFR(160,0);
      colorFL(0,0);
      colorBL(160,0);
       wait(0.57);
      cleanall();
       wait(0.57);
}

void Emergency2() {
      colorBL(0,0);
      colorFR(160,0);
       wait(0.3);
       wait(0.3);

      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);

      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);
       wait(0.3);
      cleanFL(0);
      cleanBR(0);
       wait(0.3);
      colorFL(0,0);
      colorBR(160,0);
       wait(0.3);
      cleanall();
       wait(0.3);



      colorBR(0,0);
      colorFL(160,0);
       wait(0.3);
      cleanBR(0);
      cleanFL(0);
       wait(0.3);

      colorBR(0,0);
      colorFL(160,0);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      colorBR(0,0);
      cleanFR(0);
      colorFL(160,0);
      cleanBL(0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);

      colorBR(0,0);
      cleanFR(0);
      colorFL(160,0);
      cleanBL(0);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      colorBR(0,0);
      cleanFR(0);
      colorFL(160,0);
      cleanBL(0);
       wait(0.3);
       wait(0.3);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);
       wait(0.3);
      cleanFR(0);
      cleanBL(0);
       wait(0.3);
      colorFR(0,0);
      colorBL(160,0);
       wait(0.3);
      cleanall();
       wait(0.3);
}

void UrgentEmergency1() {
       colorBL(0,0);
      colorFL(160,0);
      colorFR(0,0);
      colorBR(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep1
      colorBL(0,0);
      colorFL(160,0);
      colorFR(0,0);
      colorBR(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep2

      colorBL(0,0);
      colorFL(160,0);
      colorFR(0,0);
      colorBR(160,0);
       wait(0.57);
      cleanall();
       wait(0.14);

      for(byte z = 0; z < 3; z++) {
        whiteBL(0);
        whiteFL(0);
        whiteFR(0);
        whiteBR(0);
         wait(0.14);
        cleanall();
         wait(0.07);        
      }

      whiteBL(0);
      whiteFL(0);
      whiteFR(0);
      whiteBR(0);
       wait(0.14);
      cleanall();
       wait(0.57);


      colorBR(0,0);
      colorFR(160,0);
      colorFL(0,0);
      colorBL(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep1
      colorBR(0,0);
      colorFR(160,0);
      colorFL(0,0);
      colorBL(160,0);
       wait(0.28);
      cleanall();
       wait(0.14); // <- rep2

      colorBR(0,0);
      colorFR(160,0);
      colorFL(0,0);
      colorBL(160,0);
       wait(0.57);
      cleanall();
       wait(0.14);

      for(byte z = 0; z < 3; z++) {
        whiteBL(0);
        whiteFL(0);
        whiteFR(0);
        whiteBR(0);
         wait(0.14);
        cleanall();
         wait(0.07);        
      }

      whiteBL(0);
      whiteFL(0);
      whiteFR(0);
      whiteBR(0);
       wait(0.14);
      cleanall();
       wait(0.57);

}

void UrgentEmergency2() {
       colorBL(0,0);
      whiteFL(0);
      colorFR(160,0);
      whiteBR(0);
       wait(0.3);
      cleanBL(0);
      cleanFR(0);
       wait(0.3);

      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);
       wait(0.3);
      whiteBL(0);
      whiteFR(0);
       wait(0.3);
      cleanBL(0);
      cleanFR(0);
       wait(0.3);
      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
      whiteFL(0);
      whiteBR(0);
       wait(0.3);
      cleanFL(0);
      cleanBR(0);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);

      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);
       wait(0.3);
      whiteBL(0);
      whiteFR(0);
       wait(0.3);
      cleanBL(0);
      cleanFR(0);
       wait(0.3);
      colorBL(0,0);
      cleanFL(0);
      colorFR(160,0);
      cleanBR(0);
       wait(0.3);
      whiteFL(0);
      whiteBR(0);
       wait(0.3);
      cleanFL(0);
      cleanBR(0);
       wait(0.3);
      cleanBL(0);
      colorFL(0,0);
      cleanFR(0);
      colorBR(160,0);
       wait(0.3);
      whiteBL(0);
      cleanFL(0);
      whiteFR(0);
      cleanBR(0);
       wait(0.3);
      colorFL(0,0);
      colorBR(160,0);
       wait(0.3);
      cleanall();
       wait(0.3);



      colorBR(0,0);
      whiteFR(0);
      colorFL(160,0);
      whiteBL(0);
       wait(0.3);
      cleanBR(0);
      cleanFL(0);
       wait(0.3);

      colorBR(0,0);
      cleanFR(0);
      colorFL(160,0);
      cleanBL(0);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);
       wait(0.3);
      whiteBR(0);
      whiteFL(0);
       wait(0.3);
      cleanBR(0);
      cleanFL(0);
       wait(0.3);
      colorBR(0,0);
      cleanFR(0);
      colorFL(160,0);
      cleanBL(0);
       wait(0.3);
      whiteFR(0);
      whiteBL(0);
       wait(0.3);
      cleanFR(0);
      cleanBL(0);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);

      colorBR(0,0);
      cleanFR(0);
      colorFL(160,0);
      cleanBL(0);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);
       wait(0.3);
      whiteBR(0);
      whiteFL(0);
       wait(0.3);
      cleanBR(0);
      cleanFL(0);
       wait(0.3);
      colorBR(0,0);
      cleanFR(0);
      colorFL(160,0);
      cleanBL(0);
       wait(0.3);
      whiteFR(0);
      whiteBL(0);
       wait(0.3);
      cleanFR(0);
      cleanBL(0);
       wait(0.3);
      cleanBR(0);
      colorFR(0,0);
      cleanFL(0);
      colorBL(160,0);
       wait(0.3);
      whiteBR(0);
      cleanFR(0);
      whiteFL(0);
      cleanBL(0);
       wait(0.3);
      colorFR(0,0);
      colorBL(160,0);
       wait(0.3);
      cleanall();
       wait(0.3);
}

void bike_policelights_us() {
  for(int i = 0; i < random(1, 5); i++) {
    Cruise1();
  }
    for(int i = 0; i < random(1, 10); i++) {
    Emergency1();
  }
    for(int i = 0; i < random(1, 10); i++) {
    Emergency2();
  }
    for(int i = 0; i < random(1, 5); i++) {
    UrgentEmergency1();
  }
    for(int i = 0; i < random(1, 5); i++) {
    UrgentEmergency2();
  }
}

void Standlicht() {
      for(byte w = 0; w <= 254; w++) {
        wave = quadwave8(w);
        rgbFR(0,0,wave,0);
        rgbBL(0,0,wave,0);
        rgbFL(0,0,wave,0);
        rgbBR(0,0,wave,0);
        wait(0.01);
      }
}

void Einsatzfahrt1() {
      colorFL(160,0);
       wait(0.25);
      colorFR(160,0);
       wait(0.5);
      cleanFL(0);
       wait(0.25);
      cleanFR(0);
      colorBL(160,0);
      colorBR(160,0);
       wait(0.25);
      colorFL(160,0);
       wait(0.25);
      colorFR(160,0);
      cleanFL(0);
      cleanBL(0);
      cleanBR(0);
       wait(0.25);
      cleanFR(0);
      colorBL(160,0);
      colorBR(160,0);
       wait(0.25);
       wait(0.25);
      cleanBL(0);
      cleanBR(1);
}

void Einsatzfahrt2() {
 for(byte j = 0; j < 2; j++) {
        colorBL(160,0);
        colorFR(160,0);
         wait(0.28);
        cleanBL(0);
        cleanFR(0);
         wait(0.14);
      }
      colorBL(160,0);
      colorFR(160,0);
      wait(0.57);
      cleanBL(0);
      cleanFR(0);
      for(byte j = 0; j < 2; j++) {
        colorBR(160,0);
        colorFL(160,0);
         wait(0.28);
        cleanBR(0);
        cleanFL(0);
         wait(0.14);        
      }
      colorBR(160,0);
      colorFL(160,0);
       wait(0.57);
      cleanBR(0);
      cleanFL(1);
}

void AchtungEinsatz1() {
colorFL(160,0);
       wait(0.25);
      colorFR(160,0);
        whiteBL(0);
        whiteBR(0);
       wait(0.125);
        cleanBL(0);
        cleanBR(0);
       wait(0.0625);
        whiteBL(0);
        whiteBR(0);
       wait(0.125);
        cleanBL(0);
        cleanBR(0);
       wait(0.0625);
        whiteBL(0);
        whiteBR(0);
       wait(0.125);
        cleanBL(0);
        cleanBR(0);
       wait(0.0625);
        whiteBL(0);
        whiteBR(0);
       wait(0.125);
        cleanBL(0);
        cleanBR(0);
       wait(0.0625);
        whiteBL(0);
        whiteBR(0);
       wait(0.125);
        cleanBL(0);
        cleanBR(0);
       wait(0.0625);
        whiteBL(0);
        whiteBR(0);
       wait(0.125);
        cleanBL(0);
        cleanBR(0);
       wait(0.1875);
      cleanFL(0);
       wait(0.25);
      cleanFR(0);
        colorBL(160,0);
        colorBR(160,0);
       wait(0.25);
      colorFL(160,0);
       wait(0.25);
      colorFR(160,0);
      cleanFL(0);
        cleanBL(0);
        cleanBR(0);
       wait(0.25);
      cleanFR(0);
        colorBL(160,0);
        colorBR(160,0);
      whiteFL(0);
       wait(0.125);
      cleanFL(0);
       wait(0.0625);
      whiteFL(0);
       wait(0.0625);
      whiteFR(0);
       wait(0.0625);
      cleanFL(0);
       wait(0.0625);
      cleanFR(0);
      whiteFL(0);
       wait(0.0625);
      whiteFR(0);
       wait(0.0625);
      cleanFL(0);
        cleanBL(0);
        cleanBR(0);
       wait(0.0625);
      cleanFR(0);
       wait(0.0625);
      whiteFR(0);
       wait(0.0625);
       wait(0.0625);
      cleanFR(0);
}

void AchtungEinsatz2() {

        colorBL(160,0);
        colorFR(160,0);
         wait(0.14);
          whiteBR(0);
          whiteFL(0);
         wait(0.14);
        cleanBL(0);
        cleanFR(0);
         wait(0.14);
        colorBL(160,0);
        colorFR(160,0);
         wait(0.14);
          cleanBR(0);
          cleanFL(0);
         wait(0.14);
        cleanBL(0);
        cleanFR(0);
          whiteBR(0);
          whiteFL(0);
         wait(0.14);
      
      colorBL(160,0);
      colorFR(160,0);
       wait(0.42);
        cleanBR(0);
        cleanFL(0);
       wait(0.14);
      cleanBL(0);
      cleanFR(0);

        colorBR(160,0);
        colorFL(160,0);
         wait(0.14);
          whiteBL(0);
          whiteFR(0);
         wait(0.14);
        cleanBR(0);
        cleanFL(0);
         wait(0.14);        
        colorBR(160,0);
        colorFL(160,0);
         wait(0.14);
          cleanBL(0);
          cleanFR(0);
         wait(0.14);
        cleanBR(0);
        cleanFL(0);
          whiteBL(0);
          whiteFR(0);        
         wait(0.14);        


      colorBR(160,0);
      colorFL(160,0);
       wait(0.42);
        cleanBL(0);
        cleanFR(0);
       wait(0.14);
      cleanBR(0);
      cleanFL(1);
}

void bike_policelights_eu() {
  for(int i = 0; i < random(1, 5); i++) {
    Standlicht();
  }
    for(int i = 0; i < random(1, 10); i++) {
    Einsatzfahrt1();
  }
    for(int i = 0; i < random(1, 10); i++) {
    Einsatzfahrt2();
  }
    for(int i = 0; i < random(1, 5); i++) {
    AchtungEinsatz1();
  }
    for(int i = 0; i < random(1, 5); i++) {
    AchtungEinsatz2();
  }
}
*/

void flowing_rainbow(int colorIndex) {
  for (int l = 0; l < NUM_LEDS_PER_STRIPE_RIGHT; l++) {
    if(l<NUM_LEDS_PER_STRIPE_LEFT){
      leds_l[l] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    if(l<NUM_LEDS_PER_STRIPE_RIGHT){
      leds_r[l] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    }
    colorIndex += 1;
  }
}

void uniform_rainbow() {
  for (int c = 0; c < 255; c++) {
    for (int l = 0; l < NUM_LEDS_PER_STRIPE_LEFT; l++) {
      if(l<NUM_LEDS_PER_STRIPE_LEFT) {
        leds_l[l].setHue(c);
      }
      if(l>NUM_LEDS_PER_STRIPE_LEFT) {
        leds_r[l].setHue(c);
      }
    }
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  }
}

void police_lights() {
  for (int i = 0; i < 4; i++) {
    leds_l[0].setRGB(0,0,255);
    FastLED.delay(del_val);
    FastLED.clear();
    FastLED.delay(del_val/3);
    leds_l[0].setRGB(0,0,255);
    FastLED.delay(del_val);
    FastLED.clear();
    FastLED.delay(del_val);

    leds_l[1].setRGB(0,0,255);
    FastLED.delay(del_val);
    FastLED.clear();
    FastLED.delay(del_val/3);
    leds_l[1].setRGB(0,0,255);
    FastLED.delay(del_val);
    FastLED.clear();
    FastLED.delay(del_val);
  }
  for (int i = 0; i < 8; i++) {
    leds_l[0].setRGB(0,0,255);leds_l[1].setRGB(0,0,0);
    FastLED.delay(del_val*2);
    leds_l[0].setRGB(0,0,0);leds_l[1].setRGB(0,0,255);
    FastLED.delay(del_val*2);
  }
}


void loop() {
  static int startIndex = 0;
  startIndex++;
  flowing_rainbow(startIndex);
  //uniform_rainbow();

  //police_lights();

  //bike_policelights_us();
  //bike_policelights_eu();

  //FastLED.clear();

  FastLED.show();
}