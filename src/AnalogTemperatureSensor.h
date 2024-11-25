#ifndef AnalogTemperatureSensor_h
#define AnalogTemperatureSensor_h

#include "Arduino.h"

// Define ADC reference voltage in millivolts
#define ADC_VREF_mV 3300.0

// Define ADC resolution based on platform
#if defined(ESP8266)
    #define ADC_RESOLUTION 1024.0
#elif defined(ESP32)
    #define ADC_RESOLUTION 4096.0
#else
    #define ADC_RESOLUTION 1024.0 // Default resolution for other platforms
#endif

class AnalogTemperatureSensor {
public:
    AnalogTemperatureSensor(int sensorPin); // Constructor
    float readTemperatureC();              // Get temperature in Celsius
    float readTemperatureF();              // Get temperature in Fahrenheit

private:
    int _sensorPin;                        // Analog pin connected to the sensor
    float readSensor();                    // Read raw analog sensor value
};

#endif
