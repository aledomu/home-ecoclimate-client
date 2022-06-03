#pragma once

#include <ESP8266WiFi.h>

void setupActuators(WiFiClient espClient, String gid);

void handleActuators();