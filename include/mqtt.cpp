#include <WiFi.h>
#include <PubSubClient.h>
#include "./env/env.mqtt.h"

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_connect()

{
    client.setServer(MQTT_SERVER, MQTT_PORT);
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP32Client", MQTT_USER, MQTT_PASS))
        {
            Serial.println("connected");
            // client.subscribe(TOPIC);
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void send_msg_mqtt(String msg)
{
    if (!client.connected())
    {
        reconnect();
    }

    char payload[120];
    msg.toCharArray(payload, 120);

    if (client.publish(MQTT_TOPIC, payload) == true)
    {
        Serial.println("Success sending message");
    }
    else
    {
        Serial.println("Error sending message");
    }

    client.loop();
}