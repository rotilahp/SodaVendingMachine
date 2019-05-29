
#include "lcd.h"
#include "servo.h"
#include "stepper.h"

/* @file EventSerialKeypad.pde
 || @version 1.0
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || @description
 || | Demonstrates using the KeypadEvent.
 || #
 */
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(115200);
  stepperSetup();
  servoSetup();
  LCDSetup();
  keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
}

void loop(){
  char key = keypad.getKey(); 
  if (key) {
        Serial.println(key);
  }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        
        break;

    case RELEASED:
        if (key == "#"){
          successLCD();
          break;
        }
        updateLCD(key);
        break;

    /*case HOLD:
        
        break;*/
    }
}
