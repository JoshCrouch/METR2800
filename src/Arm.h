#ifndef _ARM_H
#define _ARM_H
#include <Adafruit_PWMServoDriver.h>

struct Servo {
    /*
        Number: the pwm number of the servo
        Speed: the speed of the servo (-100 to 100)
    */
    int number;
    int speed;
};

class Arm {
    private:
        Servo Rotation;
        Servo Extension;

        int LS1;
        int LS2;
        int LS3;
        int LS4;

        void setServoSpeed();

    public:
        Arm();
        void setRotation(int dir, int speed);
        void setExtension(int dir, int speed);
};

#endif