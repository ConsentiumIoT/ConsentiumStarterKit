#include "ConsentiumStarterKit.h"

// Unified constructor
ConsentiumStarterKit::ConsentiumStarterKit(SensorType type, int pin1, int pin2) : sensorType(type) {
    switch (type) {
        case ULTRASONIC:
            ultrasonicSensor = new UltrasonicSensor(pin1, pin2);
            break;
        case ANALOG_TEMP:
            tempSensor = new AnalogTemperatureSensor(pin1);
            break;
        case DIGITAL_TEMP_HUMIDITY:
            digitalSensor = new DigitalTemperatureHumiditySensor(pin1, pin2);
            break;
        case LUX_METER:
            luxmeter = new LuxMeter(pin1); // Corrected variable name
            break;
        default:
            // Handle unsupported sensor types
            ultrasonicSensor = nullptr;
            tempSensor = nullptr;
            digitalSensor = nullptr;
            luxmeter = nullptr;
            break;
    }
}

// Begin method to initialize the sensor
void ConsentiumStarterKit::begin() {
    switch (sensorType) {
        case ULTRASONIC:
            if (ultrasonicSensor) ultrasonicSensor->beginUltrasonicSensor();
            break;
        case DIGITAL_TEMP_HUMIDITY:
            if (digitalSensor) digitalSensor->beginDigitalTemperatureHumiditySensor();
            break;
        case ANALOG_TEMP:
        case LUX_METER:
            // These sensors require no additional initialization
            break;
        default:
            // Handle unsupported sensor types
            break;
    }
}

// Ultrasonic sensor methods
float ConsentiumStarterKit::getDistanceCm() {
    return (sensorType == ULTRASONIC && ultrasonicSensor) ? ultrasonicSensor->getDistanceCm() : -1;
}

float ConsentiumStarterKit::getDistanceInch() {
    return (sensorType == ULTRASONIC && ultrasonicSensor) ? ultrasonicSensor->getDistanceInch() : -1;
}

// Analog temperature sensor methods
float ConsentiumStarterKit::getTemperatureC() {
    return (sensorType == ANALOG_TEMP && tempSensor) ? tempSensor->readTemperatureC() : -1;
}

float ConsentiumStarterKit::getTemperatureF() {
    return (sensorType == ANALOG_TEMP && tempSensor) ? tempSensor->readTemperatureF() : -1;
}

// Digital temperature and humidity sensor methods
float ConsentiumStarterKit::getDigitalTemperatureC() {
    return (sensorType == DIGITAL_TEMP_HUMIDITY && digitalSensor) ? digitalSensor->getDTemperatureC() : -1;
}

float ConsentiumStarterKit::getDigitalTemperatureF() {
    return (sensorType == DIGITAL_TEMP_HUMIDITY && digitalSensor) ? digitalSensor->getDTemperatureF() : -1;
}

float ConsentiumStarterKit::getDigitalHumidity() {
    return (sensorType == DIGITAL_TEMP_HUMIDITY && digitalSensor) ? digitalSensor->getDHumidity() : -1;
}

// Lux meter methods
float ConsentiumStarterKit::getLuxValue(int biasResistor, float luxFactor) {
    return (sensorType == LUX_METER && luxmeter) ? luxmeter->readIntensityValue(biasResistor, luxFactor) : -1;
}
