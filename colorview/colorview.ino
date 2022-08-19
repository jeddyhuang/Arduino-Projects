#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Stepper.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

#define STEPS1 200
#define STEPS2 200
#define STEPS3 20

Stepper stepper1(STEPS1, 8, 7, 6, 5);
Stepper stepper2(STEPS2, 12, 11, 10, 9);

void setup() {
  Serial.begin(9600);
  Serial.println("Color View Test!");

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  stepper1.setSpeed(30);
  stepper2.setSpeed(30);
}


void loop() {
  uint16_t clear, red, green, blue;

  tcs.setInterrupt(false);      // turn on LED

  delay(60);  // takes 50ms to read 
  
  tcs.getRawData(&red, &green, &blue, &clear);

  tcs.setInterrupt(true);  // turn off LED
  
  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print((int)r );
  Serial.print("\tG:\t"); Serial.print((int)g);
  Serial.print("\tB:\t"); Serial.print((int)b );

  Serial.print("\t");
  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  Serial.println();

stepper1.step(STEPS1/2);

  if (r < 130 && r > 110 && g > 75 && g < 85 && b > 60 && b < 70) {
    stepper2.step(STEPS3);
    stepper1.step(STEPS1*2);
    stepper2.step(-STEPS3); 
  }
/*
  if (r < 150 && r > 130 && g > 70 && g < 80 && b > 50 && b < 60) {
    stepper2.step(-STEPS3);
    stepper1.step(STEPS1*2);
    stepper2.step(STEPS3); 
  }
*/
  if (r < 130 && r > 110 && g > 70 && g < 80 && b > 60 && b < 70) {
    stepper2.step(STEPS3*2);
    stepper1.step(STEPS1*2);
    stepper2.step(-STEPS3*2); 
  }

}
