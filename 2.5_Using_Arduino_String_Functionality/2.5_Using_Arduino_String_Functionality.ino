//2.5 Working with Groups of Values

String text1 = "This String";
String text2 = " has more Text";
String text3; // To be assigned

void setup() {
  Serial.begin(9600);

  Serial.print(text1);
  Serial.print(" is ");
  Serial.print(text1.length());
  Serial.println(" characters long.");

  Serial.print("text 2 is ");
  Serial.print(text2.length());
  Serial.println(" characters long.");

  text1.concat(text2); // Cobines the contents of strings
  Serial.println("text1 now contains: ");
  Serial.println(text1);

  // Another way to combines strings 
  text3 = text1 + " and more";
  Serial.println(text3);

  // To convert a C-style character array to an Arduino String
  char oldString[] = "I want this character array in a String object";
  String newString = oldString;
  Serial.println(newString);

}

void loop() {
  // put your main code here, to run repeatedly:

}
