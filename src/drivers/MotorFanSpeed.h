#pragma once

#include <L293.h>
#include "FanSpeed.h"

class MotorFanSpeed : public FanSpeed {

    private:
        L293 motor;

    public:
        // speedPin: Número de pin con el que se controla la velocidad del motor
        // forwardPin: Número de pin con el que se indica el sentido de avance al motor
        // backwardPin: Número de pin con el que se indica el sentido de retroceso al motor
        MotorFanSpeed(uint8_t speedPin, uint8_t forwardPin, uint8_t backwardPin);
        // Ajusta la velocidad de ventilación
        void setFanSpeed(uint8_t fanSpeed);

};