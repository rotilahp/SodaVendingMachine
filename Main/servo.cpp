#include <Arduino.h>
#include <Servo.h>
#include "lcd.h"

/*****************************
 * Written by Daniel Payne
 * 6/2/2019
 * Servos without using delays
 ***********************************/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;

int ServoPinA =44;
int ServoPinB =46;

int servoInterval = 15; //15ms interval
int servoTimer = servoInterval*90; //90 degrees of rotation
long previousServoMillis;

boolean servoStateA = false;
boolean servoStateB = false;
boolean reverse = false;
int pos = 0;    // variable to store the servo position

void openGateA(){
    servoStateA = true;
}

void openGateB(){
    servoStateB = true;
}
void updateServoA(){
    if (servoStateA == true) {
        unsigned long currentMillis = millis();
        //forward movement
        if (reverse != true){
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                myservo.write(pos);
                pos++;
            }
            if (pos >= 90){
                reverse = true;
            }
        
        }
        else {
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                pos--;
                myservo.write(pos);
            }
            if (pos <= 0){
                reverse = false;
                servoStateA = false;
            }
        }
    }
}
void updateServoB(){
    if (servoStateB == true) {
        unsigned long currentMillis = millis();
        //forward movement
        if (reverse != true){
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                myservo2.write(pos);
                pos++;
            }
            if (pos >= 90){
                reverse = true;
            }
        
        }
        else {
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                pos--;
                myservo2.write(pos);
            }
            if (pos <= 0){
                reverse = false;
                servoStateB = false;
            }
        }
    }
}

void updateServos(){
    updateServoA();
    updateServoB();
}

void servoSetup() {
  myservo.attach(ServoPinA);  // attaches the servo on pin 13 to the servo object
  myservo2.attach(ServoPinB);  // attaches the servo on pin 13 to the servo object
  previousServoMillis = millis();
}
