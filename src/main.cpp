#include <Arduino.h>
#include <Pins.h>
#include <Arm.h>
#include <ServoDriver.h>

int currentDirectionRotation = 1;
int currentDirectionExtension = 1;

void setup() {
  Arm1.setRotation(OUT, 100);
  delay(1000);
  Arm1.setRotation(STOP, 0);
  Arm1.setExtension(OUT, 100);
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
      //arm1.setRotation(currentDirectionRotation, 100);
      Serial.println("Changing to anticlockwise rotation");
    }
  } else {
    // If currently moving anticlockwise, change to clockwise
    if (currentDirectionRotation == -1) {
      currentDirectionRotation = 1;
      //arm1.setRotation(currentDirectionRotation, 100);
      Serial.println("Changing to clockwise rotation");
    }
  }
  if (limitSwitchStateExtension == HIGH) {
    // If currently moving clockwise, change to anticlockwise
    if (currentDirectionExtension == 1) {
      currentDirectionExtension = -1;
      //arm1.setExtension(currentDirectionExtension, 100);
      Serial.println("Changing to anticlockwise rotation");
    }
  } else {
    // If currently moving anticlockwise, change to clockwise
    if (currentDirectionExtension == -1) {
      currentDirectionExtension = 1;
      //arm1.setExtension(currentDirectionExtension, 100);
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