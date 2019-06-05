/*
 * 
 * Prints how Long more than one switch has been pressed
 */

#include <Streaming.h>

const int switchAPin = 2;
const int switchBPin = 3;


// Functions with references must be explicitly declared
unsigned long switchTime(int pin, boolean &state, unsigned long &startTime);


void setup() {
  pinMode(switchAPin, INPUT);
  digitalWrite(switchAPin, HIGH); // Turn on pull-up resistor

  pinMode(switchBPin, INPUT);
  digitalWrite(switchBPin, HIGH); 
  Serial.begin(9600);

}

void loop() {
  unsigned long time;

  Serial << "switch A Time = ";
  time = switchATime();
  Serial << time;

  Serial << ", switch B time = ";
  time = switchBTime();
  Serial << time << endl;
  delay(1000);                     // wait a second so as not to send massive amounts of data

}

unsigned long switchTime(int pin, boolean &state, unsigned long &startTime) {
  if (digitalRead(pin) != state) //check if the switch has changed state
  {
    state = !state;
    startTime = millis(); // Store the time
  }
  if (state == LOW) 
    return millis() - startTime;  // Return the time in milliseconds
  else 
    return 0;                     // Return 0 if the switch is not pushed (HIGH STATE)
}


long switchATime() 
{
  static unsigned long startTime = 0;   // The time the switch state change was first detected
  static boolean state;                 // Current state of the switch

  return switchTime(switchAPin, state, startTime);
}


long switchBTime() 
{
  static unsigned long startTime = 0;   // The time the switch state change was first detected
  static boolean state;                 // Current state of the switch

  return switchTime(switchBPin, state, startTime);
}
