// 2.7 Splitting comma seperated Text into groups

String message = "Peter,Paul,Mary"; 
int commaPosition; // the position of the next comma in the string


void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println(message); // Show the source string
  do {
    commaPosition = message.indexOf(',');
    if (commaPosition != -1) {
      Serial.println(message.substring(0,commaPosition));
      message = message.substring(commaPosition+1,message.length());
    } else {
      // Here after the last comma is found
      if (message.length() > 0) 
        Serial.println(message); // if there is text after the last comma, print it
    }
  } while (commaPosition >= 0);
  delay(5000);

}
