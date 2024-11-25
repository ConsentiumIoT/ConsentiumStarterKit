#include "DigitalTemperatureHumiditySensor.h"

// Constructor: Initializes the DHT sensor
DigitalTemperatureHumiditySensor::DigitalTemperatureHumiditySensor(int pin, int type)
    : _dht(pin, type), _pin(pin) {}

// Initialize the DHT sensor
void DigitalTemperatureHumiditySensor::beginDigitalTemperatureHumiditySensor() {
    _dht.begin();
}

// Get temperature in Celsius
float DigitalTemperatureHumiditySensor::getDTemperatureC() {
    float temp = _dht.readTemperature();
    if (isnan(temp)) {
        Serial.println("[Error] Failed to read temperature in Celsius!");
        return -1.0; // Return -1.0 to indicate an error
    }
    return temp;
}

// Get temperature in Fahrenheit
float DigitalTemperatureHumiditySensor::getDTemperatureF() {
    float temp = _dht.readTemperature(true);
    if (isnan(temp)) {
        Serial.println("[Error] Failed to read temperature in Fahrenheit!");
        return -1.0; // Return -1.0 to indicate an error
    }
    return temp;
}

// Get humidity percentage
float DigitalTemperatureHumiditySensor::getDHumidity() {
    float humidity = _dht.readHumidity();
    if (isnan(humidity)) {
        Serial.println("[Error] Failed to read humidity!");
        return -1.0; // Return -1.0 to indicate an error
    }
    return humidity;
}
