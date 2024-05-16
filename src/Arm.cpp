#include "Arm.h"
#include "Pins.h"
#include <Adafruit_PWMServoDriver.h>

/*!
    @brief  Instantiates a new Arm
    @param  arm_number Number the arm is
    @param  PWM Address of the PWMServoDriver
    @param  RotationServoNumber The PWM number for the Rotation Servo
    @param  ExtensionServoNumber The PWM number for the Extension Servo
 */
Arm::Arm(int arm_number, Adafruit_PWMServoDriver *PWM, int RotationServoNumber, int ExtensionServoNumber) {

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
    }

    // Attach Interrupts

    // Assign PWM driver
    this->PWM = PWM;

    // Set Servo Numbers
    this->Rotation.number = RotationServoNumber;
    this->Extension.number = ExtensionServoNumber;

}


void Arm::setServoSpeed() {
    // Write servo speeds with 
    this->PWM->setPWM(this->Extension.number, );
    this->PWM->setPWM(this->Extension.number, );
    
}

/*!
    @brief Set the rotation servo speed and direction
    @param dir The direction of the servo represented as either -1 or 1
    @param speed The speed of the servo from 0 to 100
*/
void Arm::setRotation(int dir, int speed) {
    this->Rotation.speed = dir * speed;
}

/*!
    @brief Set the extension servo speed and direction
    @param dir The direction of the servo represented as either -1 or 1
    @param speed The speed of the servo from 0 to 100
*/
void Arm::setExtension(int dir, int speed) {
    this->Extension.speed = dir * speed;
}