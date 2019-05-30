// 2.3 Using Floating-Point Numbers
/*
 * Initialized a float value to 1.1
 * It Repeatedly reduces the value by 0.1 until the value is 0
 * 
 */

 float value = 1.1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = value - 0.1; 
  if (value == 0) 
    Serial.println("The value is zero!");
  else if (fabs(value) < 0.0001)  // Function to take the absolute value of a float
    Serial.println("The value is close enought to zero.");
  else 
    Serial.println(value);

   delay(100);
}
