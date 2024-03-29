#include "ServoTempChange.h"

ServoTempChange::ServoTempChange(uint8_t servoPin) :
    servo()
{
    servo.attach(servoPin);
}

ServoTempChange::ServoTempChange(uint8_t servoPin, uint16_t servoMin, uint16_t servoMax) :
    servo()
{
    servo.attach(servoPin, servoMin, servoMax);
}

void ServoTempChange::setTempChange(int8_t tempChange) {
    servo.write((int) map(
        tempChange,
        std::numeric_limits<int8_t>::min(),
        std::numeric_limits<int8_t>::max(),
        0,
        180
    ));
}