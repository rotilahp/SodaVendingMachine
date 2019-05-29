#include <Arduino.h>
#include <Servo.h>


//Pins Config
int ServoPin =18;

Servo myservo;
Servo myservo2;

void servoSetup() {
  myservo.attach(ServoPin);   //attaches pin for the servo
}

void openGate(int x) {
  //servo opens gate
  //servo goes from 0 degree position to 90
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
