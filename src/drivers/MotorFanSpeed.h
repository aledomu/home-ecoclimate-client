#pragma once

#include <L293.h>
#include "FanSpeed.h"

class MotorFanSpeed : public FanSpeed {

    private:
        L293 motor;

    public:
        /**
         * @param speedPin Número de pin con el que se controla la velocidad del motor
         * @param forwardPin Número de pin con el que se indica el sentido de avance al motor
         * @param backwardPin Número de pin con el que se indica el sentido de retroceso al motor
         */
        MotorFanSpeed(uint8_t speedPin, uint8_t forwardPin, uint8_t backwardPin);
        void setFanSpeed(uint8_t fanSpeed);

};