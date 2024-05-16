#include <Arduino.h>
#include <Pins.h>
#include <Arm.h>
#include <ServoDriver.h>

Arm arm1(1, 0, 2); // ROT 0, EXT, 1

void setup() {
  // Initialise the PWMServoDriver
  startServoDriver();
  Serial.begin(115200);

  delay(10);
}

void loop() {
  arm1.setRotation(-1, 100);
  arm1.setExtension(1, 100);
  delay(500);

  Serial.println("Speed: 0");
  arm1.setRotation(0, 0);
  arm1.setExtension(0, 0);
  delay(500);

  Serial.println("Speed: 100");
  arm1.setRotation(1, 100);
  arm1.setExtension(-1, 100);
  delay(500);

  Serial.println("Speed: 0");
  arm1.setRotation(0, 0);
  arm1.setExtension(0, 0);
  delay(500);
}