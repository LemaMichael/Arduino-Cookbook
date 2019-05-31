/*
 * Sending text and data to be displayed 
 * on your PC using Ardunio IDE.
 * 
 * 
 * Prints numbers to the serial port
 */

int number = 0;
 
void setup() {
  Serial.begin(9600); // Send & Receive at 9600 baud
}

void loop() {
  Serial.print("The number is ");
  Serial.println(number); 

  delay(500); // delay half second between numbers
  number++; // to the text number

}
