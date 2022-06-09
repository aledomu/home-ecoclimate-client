#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "actuators.h"
#include "drivers/MotorFanSpeed.h"
#include "drivers/ServoWB.h"
#include "drivers/ServoTempChange.h"

static const String mqttServer("192.168.0.155");

static WiFiClient wifiC;
static PubSubClient client(wifiC);
static ServoTempChange tempServo(4);      // D2
static ServoWB angleServo(0);             // D3
static MotorFanSpeed motor(14, 12, 13);   // D5, D6, D7
static String groupId;

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP8266Client")) {
            Serial.println("connected");
            client.subscribe((groupId + "/tempIndex").c_str(), 1);
            client.subscribe((groupId + "/fanSpeed").c_str(), 1);
            client.subscribe((groupId + "/angle").c_str(), 1);
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void callbackAdapter(char *topic_, byte *payload_, unsigned int length, void (*f)(String, String)) {
    String topic;
    size_t topic_len = strlen(topic_);
    for (size_t i = 0; i < topic_len; i++)
        topic += topic_[i];

    String payload;
    for (size_t i = 0; i < length; i++)
        payload += ((char *) payload_)[i];

    f(topic, payload);
}

template <class T>
void handleMessage(String topic, String payload, void (*setDevice)(T)) {
    T value = (T) atoi(payload.c_str());

    setDevice(value);

    Serial.print("Etiqueta: ");
    Serial.print(topic);
    Serial.print("; payload: ");
    Serial.print(payload);
    Serial.print("; valor: ");
    Serial.println(value);
}

void callback(char *topic, byte *payload, unsigned int length) {
    callbackAdapter(topic, payload, length, [](String topic, String payload) {
        if (topic == groupId + "/tempIndex") {
            handleMessage<int8_t>(topic, payload, [](int8_t value) {
                tempServo.setTempChange(value);
            });
        } else if (topic == groupId + "/fanSpeed") {
            handleMessage<uint8_t>(topic, payload, [](uint8_t value) {
                motor.setFanSpeed(value);
            });
        } else if (topic == groupId + "/angle") {
            handleMessage<uint8_t>(topic, payload, [](uint8_t value) {
                angleServo.setAngle(value);
            });
        }
    });
}

void setupActuators(const String gid) {
    groupId = gid;
    client.setServer(mqttServer.c_str(), 1883);
    client.setCallback(callback);
}

void handleActuators() {
    if (!client.loop()) {
        reconnect();
    }
}