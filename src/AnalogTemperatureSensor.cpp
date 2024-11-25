#include "AnalogTemperatureSensor.h"

AnalogTemperatureSensor::AnalogTemperatureSensor(int sensorPin) {
    _sensorPin = sensorPin; // Assign the analog pin
}

float AnalogTemperatureSensor::readSensor() {
    // Convert analog reading to millivolts
    return analogRead(_sensorPin) * (ADC_VREF_mV / ADC_RESOLUTION);
}

float AnalogTemperatureSensor::readTemperatureC() {
    // LM35 provides 10mV per degree Celsius
    float milliVolt = readSensor();
    return milliVolt / 10.0;
}

float AnalogTemperatureSensor::readTemperatureF() {
    // Convert Celsius to Fahrenheit
    float tempC = readTemperatureC();
    return tempC * 9.0 / 5.0 + 32.0;
}
