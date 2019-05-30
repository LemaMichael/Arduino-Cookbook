//3.12 You want to read or set a particular bit in a numeric variable

/*
 * Flag is a programming term
 * for values that store the 
 * state of some aspect of 
 * the program.
 * 
 */

byte flags = 0; // These examples set, clear or read bits in a variable called flags.


// bitSet Example
void setFlag(int flagNumber) {
  bitSet(flags, flagNumber);
}


// bitClear example
void clearFlag(int flagNumber) {
  bitClear(flags, flagNumber);
}


// bitPosition example
int getFlag(int flagNumber) {
  return bitRead(flags, flagNumber);
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  showFlags();
  setFlag(2);
  setFlag(5);
  showFlags();
  clearFlag(2);
  showFlags();

  delay(10000); // wait 10 seconds
}

// reports flags that are set
void showFlags() 
{
  for(int flag = 0; flag < 8; flag++) 
  {
    if (getFlag(flag)==true) 
      Serial.print("* bit set for flag ");
    else 
      Serial.print("bit clear for flag ");

    Serial.println(flag);
  }
  Serial.println();
}
