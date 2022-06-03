#include <PubSubClient.h>
#include "actuators.h"
#include "drivers/MotorFanSpeed.h"
#include "drivers/ServoWB.h"
#include "drivers/ServoTempChange.h"

static const String mqttServer("192.168.0.155");

static PubSubClient client;
static ServoTempChange tempServo(3);
static ServoWB angleServo(4);
static MotorFanSpeed motor(6, 7, 8);
static String groupId;

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP8266Client")) {
            Serial.println("connected");
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
        topic += ((char *) payload_)[i];

    f(topic, payload);
}

void callback(char *topic, byte *payload, unsigned int length) {
    callbackAdapter(topic, payload, length, [](String topic, String payload) {
        Serial.println("Etiqueta: " + topic + ", mensaje: " + payload);

        if (topic == groupId + "/tempIndex") {
            int8_t value = (int8_t) atoi(payload.c_str());

            tempServo.setTempChange(value);
            Serial.println("Etiqueta: tempIndex; payload: ");
            Serial.print(payload);
            Serial.print("; valor: ");
            Serial.println(value);
        } else if (topic == groupId + "/fanSpeed") {
            uint8_t value = (uint8_t) atoi(payload.c_str());

            motor.setFanSpeed(value);
            Serial.println("Etiqueta: tempIndex; payload: ");
            Serial.print(payload);
            Serial.print("; valor: ");
            Serial.println(value);
        } else if (topic == groupId + "/angle") {
            uint8_t value = (uint8_t) atoi(payload.c_str());

            angleServo.setAngle(value);
            Serial.println("Etiqueta: tempIndex; payload: ");
            Serial.print(payload);
            Serial.print("; valor: ");
            Serial.println(value);
        }
    });
}

void setupActuators(WiFiClient espClient, String gid) {
    groupId = gid;
    PubSubClient client(espClient);
    client.setServer(mqttServer.c_str(), 1883);
    client.setCallback(callback);
}

void handleActuators() {
    if (!client.loop()) {
        reconnect();
    }
}