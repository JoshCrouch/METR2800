#ifndef _SERVODRIVER_H
#define _SERVODRIVER_H

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <Pins.h>

#define USMIN  500 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2500 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600

extern Adafruit_PWMServoDriver PWM;

void startServoDriver();
void updateServoSpeed(int number, int speed);


#endif