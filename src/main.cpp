#include <Arduino.h>
#include <Pins.h>
#include <Arm.h>
#include <ServoDriver.h>

int currentDirectionRotation = 1;
int currentDirectionExtension = 1;

// ARM4
void LS41ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(OUT, 100);
}
void LS42ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
    //delay(1000);
    Arm4.setRotation(STOP, 0);
    Arm4.setExtension(RETRACTION, 100);
}
void LS43ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
}
void LS44ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(STOP, 0);
}

void setup() {
  Arm1.setRotation(OUT, 100);
  //delay(1000);
  Arm1.setRotation(STOP, 0);
  Arm1.setExtension(OUT, 100);
}

void loop () {
  if (digitalRead(LS41) == HIGH) {
    LS41ISR();
  } else if (digitalRead(LS42) == HIGH) {
    LS42ISR();
  } else if (digitalRead(LS43) == HIGH) {
    LS43ISR();
  } else if (digitalRead(LS44) == HIGH) {
    LS44ISR();
  }
}