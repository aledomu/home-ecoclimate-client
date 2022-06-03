#include <ESP8266WiFi.h>
#include "sensors.h"

static const String SSID("NombreConexion");
static const String PSK("ContraseñaConexion");

void setup_wifi() {
    delay(10);

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(SSID);

    /*
     * Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     * would try to act as both a client and an access-point and could cause
     * network-issues with your other WiFi-devices on your WiFi-network.
     */
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PSK);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  setupSensors("unique");
  setup_wifi();
}

void loop() {
    handleSensors();
}