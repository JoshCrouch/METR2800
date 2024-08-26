#include <ServoDriver.h>

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <Pins.h>

Adafruit_PWMServoDriver PWM(0x40, Wire);

/*!
    @brief Instantiates the servo driver
*/
void startServoDriver() {
    Wire.begin(SDA, SCL);
    PWM.begin();
    PWM.setOscillatorFrequency(27000000);
    PWM.setPWMFreq(50);
}

/*!
    @brief Updates the servo speed

    @param number The number servo
    @param speed The speed the servo should move at from -100 to 100
*/
void updateServoSpeed(int number, int speed) {
    int ExtensionPulseLen = map(speed, -100, 100, USMIN, USMAX);
    PWM.writeMicroseconds(number, ExtensionPulseLen);
}