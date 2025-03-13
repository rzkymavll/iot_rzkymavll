#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
}

void loop() {
  Serial.println("Red");
  digitalWrite(33, HIGH);
  delay(5000);
  digitalWrite(33, LOW);

  Serial.println("Yellow");
  digitalWrite(25, HIGH);
  delay(1000);
  digitalWrite(25, LOW);

  Serial.println("Green");
  digitalWrite(26, HIGH);
  delay(5000);
  digitalWrite(26, LOW);
}