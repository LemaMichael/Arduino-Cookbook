// 3.13 Setting and Reading Bits

/*
 * Use the << (bit-shift left)
 * and >> (bit-shift right) operators
 * to shift the bits of a value.
 * 
 * 
 * NOTE: Arduino Controller chip can shift 
 * bits more efficiently than it can multiply and divide
 */

void setup() {
  Serial.begin(9600);

  int x = 6;
  Serial.print("The value of x: ");
  Serial.println(x);
  int result = x << 1;  // Same as x * 2
  Serial.print("Using bit-shift left, the new value is: ");
  Serial.println(result);

  result = x >> 2; // Same as x / 4
  Serial.print("Using bit-shift right, the new value is: ");
  Serial.println(result);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
