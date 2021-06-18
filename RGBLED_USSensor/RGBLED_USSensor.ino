#include <HCSR04.h>
#include "SR04.h"

// define pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define TRIG_PIN 12
#define ECHO_PIN 11

//Fading time between colors
#define delayTime 30

//Ultrasonic sensor object and distance variable
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

void setup()  {
  //Setting pins
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);

}

void loop() {

  //Static variables for RGB values
  static int blueVal = 255;
  static int redVal = 0;
  static int greenVal = 0;

  //Fading from blue to red
  while (sr04.Distance() < 20) {
    blueVal -= 1;
    redVal += 1;
    greenVal = 0;
    if ( (blueVal < 0) || (redVal > 255) ) {
      break;
    }

    //Pauses the fading when sensor obstruction is removed momentarily
    if (sr04.Distance() >= 20) {
      for (int i = 0; i < 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000; i++) {
        if (sr04.Distance() < 20) {
          break;
        }
      }
    }
    
    analogWrite(GREEN, greenVal);
    analogWrite(BLUE, blueVal);
    analogWrite(RED, redVal);
    delay(delayTime);
  }

  //Fading from red to green
  while (sr04.Distance() < 20) {
    redVal -= 1;
    greenVal += 1;
    blueVal = 0;
    if ( (redVal < 0) || (greenVal > 255) ) {
      break;
    }

    //Pauses the fading when sensor obstruction is removed momentarily
    if (sr04.Distance() >= 20) {
      for (int i = 0; i < 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000; i++) {
        if (sr04.Distance() < 20) {
          break;
        }
      }
    }

    analogWrite(BLUE, blueVal);
    analogWrite(RED, redVal);
    analogWrite(GREEN, greenVal);
    delay(delayTime);
  }

  //Fading from green to blue
  while (sr04.Distance() < 20) {
    greenVal -= 1;
    blueVal += 1;
    redVal = 0;
    if ( (greenVal < 0) || (blueVal > 255) ) {
      break;
    }

    //Pauses the fading when sensor obstruction is removed momentarily
    if (sr04.Distance() >= 20) {
      for (int i = 0; i < 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000; i++) {
        if (sr04.Distance() < 20) {
          break;
        }
      }
    }
    
    analogWrite(RED, redVal);
    analogWrite(GREEN, greenVal);
    analogWrite(BLUE, blueVal);
    delay(delayTime);
  }

}
