#include "MotorAndServoAC.h"

MotorAndServoAC::MotorAndServoAC(uint8_t speedPin, uint8_t forwardPin, uint8_t backwardPin, uint8_t servoPin) :
    motor(speedPin, forwardPin, backwardPin),
    servo()
{
    servo.attach(servoPin);
}

MotorAndServoAC::MotorAndServoAC( uint8_t speedPin,
                                  uint8_t forwardPin,
                                  uint8_t backwardPin,
                                  uint8_t servoPin,
                                  uint16_t servoMin,
                                  uint16_t servoMax   ) :
    motor(speedPin, forwardPin, backwardPin),
    servo()
{
    servo.attach(servoPin, servoMin, servoMax);
}

void MotorAndServoAC::setTempChange(int8_t tempChange) {
    servo.write((int) map(tempChange, -100, 100, 0, 180));
}

void MotorAndServoAC::setFanSpeed(uint8_t fanSpeed) {
    motor.forward(fanSpeed);
}