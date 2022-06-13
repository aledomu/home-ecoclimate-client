// Nota: el sistema de actuadores y sensores son mutuamente excluyentes. Para
//       habilitar uno u otro, descomentar las líneas comentadas y comentar
//       la inmediatamente inferior.

#include <ESP8266WiFi.h>
// #include "actuators.h"
#include "sensors.h"

const String SSID("NombreConexion");
const String PSK("ContraseñaConexion");

void setup_wifi() {
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
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup() {
    Serial.begin(9600);
    setup_wifi();
    // setupActuators("unique");
    setupSensors("unique");
}

void loop() {
    // handleActuators();
    handleSensors();
}