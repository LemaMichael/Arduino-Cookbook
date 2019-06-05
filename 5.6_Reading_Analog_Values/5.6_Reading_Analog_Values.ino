/*
 * Read the voltage on an analog pin using a potentiometer
 * 
 * - The sketch reads the voltage on an analog pin and 
 * flashed an LED in a proportional rate to the value.
 */

#include <Streaming.h>

 const int potPin = 0; // Select the input pint for the potentiometer
 const int ledPin = 13; 
 int val = 0;         // Variable to store the value coming from the sensor


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  val = analogRead(potPin);  // Read the voltage on the potentiometer
  Serial << val << endl;
  digitalWrite(ledPin, HIGH); 
  delay(val);               // Blink rate set by pot value (milliseconds)
  digitalWrite(ledPin, LOW);
  delay(val);              // Turn led off for the same period as it was turned on 

}
