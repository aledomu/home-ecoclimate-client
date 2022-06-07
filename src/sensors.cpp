#include <RestClient.h>
#include <ArduinoJson.h>
#include "sensors.h"
#include "drivers/DHT11HumAndTemp.h"

static RestClient client("192.168.251.93", 80);
static DHT11HumAndTemp sensor(14);  // D5
static String groupId;

void setupSensors(String gid) {
    groupId = gid;
}

void handleSensors() {
    DHTResult<float> humidMeasure = sensor.getHumidity();
    if (humidMeasure.error == 0) {
        StaticJsonDocument<100> humidJson;
        humidJson["groupId"] = groupId;
        humidJson["sensorId"] = "test-humid";
        humidJson["ratio"] = humidMeasure.result;

        String humidBody;
        serializeJson(humidJson, humidBody);
        String humidResponse;
        client.post("/humidity", humidBody.c_str(), &humidResponse);
        Serial.print("Humidity POST result: ");
        Serial.println(humidResponse);
    }

    DHTResult<float> tempMeasure = sensor.getTemperature();
    if (tempMeasure.error == 0) {
        StaticJsonDocument<100> tempJson;
        tempJson["groupId"] = groupId;
        tempJson["sensorId"] = "test-temp";
        tempJson["celsius"] = tempMeasure.result;

        String tempBody;
        serializeJson(tempJson, tempBody);
        String tempResponse;
        client.post("/temperature", tempBody.c_str(), &tempResponse);
        Serial.print("Temperature POST result: ");
        Serial.println(tempResponse);
    }

    delay(10000);
}