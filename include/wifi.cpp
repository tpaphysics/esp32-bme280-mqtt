#include <WiFi.h>
#include "./env/env.wifi.h"

void wifi_connect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // CONFIGURE
    IPAddress local_IP(192, 168, 0, 50);
    IPAddress gateway(192, 168, 0, 1);
    IPAddress subnet(255, 255, 0, 0);
    IPAddress primaryDNS(8, 8, 8, 8);
    IPAddress secondaryDNS(8, 8, 4, 4);

    if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS))
    {
        Serial.println("STA Failed to configure");
    }

    Serial.print("Connecting to WiFi ...");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(WiFi.localIP());
}
