/*
 * - Display the voltage of a 9V Battery
 * and trigger an alarm LED when the voltage
 * falls below a certain level.
 */

const int referenceVolts = 5; // Default reference on a 5-volt board

const int R1 = 1000; // Value for a maximum voltage of 10 Volts
const int R2 = 1000;

// Determine by voltage resistors
const int resistorFactor = 511;
const int batteryPin = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  float val = analogRead(batteryPin);  // Read value from the sensor (The variable is of type float)
  //Serial.println(val);
  float volts = (val/resistorFactor) * referenceVolts; // Calculate the ratio
  Serial.println(volts);  // Print the value in volts

}
