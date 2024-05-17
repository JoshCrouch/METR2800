#include <Arduino.h>
#include <Pins.h>
#include <Arm.h>
#include <ServoDriver.h>

Arm arm1(1, 0, 2); // ROT 0, EXT, 1

int currentDirectionRotation = 1;
int currentDirectionExtension = 1;

// const int ext = 2; // Extension
// const int ret = 0; // Rotation
// const int clo = 4; // Clockwise
// const int ant = 5; // Anti-Clockwise

// Flags for ISR-triggered stops
// volatile bool stopExtension = false;
// volatile bool stopRotation = false;

// Forward declarations for the ISR functions
// void stopExt();
// void stopRet();
// void stopClo();
// void stopAnt();

void setup() {
  // Initialise the PWMServoDriver
  startServoDriver();
  Serial.begin(115200);
  pinMode(LS41, INPUT);
  pinMode(LS42, INPUT);


  // Set up limit switch pins as input with internal pull-up
  // pinMode(ext, INPUT_PULLUP); 
  // pinMode(ret, INPUT_PULLUP); 
  // pinMode(clo, INPUT_PULLUP); 
  // pinMode(ant, INPUT_PULLUP);

  // // Initialise limit switches
  // attachInterrupt(digitalPinToInterrupt(ext), stopExt, FALLING);
  // attachInterrupt(digitalPinToInterrupt(ret), stopRet, FALLING);
  // attachInterrupt(digitalPinToInterrupt(clo), stopClo, FALLING);
  // attachInterrupt(digitalPinToInterrupt(ant), stopAnt, FALLING);



  delay(10);
}

void manageServoDirection() {
  // Read the state of the limit switch
  int limitSwitchStaterotation = digitalRead(LS41);
  int limitSwitchStateExtension = digitalRead(LS42);


  // Check if the limit switch is triggered (HIGH)
  if (limitSwitchStaterotation == HIGH) {
    // If currently moving clockwise, change to anticlockwise
    if (currentDirectionRotation == 1) {
      currentDirectionRotation = -1;
      arm1.setRotation(currentDirectionRotation, 100);
      Serial.println("Changing to anticlockwise rotation");
    }
  } else {
    // If currently moving anticlockwise, change to clockwise
    if (currentDirectionRotation == -1) {
      currentDirectionRotation = 1;
      arm1.setRotation(currentDirectionRotation, 100);
      Serial.println("Changing to clockwise rotation");
    }
  }
  if (limitSwitchStateExtension == HIGH) {
    // If currently moving clockwise, change to anticlockwise
    if (currentDirectionExtension == 1) {
      currentDirectionExtension = -1;
      arm1.setExtension(currentDirectionExtension, 100);
      Serial.println("Changing to anticlockwise rotation");
    }
  } else {
    // If currently moving anticlockwise, change to clockwise
    if (currentDirectionExtension == -1) {
      currentDirectionExtension = 1;
      arm1.setExtension(currentDirectionExtension, 100);
      Serial.println("Changing to clockwise rotation");
    }
  }
}

void loop() {
  // Manage the servo direction based on the limit switch state
  manageServoDirection();
  delay(50); // Small delay to prevent too rapid switching
}

// void loop() {
//   arm1.setRotation(0, 0);
//   //arm1.setExtension(1, 100);
//    if (digitalRead(LS41) == HIGH) {
//     arm1.setRotation(-1, 100);
//   //   arm1.setExtension(0, 0);
//   }
//    if (digitalRead(LS42) == HIGH) {
//      arm1.setRotation(1, 100);
//   }
  // delay (500);
  //   Serial.println("Speed: 0");
  //   arm1.setRotation(0, 0);
  //  // arm1.setExtension(0, 0);
  //   delay(1000);

  //   Serial.println("Speed: 100");
  //   arm1.setRotation(1, 100);
  //   //arm1.setExtension(-1, 100);
  //   delay(500);

  //   Serial.println("Speed: 0");
  //   arm1.setRotation(0, 0);
  //   //arm1.setExtension(0, 0);
  //   delay(1000);
  
// void stopExt(){
//   arm1.setExtension(0,0);
//   stopRotation = true;
// }
// void stopRet(){
//   arm1.setExtension(0,0);
//   stopRotation = true;
// }
// void stopClo(){
//   arm1.setRotation(0,0);
//   stopRotation = true;
// }
// void stopAnt(){
//   arm1.setRotation(0,0);
//   stopRotation = true;
// }