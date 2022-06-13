#include "MotorFanSpeed.h"

MotorFanSpeed::MotorFanSpeed(uint8_t speedPin, uint8_t forwardPin, uint8_t backwardPin) :
    motor(speedPin, forwardPin, backwardPin) {}

void MotorFanSpeed::setFanSpeed(uint8_t fanSpeed) {
    if (fanSpeed == 0) {
        motor.stop();
    } else {
        motor.forward(fanSpeed);
    }
}