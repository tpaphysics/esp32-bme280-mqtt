#include <Wire.h>
#include <Adafruit_BME280.h>
#include "utils.cpp"

#define I2C_ESP32 0x76
#define SEALEVELPRESSURE_HPA (1013.25)
#define SENSOR_MENSURE_DALAY 5000

Adafruit_BME280 bme; // use I2C interface

void start_bme()
{
    if (!bme.begin(I2C_ESP32))
    {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
        while (1)
            delay(10);
    }
    Serial.println(F("BME280 Sensor event test"));
}

String bme_mensure_json()
{
    String payload = json_stringfy(bme.readTemperature(), bme.readHumidity(), bme.readPressure(), bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(payload);
    // delay(SENSOR_MENSURE_DALAY);

    return payload;
}

void bme_serial_test()
{

    Serial.print(F("Temperature = "));
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Humidity = "));
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.print(F("Pressure = "));
    Serial.print(bme.readPressure());
    Serial.println(" hPa");

    Serial.print(F("Altitude = "));
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.println();
    delay(SENSOR_MENSURE_DALAY);
}
