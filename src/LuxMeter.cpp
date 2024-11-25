#include "LuxMeter.h"

LuxMeter::LuxMeter(int sensorPin) {
    _sensorPin = sensorPin; // Assign the analog pin
}

float LuxMeter::readSensor() {
    // Convert analog reading to millivolts
    return analogRead(_sensorPin) * (ADC_VREF_mV / ADC_RESOLUTION);
}

float LuxMeter::readIntensityValue(int biasResistor, float luxFactor = 500.0) {
    float milliVolt = readSensor();
    float r_ldr = (biasResistor * (ADC_VREF_mV - milliVolt)) / milliVolt;
    float lux_val = luxFactor / (r_ldr / 1000); // Calculate Lux value

    return lux_val;
}


