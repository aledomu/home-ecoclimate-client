#pragma once

#include <stdint.h>

/**
 * @brief Interfaz que especifica cómo obtener una medición de humedad
 * 
 * @tparam T Tipo de valor de medición
 */
template <class T>
class Humidity {

    public:
        virtual T getHumidity();

};