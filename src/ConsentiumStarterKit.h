#ifndef ConsentiumStarterKit_h
#define ConsentiumStarterKit_h

#include "Arduino.h"
#include "LuxMeter.h"
#include "UltrasonicSensor.h"
#include "AnalogTemperatureSensor.h"
#include "DigitalTemperatureHumiditySensor.h"

// Enum to differentiate sensor types
enum SensorType {
    ULTRASONIC,
    ANALOG_TEMP,
    DIGITAL_TEMP_HUMIDITY, 
    LUX_METER
};

class ConsentiumStarterKit {
public:
    // Constructor for initializing different sensor types
    ConsentiumStarterKit(SensorType type, int pin1, int pin2 = -1);

    // Method to initialize the respective sensor
    void begin();

    // Ultrasonic sensor methods
    float getDistanceCm();   // Get distance in centimeters
    float getDistanceInch(); // Get distance in inches

    // Analog temperature sensor methods
    float getTemperatureC(); // Get temperature in Celsius
    float getTemperatureF(); // Get temperature in Fahrenheit

    // Digital temperature and humidity sensor methods
    float getDigitalTemperatureC(); // Get temperature in Celsius
    float getDigitalTemperatureF(); // Get temperature in Fahrenheit
    float getDigitalHumidity();     // Get humidity in percentage

    // Lux meter methods
    // biasResistor: Resistance value in ohms used in the voltage divider
    // luxFactor: Conversion factor for calculating lux (default: 500)
    float getLuxValue(int biasResistor, float luxFactor = 500.0);

private:
    SensorType sensorType; // Stores the type of the sensor

    // Sensor instances (optional, based on type)
    UltrasonicSensor* ultrasonicSensor = nullptr;
    AnalogTemperatureSensor* tempSensor = nullptr;
    DigitalTemperatureHumiditySensor* digitalSensor = nullptr;
    LuxMeter* luxmeter = nullptr;
};

#endif
