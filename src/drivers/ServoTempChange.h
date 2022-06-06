#pragma once

#include <Servo.h>
#include "TempChange.h"

class ServoTempChange : public TempChange {

    private:
        Servo servo;

    public:
        // servoPin: Número de pin al cual la señal del servo está conectado
        ServoTempChange(uint8_t servoPin);
        // servoPin: Número de pin al cual la señal del servo está conectado
        // servoMin: Ancho del pulso, en microsegundos, correspondiente al
        // ángulo mínimo en el servo (0º)
        // servoMax: Ancho del pulso, en microsegundos, correspondiente al
        // ángulo máximo en el servo (180º)
        ServoTempChange(uint8_t servoPin, uint16_t servoMin, uint16_t servoMax);
        // Ajusta el grado de cambio de la temperatura
        void setTempChange(int8_t tempChange);

};