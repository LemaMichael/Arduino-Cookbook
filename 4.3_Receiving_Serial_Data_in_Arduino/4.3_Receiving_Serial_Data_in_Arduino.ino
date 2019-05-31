
/*
 * Receiving Data on Arduino from a computer.
 * 
 * 
 * This sketch receives a digit (0-9) and blinks LED 13 at a 
 * rate proportional to the received digit value
 */
#include <Streaming.h>

const int ledPin = 13;
int blinkRate = 0;
int value;

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  if (Serial.available()) // check to see if at least 1 character is available
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '9') // is the input an ascii digit between 0 and 9?
    {
      value = (value * 10) + (ch - '0'); // Accumulate the value
    } 
    else if (ch == 10)  // is the character the newline Character
    {
      blinkRate = value; // Set blinkrate to the accumulated value
      Serial.println(blinkRate);
      value = 0; // reset val to 0 ready for the next sequence of digits
    }
  }
  blink();
}

// blink the LED with the on and off times determined by blinkRate
void blink() {
  digitalWrite(ledPin, HIGH);
  delay(blinkRate); // Delay depends on blinkrate value
  digitalWrite(ledPin, LOW);
  delay(blinkRate);
}
