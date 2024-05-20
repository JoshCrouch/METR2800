#include "Arm.h"
#include "Pins.h"
#include <Adafruit_PWMServoDriver.h>
#include <ServoDriver.h>
#include <Scheduler.h>

Arm::Arm(int arm_number, int RotationServoNumber, int ExtensionServoNumber) {
    this->arm_number = arm_number;

    // Limit Switch Pin Assignment
    switch (arm_number) {
        case 1:
            this->LS1 = LS11;
            this->LS2 = LS12;
            this->LS3 = LS13;
            this->LS4 = LS14;
        case 2:
            this->LS1 = LS21;
            this->LS2 = LS22;
            this->LS3 = LS23;
            this->LS4 = LS24;
        case 3:
            this->LS1 = LS31;
            this->LS2 = LS32;
            this->LS3 = LS33;
            this->LS4 = LS34;
        case 4:
            this->LS1 = LS41;
            this->LS2 = LS42;
            this->LS3 = LS43;
            this->LS4 = LS44;
        case 5:
            this->LS1 = LS51;
            this->LS2 = LS52;
            this->LS3 = LS53;
            this->LS4 = LS54;
        case 6:
            this->LS1 = LS61;
            this->LS2 = LS62;
            this->LS3 = LS63;
            this->LS4 = LS64;
        case 7:
            this->LS1 = LS41;
            this->LS2 = LS42;
            this->LS3 = LS52;
            this->LS4 = LS44;
    }

    // Attach Interrupts
    pinMode(this->LS1, INPUT);
    pinMode(this->LS2, INPUT);
    pinMode(this->LS3, INPUT);
    pinMode(this->LS4, INPUT);

    // Set Servo Numbers
    this->Rotation.number = RotationServoNumber;
    this->Extension.number = ExtensionServoNumber;

}

void Arm::setRotation(int dir, int speed) {
    this->Rotation.speed = dir * speed;
    updateServoSpeed(this->Rotation.number, this->Rotation.speed);
}

void Arm::setExtension(int dir, int speed) {
    this->Extension.speed = dir * speed;
    updateServoSpeed(this->Extension.number, this->Extension.speed);
}

void Arm::checkLimitSwitches() {
    if (digitalRead(this->LS1) == HIGH && !this->LS1Hit) {
        LS1Func();
        this->LS1Hit = true;
    }
    if (digitalRead(this->LS2) == HIGH && !this->LS2Hit && this->LS1Hit) {
        LS2Func();
        this->LS2Hit = true;
    }
    if (digitalRead(this->LS3) == HIGH && !this->LS3Hit && this->LS2Hit) {
        LS3Func();
        this->LS3Hit = true;
    }
    if (digitalRead(this->LS4) == HIGH && !this->LS4Hit && this->LS3Hit) {
        LS4Func();
        this->LS4Hit = true;
    }
}

/*!
    @brief Function to run when the extension limit switch is hit 
*/
void Arm::LS1Func() {
    // Print Switch hit
    Serial.print("Arm ");
    Serial.print(this->arm_number);
    Serial.println(", Extension Switch (1) hit!");
    
    // Stop extending
    this->setExtension(STOP, 0);

    // Go towards ball
    this->setRotation(BALL, 10);
}

/*!
    @brief Function to run when the cup limit switch is hit 
*/
void Arm::LS2Func() {
    // Print Switch hit
    Serial.print("Arm ");
    Serial.print(this->arm_number);
    Serial.println(", Cup Switch (2) hit!");
    
    // Start retracting
    this->setExtension(RETRACTION, 100);

    // Slowly rotate to home
    this->setRotation(HOME, 5);
}

/*!
    @brief Function to run when the retraction limit switch is hit 
*/
void Arm::LS3Func() {
    // Print Switch hit
    Serial.print("Arm ");
    Serial.print(this->arm_number);
    Serial.println(", Retraction Switch (3) hit!");
    
    // Stop retracting
    this->setExtension(RETRACTION, 20);

    // Quickly rotate home
    this->setRotation(HOME, 25);
}

/*!
    @brief Function to run when the home limit switch is hit 
*/
void Arm::LS4Func() {
    // Print Switch hit
    Serial.print("Arm ");
    Serial.print(this->arm_number);
    Serial.println(", Home Switch (4) hit!");
    
    // Start retracting
    this->setExtension(STOP, 0);

    // Slowly rotate to home
    this->setRotation(STOP, 0);
}
