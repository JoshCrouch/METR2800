#include <Arduino.h>
#include <Pins.h>
#include <Arm.h>
#include <ServoDriver.h>
#include <Scheduler.h>

// Create each arm
Arm Arm_1(1, 0, 1); // ROT 0, EXT, 1

// Prototype functions so they can be referenced later on
void startSequence();
void Arm1StartUp();


void setup() {
  // Initialise the PWMServoDriver
  startServoDriver();

  // Initialise the serial terminal and wait for it to start
  Serial.begin(115200);

  // Wait a second before starting
  delay(1000);

  // Run the initial startup sequence
  void startSequence();
}

void startSequence() {
  Arm_1.setRotation(BALL, 100);
  Scheduler::schedule(6000, Arm1StartUp);
}

void loop() {
  // Check limit switches for each arm
  Arm_1.checkLimitSwitches();

  // Update the Scheduler
  Scheduler::update();
}

void Arm1StartUp() {
    // Slowly rotate towards home to stop arm from falling
    Arm_1.setRotation(HOME, 1);

    // Begin Extension at full speed
    Arm_1.setExtension(EXTENSION, 100);
}