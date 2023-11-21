#include <SoftwareSerial.h>

// Define SoftwareSerial object
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);  // Serial monitor
  mySerial.begin(9600); // SoftwareSerial
}

void loop() {
  while (mySerial.available()) {
    String c = mySerial.readString();
    Serial.println(c);
  }
}
