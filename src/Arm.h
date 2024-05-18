#ifndef _ARM_H
#define _ARM_H
#include <Adafruit_PWMServoDriver.h>
#include <ServoDriver.h>

#define OUT 1
#define IN -1
#define EXTENSION 1
#define RETRACTION -1
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
        Servo Rotation;
        Servo Extension;

    public:
        int LS1;
        int LS2;
        int LS3;
        int LS4;

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
            @param direction The direction of the servo (CLOCKWISE or ANTICLOCKWISE)
            @param speed The speed of the servo from 0 to 100
        */
        void setRotation(int direction, int speed);

        /*!
            @brief Set the extension servo speed and direction
            @param direction The direction of the servo (CLOCKWISE or ANTICLOCKWISE)
            @param speed The speed of the servo from 0 to 100
        */

        void setExtension(int direction, int speed);
};

extern Arm Arm1; // ROT 0, EXT, 1
extern Arm Arm2; // ROT 0, EXT, 1
extern Arm Arm3; // ROT 0, EXT, 1
extern Arm Arm4; // ROT 0, EXT, 1
extern Arm Arm5; // ROT 0, EXT, 1
extern Arm Arm6; // ROT 0, EXT, 1

void LS11ISR();
void LS12ISR();
void LS13ISR();
void LS14ISR();

void LS21ISR();
void LS22ISR();
void LS23ISR();
void LS24ISR();

void LS31ISR();
void LS32ISR();
void LS33ISR();
void LS34ISR();

void LS41ISR();
void LS42ISR();
void LS43ISR();
void LS44ISR();

void LS51ISR();
void LS52ISR();
void LS53ISR();
void LS54ISR();

void LS61ISR();
void LS62ISR();
void LS63ISR();
void LS64ISR();

#endif