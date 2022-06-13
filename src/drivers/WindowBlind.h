#pragma once

#include <stdint.h>

/**
 * @brief Interfaz que indica el nivel de apertura de la persiana (vertical)
 */
class WindowBlind {

    public:
        /**
         * @param angle Ajusta el grado de apertura. Valores posibles: 0 a 255.
         */
        virtual void setAngle(uint8_t angle);

};