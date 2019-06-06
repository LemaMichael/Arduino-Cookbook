/*
 * 
 * - Map the range of analog values from a pot to scale from 0 - 100 
 */
 
#include <Streaming.h>
 
const int potPin = 0;   // Input put for Potentiometer
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val;                            // Value coming from the sensor
  int percent;                        // The mapped value

  val = analogRead(potPin);          // Read the voltage on the pot (value ranges from 0 - 1023)

  percent = map(val,0,1023,0,100);  // Percent will range from 0 - 100
  digitalWrite(ledPin, HIGH);       
  delay(percent);
  digitalWrite(ledPin, LOW);
  delay(100 - percent);           // Off time is 100 minus On time
  Serial << percent << "%" << endl;        // Show the % of pot rotation
}
