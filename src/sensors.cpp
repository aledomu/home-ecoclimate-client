#include <RestClient.h>
#include <ArduinoJson.h>
#include "sensors.h"
#include "drivers/DHT11HumAndTemp.h"

static RestClient client("192.168.251.93", 80);
static DHT11HumAndTemp sensor(5);  // D1
static String groupId;

void setupSensors(String gid) {
    groupId = gid;
}

template <class T, size_t N>
void sendDHTMeasure(
    String sensorName,
    String sensorId,
    String resourceAddress,
    DHTResult<T> (*getMeasure)(),
    void (*setMeasureInJson)(StaticJsonDocument<N>&, DHTResult<T>)
) {
    DHTResult<T> measure = getMeasure();
    Serial.print(sensorName);
    Serial.print(" error code: ");
    Serial.print(measure.error);
    Serial.print("; Value: ");
    Serial.println(measure.result);
    if (measure.error == SimpleDHTErrSuccess) {
        StaticJsonDocument<N> json;
        json["groupId"] = groupId;
        json["sensorId"] = sensorId;
        setMeasureInJson(json, measure);

        String body;
        serializeJson(json, body);
        String response;
        int code = client.post(resourceAddress.c_str(), body.c_str(), &response);
        Serial.print(sensorName);
        Serial.print(" POST return code: ");
        Serial.println(code);
    }
}

void handleSensors() {
    sendDHTMeasure<float, 200>(
        "Humidity",
        "test-humid",
        "/humidity",
        []() { return sensor.getHumidity(); },
        [](auto humidJson, auto humidMeasure) { humidJson["ratio"] = humidMeasure.result; }
    );

    sendDHTMeasure<float, 200>(
        "Temperature",
        "test-temp",
        "/temperature",
        []() { return sensor.getTemperature(); },
        [](auto tempJson, auto tempMeasure) { tempJson["celsius"] = tempMeasure.result; }
    );

    delay(10000);
}