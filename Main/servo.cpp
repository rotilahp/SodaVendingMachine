#include <Arduino.h>
#include <Servo.h>
#include "lcd.h"

//Pins Config
int ServoPinA =44;
int ServoPinB =46;

Servo myservo;
Servo myservo2;

void servoSetup() {
  myservo.attach(ServoPinA);   //attaches pin for servo a
  myservo2.attach(ServoPinB);
}

void openGateA(){
        Serial.print("Hello :o");
        for (int pos = 0; pos <= 90; pos+=1){
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);   
      }
      //reverse servo movement
      //servo goes from 90 degree position to 0 
      for (int pos = 90; pos > 0; pos-=1){
        myservo.write(pos);              
        delay(15);   
      }  
    }
    

void openGateB(){       
       for (int pos = 0; pos <= 90; pos+=1){
        myservo2.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);   
      }
      //reverse servo movement
      //servo goes from 90 degree position to 0 
      for (int pos = 90; pos > 0; pos-=1){
        myservo2.write(pos);              
        delay(15);   
      }   
        
    } 
