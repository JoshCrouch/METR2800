#include <Arduino.h>

void setup() {
  pinMode(1, OUTPUT); //4.1
  pinMode(43, OUTPUT); //4.2
  pinMode(4, OUTPUT); //4.3
  pinMode(6, OUTPUT); //4.4
}

int pins[] = {1,43,4,6};

void loop() {
  for (int i = 0; i < 4; i++){
    digitalWrite(pins[i], HIGH);
    delay(100);
    digitalWrite(pins[i], LOW);
    delay(200);
  }
}