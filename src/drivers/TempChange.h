#pragma once

#include <stdint.h>

/**
 * @brief Interfaz que especifica cómo regular el control de temperatura
 */
class TempChange {

    public:
        /**
         * @param tempChange Ajusta el nivel de calor o frío. Valores posibles: -128 a 127.
         *                   Valores negativos activan el calentamiento y positivos el
         *                   enfriamiento.
         */
        virtual void setTempChange(int8_t tempChange);

};