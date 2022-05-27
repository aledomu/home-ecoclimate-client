#include "DHT11HumAndTemp.h"

DHT11HumAndTemp::DHT11HumAndTemp(uint8_t signalPin) : sensor(signalPin) {}

DHTResult<float> DHT11HumAndTemp::getHumidity() {
    DHTResult<float> res;
    res.error = sensor.read2(NULL, &res.result, NULL);

    return res;
}

DHTResult<float> DHT11HumAndTemp::getTemperature() {
    DHTResult<float> res;
    res.error = sensor.read2(&res.result, NULL, NULL);

    return res;
}