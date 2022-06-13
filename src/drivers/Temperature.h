#pragma once

#include <stdint.h>

/**
 * @brief Interfaz que especifica cómo obtener una medición de temperatura
 * 
 * @tparam T Tipo de valor de medición
 */
template <class T>
class Temperature {

    public:
        virtual T getTemperature();

};