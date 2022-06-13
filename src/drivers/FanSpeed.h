#pragma once

#include <stdint.h>

/**
 * @brief Interfaz que especifica cómo controlar la velocidad del ventilador
 */
class FanSpeed {

    public:
        /**
         * @param fanSpeed Ajusta la velocidad de giro. Valores posibles: 0 a 255.
         */
        virtual void setFanSpeed(uint8_t fanSpeed);

};