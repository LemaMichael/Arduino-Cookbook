/*
 * Detect the length of time a switch has been in its current state.
 * or increment the value while a switch is pushed and want the 
 * rate to increase the longer the switch is held. (Clocks)
 * 
 * 
 * 
 * Code debounces the switch and accelerates the rate which counter increased
 * for when the switch is held for longer periods
 * - Holding the switch more than 1 sec. increases the increment rate by 4 and 4 sec. by a rate of 10.
 */

const int ledPin = 13;
const int inputPin = 2;

const int debounceTime = 20; // Milliseconds 
const int fastIncrement = 1000;     // Increment this fast after 1 second
const int veryFastIncrement = 4000; // Increment this fast after 4 seconds.
int count = 0;              // Decrements every tenth of a second until reaches 0


void setup() {
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin, HIGH); // Turn on pull-up resistor

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


/* Return the time in milliseconds that the switch has been pressed (L0W) */
long switchTime() 
{
  static unsigned long startTime = 0; //Time switch state change was first detected
  static boolean state;               // Current state of the switch

  if(digitalRead(inputPin) != state) // check to see if the switch has changed state
  {
    state = !state;
    startTime = millis(); // store the time.
  }
  if (state == LOW) 
    return millis() - startTime;     // Switch pushed, return time in milliseconds
  else 
    return 0;                       // Switch has not been pushed.
  
}

void loop() {
  
  int duration = switchTime();
  if (duration > veryFastIncrement)
    count += 10;
  else if (duration > fastIncrement) 
    count += 4;
  else if (duration > debounceTime)
    count += 1;
  else 
  {
    // The switch is not pressed
    if (count == 0) 
      digitalWrite(ledPin, HIGH); // Turn the LED ON
    else  
    {
      digitalWrite(ledPin, LOW);  //  Turn the LED OFF
      count -= 1;
    }
  }

  Serial.println(count);
  delay(100);

}
