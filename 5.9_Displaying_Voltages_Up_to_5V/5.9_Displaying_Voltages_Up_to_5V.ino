/*
 * Display the voltage of a single 1.5V cell on the Serial Monitor
 * 
 * - DO NOT CONNECT MORE THAN 5V DIRECTLY TO AN ARDUINO PIN
 */

 #include<Streaming.h>

const int referenceVolts = 5;
const int  batteryPin = 0;
 

void setup() {
  Serial.begin(9600);

}

// Print the value using decimal points
void loop() {
  int val = analogRead(batteryPin);   // Read the value from the sensor
  Serial << val / (1023/5) << endl;   // Print the integer value of the voltage
  Serial << "." << val % (1023/5) << endl; // Print the fraction
}
