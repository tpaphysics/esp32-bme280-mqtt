#include <ArduinoJson.h>

String json_stringfy(float temperature, float humidity, float pressure, float altitude)
{
    StaticJsonDocument<1024> obj;

    obj["temperature"] = serialized(String(temperature, 2));
    obj["humidity"] = serialized(String(humidity, 2));
    obj["pressure"] = serialized(String(pressure, 2));
    obj["altitude"] = serialized(String(altitude, 2));

    String payload;
    serializeJson(obj, payload);

    return payload;
}