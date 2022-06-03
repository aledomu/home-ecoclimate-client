#include <RestClient.h>
#include <ArduinoJson.h>
#include "sensors.h"

static RestClient client("192.168.251.93", 80);

void handleSensors() {
    // For humidity
    StaticJsonDocument<100> humidJson;
    humidJson["id"] = "test-humid";
    humidJson["ratio"] = 50.0;

    String humidBody;
    serializeJson(humidJson, humidBody);
    String humidResponse;
    client.post("/humidity", humidBody.c_str(), &humidResponse);

    // For temperature
    StaticJsonDocument<100> tempJson;
    tempJson["id"] = "test-temp";
    tempJson["celsius"] = 50.0;

    String tempBody;
    serializeJson(tempJson, tempBody);
    String tempResponse;
    client.post("/temperature", tempBody.c_str(), &tempResponse);

    delay(10000);
}