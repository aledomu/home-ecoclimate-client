#pragma once

#include <Servo.h>
#include "WindowBlind.h"

class ServoWB : public WindowBlind {

    private:
        Servo servo;

    public:
        /**
         * @param pin Número de pin al cual la señal del servo está conectado
         */
        ServoWB(uint8_t pin);
        /**
         * @param pin Número de pin al cual la señal del servo está conectado
         * @param min Ancho del pulso, en microsegundos, correspondiente al
         *            ángulo mínimo en el servo (0º)
         * @param max Ancho del pulso, en microsegundos, correspondiente al
         *            ángulo máximo en el servo (180º)
         */
        ServoWB(uint8_t pin, uint16_t min, uint16_t max);
        void setAngle(uint8_t angle);

};