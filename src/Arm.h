#ifndef _ARM_H
#define _ARM_H
#include <Adafruit_PWMServoDriver.h>
#include <ServoDriver.h>

#define BALL -1
#define HOME 1
#define EXTENSION -1
#define RETRACTION 1
#define STOP 0

/*!
    @brief A struct to define servos

    @param number The number PWM output number
    @param speed The speed of the servo from -100 to 100
*/
struct Servo {
    int number;
    int speed;
};

/*!
    @brief A class to manage each arm
*/
class Arm {
    private:
        int arm_number;

        Servo Rotation;
        Servo Extension;

        int LS1;
        int LS2;
        int LS3;
        int LS4;

        bool LS1Hit = false;
        bool LS2Hit = false;
        bool LS3Hit = false;
        bool LS4Hit = false;

        void LS1Func();
        void LS2Func();
        void LS3Func();
        void LS4Func();

    public:
        /*!
            @brief  Instantiates a new Arm
            @param  arm_number Number the arm is
            @param  PWM Address of the PWMServoDriver
            @param  RotationServoNumber The PWM number for the Rotation Servo
            @param  ExtensionServoNumber The PWM number for the Extension Servo
        */
        Arm(int arm_number, int RotationServoNumber, int ExtensionServoNumber);

        /*!
            @brief Set the rotation servo speed and direction
            @param dir The direction of the servo represented as either -1 or 1
            @param speed The speed of the servo from 0 to 100
        */
        void setRotation(int dir, int speed);

        /*!
            @brief Set the extension servo speed and direction
            @param dir The direction of the servo represented as either -1 or 1
            @param speed The speed of the servo from 0 to 100
        */
        void setExtension(int dir, int speed);

        /*!
            @brief Polls every limit switch in the arm and calls related hit Func if hit
        */
        void checkLimitSwitches();

        void startUp();
};

#endif