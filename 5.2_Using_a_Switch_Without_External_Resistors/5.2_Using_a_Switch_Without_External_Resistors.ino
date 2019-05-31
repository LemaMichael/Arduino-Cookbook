
/*
 * Elimate external pull-up resistors when connecting switches.
 * 
 */

 const int ledPin = 13;
 const int inputPin = 2;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin, HIGH); // turn on internall pull-up on the inputPin.

}

void loop() {
  int val = digitalRead(inputPin); 
  if (val == HIGH) 
    digitalWrite(ledPin, LOW); // Turn LED OFF
  else 
    digitalWrite(ledPin, HIGH);

}
