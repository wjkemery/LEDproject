#include <FastLED.h>


// Look into MIDI

#define numLED 300
#define dataPin 7

const PROGMEM int analogPin = A0;
int color = 0;
float Dtime = 1;

CRGB leds [numLED];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL,dataPin>(leds, numLED);

}

// Make color patterns their own fucntion to clean up loop

void loop() {


//rainbowCycle(20);
//FastLED.clear();
//RunningLights(0xff,0xff,0x00, 50);

//RunningLights(0x00ced1,0x00ced1,0x00bfff, 1);

  //checkAnalog();
 //TestLights();
 
    leds[107] = CRGB::Orange;
  //leds[16] = CRGB::HotPink;
  //leds[46] = CRGB::DarkCyan;
  
  FastLED.show();
  
}

int checkAnalog()
{
  int input = 0;
  float volts;
  input = analogRead(analogPin);

  volts = (input*5.0)/1024.0;
 

  Serial.print("output value: ");
  Serial.print(volts);
  Serial.println(" ");

delay(50);
  return volts;
 
}


void TestLights()
{
  // put your main code here, to run repeatedly:
  //FastLED.clear();

//fill_solid( leds, numLED, CRGB::Blue);

  //color = checkAnalog();
 
  //if(color > 3.75 && color < 3.78 ) {

   // fill_solid(leds, numLED, CRGB:: Green);
  
   
   for(int i = 0; i < numLED; i++){
     
      
      leds[i] = CRGB::Green;
      leds[i+1] = CRGB::Green;
      leds[i+2] = CRGB::Green;
      FastLED.show();
      delay(Dtime);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(Dtime);
    }
    
   
   for(int i = numLED; i > 0 ; i--)
   {
      leds[i] = CRGB::Blue;
      leds[i-1] = CRGB::Blue;
      leds[i-2] = CRGB::Blue;
     // leds[i+3] = CRGB::Blue;
     // leds[i+4] = CRGB::Blue;
     // leds[i+5] = CRGB::Blue;
      //leds[i+6] = CRGB::Blue;
     // leds[i+7] = CRGB::Blue;
      //leds[i+8] = CRGB::Blue;
      //leds[i+9] = CRGB::Blue;
      FastLED.show();
      delay(Dtime);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(Dtime);
   }

   for(int i = 0; i < numLED; i++){
   
      leds[i] = CRGB::Magenta;
      leds[i+1] = CRGB::Magenta;
      leds[i+2] = CRGB::Magenta;
      FastLED.show();
      delay(Dtime);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(Dtime);
    }

for(int i = numLED; i > 0 ; i--)
   {
      leds[i] = CRGB::Aqua;
      leds[i-1] = CRGB::Aqua;
      leds[i-2] = CRGB::Aqua;
     // leds[i+3] = CRGB::Blue;
     // leds[i+4] = CRGB::Blue;
     // leds[i+5] = CRGB::Blue;
      //leds[i+6] = CRGB::Blue;
     // leds[i+7] = CRGB::Blue;
      //leds[i+8] = CRGB::Blue;
      //leds[i+9] = CRGB::Blue;
      FastLED.show();
      delay(Dtime);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(Dtime);
   }
  
 // }

 //  if(color < 3.75 ) {

  //fill_solid(leds, numLED, CRGB:: Blue);


   for(int i = 0; i < numLED; i++){
    leds[i] = CRGB::Red;
   leds[i+1] = CRGB::Red;
   leds[i+2] = CRGB::Red;
   FastLED.show();
   delay(Dtime);
   leds[i] = CRGB::Black;
   FastLED.show();
   delay(Dtime);
    }
   
  //}
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;
 
  for(int j=0; j<numLED*2; j++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i<numLED; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
      }

      FastLED.show();     
     // showStrip();
      delay(WaveDelay);
  }
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}


void rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< numLED; i++) {
      c=Wheel(((i * 256 / numLED) + j) & 255);
      setPixel(i, *c, *(c+1), *(c+2));
    }
    //showStrip();
    FastLED.show();
    delay(SpeedDelay);
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];
 
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }

  return c;
}
