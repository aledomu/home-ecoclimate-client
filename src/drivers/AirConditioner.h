#pragma once

#include <stdint.h>

class AirConditioner {

    public:
        virtual void setTempChange(int8_t tempChange);
        virtual void setFanSpeed(int8_t fanSpeed);
        virtual ~AirConditioner();

};