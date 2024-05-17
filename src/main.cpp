#include <Arduino.h>
#include <Pins.h>
#include <Arm.h>
#include <ServoDriver.h>

// Define an array of Arm objects
Arm arms[] = {
    Arm(1, 0, 2),
    /*
    Arm(2, 0, 3),
    Arm(3, 0, 4),
    Arm(4, 0, 5),
    Arm(5, 0, 6),
    Arm(6, 0, 7)
    */
};

// Calculate the number of arms
const int numArms = sizeof(arms) / sizeof(arms[0]);

int currentDirectionRotation = 1;
int currentDirectionExtension = 1;

const int ext = 2; // Extension
const int ret = 0; // Rotation
const int clo = 4; // Clockwise
const int ant = 5; // Anti-Clockwise

// Flags for ISR-triggered stops
volatile bool stopExtension = false;
volatile bool stopRotation = false;

// Forward declarations for the ISR functions
void stopExt();
void stopRet();
void stopClo();
void stopAnt();

void setup() {
  // Initialise the PWMServoDriver
  Serial.begin(115200);
  Serial.print("begin");
  startServoDriver();

  
  pinMode(LS41, INPUT);
  pinMode(LS42, INPUT);

  // Set up limit switch pins as input with internal pull-up
  pinMode(ext, INPUT_PULLUP); 
  pinMode(ret, INPUT_PULLUP); 
  pinMode(clo, INPUT_PULLUP); 
  pinMode(ant, INPUT_PULLUP);

  // Initialise limit switches
  attachInterrupt(digitalPinToInterrupt(ext), stopExt, FALLING);
  attachInterrupt(digitalPinToInterrupt(ret), stopRet, FALLING);
  attachInterrupt(digitalPinToInterrupt(clo), stopClo, FALLING);
  attachInterrupt(digitalPinToInterrupt(ant), stopAnt, FALLING);

  delay(10);
}

void manageServoDirection() {
  // Read the state of the limit switches
  int limitSwitchStaterotation = digitalRead(LS41);
  int limitSwitchStateExtension = digitalRead(LS42);

  // Debug output for limit switch states
  Serial.print("LS41: ");
  Serial.println(limitSwitchStaterotation);
  Serial.print("LS42: ");
  Serial.println(limitSwitchStateExtension);

  // Manage rotation based on the limit switch state
  if (limitSwitchStaterotation == HIGH) {
    if (currentDirectionRotation == 1) {
      currentDirectionRotation = -1;
      for (int i = 0; i < numArms; i++) {
        arms[i].setRotation(currentDirectionRotation, 100);
      }
      Serial.println("Changing to anticlockwise rotation");
    }
  } else {
    if (currentDirectionRotation == -1) {
      currentDirectionRotation = 1;
      for (int i = 0; i < numArms; i++) {
        arms[i].setRotation(currentDirectionRotation, 100);
      }
      Serial.println("Changing to clockwise rotation");
    }
  }

  // Manage extension based on the limit switch state
  if (limitSwitchStateExtension == HIGH) {
    if (currentDirectionExtension == 1) {
      currentDirectionExtension = -1;
      for (int i = 0; i < numArms; i++) {
        arms[i].setExtension(currentDirectionExtension, 100);
      }
      Serial.println("Changing to retraction");
    }
  } else {
    if (currentDirectionExtension == -1) {
      currentDirectionExtension = 1;
      for (int i = 0; i < numArms; i++) {
        arms[i].setExtension(currentDirectionExtension, 100);
      }
      Serial.println("Changing to extension");
    }
  }
}

void loop() {
  // Manage the servo direction based on the limit switch state
  manageServoDirection();
  delay(50); // Small delay to prevent too rapid switching

  // Uncommented original loop logic adapted for array of arms
  for (int i = 0; i < numArms; i++) {
    arms[i].setRotation(0, 0);
    arms[i].setExtension(1, 100);
  }


  if (digitalRead(LS41) == HIGH) {
    for (int i = 0; i < numArms; i++) {
      arms[i].setRotation(-1, 100);
      arms[i].setExtension(0, 0);
    }
  
  }
  if (digitalRead(LS42) == HIGH) {
    for (int i = 0; i < numArms; i++) {
      arms[i].setRotation(1, 100);
      arms[i].setExtension(0, 0);
    }
  }

  delay(500);
  Serial.println("Speed: 0");
  for (int i = 0; i < numArms; i++) {
    arms[i].setRotation(0, 0);
    arms[i].setExtension(0, 0);
  }
  delay(1000);

  Serial.println("Speed: 100");
  for (int i = 0; i < numArms; i++) {
    arms[i].setRotation(1, 100);
    arms[i].setExtension(-1, 100);
  }
  delay(500);

  Serial.println("Speed: 0");
  for (int i = 0; i < numArms; i++) {
    arms[i].setRotation(0, 0);
    arms[i].setExtension(0, 0);
  }
  delay(1000);
}

void stopExt() {
  for (int i = 0; i < numArms; i++) {
    arms[i].setExtension(0, 0);
  }
  stopExtension = true;
}

void stopRet() {
  for (int i = 0; i < numArms; i++) {
    arms[i].setExtension(0, 0);
  }
  stopExtension = true;
}

void stopClo() {
  for (int i = 0; i < numArms; i++) {
    arms[i].setRotation(0, 0);
  }
  stopRotation = true;
}

void stopAnt() {
  for (int i = 0; i < numArms; i++) {
    arms[i].setRotation(0, 0);
  }
  stopRotation = true;
}
