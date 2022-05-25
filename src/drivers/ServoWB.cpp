#include "ServoWB.h"

ServoWB::ServoWB(uint8_t pin) {
    servo.attach(pin);
}

ServoWB::ServoWB(uint8_t pin, uint16_t min, uint16_t max) {
    servo.attach(pin, min, max);
}

void ServoWB::setAngle(uint8_t angle) {
    servo.write(angle > 180 ? 180 : angle);
}