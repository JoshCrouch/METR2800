#include <Arduino.h>
#include <Pins.h>
#include <Adafruit_PWMServoDriver.h>

void setup() {
  //pinMode(LS11, OUTPUT); //4.1
  //pinMode(LS12, OUTPUT); //4.2
  //pinMode(LS13, OUTPUT); //4.3
  //pinMode(LS14, OUTPUT); //4.4
}

int pins[] = {LS11,LS12,LS13,LS14};

void loop() {
  for (int i = 0; i < 4; i++){
    digitalWrite(pins[i], HIGH);
    delay(100);
    digitalWrite(pins[i], LOW);
    delay(200);
  }
}