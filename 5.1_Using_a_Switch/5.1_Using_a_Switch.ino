// 5.1 Using a Switch

/*
 * Make the sketch respond to the 
 * closing of an electrical contact
 * 
 */


const int ledPin = 13;
const int inputPin = 2; // Input pin for pushbutton

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(inputPin, INPUT);
}

void pullDown() {
  int val = digitalRead(inputPin); // Read input value
  if (val == HIGH) 
    digitalWrite(ledPin, HIGH); // Turn the LED on if switch is pressed
  else 
    digitalWrite(ledPin, LOW); 

    // Second Way
//    digitalWrite(ledPin, digitalRead(inputPin));
}


void pullUp() {
  int val = digitalRead(inputPin);
  if (val == HIGH) 
    digitalWrite(ledPin, LOW); // Turn LED OFF
  else 
    digitalWrite(ledPin, HIGH);
}

void loop() {
  //pullDown();
  pullUp();


}
