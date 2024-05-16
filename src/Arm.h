#ifndef _ARM_H
#define _ARM_H
#include <Adafruit_PWMServoDriver.h>

/*!
    @brief A struct
*/
struct Servo {
    int number;
    int speed;
};

class Arm {
    private:
        Servo Rotation;
        Servo Extension;
        Adafruit_PWMServoDriver * PWM;

        int LS1;
        int LS2;
        int LS3;
        int LS4;

        void setServoSpeed();

    public:
        Arm(int arm_number, Adafruit_PWMServoDriver * PWM, int RotationServoNumber, int ExtensionServoNumber);
        void setRotation(int dir, int speed);
        void setExtension(int dir, int speed);
};

#endif