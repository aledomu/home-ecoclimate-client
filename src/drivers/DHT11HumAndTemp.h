#include <SimpleDHT.h>
#include "Humidity.h"
#include "Temperature.h"

template <class T>
struct DHTResult {
    int error;
    T result;
};

class DHT11HumAndTemp : public Humidity<DHTResult<float>>, public Temperature<DHTResult<float>> {

    private:
        SimpleDHT11 sensor;

    public:
        DHT11HumAndTemp(uint8_t signalPin);
        DHTResult<float> getHumidity();
        DHTResult<float> getTemperature();

};