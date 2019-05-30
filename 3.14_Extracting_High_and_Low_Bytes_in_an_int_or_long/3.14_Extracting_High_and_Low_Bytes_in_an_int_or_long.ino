/* 
 *  Extract the high or low byte of an integer. 
 * This is useful for sending integer values 
 * as bytes on a serial or other communication lines
 * 
 * 
 * lowbyte(i) is the least significant byte from an integer.
 * highbyte(i) the most significant byte from an integer
 *
 */

 int intValue = 258; // 258 in hex notation is 0x102

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lowWord, hiWord;
  byte loByte, hiByte;

  hiByte = highByte(intValue);
  loByte = lowByte(intValue);

  Serial.println(intValue, DEC);
  Serial.println(intValue, HEX);
  Serial.println(loByte, DEC);
  Serial.println(hiByte, DEC);

  delay(10000); 

}
