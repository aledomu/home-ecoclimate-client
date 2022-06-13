#include <SimpleDHT.h>
#include "Humidity.h"
#include "Temperature.h"

/**
 * @brief Resultado de la medición del sensor DHT11 con código de error
 * 
 * @tparam T Tipo de valor de la medición
 */
template <class T>
struct DHTResult {
    int error;
    T result;
};

class DHT11HumAndTemp : public Humidity<DHTResult<float>>, public Temperature<DHTResult<float>> {

    private:
        SimpleDHT11 sensor;

    public:
        /**
         * @param signalPin Pin de señal del sensor DHT11
         */
        DHT11HumAndTemp(uint8_t signalPin);
        DHTResult<float> getHumidity();
        DHTResult<float> getTemperature();

};