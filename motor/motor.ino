#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Stepper.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

#define STEPS1 200
#define STEPS2 200
#define STEPS3 20

Stepper stepper1(STEPS1, 12, 11, 10, 9);
Stepper stepper2(STEPS2, 8, 7, 6, 5);

void setup() {
  Serial.begin(9600);
  Serial.println("Color View Test!");

  stepper1.setSpeed(30);
}


void loop() {
stepper1.step(STEPS1/2);

  if (r < 100 && g > 80 && b < 90) {
    stepper2.step(STEPS3);
    stepper1.step(STEPS1*2);
    stepper2.step(-STEPS3); 
  }
}
