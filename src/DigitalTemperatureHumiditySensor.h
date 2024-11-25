#ifndef DigitalTemperatureHumiditySensor_h
#define DigitalTemperatureHumiditySensor_h

#include "Arduino.h"
#include <DHT.h> // Include the DHT library

class DigitalTemperatureHumiditySensor {
public:
    // Constructor: Takes the pin number and the type of DHT sensor
    DigitalTemperatureHumiditySensor(int pin, int type = DHT11);

    // Initialize the sensor
    void beginDigitalTemperatureHumiditySensor();

    // Get temperature in Celsius
    float getDTemperatureC();

    // Get temperature in Fahrenheit
    float getDTemperatureF();

    // Get humidity percentage
    float getDHumidity();

private:
    DHT _dht; // DHT sensor object
    int _pin; // Digital pin connected to the DHT sensor
};

#endif
