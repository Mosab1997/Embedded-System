//  123D.Circuits.io/circuits/752641
//  This circuit demonstrates how to give the Arduino commands through the Serial Monitor
//  Pressing the r, or g, or b key followed by the Enter key toggles the LEDs
//  Typing in an angle between 0 and 180 followed by the d key followed by the Enter key commands the servo

#include <Servo.h>            // include the servo library, source: http://arduino.cc/en/reference/servo

#define PIN_RED 7           // giving pins names
#define PIN_GREEN 6
#define PIN_BLUE 5
int angle = 90;             // initialize the servo to 90 degrees (straight up)
int nextAngle = 0;            // next angle to be set

Servo servo1;             // define the servo as "servo1"
int redOn =LOW;             // define and initialize status of LEDs
int greenOn =LOW;
int blueOn =LOW;

void setup()
{
  pinMode(PIN_RED, OUTPUT);     // setting pins as outputs
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  digitalWrite(PIN_RED, redOn);
  digitalWrite(PIN_GREEN, greenOn);
  digitalWrite(PIN_BLUE, blueOn);
  
  servo1.attach(9);         // set pulse width range: 500 to 2500 microseconds (default values for Arduino servo library)
  // servo1.attach(9, 1000, 2000);  // set pulse width range: 1000 to 2000 microseconds (matches actual servo range)
  
  Serial.begin(9600);         // initalize the serial connection
}

void loop()
{
  if (Serial.available()){  // if something has been typed and is in the Serial buffer
    char c = Serial.read(); // read 1 character from serial monitor, store it in variable c
    if (c == 'r'){      // if pressed r turn on the red LED
      if (redOn == HIGH){
        redOn = LOW;    // if red LED is already on, turn it off
      } else {
        redOn = HIGH;
      }
    }
    if (c == 'g') greenOn = greenOn == HIGH ? LOW : HIGH; // same logic as above condensed into one line
    if (c == 'b') blueOn = blueOn == HIGH ? LOW : HIGH; // same logic as above condensed into one line
    
    // to control servo enter a number followed by 'd', this is how to receive numbers with more than one digit
    if (c >= '0' && c <= '9') { // Digit between 0 and 9 received (these are actually ASCII48 to ASCII57)
      nextAngle = nextAngle * 10; // until 'd' is received build up number by multiplying by 10
      nextAngle = nextAngle + (c - '0'); // convert 'c' to decimal and add it to nextAngle ("0" is ASCII48)
    }
    if (c == 'd') { // when a 'd' is received act upon nextAngle
      if (nextAngle > 180) {
        Serial.println("must be <= 180 degrees");
      } else {
        angle = nextAngle; // angle is used to set the servo position
      }
      nextAngle = 0; // Clear this for next input
    }
  }
  digitalWrite(PIN_RED, redOn); // update the values of the LEDs
  digitalWrite(PIN_GREEN, greenOn);
  digitalWrite(PIN_BLUE, blueOn);     
  
  // tell servo to go to new position, map angle to servo command (units of angle are micro-seconds)
  servo1.write(map(angle,0,180,1000,4000)); 

  delay(5);             // this delay is necessary to cycle-accurately simulate (no lag)
    
}
