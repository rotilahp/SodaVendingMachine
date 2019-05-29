
#include <Arduino.h>

//Pin Config
#define stepPin 11
#define directionPin 10

void stepperSetup() {
  pinMode (stepPin, OUTPUT);
  pinMode (directionPin, OUTPUT);
}

void sodaDelivery() {
  //forward direction 
  digitalWrite(directionPin, HIGH);
  //200 steps for one full cycle rotation
  for (int x = 0; x <200; x++){
    digitalWrite(stepPin, HIGH);
    //delay(20);
    digitalWrite(stepPin, LOW);
    delay(25);
  }
  //one sec delay
  delay(1000);

  //reverse direction
  digitalWrite(directionPin, LOW);

  for (int x = 0; x <200; x++){
    digitalWrite(stepPin, HIGH);
    //delay(20);
    digitalWrite(stepPin, LOW);
    delay(25);
  }
}
