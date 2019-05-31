/*
 * Send serial data from Arduino displayed
 * as text, decimal values, hexadecimal
 * or binary
 * 
 * 
 * 
 * Print values in various formats to the serial port
 * This Sketch uses the Streaming Library for C++-style output 
 */

 #include <Streaming.h>

 char chrValue = 65; 
 int intValue = 65;
 float floatValue = 65.0;
 

void setup() {
  Serial.begin(9600);

}

void loop() {

  Serial << "chrValue: " << chrValue << ", Dec: " << _DEC(chrValue) << endl;

  Serial << "intValue: " << intValue << ", Dec: " << _DEC(intValue) << ", Hex: " << _HEX(intValue) << ", Oct: " << _OCT(intValue) << ", Bin: "<< _BIN(intValue) << endl;

  Serial << "floatValue: " << floatValue << endl;

  delay(1000);
  chrValue++;
  intValue++;
}
