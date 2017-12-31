#include <Adafruit_NeoPixel.h>

#define PLYR1 2
#define PLYR2 3
#define PLYR3 4
#define PLYR4 5

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(22, PLYR1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(22, PLYR2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(22, PLYR3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(22, PLYR4, NEO_GRB + NEO_KHZ800);

const int links1 = 8;
const int rechts1 = 9;
const int links2 = 10;
const int rechts2 = 11;

unsigned long motorTimer = 0;

void setup()
{
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'
  
  pinMode(links1, OUTPUT);
  pinMode(rechts1, OUTPUT);
  pinMode(links2, OUTPUT);
  pinMode(rechts2, OUTPUT);

  randomSeed(analogRead(0));
  
  Serial.begin(9600);
  Serial.println("Booted");
}

void loop()
{
  if(millis() > (motorTimer + 500)) {
    motorTimer = millis();
    if (millis() < 10000) {
      doVooruit();
    } else {
      randomPart(); 
    }
  }
}

void randomPart() {
  switch (random(1,51)) {
    case 10:
      doStop();
    break;
    case 20:
      doStop();
    break;  
    case 30:
      doAchteruit();
    break;
    case 40:
      doAchteruit();
    break;
    case 50:
      doAchteruit();
    break;
    default:
      doVooruit();
  }
}

void doStop() {
  Serial.println("State Stop Entered");
  digitalWrite(links1, LOW);
  digitalWrite(rechts1, LOW);
  digitalWrite(links2, HIGH);
  digitalWrite(rechts2, HIGH);
}

void doAchteruit(){
  Serial.println("State Links Entered");
  digitalWrite(links1, LOW);
  digitalWrite(rechts1, LOW);
  digitalWrite(links2, LOW);
  digitalWrite(rechts2, LOW);
}

void doVooruit(){
  Serial.println("State Rechts Entered");
  digitalWrite(links1, HIGH);
  digitalWrite(rechts1, HIGH);
  digitalWrite(links2, HIGH);
  digitalWrite(rechts2, HIGH);
}

void colorWipePlyr1(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
}
void colorWipePlyr2(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c);
    strip2.show();
    delay(wait);
  }
}
void colorWipePlyr3(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip3.numPixels(); i++) {
    strip3.setPixelColor(i, c);
    strip3.show();
    delay(wait);
  }
}

void colorWipePlyr4(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip4.numPixels(); i++) {
    strip4.setPixelColor(i, c);
    strip4.show();
    delay(wait);
  }
}
