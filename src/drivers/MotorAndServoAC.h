#pragma once

#include <stdint.h>
#include <L293.h>
#include <PWMServo.h>
#include "AirConditioner.h"

class MotorAndServoAC : public AirConditioner {

    private:
        L293 motor;
        PWMServo servo;

    public:
        // speedPin: Número de pin con el que se controla la velocidad del motor
        // forwardPin: Número de pin con el que se indica el sentido de avance al motor
        // backwardPin: Número de pin con el que se indica el sentido de retroceso al motor
        // servoPin: Número de pin al cual la señal del servo está conectado
        MotorAndServoAC(uint8_t speedPin, uint8_t forwardPin, uint8_t backwardPin, uint8_t servoPin);
        // servoPin: Número de pin al cual la señal del servo está conectado
        // servoMin: Ancho del pulso, en microsegundos, correspondiente al
        // ángulo mínimo en el servo (0º)
        // servoMax: Ancho del pulso, en microsegundos, correspondiente al
        // ángulo máximo en el servo (180º)
        MotorAndServoAC( uint8_t speedPin,
                         uint8_t forwardPin,
                         uint8_t backwardPin,
                         uint8_t servoPin,
                         uint16_t servoMin,
                         uint16_t servoMax    );
        // Ajusta el grado de cambio de la temperatura
        void setTempChange(int8_t tempChange);
        // Ajusta la velocidad de ventilación
        void setFanSpeed(uint8_t fanSpeed);

};