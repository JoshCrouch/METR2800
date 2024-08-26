#include <Arduino.h>
#include <Pins.h>
#include <Arm.h>
#include <ServoDriver.h>
#include <Scheduler.h>

// Prototype functions so they can be referenced later on
void startSequence();
void Arm1StartUp();

Arm Arm_1(7, 0, 1);

//#define RESET

// Reset function to help with rewinding the arms
#ifdef RESET
void setup() {
  Wire.begin(SDA, SCL);
  PWM.begin();
  PWM.setOscillatorFrequency(27000000);
  PWM.setPWMFreq(50);

  Serial.begin(115200);
  
  Arm_1.setExtension(RETRACTION, 50);
}

void loop() {
  if (digitalRead(LS13) == HIGH) {
    Arm_1.setRotation(STOP, 0);
  }
}
#endif

#ifndef RESET
void setup() {
  // Initialise the PWMServoDriver
  startServoDriver();

  // Initialise the serial terminal and wait for it to start
  Serial.begin(115200);

  // Wait a second before starting
  delay(3000);
  Serial.println("Delay Finished");

  // Run the initial startup sequence
  startSequence();
}

void startSequence() {
  Serial.println("Start Arm 1");
  Arm_1.setRotation(BALL, 25);
  Arm_1.setExtension(EXTENSION, 25);
  Scheduler::schedule(12000, Arm1StartUp);
}

void loop() {
  // Check limit switches for each arm
  Arm_1.checkLimitSwitches();

  // Update the Scheduler
  Scheduler::update();
}

inline void Arm1StartUp() {
    // Slowly rotate towards home to stop arm from falling
    Arm_1.setRotation(BALL, 1);

    // Begin Extension at full speed
    Arm_1.setExtension(EXTENSION, 100);
}

#endif