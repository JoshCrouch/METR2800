#include "Arm.h"
#include "Pins.h"
#include <Adafruit_PWMServoDriver.h>
#include <ServoDriver.h>

Arm Arm1(1, 0, 2); // ROT 0, EXT, 1
Arm Arm2(2, 0, 2); // ROT 0, EXT, 1
Arm Arm3(3, 0, 2); // ROT 0, EXT, 1
Arm Arm4(4, 0, 2); // ROT 0, EXT, 1
Arm Arm5(5, 0, 2); // ROT 0, EXT, 1
Arm Arm6(6, 0, 2); // ROT 0, EXT, 1

Arm::Arm(int arm_number, int RotationServoNumber, int ExtensionServoNumber) {

    // Limit Switch Pin Assignment
    switch (arm_number) {
        case 1:
            this->LS1 = LS11;
            this->LS2 = LS12;
            this->LS3 = LS13;
            this->LS4 = LS14;

            attachInterrupt(this->LS1, LS11ISR, RISING);
            attachInterrupt(this->LS2, LS12ISR, RISING);
            attachInterrupt(this->LS4, LS14ISR, RISING);
        case 2:
            this->LS1 = LS21;
            this->LS2 = LS22;
            this->LS3 = LS23;
            this->LS4 = LS24;

            attachInterrupt(this->LS1, LS21ISR, RISING);
            attachInterrupt(this->LS2, LS22ISR, RISING);
            attachInterrupt(this->LS4, LS24ISR, RISING);
        case 3:
            this->LS1 = LS31;
            this->LS2 = LS32;
            this->LS3 = LS33;
            this->LS4 = LS34;

            attachInterrupt(this->LS1, LS31ISR, RISING);
            attachInterrupt(this->LS2, LS32ISR, RISING);
            attachInterrupt(this->LS4, LS34ISR, RISING);
        case 4:
            this->LS1 = LS41;
            this->LS2 = LS42;
            this->LS3 = LS43;
            this->LS4 = LS44;

            attachInterrupt(this->LS1, LS41ISR, RISING);
            attachInterrupt(this->LS2, LS42ISR, RISING);
            attachInterrupt(this->LS4, LS44ISR, RISING);
        case 5:
            this->LS1 = LS51;
            this->LS2 = LS52;
            this->LS3 = LS53;
            this->LS4 = LS54;

            attachInterrupt(this->LS1, LS51ISR, RISING);
            attachInterrupt(this->LS2, LS52ISR, RISING);
            attachInterrupt(this->LS4, LS54ISR, RISING);
        case 6:
            this->LS1 = LS61;
            this->LS2 = LS62;
            this->LS3 = LS63;
            this->LS4 = LS64;

            attachInterrupt(this->LS1, LS61ISR, RISING);
            attachInterrupt(this->LS2, LS62ISR, RISING);
            attachInterrupt(this->LS4, LS64ISR, RISING);

        break;
    }

    // Set Servo Numbers
    this->Rotation.number = RotationServoNumber;
    this->Extension.number = ExtensionServoNumber;
}

void Arm::detachAllInterrupts() {
    detachInterrupt(this->LS1);
    detachInterrupt(this->LS2);
    detachInterrupt(this->LS3);
    detachInterrupt(this->LS4);
}

void Arm::setRotation(int direction, int speed) {
    this->Rotation.speed = direction * speed;
    updateServoSpeed(this->Rotation.number, this->Rotation.speed);
}

void Arm::setExtension(int direction, int speed) {
    this->Extension.speed = direction * speed;
    updateServoSpeed(this->Extension.number, this->Extension.speed);
}

// LS1 - Extended
// LS2 - Cup
// LS3 - Retraction
// LS4 - ROTHome

// ARM1
void LS11ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(OUT, 100);
    attachInterrupt(Arm4.LS3, LS43ISR, RISING);
}
void LS12ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
    delay(1000);
    Arm4.setRotation(STOP, 0);
    Arm4.setExtension(RETRACTION, 100);
}
void LS13ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
}
void LS14ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(STOP, 0);
    Arm4.detachAllInterrupts();
}

//ARM2
void LS21ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(OUT, 100);
    attachInterrupt(Arm4.LS3, LS43ISR, RISING);
}
void LS22ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
    delay(1000);
    Arm4.setRotation(STOP, 0);
    Arm4.setExtension(RETRACTION, 100);
}
void LS23ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
}
void LS24ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(STOP, 0);
    Arm4.detachAllInterrupts();
}

// ARM3
void LS31ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(OUT, 100);
    attachInterrupt(Arm4.LS3, LS43ISR, RISING);
}
void LS32ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
    delay(1000);
    Arm4.setRotation(STOP, 0);
    Arm4.setExtension(RETRACTION, 100);
}
void LS33ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
}
void LS34ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(STOP, 0);
    Arm4.detachAllInterrupts();
}

// ARM4
void LS41ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(OUT, 100);
    attachInterrupt(Arm4.LS3, LS43ISR, RISING);
}
void LS42ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
    delay(1000);
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
    Arm4.detachAllInterrupts();
}

// ARM5
void LS51ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(OUT, 100);
    attachInterrupt(Arm4.LS3, LS43ISR, RISING);
}
void LS52ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
    delay(1000);
    Arm4.setRotation(STOP, 0);
    Arm4.setExtension(RETRACTION, 100);
}
void LS53ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
}
void LS54ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(STOP, 0);
    Arm4.detachAllInterrupts();
}

// ARM6
void LS61ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(OUT, 100);
    attachInterrupt(Arm4.LS3, LS43ISR, RISING);
}
void LS62ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
    delay(1000);
    Arm4.setRotation(STOP, 0);
    Arm4.setExtension(RETRACTION, 100);
}
void LS63ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(IN, 100);
}
void LS64ISR() {
    Arm4.setExtension(STOP, 0);
    Arm4.setRotation(STOP, 0);
    Arm4.detachAllInterrupts();
}