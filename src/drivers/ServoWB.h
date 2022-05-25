#pragma once

#include <PWMServo.h>
#include "WindowBlind.h"

class ServoWB : public WindowBlind {

    private:
        PWMServo servo;

    public:
        // pin: Número de pin al cual la señal del servo está conectado
        ServoWB(uint8_t pin);
        // pin: Número de pin al cual la señal del servo está conectado
        // min: Ancho del pulso, en microsegundos, correspondiente al
        // ángulo mínimo en el servo (0º)
        // max: Ancho del pulso, en microsegundos, correspondiente al
        // ángulo máximo en el servo (180º)
        ServoWB(uint8_t pin, uint16_t min, uint16_t max);
        // Ajusta al ángulo indicado, saturando el valor en 180 si es superado
        void setAngle(uint8_t angle);

};