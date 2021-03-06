#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int trigPin = 9; 
const int echoPin = 10; 
float duration, distance; 


void setup() { 
pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1; 


if (distance < 125 < 200) {
  for(int i=0; i<24; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(0 , 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
   
  }
 }
 
if (distance < 120 ) {
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<24; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(255 , 255, 255));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(100);
  }
}

if (distance < 85 ) {
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<24; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(0 , 255, 255));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(100);
  }
}

if (distance < 60 ) {
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<24; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(255 , 90, 70));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(100);
  }
}
}