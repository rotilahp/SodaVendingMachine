

/* Soda Vending Machine by Daniel Payne
 *  
 *  danielgatesf@gmail.com
 *  
 *  EventSerialKeypad by Alexander Brevig was used to get this started
 *   
 */
#include <Keypad.h>
#include "lcd.h"
#include "servo.h"
#include "stepper.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 

boolean blink = false;
boolean ledPin_state;

long keypadTimer;
long currentMillis;
char previousKey;

void setup(){
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad

    LCDSetup();
    defaultLCD();
    servoSetup();
    stepperSetup();
}

void loop(){
    currentMillis = millis();
    
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
        keypadTimer = currentMillis;
    }

    //if keypad hasnt been pressed for 4 seconds, put default message back on
    if (currentMillis - keypadTimer > 4000){
        previousKey = '0';
        defaultLCD();
    }

    updateServos();
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        clearLCD();
        if(key == '#' && previousKey == '1'){
            successLCD();
            openGateA();
           // sodaDelivery();
            clearLCD();
            defaultLCD();
        }
        else if(key == '#' && previousKey == '2'){
            successLCD();
            openGateB();
          //  sodaDelivery();
            clearLCD();
            defaultLCD();
        }
        else if (key == '#' && (previousKey != '1' || previousKey != '2')){
            tryAgainLCD();
        }
        else {
          updateLCD(key);
        }
        previousKey = key;
        break;

    case RELEASED:
        if (key == '*') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == '*') {
            blink = true;    // Blink the LED when holding the * key.
        }
        break;
    }
}
          
