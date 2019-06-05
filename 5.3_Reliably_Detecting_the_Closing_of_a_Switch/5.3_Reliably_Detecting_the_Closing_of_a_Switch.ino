/*
 * - Avoid false readings due to contact bounce
 * 
 * 
 * Debounce Sketch
 */

int count; // Store the number of presses
const int inputPin = 2;
const int ledPin = 13; 
const int debounceDelay = 100; // milliseconds to wait until stable

// Returns true if the switch in the given pin is closed and stable
boolean debounce(int pin) {
  boolean state;
  boolean previousState;

  previousState = digitalRead(pin); // Store switch state
  for(int counter = 0; counter < debounceDelay; counter++) {
    delay(1);                    // Wait for 1 millisecond
    state = digitalRead(pin);   // Read the pin
    if (state != previousState) 
    {
      counter = 0;
      previousState = state;   // sace the current state
    }
  }
  // Here when the switch state has been stable longer than the debounce period. (Using pull-up resistors instead of pull-down)
  // low means pressed since pull-ups is being used
  return state;
}
 
void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (debounce(inputPin)) 
  {
    digitalWrite(ledPin, HIGH);
    count++;
    Serial.println(count); 
  }

}
