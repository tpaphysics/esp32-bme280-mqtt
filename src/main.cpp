#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "wifi.cpp"
#include "bme280.cpp"
#include "mqtt.cpp"

void setup()
{
  Serial.begin(115200);
  wifi_connect();
  start_bme();
  mqtt_connect();
}

void loop()
{
  // bme_serial_test();
  send_msg_mqtt(bme_mensure_json());

  delay(5000);
}
