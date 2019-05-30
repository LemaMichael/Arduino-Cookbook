// 2.6 Using C Character Strings

void setup() {
  Serial.begin(9600);
  char StringA[8]; // declare a string of up to 7 chars plus terminating null
  char StringB[8] = "Arduino"; // as above and initialize the string to "Arduino"

  char StringC[16] = "Arduino"; // The string has room to grow
  char StringD[ ] = "Arduino"; // The compiler inits the string

  // Determine the number of characters before the null/
  int length = strlen(StringB);
  Serial.println(length);

  // Copy one string to another
  Serial.print("StringB is: ");
  Serial.println(StringB);
  strcpy(StringB,"Hello"); 
  Serial.print("StringB changed to: ");
  Serial.println(StringB);


  // Limit the number of characters to copy
  strncpy(StringB, "mad", 2); // Copy up to 2 characters from source to destination
  Serial.println(StringB);
  
  // Append one String to the end of another
  strcat(StringB, " !");
  Serial.println(StringB);

  // Compare two strings
  if (strcmp(StringD, StringC) == 0) {
    Serial.println("StringD and StringC are equal.");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
