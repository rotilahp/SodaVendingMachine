/*********
  Address of LCD Screen is 0x27
*********/

#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

// set the LCD number of columns and rows
int lcdColumns =16;
int lcdRows =2;

int counter = 0;
long previousMillis = 0;
long interval = 1000;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void LCDSetup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void scrollText(String message, int delayTime) {
  
//  message.substring(pos, pos + lcdColumns)
}

void updateLCD(char x){

  String mystring(x);
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Press # to buy:");
  lcd.setCursor(0,1);
  lcd.print(mystring);
}

void defaultLCD(){

  String defaultMessage1 = "Daniel's Soda";
  String defaultMessage2 = "Machine!";
  
  lcd.setCursor(0,0);
  // print message
  lcd.print(defaultMessage1);
  
  lcd.setCursor(4,1);
  lcd.print(defaultMessage2);

  //This is for scrolling text stuff
  //using millis for a timer, scrolling text is updated every 1 second
  //interval = 1000ms = 1second
  
  unsigned long currentMillis = millis();         //takes current time and subtracts from the last time the lcd was scrolled
  if(currentMillis - previousMillis > interval) {   
      previousMillis = currentMillis;
      if (counter > 16){                          //variable counter keeps track of where the words are on the scree
        for (int x = 0; x <= 16; x++){            //after 16 movements to the left, its time to restart the scrolling
          lcd.scrollDisplayRight();               //we go 16 movements to the right to restart
        }
        counter = 0;
      }
      else if (counter != 0){
        lcd.scrollDisplayLeft();
      }
      counter ++;
  }
}



void clearLCD(){
  lcd.clear();
}

void successLCD(){
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Thank you for");
  lcd.setCursor(1,1);
  lcd.print("your purchase!");
  delay(3000);
  lcd.clear();
  defaultLCD();

}
