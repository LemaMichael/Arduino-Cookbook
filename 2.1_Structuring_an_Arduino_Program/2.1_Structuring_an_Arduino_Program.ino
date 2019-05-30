// 2.1 Structuring An Arduino Program

const int ledPin = 13; // LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT); // initialize the digital pin as output
}

void loop() {
  digitalWrite(ledPin,HIGH); // Turn on LED
  delay(1000); // Wait 1 second
  digitalWrite(ledPin, LOW); // Turn off LED
  delay(1000);
}
