/*
 * 
 * NOTE: Using a 4x4 kepad instead of a SparkFun 12-Button Keypad
 * 
 * Prints the key pressed on a keypad to the serial port
 */
#include <Streaming.h>

const int numRows = 4;
const int numCols = 4; 
const int debounceTime = 20; // # of Milliseconds for switch to be stable

 // keymap defines the character returned when the corresponding key is pressed
 const char keymap[numRows][numCols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
 };

 // This array determines the pins used for rows and columns
 const int rowPins[numRows] = {9,8,7,6}; // Rows 0 - 3
 const int colPins[numCols] = {5,4,3,2}; // Columns 0 - 3

 
void setup() {
  Serial.begin(9600);
  for(int row = 0; row < numRows; row++)
  {
    pinMode(rowPins[row], INPUT);
    digitalWrite(rowPins[row], HIGH); // Turn on PULL-UPS
  }
  for(int column = 0; column < numCols; column++) 
  {
    pinMode(colPins[column], OUTPUT);     // Set column pins as outputs for writing
    digitalWrite(colPins[column], HIGH); // Make all columns inactive
  }
}

void loop() {
  char key = getKey();
  if (key != 0) // If the character is not 0, we have a valid key press
  {
    Serial << "Got Key " << key << endl;
  }
}


// Returns the key pressed or 0 if no key is pressed
char getKey() 
{
  char key = 0;       // 0 indicated no key pressed

  for(int column = 0; column < numCols; column++) 
  {
    digitalWrite(colPins[column], LOW);  // Activate the current column
    for(int row = 0; row < numRows; row++) 
    {
      if(digitalRead(rowPins[row]) == LOW) // Is a key pressed?
      {
        delay(debounceTime);
        while(digitalRead(rowPins[row]) == LOW); // Wait for key to be released
        key = keymap[row][column];                 // Remember which key was pressed;
      }
    }
    digitalWrite(colPins[column], HIGH);      // Deactivate the current column
  }
  return key; 
}
